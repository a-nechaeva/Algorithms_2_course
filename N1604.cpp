#include <iostream>


std::pair<int, int> signs[10000];

bool compare(std::pair<int, int> s_1, std::pair<int, int> s_2) {
    return s_1.second > s_2.second;
}

//quicksort
void sorter(int left, int right) {
    int i = left;
    int j = right;

    std::pair<char, int> cur = signs[(left + right) / 2];

    while (i <= j) {
        while (compare(signs[i], cur)) {
            ++i;
        }
        while (compare(cur, signs[j])) {
            --j;
        }

        if (i <= j) {
            std::swap(signs[i++], signs[j--]);
        }
    }

    if (i < right) sorter(i, right);

    if (j > left) sorter(left, j);

}

int main() {
    int k;
    std::cin >> k;

    int sum = 0;

    for (int i = 0; i < k; ++i) {
        std::cin >> signs[i].second;
        signs[i].first = i + 1;
        sum += signs[i].second;
    }

    sorter(0, k - 1);
    int res[sum];

    bool check = false;
    if (signs[0].second > (sum + 1) / 2) {
        int i = 1;
        int j = k - 1;

        while (i < sum) {
            res[i] = signs[j].first;
            --signs[j].second;
            signs[j].second == 0 ? --j : j;
            i += 2;

            if (!check && i > sum - 1) {
                check = true;
                i = 0;
            }
        }
    } else {
        int i = 0;
        int j = 0;

        while (i < sum) {
            res[i] = signs[j].first;
            --signs[j].second;
            signs[j].second == 0 ? ++j : j;
            i += 2;

            if (!check && i > sum - 1) {
                check = true;
                i = 1;
            }
        }
    }

    for (int i = 0; i < sum; ++i) {
        std::cout << res[i] << " ";
    }
    return 0;
}
