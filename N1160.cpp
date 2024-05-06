#include <iostream>
#include <algorithm>
#include <vector>


// special structure to store information about connections
struct _connection {
    int v_1;
    int v_2;
    int l;
};

// special comparator to sort possible connections
bool _compare(_connection c_1, _connection c_2) {
    return c_1.l < c_2.l;
}



int main(){

    int N, M, v_1, v_2, l;
    std::cin >> N >> M;
    // vector of possible connections
    std::vector<_connection> _pos_con;

    for (int i = 0; i < M; ++i) {

        std::cin >> v_1 >> v_2 >> l;
        _pos_con.push_back((_connection){v_1 - 1, v_2 - 1, l});
    }
    // here starts the Kruskal's algorithm
    std::sort(_pos_con.begin(), _pos_con.end(), _compare);

    int _visited_v[N];
    int _visited_e[M];

    for (int i = 0; i < N; ++i) {
        _visited_v[i] = -1;
    }

    for (int i = 0; i < M; ++i) {
        _visited_e[i] = 0;
    }

    int _subgraph_number = 0;
    int _max = 0;
    int _counter = 0;

    for (int i = 0; i < M; ++i) {
        if (_visited_v[_pos_con[i].v_1] != -1 && _visited_v[_pos_con[i].v_1] == _visited_v[_pos_con[i].v_2]) continue;

        else if (_visited_v[_pos_con[i].v_1] == -1 && _visited_v[_pos_con[i].v_2] == -1) {
            _visited_v[_pos_con[i].v_1] = ++_subgraph_number;
            _visited_v[_pos_con[i].v_2] = _subgraph_number;

        } else if ((_visited_v[_pos_con[i].v_1] != -1 && _visited_v[_pos_con[i].v_2] == -1) ||
                   (_visited_v[_pos_con[i].v_1] == -1 && _visited_v[_pos_con[i].v_2] != -1)) {

            int _loc_subgraph = _visited_v[_pos_con[i].v_1] + _visited_v[_pos_con[i].v_2] + 1;
            _visited_v[_pos_con[i].v_1] = _loc_subgraph;
            _visited_v[_pos_con[i].v_2] = _loc_subgraph;
        } else {

            int min_subgraph;
            int max_subgraph;

            if (_visited_v[_pos_con[i].v_1] < _visited_v[_pos_con[i].v_2]) {
                min_subgraph = _visited_v[_pos_con[i].v_1];
                max_subgraph = _visited_v[_pos_con[i].v_2];
            } else {
                max_subgraph = _visited_v[_pos_con[i].v_1];
                min_subgraph = _visited_v[_pos_con[i].v_2];
            }

            for (int j = 0; j < N; ++j) {
                if (_visited_v[j] == max_subgraph) {
                    _visited_v[j] = min_subgraph;
                }
            }
        }
        _visited_e[i] = 1;
        _max = _pos_con[i].l;
        ++_counter;

    }
    std::cout << _max << std::endl << _counter << std::endl;

    for (int j = 0; j < M; ++j) {
        if (_visited_e[j]) {
            std::cout << _pos_con[j].v_1 + 1 << " " << _pos_con[j].v_2 + 1 << std::endl;
        }
    }

    return 0;

}

