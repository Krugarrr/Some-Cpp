#include "fair_cube_checker.h"
bool fair_cube_checker::fair_check(std::vector <std::vector <char>>& cube) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 9; ++j) {
            if ((cube[i][j] != 'y') && (cube[i][j] != 'o') && (cube[i][j] != 'g') && (cube[i][j] != 'r') && (cube[i][j] != 'b') && (cube[i][j] != 'w')) {
                return false;
            }
        }
    }

    std::vector <int> temp_cube(6, 0);
    bool flag = true;

    std::vector<std::pair<char, char>> edge;
    flag = flag && check_edge(edge, cube[0][1], cube[4][1], flag, temp_cube);
    flag = flag && check_edge(edge, cube[0][3], cube[1][1], flag, temp_cube);
    flag = flag && check_edge(edge, cube[0][5], cube[3][1], flag, temp_cube);
    flag = flag && check_edge(edge, cube[0][7], cube[2][1], flag, temp_cube);

    flag = flag && check_edge(edge, cube[1][5], cube[2][3], flag, temp_cube);
    flag = flag && check_edge(edge, cube[2][5], cube[3][3], flag, temp_cube);
    flag = flag && check_edge(edge, cube[3][5], cube[4][3], flag, temp_cube);
    flag = flag && check_edge(edge, cube[4][5], cube[1][3], flag, temp_cube);

    flag = flag && check_edge(edge, cube[5][1], cube[2][7], flag, temp_cube);
    flag = flag && check_edge(edge, cube[5][3], cube[1][7], flag, temp_cube);
    flag = flag && check_edge(edge, cube[5][5], cube[3][7], flag, temp_cube);
    flag = flag && check_edge(edge, cube[5][7], cube[4][7], flag, temp_cube);


    std::vector <char> center;
    flag = flag && check_center(center, cube[0][4], flag, temp_cube);
    flag = flag && check_center(center, cube[1][4], flag, temp_cube);
    flag = flag && check_center(center, cube[2][4], flag, temp_cube);
    flag = flag && check_center(center, cube[3][4], flag, temp_cube);
    flag = flag && check_center(center, cube[4][4], flag, temp_cube);
    flag = flag && check_center(center, cube[5][4], flag, temp_cube);


    std::vector<std::pair<char, std::pair<char, char>>> corner;
    flag = flag && check_corner(corner, cube[0][0], cube[1][0], cube[4][2], flag, temp_cube);
    flag = flag && check_corner(corner, cube[0][2], cube[3][2], cube[4][0], flag, temp_cube);
    flag = flag && check_corner(corner, cube[0][6], cube[1][2], cube[2][0], flag, temp_cube);
    flag = flag && check_corner(corner, cube[0][8], cube[2][2], cube[3][0], flag, temp_cube);

    flag = flag && check_corner(corner, cube[5][0], cube[1][8], cube[2][6], flag, temp_cube);
    flag = flag && check_corner(corner, cube[5][2], cube[2][8], cube[3][6], flag, temp_cube);
    flag = flag && check_corner(corner, cube[5][6], cube[1][6], cube[4][8], flag, temp_cube);
    flag = flag && check_corner(corner, cube[5][8], cube[3][8], cube[4][6], flag, temp_cube);

    if (!flag) {
        return flag;
    }
    else {
        for (int i = 0; i < 6; ++i) {
            if (temp_cube[i] != 9) {
                return false;
            }
        }
        return flag;
    }
}

void fair_cube_checker::check_cube(std::vector<int> &cube, char colour) {
    if (colour == 'y') {
        cube[0]++;
    }
    else if (colour == 'r') {
        cube[1]++;
    }
    else if (colour == 'g') {
        cube[2]++;
    }
    else if (colour == 'o') {
        cube[3]++;
    }
    else if (colour == 'b') {
        cube[4]++;
    }
    else if (colour == 'w') {
        cube[5]++;
    }
}

bool fair_cube_checker::check_edge(std::vector<std::pair<char, char>> &edge, char a, char b, bool &flag,
                                   std::vector<int> &temp_cube) {
    if (flag) {
        for (auto & i : edge) {
            if ((i.first == a && i.second == b) || (i.first == b && i.second == a) || check_column(a, b)) {
                return false;
            }
        }
        check_cube(temp_cube, a);
        check_cube(temp_cube, b);
        edge.emplace_back(a, b);
        return true;
    }
    else {
        return false;
    }
}

bool fair_cube_checker::check_column(char a, char b) {
    if ((a == 'w' && b == 'y') || (a == 'y' && b == 'w') || (a == 'r' && b == 'o') || (a == 'o' && b == 'r') || (a == 'b' && b == 'g') || (a == 'g' && b == 'b')) {
        return true;
    }
    return false;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "Simplify"
bool fair_cube_checker::check_corner(std::vector<std::pair<char, std::pair<char, char>>> corner, char a, char b, char c,
                                    bool &flag, std::vector<int> &cub) {
    if (flag) {
        for (unsigned int i = 0; i < corner.size(); ++i) {
            std::pair <char, char> now = corner[i].second;
            char first = corner[i].first, second = now.first, third = now.second;
            if ((first == a && second == b && third == c) &&
                (first == a && second == c && third == b) &&
                (first == b && second == a && third == c) &&
                (first == b && second == c && third == a) &&
                (first == c && second == a && third == b) &&
                (first == c && second == b && third == a) &&
                check_column(a, b) && check_column(a, c) && check_column(b, c)) {
                    return false;
            }
        }
        check_cube(cub, a);
        check_cube(cub, b);
        check_cube(cub, c);
        corner.push_back({a, {b, c}});
        return true;
    }
    else {
        return false;
    }
}

bool fair_cube_checker::check_center(std::vector<char> &center, char a, bool &flag, std::vector<int> &cub) {
    if (flag) {
        for (char i : center) {
            if (i == a) {
                return false;
            }
        }
        check_cube(cub, a);
        center.push_back(a);
        return true;
    }
    else {
        return false;
    }
}

bool fair_cube_checker::is_assembled(std::vector<std::vector<char>> &cube) {
    if ((cube[0][0] == 'y') && (cube[0][2] == 'y') && (cube[0][3] == 'y') && (cube[0][4] == 'y') && (cube[0][5] == 'y') && (cube[0][6] == 'y') && (cube[0][7] == 'y') && (cube[0][8] == 'y')
        && (cube[1][0] == 'r') && (cube[1][2] == 'r') && (cube[1][3] == 'r') && (cube[1][4] == 'r') && (cube[1][5] == 'r') && (cube[1][6] == 'r') && (cube[1][7] == 'r') && (cube[1][8] == 'r')
        && (cube[2][0] == 'g') && (cube[2][2] == 'g') && (cube[2][3] == 'g') && (cube[2][4] == 'g') && (cube[2][5] == 'g') && (cube[2][6] == 'g') && (cube[2][7] == 'g') && (cube[2][8] == 'g')
        && (cube[3][0] == 'o') && (cube[3][2] == 'o') && (cube[3][3] == 'o') && (cube[3][4] == 'o') && (cube[3][5] == 'o') && (cube[3][6] == 'o') && (cube[3][7] == 'o') && (cube[3][8] == 'o')
        && (cube[4][0] == 'b') && (cube[4][2] == 'b') && (cube[4][3] == 'b') && (cube[4][4] == 'b') && (cube[4][5] == 'b') && (cube[4][6] == 'b') && (cube[4][7] == 'b') && (cube[4][8] == 'b')
        && (cube[5][0] == 'w') && (cube[5][2] == 'w') && (cube[5][3] == 'w') && (cube[5][4] == 'w') && (cube[5][5] == 'w') && (cube[5][6] == 'w') && (cube[5][7] == 'w') && (cube[5][8] == 'w')) {
        return true;
    }
    else {
        return false;
    }
}

bool fair_cube_checker::check_cross(std::vector<std::vector<char>> &cube) {
    if (((cube[5][1] == 'w') && (cube[2][7] == 'g')) && ((cube[5][3] == 'w') && (cube[1][7] == 'r')) && ((cube[5][5] == 'w') && (cube[3][7] == 'o')) && ((cube[5][7] == 'w') && (cube[4][7] == 'b'))) {
        return true;
    }
    else {
        return false;
    }
}

bool fair_cube_checker::check_white_angle(std::vector<std::vector<char>> &cube) {
    if ((cube[5][1] == 'w') && (cube[2][7] == 'g') && (cube[5][3] == 'w') && (cube[1][7] == 'r') && (cube[5][5] == 'w') && (cube[3][7] == 'o') && (cube[5][7] == 'w') && (cube[4][7] == 'b') &&
        (cube[1][8] == 'r') && (cube[2][6] == 'g') && (cube[5][0] == 'w') && (cube[2][8] == 'g') && (cube[3][6] == 'o') && (cube[5][2] == 'w') &&
        (cube[3][8] == 'o') && (cube[4][6] == 'b') && (cube[5][8] == 'w') && (cube[4][8] == 'b') && (cube[1][6] == 'r') && (cube[5][6] == 'w')) {
        return true;
    }
    else {
        return false;
    }
}

bool fair_cube_checker::check_right_yellow_cross(std::vector<std::vector<char>> &cube) {
    if ((cube[5][1] == 'w') && (cube[2][7] == 'g') && (cube[5][3] == 'w') && (cube[1][7] == 'r') && (cube[5][5] == 'w') && (cube[3][7] == 'o') && (cube[5][7] == 'w') && (cube[4][7] == 'b') &&
        (cube[1][8] == 'r') && (cube[2][6] == 'g') && (cube[5][0] == 'w') && (cube[2][8] == 'g') && (cube[3][6] == 'o') && (cube[5][2] == 'w') &&
        (cube[3][8] == 'o') && (cube[4][6] == 'b') && (cube[5][8] == 'w') && (cube[4][8] == 'b') && (cube[1][6] == 'r') && (cube[5][6] == 'w') &&
        (cube[1][3] == 'r') && (cube[1][5] == 'r') && (cube[2][3] == 'g') && (cube[2][5] == 'g') && (cube[3][3] == 'o') && (cube[3][5] == 'o') && (cube[4][3] == 'b') && (cube[4][5] == 'b') &&
        (cube[0][1] == 'y') && (cube[0][3] == 'y') && (cube[0][5] == 'y') && (cube[0][7] == 'y')) {
        return true;
    }
    else {
        return false;
    }
}

bool fair_cube_checker::check_yellow_cross(std::vector<std::vector<char>> &cube) {
    if ((cube[5][1] == 'w') && (cube[2][7] == 'g') && (cube[5][3] == 'w') && (cube[1][7] == 'r') && (cube[5][5] == 'w') && (cube[3][7] == 'o') && (cube[5][7] == 'w') && (cube[4][7] == 'b') &&
        (cube[1][8] == 'r') && (cube[2][6] == 'g') && (cube[5][0] == 'w') && (cube[2][8] == 'g') && (cube[3][6] == 'o') && (cube[5][2] == 'w') &&
        (cube[3][8] == 'o') && (cube[4][6] == 'b') && (cube[5][8] == 'w') && (cube[4][8] == 'b') && (cube[1][6] == 'r') && (cube[5][6] == 'w') &&
        (cube[1][3] == 'r') && (cube[1][5] == 'r') && (cube[2][3] == 'g') && (cube[2][5] == 'g') && (cube[3][3] == 'o') && (cube[3][5] == 'o') && (cube[4][3] == 'b') && (cube[4][5] == 'b') &&
        (cube[0][1] == 'y') && (cube[0][3] == 'y') && (cube[0][5] == 'y') && (cube[0][7] == 'y')) {
        return true;
    }
    else {
        return false;
    }
}

bool fair_cube_checker::is_f2l(std::vector<std::vector<char>> &cube) {
    if ((cube[5][1] == 'w') && (cube[2][7] == 'g') && (cube[5][3] == 'w') && (cube[1][7] == 'r') && (cube[5][5] == 'w') && (cube[3][7] == 'o') && (cube[5][7] == 'w') && (cube[4][7] == 'b') &&
        (cube[1][8] == 'r') && (cube[2][6] == 'g') && (cube[5][0] == 'w') && (cube[2][8] == 'g') && (cube[3][6] == 'o') && (cube[5][2] == 'w') &&
        (cube[3][8] == 'o') && (cube[4][6] == 'b') && (cube[5][8] == 'w') && (cube[4][8] == 'b') && (cube[1][6] == 'r') && (cube[5][6] == 'w') &&
        (cube[1][3] == 'r') && (cube[1][5] == 'r') && (cube[2][3] == 'g') && (cube[2][5] == 'g') && (cube[3][3] == 'o') && (cube[3][5] == 'o') && (cube[4][3] == 'b') && (cube[4][5] == 'b')) {
        return true;
    }
    else {
        return false;
    }
}

#pragma clang diagnostic pop
