#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int number;
    std::cin >> number;

    std::vector<int> stones_weights(number);

    int full_sum = 0;

    for (int i = 0; i < number; ++i) {
        std::cin >> stones_weights[i];
        full_sum += stones_weights[i];
    }

    int min = full_sum;

    for (int i = 0; i < pow(2, number - 1); ++i) {
        int cur = i;
        int iter_numb = 0;
        int first_sum = 0;
        while (cur != 0) {
            if (cur % 2 == 1) {
                first_sum += stones_weights[iter_numb];
            }
            cur = cur / 2;
            ++iter_numb;
        }
        min = std::min(min, std::abs(full_sum - 2 * first_sum));
    }
    printf("%d", min);

    return 0;
}

