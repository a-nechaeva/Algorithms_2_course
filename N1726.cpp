#include <iostream>

unsigned long long x[100000];
unsigned long long y[100000];

//quicksort for x
void sorter_x(int left, int right) {
    int i = left;
    int j = right;

    unsigned long long medium = x[(left + right) / 2];

    while (i <= j) {
        while (x[i] < medium) {
            ++i;
        }
        while (medium < x[j]) {
            --j;
        }

        if (i <= j) {
            std::swap(x[i++], x[j--]);
        }
    }

    if (i < right) sorter_x(i, right);

    if (j > left) sorter_x(left, j);

}

//quicksort for y
void sorter_y(int left, int right) {
    int i = left;
    int j = right;

    unsigned long long medium = y[(left + right) / 2];

    while (i <= j) {
        while (y[i] < medium) {
            ++i;
        }
        while (medium < y[j]) {
            --j;
        }

        if (i <= j) {
            std::swap(y[i++], y[j--]);
        }
    }

    if (i < right) sorter_y(i, right);

    if (j > left) sorter_y(left, j);
}

int main() {
    long long n;
    std::cin >> n;
    unsigned long long sum = 0l;

    for (long long i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    sorter_x(0, (int) n - 1);
    sorter_y(0, (int) n - 1);

    for (int i = 0; i < n; ++i) {
        sum += (x[i] - x[i - 1]) * i * (n - i);
        sum += (y[i] - y[i - 1]) * i * (n - i);
    }
    sum = 2l * sum / (n * (n - 1));
    std::cout << sum;
    return 0;
}
