#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

// это массив всех возможных папок, он нужен для обращений к адресу потомка
std::string a[40001];

int main() {
    int number;
    std::cin >> number;
    std::string input_string, temp_string;
    // словарь, в котором ключ -- родительская директория (корень)
    std::map<std::string , std::vector<std::string >> global_map;
    //std::vector<std::string> only_parent;

    for (int i = 0; i < number; ++i) {
        std::vector<std::string> cur_words;
        std::cin >> input_string;
        std::stringstream string_like_stream(input_string);

        while (std::getline(string_like_stream, temp_string, '\\')) {
            cur_words.push_back(temp_string);
        }
        // здесь у нас есть массив текущей директории
        for (int j = 0; j < cur_words.size(); ++j) {
            //std::string cur_key;
            //cur_key = cur_words[j];
            // нужно сохранять подстрочку и массив указателей на ее потомков
        }
    }

    return 0;
}


