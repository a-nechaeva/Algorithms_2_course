#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265358979323846
#define EPS 1e-10

// new struct for points, it keeps x, y, number of the point, length and angle
struct point_struct {
    int x;
    int y;
    double angle;
    int id;
    double len;
};

const int MAX_N = 30001;
point_struct data_points[MAX_N];

bool compare(point_struct a, point_struct b) {
    if (abs(a.angle - b.angle) > EPS) {
        return a.angle < b.angle;
    }

    return a.len < b.len;
}

void quick_sort(int left, int right) {
    int i = left;
    int j = right;

    point_struct x = data_points[(left + right) / 2];

    while (i <= j) {
        while (compare(data_points[i], x)) {
            i++;
        }
        while (compare(x, data_points[j])) {
            j--;
        }

        if (i <= j) {
            swap(data_points[i], data_points[j]);

            i++;
            j--;
        }
    }

    if (i < right) {
        quick_sort(i, right);
    }
    if (left < j) {
        quick_sort(left, j);
    }
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> data_points[i].x >> data_points[i].y;
        data_points[i].id = i;

        if (i == 0) {
            data_points[i].angle = INT_MIN;
            data_points[i].len = 0;
        } else if (data_points[i].x == data_points[0].x){
            if (data_points[i].y  > data_points[0].y) {
                data_points[i].angle = 90;
            } else {
                data_points[i].angle = -90;
            }
            data_points[i].len = abs(data_points[i].y - data_points[0].y);
        } else {
            data_points[i].angle = atan((double) (data_points[i].y - data_points[0].y) / (data_points[i].x - data_points[0].x)) * 180.0 / PI;
            if (data_points[i].x <= data_points[0].x) {
                data_points[i].angle -= 180;
            }
            data_points[i].len = abs(sqrt((double) (pow((data_points[i].x - data_points[0].x), 2) + pow((data_points[i].y - data_points[0].y), 2))));
        }
    }

    quick_sort(0, n - 1);

    double max_a = 360 + data_points[1].angle - data_points[n - 1].angle;
    int counter = 1;

    for (int i = 1; i < n - 1; i++) {
        if (data_points[i + 1].angle - data_points[i].angle > max_a) {
            max_a = data_points[i + 1].angle - data_points[i].angle;
            counter = i + 1;
        }
    }

    cout << n << endl;
    cout << 1 << endl;

    for (int i = counter; i < n; i++) {
        cout << data_points[i].id + 1 << endl;
    }

    for (int i = 1; i < counter; i++) {
        cout << data_points[i].id + 1 << endl;
    }

    return 0;
}