#ifndef LAST_FAIR_CUBE_CHECKER_H
#define LAST_FAIR_CUBE_CHECKER_H
#include "../../simple_include/include.h"
class fair_cube_checker {
private:
    static void check_cube(std::vector <int>& cube, char colour);
    static bool check_column(char a, char b);
public:
    bool fair_check(std::vector <std::vector <char>>& cube);
    bool check_edge(std::vector <std::pair <char, char>>& edge, char a, char b, bool& flag, std::vector <int>& temp_cube);
    bool check_corner(std::vector <std::pair <char, std::pair<char, char>>> corner, char a, char b, char c, bool& flag, std::vector <int>& temp_cube);
    bool check_center(std::vector <char>& center, char a, bool& flag, std::vector <int>& temp_cube);
    bool is_assembled(std::vector <std::vector <char>>& cube);
    bool check_cross(std::vector <std::vector <char>>& cube);
    bool check_white_angle(std::vector <std::vector <char>>& cube);
    bool check_right_yellow_cross(std::vector <std::vector <char>>& cube);
    bool check_yellow_cross(std::vector <std::vector <char>>& cube);
    bool is_f2l(std::vector <std::vector <char>>& cube);
};


#endif //LAST_FAIR_CUBE_CHECKER_H
