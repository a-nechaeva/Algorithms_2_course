#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

// new struct for points, it keeps x, y, number of the point and angle
struct point_struct {
    int x;
    int y;
    double angle;
    int num;
};

point_struct data[10000];

bool compare(point_struct a, point_struct b) {
    return a.angle < b.angle;
}

void quick_sort(int left, int right){
    int i = left;
    int j = right;

    point_struct median = data[(left + right) / 2];

    while (i <= j) {
        while (compare(data[i], median)) {
            ++i;
        }
        while (compare(median, data[j])) {
            --j;
        }
        if (i <= j) {
            std::swap(data[i], data[j]);
            ++i;
            --j;
        }
    }
    if (i < right) {
        quick_sort(i, right);
    }
    if (left < j) {
        quick_sort(left, j);
    }
};

int main() {
    int n;
    std::cin >> n;

    int first_x = 1000000;
    int first_id = 0;

    for (int i = 0; i < n; ++i) {
        int p_x;
        int p_y;

        std::cin >> p_x >> p_y;

        if (p_x < first_x) {
            first_id = i;
            first_x = p_x;
        }

        data[i].x = p_x;
        data[i].y = p_y;
        data[i].num = i;
    }

    // here we analyze the angles
    for (int i = 0; i < n; ++i) {
        if (data[i].num == first_id) {
            data[i].angle = -360;
        } else {
            if (data[i].x == data[first_id].x) {
                if (data[i].y > data[first_id].y) {
                    data[i].angle = 90;
                } else {
                    data[i].angle = -90;
                }
            } else {
                data[i].angle = atan((double) (data[i].y - data[first_id].y) / (data[i].x - data[first_id].x)) * 180.0 / PI;
            }
        }
    }

    quick_sort(0, n - 1);

    std::cout << first_id + 1 << " " << data[n / 2].num + 1 << std::endl;

    return 0;
}
