#include <iostream>
#include <stack>


int main() {
    int n;
    std::cin >> n;
    // special data structure stack (first in - last out)
    // helps to check order of balls
    std::stack<int> stack_of_balls;
    // true if not cheater
    bool cheater = false;
    // the biggest number of ball was input
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        int cur_ball;
        std::cin >> cur_ball;
        // check and update stack of the balls
        if (temp < cur_ball) {
            for (int j = temp + 1; j < cur_ball; ++j) {
                stack_of_balls.push(j);
            }
            temp = cur_ball;
        } else {
            // check if current ball is on the top of stack
            if (cur_ball == stack_of_balls.top()) {
                // update stack by pop the highest
                stack_of_balls.pop();
            } else {
                cheater = true;
            }
        }
    }

    if (cheater) {
        std::cout << "Cheater" << std::endl;
    } else {
        std::cout << "Not a proof" << std::endl;
    }
}