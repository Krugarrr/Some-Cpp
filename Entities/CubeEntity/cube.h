#ifndef LAST_CUBE_H
#define LAST_CUBE_H
#include "../../simple_include/include.h"
#include "../../Models/SmallCubeModel/tiny_cube.h"
#include "../../Models/DrawModel/drawer.h"
#include "../../Models/CubeChecker/fair_cube_checker.h"
#include "../../Tools/gl_params.h"

class Cube {
private:
    const static int max_steps_per_try = 100;
    const static int colours_number = 6;
    const static int sides_number = 6;
    bool graphic_arr[3][3][3];
    tiny_cube temp[3][3];
    tiny_cube pieces[3][3][3]; // <-- 27 pieces of cube
    int rotation_angle[sides_number]; // <-- rotation angle for every side
    unsigned int colours[colours_number];
    double size;
public:
    gl_params glParams;
    std::vector <std::vector <char>> cube;
    std::string steps;
    draw_master drawer;
    fair_cube_checker checker;

public:
    Cube();
    void show();
    void save();
    void read_from_file();

    void spin();
    void generate();

    void solve();

    void clear(double size, unsigned int* color);
    void draw();
    void display();
    void rot90(int idx, int sign);
    void timer(int RorL, int);
    void Rotate(int idx, int angle, int RorL);
    int turns_counter;


    //Fucking turns
    void GR();
    void RR();
    void OR();
    void BR();
    void YR();
    void WR();

    void GRb ();
    void RRb ();
    void ORb ();
    void BRb ();
    void YRb ();
    void WRb ();

    void GL();
    void RL();
    void OL();
    void BL();
    void YL();
    void WL();

    void GLb ();
    void RLb ();
    void OLb ();
    void BLb ();
    void YLb ();
    void WLb ();

    void GU ();
    void RU ();
    void OU ();
    void BU ();
    void YU ();
    void WU ();

    void GUb ();
    void RUb ();
    void OUb ();
    void BUb ();
    void YUb ();
    void WUb ();

    void GD ();
    void RD ();
    void OD ();
    void BD ();
    void YD ();
    void WD ();

    void GDb();
    void RDb();
    void ODb();
    void BDb();
    void YDb();
    void WDb();

    void GF();
    void RF();
    void OF();
    void BF();
    void YF();
    void WF();

    void GFb();
    void OFb();
    void RFb();
    void BFb();
    void YFb();
    void WFb();

    //ya plakal poka pisal eti povoroti
    void GB();
    void RB();
    void OB();
    void BB();
    void YB();
    void WB();

    void GBb();
    void RBb();
    void OBb();
    void BBb();
    void YBb();
    void WBb();

    void RotateGR();
    void RotateGL();
    void RotateGU();
    void RotateGF();
    void RotateGB();
    void RotateGD();
    ~Cube();


private:
    //Tools
    void rotate_clockwise(int turn);
    void rotate_counterclockwise(int turn);
    void cross_manage(char first_colour, char second_colour);

    //Crosses
    void solve_white_cross();
    void solve_yellow_cross();
    void solve_right_yellow_cross();

    //Solve angles
    void solve_right_yellow_angle();
    void solve_white_angle();

    //f2l
    void solve_f2l();

    //Angles
    void turn_red_angle(char first_colour, char second_colour, char third_colour);
    void turn_green_angle(char first_colour, char second_colour, char third_colour);
    void turn_orange_angle(char first_colour, char second_colour, char third_colour);
    void turn_blue_angle(char first_colour, char second_colour, char third_colour);

    //Edges
    void turn_red_edge(char first_colour, char second_colour);
    void turn_green_edge(char first_colour, char second_colour);
    void turn_orange_edge(char first_colour, char c2);
    void turn_blue_edge(char first_colour, char c2);

    //Yellow magick
    void turn_yellow(int x);
    void turn_yellow_edgeR(char x);
    void turn_yellow_edgeG(char x);
    void turn_yellow_edgeO(char x);
    void turn_yellow_edgeB(char x);

};

#endif //LAST_CUBE_H