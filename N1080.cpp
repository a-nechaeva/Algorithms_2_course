#include <iostream>
#include <vector>
#include <queue>


std::vector<int> color(100, -1);
std::vector<int> edge[100];


// bfs algorithm
void _my_bfs(int _start) {

    std::queue<int> _queue;
    _queue.push(_start);
    color[_start] = 0;

    while (!_queue.empty()) {
        int v = _queue.front();
        _queue.pop();

        for (int i = 0; i < edge[v].size(); ++i) {
            int _cur_edge = edge[v][i];

            if (color[v] == color[_cur_edge]) {
                std::cout << -1;
                exit(0);
            }

            if (color[_cur_edge] == -1) {
                color[_cur_edge] = !color[v];
                _queue.push(_cur_edge);
            }
        }
    }
}


int main() {
    int n;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int _token = -1;

        while (_token != 0) {
            std::cin >> _token;

            if (_token != 0) {
                edge[i].push_back(--_token);
                edge[_token++].push_back(i);
            }
        }
    }

    _my_bfs(0);

    // check that all vertexes are colored
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            _my_bfs(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << color[i];
    }
    return 0;
}
