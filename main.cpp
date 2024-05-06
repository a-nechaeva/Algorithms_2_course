#include <iostream>
#include <algorithm>
#include <vector>


// special structure to store exchange points parameters
struct edge {
    int a;
    int b;
    double rate;
    double commission;
};

std::vector<edge> edges;
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

        edges.push_back({a, b, rab, cab});
        edges.push_back({b, a, rba, cba});
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < edges.size(); ++j) {
            nodes[edges[j].b] = std::max(edges[j].rate * (nodes[edges[j].a] - edges[j].commission), nodes[edges[j].b]);
        }
    }

    for (int i = 0; i < edges.size(); ++i) {
        if ( nodes[edges[i].b] < edges[i].rate * (nodes[edges[i].a] - edges[i].commission)) {
            std::cout << "YES";
            exit(0);
        }
    }
    std::cout << "NO";
}




