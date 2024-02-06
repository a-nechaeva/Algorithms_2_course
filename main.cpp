#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

int main() {
    int number;
    std::cin >> number;

    std::string input_string, temp_string;
    std::map<std::string , std::vector<std::string >> global_map;

    for (int i = 0; i < number; ++i) {
        std::vector<std::string> cur_words;
        std::cin >> input_string;

        std::stringstream string_like_stream(input_string);
        while (std::getline(string_like_stream, temp_string, '\\' )) {
            cur_words.push_back(temp_string);
        }
        for (int j = 0; j < cur_words.size(); ++j) {
            std::string cur_key;
            cur_key = cur_words[j];
            if (global_map.find(cur_key) != global_map.end()) {

                if (j < cur_words.size() - 1) {
                    auto element = std::find(global_map[cur_key].begin(),
                                             global_map[cur_key].end(), cur_words[j + 1]);
                    if (element == global_map[cur_key].end()) {
                        std::vector<std::string > temp = global_map[cur_key];
                        temp.push_back(cur_words[j + 1]);
                        global_map[cur_key] = temp;
                    }
                }
            } else {
                if (j < cur_words.size() - 1) {
                    std::vector<std::string> temp;
                    temp.push_back(cur_words[j + 1]);
                    global_map[cur_key] = temp;
                } else {
                    std::vector<std::string > temp;
                    temp.push_back("");
                    global_map[cur_key] = temp;
                }
            }
        }
    }
   /* for(const auto& pair : global_map) {
        std::cout << "Key: " << pair.first << ", Value: ";
        for (int i = 0; i < pair.second.size(); ++i) {
            std::cout << pair.second[i] << " ";
        }
        std::cout << std::endl;
    }
    */
   

    return 0;
}
