#include <iostream>
#include <algorithm>
#include <vector>


// special structure to store exchange points parameters
struct _exchange {
    int a;
    int b;
    double rate;
    double commission;
};

std::vector<_exchange> _exchanges;

double nodes[101];


int main() {

    int n, m, s;
    double v;

    std::cin >> n >> m >> s >> v;
    nodes[s] = v;

    for (int i = 0; i < m; ++i) {

        int a, b;
        double rab, cab, rba, cba;

        std::cin >> a >> b >> rab >> cab >> rba >> cba;

        _exchanges.push_back({a, b, rab, cab});
        _exchanges.push_back({b, a, rba, cba});
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < _exchanges.size(); ++j) {
            nodes[_exchanges[j].b] = std::max(_exchanges[j].rate *
                    (nodes[_exchanges[j].a] - _exchanges[j].commission),nodes[_exchanges[j].b]);
        }
    }

    for (int i = 0; i < _exchanges.size(); ++i) {
        if ( nodes[_exchanges[i].b] < _exchanges[i].rate * (nodes[_exchanges[i].a] - _exchanges[i].commission)) {
            std::cout << "YES";
            exit(0);
        }
    }
    std::cout << "NO";
}




