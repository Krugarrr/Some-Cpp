#ifndef LAST_DRAWER_H
#define LAST_DRAWER_H
#include "../SmallCubeModel/tiny_cube.h"

class draw_master {
public:
    void draw(tiny_cube cube_model);
    void draw(tiny_cube cube_model, GLfloat X, GLfloat Y, GLfloat Z);
};
#endif //LAST_DRAWER_H
