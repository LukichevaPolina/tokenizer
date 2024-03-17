#include "model.hpp"

namespace tokenizer {

Model::Model(t_merges merges_, t_vocab vocab_) : merges(merges_), vocab(vocab_) {}
Model::~Model() {}

void Model::apply_merges(const t_pretokenized_text& inp, t_pretokenized_text& out) {
    // splitting input into characters
    out = {};
    for (auto& word : inp) {
        std::list<std::string> symbols;
        for (auto& symb : word) {
            symbols.push_back(symb);
        }
        out.push_back(symbols);
    }

    // apply merges
    for (const auto& merge : merges) {
        for (auto& word : out) {
            auto it = word.begin();
            while (it != std::prev(word.end(), 1)) {
                auto next_it = std::next(it);
                if (*it == merge.first.first && *next_it == merge.first.second) {
                    *it = merge.second;
                    word.erase(next_it);
                } else {
                    it = next_it;
                }
            }
        }
    }
}

void Model::tokenize(const t_pretokenized_text& inp, std::vector<int>& ids) {
    for (auto& word : inp) {
        for (auto& subword : word) {
            ids.push_back(vocab[subword]);
        }
    }
}

void Model::encode_as_ids(const t_pretokenized_text& inp, std::vector<int>& ids) {
    t_pretokenized_text subwords;
    apply_merges(inp, subwords);
    tokenize(subwords, ids);
}

void Model::encode_as_subwords(const t_pretokenized_text& inp, t_pretokenized_text& subwords) {
    apply_merges(inp, subwords);
}
} // namespace tokenizer
