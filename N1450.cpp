#include <iostream>
#include <vector>


// structure to keep the edge
struct Way {
    int a, b, w;
};


int main() {

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, s, f;
    std::vector<Way> ways;
    std::vector<int> gas_transfer(500, -1);

    std::cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        std::cin >> a >> b >> w;
        ways.push_back({a - 1, b - 1, w});
    }

    std::cin >> s >> f;
    --s;
    --f;

    gas_transfer[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {

            if (gas_transfer[ways[j].b] < gas_transfer[ways[j].a] + ways[j].w && gas_transfer[ways[j].a] != -1)
                gas_transfer[ways[j].b] = gas_transfer[ways[j].a] + ways[j].w;
        }
    }

    if (gas_transfer[f] != -1) std::cout << gas_transfer[f];
    else std::cout << "No solution";

    return 0;
}
