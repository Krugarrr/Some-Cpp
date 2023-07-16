#ifndef LAST_TINY_CUBE_H
#define LAST_TINY_CUBE_H
#include "../../simple_include/include.h"

class tiny_cube {
private:
    const static int count_of_tiny_cube_sides = 3;
    const static int count_of_palette_colours = 6;
    unsigned char _colour[count_of_tiny_cube_sides];

public:

    float size;
    int palette[count_of_palette_colours];

    void rotX();
    void rotY();
    void rotZ();
    const double getSize();

    void setColor(int pos, int colour);

    unsigned char* move(int i);
};
#endif //LAST_TINY_CUBE_H
