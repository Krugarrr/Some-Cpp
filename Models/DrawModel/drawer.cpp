#include "drawer.h"
void draw_master::draw(tiny_cube cube_model) {
    glPushMatrix();
    glBegin(GL_QUADS);

    // top
    glColor3ubv(cube_model.move(0));
    glNormal3f(0, 0, 1);
    glVertex3f(cube_model.getSize(), cube_model.getSize(), cube_model.getSize());
    glVertex3f(0, cube_model.getSize(), cube_model.getSize());
    glVertex3f(0, 0, cube_model.getSize());
    glVertex3f(cube_model.getSize(), 0, cube_model.getSize());

    // bot
    glColor3ubv(cube_model.move(1));
    glNormal3f(0, 0, -1);
    glVertex3f(cube_model.getSize(), 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, cube_model.getSize(), 0);
    glVertex3f(cube_model.getSize(), cube_model.getSize(), 0);

    // front (ahahaha nu tipo war)
    glColor3ubv(cube_model.move(2));
    glNormal3f(0, -1, 0);
    glVertex3f(cube_model.getSize(), 0, cube_model.getSize());
    glVertex3f(0, 0, cube_model.getSize());
    glVertex3f(0, 0, 0);
    glVertex3f(cube_model.getSize(), 0, 0);

    // back
    glColor3ubv(cube_model.move(3));
    glNormal3f(0, 1, 0);
    glVertex3f(cube_model.getSize(), cube_model.getSize(), 0);
    glVertex3f(0, cube_model.getSize(), 0);
    glVertex3f(0, cube_model.getSize(), cube_model.getSize());
    glVertex3f(cube_model.getSize(), cube_model.getSize(), cube_model.getSize());

    // left
    glColor3ubv(cube_model.move(4));
    glNormal3f(-1, 0, 0);
    glVertex3f(0, cube_model.getSize(), cube_model.getSize());
    glVertex3f(0, cube_model.getSize(), 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, cube_model.getSize());

    // right
    glColor3ubv(cube_model.move(5));
    glNormal3f(1, 0, 0);
    glVertex3f(cube_model.getSize(), cube_model.getSize(), 0);
    glVertex3f(cube_model.getSize(), cube_model.getSize(), cube_model.getSize());
    glVertex3f(cube_model.getSize(), 0, cube_model.getSize());
    glVertex3f(cube_model.getSize(), 0, 0);

    glEnd();
    glPopMatrix();
}


void draw_master::draw(tiny_cube cube_model, GLfloat X, GLfloat Y, GLfloat Z) {
    glPushMatrix();
    glTranslated(X, Y, Z);
    draw(cube_model);
    glPopMatrix();
}


