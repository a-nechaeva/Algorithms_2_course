#include <iostream>
#include <bits/stdc++.h>


// to compare first items
bool c_1(std::pair<int, int> a, std::pair<int, int> b) {
    return (a.first != b.first) ? a.first < b.first : a.second < b.second;
}

//to compare second items
bool c_2(std::pair<int, int> a, std::pair<int, int> b) {
    return (a.second != b.second) ? a.second < b.second : a.first < b.first;
}

int main() {
    std::vector<std::pair<int, int>> day;
    std::vector<std::pair<int, int>> s_day;
    int m, n, k;
    int ans = 0;

    std::cin >> m >> n >> k;

    for (int i = 0; i < k; ++i) {
        std::pair<int, int> cur;
        std::cin >> cur.first >> cur.second;
        cur.first--;
        cur.second--;
        day.push_back(cur);
    }

    for (int i = 0; i < m; ++i) {
        std::pair<int, int> cur = {i, -1};
        std::pair<int, int> c_cur = {i, n};
        day.push_back(c_cur);
        day.push_back(cur);
    }

    for (int i = 0; i < n; ++i) {
        std::pair<int, int> cur = {-1, i};
        std::pair<int, int> c_cur = {m, i};
        day.push_back(c_cur);
        day.push_back(cur);
    }
    std::sort(day.begin(), day.end(), c_1);

    for (int i = 0; i < day.size() - 1; ++i) {
        if (day[i].first == day[i + 1].first)  {
            if (day[i + 1].second - day[i].second > 2) {
                ++ans;
            } else if (day[i + 1].second - day[i].second == 2) {
                std::pair<int, int> cur(day[i].first, day[i].second + 1);
                s_day.push_back(cur);
            }
        }
    }

    std::sort(day.begin(), day.end(), c_2);

    for (int i = 0; i < day.size(); ++i) {
        if (day[i].second == day[i + 1].second) {
            if (day[i + 1].first - day[i].first > 2) {
                ++ans;
            } else if (day[i + 1].first - day[i].first == 2) {
                std::pair<int, int> cur(day[i].first + 1, day[i].second);
                s_day.push_back(cur);
            }
        }
    }

    std::sort(s_day.begin(), s_day.end(), c_1);

    if (s_day.size() > 1) {
        for (int i = 0; i < s_day.size() - 1; ++i) {
            if (s_day[i] == s_day[i + 1]) {
                ++ans;
                ++i;
            }
        }
    }

    std::cout << ans;
    return 0;

}