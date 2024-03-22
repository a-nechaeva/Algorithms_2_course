#include <iostream>
#include <cmath>


int result_points[512][512];
int current_number = 3;


void creator(int n, int x, int y,  int empty_x, int empty_y) {
    // base square
    if (n == 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (x + i != empty_x || y + j != empty_y) {
                    result_points[x + i][y + j] = current_number / 3;
                    ++current_number;
                }
            }
        }
        return;
    }
    // work with middle triangle
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int x_1 = x + i * n / 2;
            int x_2 = x + i * n / 2 + n / 2;
            int y_1 = y + j * n / 2;
            int y_2 =  y + j * n / 2 + n / 2;

            if (x_1 > empty_x || x_2 <= empty_x ||
            y_1 > empty_y || y_2 <= empty_y) {
                result_points[x + n / 2 - 1 + i][y + n / 2 - 1 + j] = current_number / 3;
                ++current_number;
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int x_1 = x + i * n / 2;
            int x_2 = x + i * n / 2 + n / 2;
            int y_1 = y + j * n / 2;
            int y_2 = y + j * n / 2 + n / 2;

            // parts with empty point and without
            x_1 <= empty_x && x_2 > empty_x &&
            y_1 <= empty_y && y_2 > empty_y ?
            creator(n / 2, x_1, y_1, empty_x, empty_y) :
            creator(n / 2, x_1, y_1, x + n / 2 - 1 + i, y + n / 2 - 1 + j);
        }
    }
}

int main() {
    int n, empty_x, empty_y;
    std::cin >> n >> empty_x >> empty_y;
    n = pow(2, n);

    creator(n, 0, 0, empty_x - 1, empty_y - 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << result_points[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
