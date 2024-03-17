#include "parser.hpp"

namespace tokenizer {

Parser::Parser(std::string path) {
    parse_merges(path);
    parse_vocab(path);
}

void Parser::parse_merges_from_txt(std::string path) {
    try {
        std::ifstream file(path);
        if (file.is_open()) {
            t_merge merge;
            while (file >> merge.first >> merge.second) {
                if (merge.first[0] != '#') // skip comments
                    merges[merge] = merge.first + merge.second;
            }
        }
        file.close();
    } catch(const std::ifstream::failure& e) {
        std::cout << "Exception during opening/reading file";
        throw;
    }
}

void Parser::parse_merges_from_json(std::string path) {
    try {
        std::ifstream file(path);
        if (file.is_open()) {
            // find "merges" in json file
            std::string line, substr = "\"merges\": [";
            while (std::getline(file, line) && line.find(substr) == std::string::npos) {}

            // parse merges
            t_merge merge;
            std::string first_str, second_str;
            while (file >> first_str >> second_str && first_str != "]") {
                merge.first = first_str.erase(0, 1);
                merge.second = second_str.erase(second_str.size() - 2, second_str.size() - 1);;
                merges[merge] = merge.first + merge.second;
            }
        }
        file.close();
    } catch(const std::ifstream::failure& e) {
        std::cout << "Exception during opening/reading file";
        throw;
    }
}


void Parser::parse_merges(std::string path) {
    std::string file_extention = path.substr(path.rfind(".") + 1);
    if (file_extention == "txt") {
        parse_merges_from_txt(path);
    } else if (file_extention == "json") {
        parse_merges_from_json(path);
    } else {
        std::cout << "Wrong type of file. Supportes types: txt and json" << std::endl;
        throw;        
    }
}

void Parser::parse_vocab(std::string path) {
    try {
        std::ifstream file(path);
        if (file.is_open()) {
            // find "vocab" in json file
            std::string line, substr = "\"vocab\": {";
            while (std::getline(file, line) && line.find(substr) == std::string::npos) {}
            
            // parse vocab  
            t_merge merge;
            std::string key, val;
            while (file >> key >> val && key != "},") {
                key = key.substr(1, key.size() - 3);
                val.erase(val.size() - 1);
                vocab[key] = std::stoi(val);
            }
        }
        file.close();
    } catch(const std::ifstream::failure& e) {
        std::cout << "Exception during opening/reading file";
        throw;
    }
}

t_merges Parser::get_merges() {
    return merges;
}

t_vocab Parser::get_vocab() {
    return vocab;
}

} // namespace tokenizer
