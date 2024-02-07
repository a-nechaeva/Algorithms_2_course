#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int cube[8];
std::vector<std::string> v_names = {"A", "B", "C", "D", "E", "F", "G", "H"};

void annihilate(int ind_1, int ind_2) {
    int min_numb = std::min(cube[ind_1], cube[ind_2]);

    for (int i = 0; i < min_numb; ++i) {
        std::cout << v_names[ind_1] + v_names[ind_2] + "-" << std::endl;
        --cube[ind_1];
        --cube[ind_2];
    }
}

void create(int ind_1, int ind_2, int cost) {

    for (int i = 0; i < cost; ++i) {
        std::cout << v_names[ind_1] + v_names[ind_2] + "+" << std::endl;
        ++cube[ind_1];
        ++cube[ind_2];
    }
}

int main() {
    int sum_of_all = 0;

    for (int i = 0; i < 8; ++i) {
        std::cin >> cube[i];
        sum_of_all += cube[i];
    }

    // что-то интуитивное, но нужно док-ть
    if ((cube[0] + cube[2] + cube[5] + cube[7]) != (cube[1] + cube[3] + cube[4] + cube[6])) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        // берем 1 вершину и аннигилируем со всеми смежными
        annihilate(0, 1);
        annihilate(0, 3);
        annihilate(0, 4);
        // если после этого вершина А (0) не обнулилась добиваем одну (в паре с ей смежной вершиной) из смежных вершин до стоимости А
        if (cube[0] > 0) {
            create(1, 2, cube[0]);
        }
        // добиваем вершину А до нуля
        annihilate(0, 1);

        // берем 2 вершину B и аннигилируем со всеми смежными, кроме обнуленной А
        annihilate(1, 2);
        annihilate(1, 5);

        if (cube[1] > 0) {
            create(2, 6, cube[1]);
        }
        annihilate(1, 2);

        // убираем вершину D
        annihilate(3, 2);
        annihilate(3, 7);

        if (cube[3] > 0) {
            create(7, 6, cube[3]);
        }
        annihilate(3, 7);

        // убираем E
        annihilate(4, 5);
        annihilate(4, 7);

        if (cube[4] > 0) {
            create(7, 6, cube[4]);
        }
        annihilate(4, 7);

        // убираем G
        annihilate(6, 2);
        annihilate(6, 5);
        annihilate(6, 7);

    }
}
