#include "parser.hpp"
#include "model.hpp"
#include <string>

int main() {

    tokenizer::Parser parser("/home/polina/tokenizer/data/tokenizer_llama.json");

    tokenizer::t_vocab vocab = parser.get_vocab();
    tokenizer::t_merges merges = parser.get_merges();
    tokenizer::t_pretokenized_text text = {{"Word"}};

    tokenizer::Model model(merges, vocab);
    std::vector<int> tokens;
    model.encode_as_ids(text, tokens);

    for (auto& token : tokens) {
        std::cout << token << " ";
    }
    std::cout << std::endl;

    return 0;
}
