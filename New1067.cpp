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

    disk* rt = new disk();

    for (int i = 0; i < n; ++i) {
        std::string cur_path;
        std::cin >> cur_path;
        disk* cur_d = rt;
        std::string d;

        for (int j = 0; j <= cur_path.size(); ++j) {

            if (cur_path[j] == '\\' || cur_path[j] == '\0') {
                auto d_disk = cur_d -> child.find(d);

                if (d_disk == cur_d -> child.end()) {
                    disk* new_disk = new disk(d);
                    cur_d -> child[d] = new_disk;
                    cur_d = cur_d -> child.find(d) -> second;

                } else {
                    cur_d = d_disk -> second;
                }

                d = "";
                
            } else {
                d += cur_path[j];
            }
        }
    }
    disk_printer(rt, 0);

    return 0;
}


