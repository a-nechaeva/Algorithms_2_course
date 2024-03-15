#include <iostream>


const int maximum_n = 100000;

std::pair<char, int> data[maximum_n];

bool comparator(std::pair<char, int> first, std::pair<char, int> second) {
    return (first.first != second.first) ? first.first < second.first : first.second < second.second;
}

//sort in lexicographic order (quick sort)
void sorter(int left, int right) {
    int i = left;
    int j = right;

    std::pair<char, int> cur = data[(left + right) / 2];

    while (i <= j) {
        while (comparator(data[i], cur)) {
            ++i;
        }
        while (comparator(cur, data[j])) {
            --j;
        }

        if (i <= j) {
            std::swap(data[i++], data[j--]);
        }
    }

    if (i < right) sorter(i, right);

    if (j > left) sorter(left, j);

}

int main() {
    int s;
    std::string str;

    std::cin >> s >> str;

    int symbols_counter = str.length();

    for (int i = 0; i < symbols_counter; ++i) {
        data[i].first = str[i];
        data[i].second = i;
    }

    sorter(0, symbols_counter - 1);

    int result[symbols_counter];

    for (int i = 0; i < symbols_counter; ++i) {
        result[i] = data[i].second;
    }

    int current = s - 1;

    for (int i = 0; i < symbols_counter; ++i) {
        std::cout << data[current].first;
        current = result[current];
    }

    return 0;
}
