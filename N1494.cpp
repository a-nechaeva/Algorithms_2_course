#include <iostream>
#include <stack>


int main() {
    int n;
    std::cin >> n;
    // special data structure stack (first in - last out)
    std::stack<int> stack_of_balls;
    bool result = true;
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        int cur_ball;
        std::cin >> cur_ball;
        if (temp < cur_ball) {
            for (int j = temp + 1; j < cur_ball; ++j) {
                stack_of_balls.push(j);
            }
            temp = cur_ball;
        } else {
            if (cur_ball == stack_of_balls.top()) {
                stack_of_balls.pop();
            } else {
                result = false;
            }
        }

    }
    if (result) {
        std::cout << "Not a proof" << std::endl;
    } else {
        std::cout << "Cheater" << std::endl;
    }
}