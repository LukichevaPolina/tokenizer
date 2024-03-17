#include <string>
#include <map>
#include <list>
#include <vector>

#include <iostream>

namespace tokenizer {

typedef std::pair<std::string, std::string> t_merge;
typedef std::map<t_merge, std::string> t_merges;
typedef std::vector<std::list<std::string>> t_pretokenized_text;
typedef std::map<std::string, int> t_vocab;

} // namespace tokenizer
