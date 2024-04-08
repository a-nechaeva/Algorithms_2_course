#include <iostream>
#include <vector>


int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> circle_order;

    // clang-tidy recommendation
    circle_order.reserve(n);
    for (int i = 0; i < n; ++i) {
        circle_order.push_back(i);
    }
    // position to go out of the circle
    int go_away = --k;

    for (int i = --n; i > 0; --i) {
        std::cout << circle_order[go_away] + 1 << " ";
        circle_order.erase(circle_order.begin() + go_away);
        go_away = (go_away + k) % i;
    }

    std::cout << circle_order[0] + 1 << " ";
    return 0;
}