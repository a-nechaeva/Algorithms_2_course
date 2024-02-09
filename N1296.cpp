#include <iostream>


int main() {
    int n;
    std::cin >> n;

    // task to search substring with max sum
    int max_sum = 0;
    int cur_sum = 0;

    for (int i = 0; i < n; ++i) {
        int cur_p;
        std::cin >> cur_p;

        cur_sum += cur_p;
        cur_sum = cur_sum < 0 ? 0 : cur_sum;
        max_sum = max_sum < cur_sum ? cur_sum : max_sum;
    }

    std::cout << max_sum << std::endl;
}
