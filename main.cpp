#include <iostream>
#include <map>
#include <utility>


// structure for smart store disk items and their relates
struct disk {
    std::string item;
    std::map<std::string, disk *> child;

    // clang-tidy recommendation for single-argument constructions
    explicit disk(std::string name) {
        // clang-tidy recommendation
        this -> item = std::move(name);
        this -> child = {};
    }

    disk() {
        this -> item = "";
        this -> child = {};
    }
};


// method for printing disk structure in recursive mode
void disk_printer(disk* cur, int depth) {
    for (int i = 0; i < depth - 1; ++i) {
        std::cout << " ";
    }
    if (!cur -> item.empty()) {
        std::cout << cur -> item << std::endl;
    }
    ++depth;

    for (auto &child_dir : cur -> child) {
        disk_printer(child_dir.second, depth);
    }
}


int main() {
    int n;
    std::cin >> n;

    disk* main_part = new disk();

    for (int i = 0; i < n; ++i) {
        std::string cur_path;
        std::cin >> cur_path;
        disk* cur_part = main_part;
        std::string dir;

        for (int j = 0; j <= cur_path.size(); ++j) {
            if (cur_path[j] == '\\' || cur_path[j] == '\0') {
                auto dir_tr = cur_part -> child.find(dir);

                if (dir_tr == cur_part -> child.end()) {
                    disk* new_disk = new disk(dir);
                    cur_part -> child[dir] = new_disk;
                    cur_part = cur_part -> child.find(dir) -> second;
                } else {
                    cur_part = dir_tr -> second;
                }
                dir = "";
            } else {
                dir += cur_path[j];
            }
        }
    }
    disk_printer(main_part, 0);

    return 0;
}


