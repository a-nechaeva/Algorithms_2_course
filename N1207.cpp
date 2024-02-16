#include <iostream>
#include <vector>


// new struct for points, it keeps x, y, number of the point and angle
struct point_struct {
    int x;
    int y;
    double angle;
    int num;
};

void quick_sort(point_struct* points, int left, int right){
    int left_ind = left;
    int right_ind = right;
    double rotation = points[(left_ind + right_ind) / 2].angle;

    while (left_ind <= right_ind) {
        while (points[left_ind].angle < rotation) {
            ++left_ind;
        }
        while (points[right_ind].angle > rotation) {
            --right_ind;
        }

        
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<int[2]> points;

    int first_x;
    int first_y;

    for (int i = 0; i < n; ++i) {
        int temp[2];
        std::cin >> temp[0] >> temp[1];

    }
}
