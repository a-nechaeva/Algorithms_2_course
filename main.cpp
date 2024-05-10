#include <iostream>
#include <map>
#include <set>


// structure for city parameters
struct City {
    std::string _name;
    long long _money;
    int _days;
} pCity[60000];

//structure for billionaires' parameters
struct Billionaire {
    long long _money;
    City *_loc;
} pBillionaire[10000];


int main() {

    int n, m, k;
    std::cin >> n;

    int _city_number = 0;

    std::map<std::string, City *> _cities;
    std::map<std::string, Billionaire *> _billionaires;
    std::set<std::pair<long long, City *>, std::greater<>> score;

    for (int i = 0; i < n; i++) {
        std::string name_person;
        std::string name_city;
        long long money;
        std::cin >> name_person >> name_city >> money;

        if (!_cities[name_city]) {

            pCity[_city_number]._name = name_city;
            pCity[_city_number]._money = money;
            _cities[name_city] = &pCity[_city_number++];

        } else _cities[name_city]->_money += money;


        pBillionaire[i]._money = money;
        pBillionaire[i]._loc = _cities[name_city];
        _billionaires[name_person] = &pBillionaire[i];

    }

    for (auto &item : _cities) {
        score.insert({item.second->_money, item.second});
    }

    int today = 0;

    std::cin >> m >> k;

    for (int i = 0; i < k; i++) {
        int day;
        std::string name_person;
        std::string name_city;
        std::cin >> day >> name_person >> name_city;

        int count = day - today;
        today = day;

        auto a = score.begin();
        auto b = a++;

        if (a->first < b->first || a == score.end()) {
            b->second->_days += count;
        }

        City *to_city = _cities[name_city];
        Billionaire *who = _billionaires[name_person];

        if (to_city == nullptr) {

            pCity[_city_number]._name = name_city;
            _cities[name_city] = &pCity[_city_number++];
            to_city = _cities[name_city];
        }

        score.erase({who->_loc->_money, who->_loc});
        score.erase({to_city->_money, to_city});

        who->_loc->_money -= who->_money;

        score.insert({who->_loc->_money, who->_loc});

        who->_loc = to_city;
        to_city->_money += who->_money;

        score.insert({to_city->_money, to_city});
    }

    int count = m - today;

    auto a = score.begin();
    auto b = a++;

    if (a->first < b->first || a == score.end()) {
        b->second->_days += count;
    }

    for (auto &item : _cities) {
        if (item.second->_days > 0) {
            std::cout << item.first << " " << item.second->_days << std::endl;
        }
    }

    return 0;
}