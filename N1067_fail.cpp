#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>


void recursion(std::string cur_key, int ws, std::map<std::string , std::vector<std::string >> global_map) {

    if (cur_key != "") {
        for (int i = 0; i < ws; ++i) {
            printf("%s", " ");
        }
        printf("%s\n", cur_key.c_str());
        std::vector<std::string> cur_key_children = global_map[cur_key];
        std::sort(cur_key_children.begin(), cur_key_children.end());
        ++ws;
        for (int j = 0; j < cur_key_children.size(); ++j) {
            recursion(cur_key_children[j], ws, global_map );
        }
    }
}

int main() {
    int number;
    std::cin >> number;

    std::string input_string, temp_string;
    std::map<std::string , std::vector<std::string >> global_map;
    std::vector<std::string> only_parent;


    for (int i = 0; i < number; ++i) {
        std::vector<std::string> cur_words;
        std::cin >> input_string;



            std::stringstream string_like_stream(input_string);
            while (std::getline(string_like_stream, temp_string, '\\')) {
                cur_words.push_back(temp_string);
            }
            for (int j = 0; j < cur_words.size(); ++j) {
                std::string cur_key;
                cur_key = cur_words[j];
                // проверка наличия ключа
                if (global_map.find(cur_key) != global_map.end()) {

                    if (j < cur_words.size() - 1) {
                        // проверка наличия элемента в словаре
                        auto element = std::find(global_map[cur_key].begin(),
                                                 global_map[cur_key].end(), cur_words[j + 1]);
                        if (element == global_map[cur_key].end()) {
                            std::vector<std::string> temp = global_map[cur_key];
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
                        std::vector<std::string> temp;
                        temp.push_back("");
                        global_map[cur_key] = temp;
                    }
                    only_parent.push_back(cur_key);
                    // удаляем из массива родителей элемент, являющийся чьи-то потомком
                    if (j > 0) {
                        only_parent.erase(std::remove(only_parent.begin(), only_parent.end(), cur_words[j]),
                                          only_parent.end());
                    }
                }
            }

    }
    //найти таких родителей, которые не являются ничьими потомками
    // берем массив only_parent и начинаем в лексическом порядке вытягивать цепочки родитель-потомок
    std::sort(only_parent.begin(), only_parent.end());
    int white_space_counter = 0;
    for (int i = 0; i < only_parent.size(); ++i) {
        recursion(only_parent[i], white_space_counter, global_map);
    }

    return 0;
}

