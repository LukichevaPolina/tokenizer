#include "parser.hpp"
#include <string>

int main() {

    tokenizer::Parser parser;
    parser.parse_vocab("/home/polina/tokenizer/data/tokenizer_gpt2.json");

    tokenizer::t_vocab vocab = parser.get_vocab();

    return 0;
}