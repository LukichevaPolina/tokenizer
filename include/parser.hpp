#ifndef PARSER_JSON_HPP
#define PARSER_JSON_HPP

#include <string>
#include <fstream>
#include <sstream>

#include "utils.hpp"

namespace tokenizer {

class Parser {
public:
    Parser(){};
    ~Parser(){};

    void parse_merges(std::string path);
    void parse_vocab(std::string path);

    t_vocab get_vocab();
    t_merges get_merges();

private:
    void parse_merges_from_txt(std::string path);
    void parse_merges_from_json(std::string path);

private:
    t_merges merges;
    t_vocab vocab;
};

} // namespace tokenizer

#endif // PARSER_JSON_HPP