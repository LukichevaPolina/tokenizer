#ifndef MODEL_HPP
#define MODEL_HPP

#include "utils.hpp"

namespace tokenizer {

class Model{
public:
    Model(t_merges merges, t_vocab vocab);
    ~Model();

    void encode_as_ids(const t_pretokenized_text& inp, std::vector<int>& tokens);
    void encode_as_subwords(const t_pretokenized_text& inp, t_pretokenized_text& subwords);

private:
    void apply_merges(const t_pretokenized_text& inp, t_pretokenized_text& out); // TODO:rename
    void tokenize(const t_pretokenized_text& inp, std::vector<int>& tokens);

private:
    t_merges merges;
    t_vocab vocab;
};
} // namespace tokenizer

#endif // MODEL_HPP
