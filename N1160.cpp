#include <iostream>
#include <algorithm>
#include <vector>


struct _cable {
    int v_1;
    int v_2;
    int l;
};


bool _compare(_cable c_1, _cable c_2) {
    return c_1.l < c_2.l;
}



int main(){

    int N, M, v_1, v_2, l;
    std::cin >> N >> M;

    std::vector<_cable> _possible_connections;

    for (int i = 0; i < M; ++i) {

        std::cin >> v_1 >> v_2 >> l;
        _possible_connections.push_back((_cable){v_1 - 1, v_2 - 1, l});
    }

    std::sort(_possible_connections.begin(), _possible_connections.end(), _compare);



}

