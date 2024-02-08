#include <iostream>


int main() {
    int numb_test;
    std::cin >> numb_test;

    for (int i = 0; i < numb_test; ++i) {

        int fighters, teams;
        std::cin >> fighters;
        std::cin >> teams;

        int medium_in_team = fighters / teams;
        int extra_fighters = fighters % teams;
        int result = (medium_in_team * (teams - extra_fighters) * (fighters - medium_in_team) +
                extra_fighters * (medium_in_team + 1) * (fighters - medium_in_team - 1)) / 2;

        std::cout << result << std::endl;
    }
}
