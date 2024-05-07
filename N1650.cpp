#include <iostream>
#include <map>
#include <set>


struct City {
    std::string name;
    long long money;
    int days;
} city[60000];

struct Person {
    long long money;
    City *location;
} person[10000];

std::map<std::string, Person *> human;
std::map<std::string, City *> world;
std::set<std::pair<long long, City *>, std::greater<>> score;

int main() {

    int n;
    std::cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        std::string name_person;
        std::string name_city;
        long long money;
        std::cin >> name_person >> name_city >> money;

        if (!world[name_city]) {
            city[cnt].name = name_city;
            city[cnt].money = money;
            world[name_city] = &city[cnt];
            cnt++;
        } else {
            world[name_city]->money += money;
        }

        person[i].money = money;
        person[i].location = world[name_city];
        human[name_person] = &person[i];
    }

    for (auto &item : world) {
        score.insert({item.second->money, item.second});
    }

    int m, k, today = 0;
    std::cin >> m >> k;

    for (int i = 0; i < k; i++) {
        int day;
        std::string name_person;
        std::string name_city;
        std::cin >> day >> name_person >> name_city;

        int count = day - today;
        today = day;

        auto it2 = score.begin();
        auto it = it2++;

        if (it2 == score.end() || it->first > it2->first) {
            it->second->days += count;
        }

        City *to_city = world[name_city];
        Person *who = human[name_person];

        if (to_city == nullptr) {
            city[cnt].name = name_city;
            world[name_city] = &city[cnt];
            cnt++;

            to_city = world[name_city];
        }

        score.erase({who->location->money, who->location});
        score.erase({to_city->money, to_city});
        who->location->money -= who->money;
        score.insert({who->location->money, who->location});
        who->location = to_city;
        to_city->money += who->money;
        score.insert({to_city->money, to_city});
    }

    int count = m - today;
    auto it2 = score.begin();
    auto it = it2++;
    if (it2 == score.end() || it->first > it2->first) {
        it->second->days += count;
    }

    for (auto &item : world) {
        if (item.second->days > 0) {
            std::cout << item.first << " " << item.second->days << std::endl;
        }
    }

    return 0;
}
