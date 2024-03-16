#include <iostream>
#include <cmath>


#define PI 3.14159265358979323846
#define EPS 1e-10

// new struct for points, it keeps x, y, number of the point, length and angle
struct point_struct {
    int x;
    int y;
    double len;
    double angle;
    int num;
};

point_struct data[30000];

bool compare(point_struct a, point_struct b) {
    if (abs(a.angle - b.angle) > EPS) {
        return a.angle < b.angle;
    }
    return a.len < b.len
}
