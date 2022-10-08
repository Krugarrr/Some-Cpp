#include  "Models/SmallCubeModel/tiny_cube.h"
#include "Models/drawModel/drawer.h"
#include "Entities/CubeEntity/cube.h"

Cube cube;
unsigned int colour[6] = {0x00FF00, 0x0000FF, 0xFFFFFF, 0xFFFF00, 0xFF0000, 0xFF6800 };

void display() {
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glTranslatef(0, 0, cube.glParams.AXIS);
    glRotatef(cube.glParams.xRot, 1, 0, 0);
    glRotatef(cube.glParams.yRot, 0, 1, 0);
    glTranslatef(cube.glParams.CUBE_SIZE / -2.0, cube.glParams.CUBE_SIZE / -2.0, cube.glParams.CUBE_SIZE / -2.0);
    cube.draw();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat fAspect = (GLfloat)w / (GLfloat)h;
    gluPerspective(60, fAspect, 1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void init() {
    // ���� ����
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // ���������
    float mat_specular[] = { 0.3, 0.3, 0.3, 0 };
    float diffuseLight[] = { 0.2, 0.2, 0.2, 1 };
    float ambientLight[] = { 0.9, 0.9, 0.9, 1.0 };
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMateriali(GL_FRONT, GL_SHININESS, 128);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    cube.clear(cube.glParams.CUBE_SIZE, colour);
}


void specialKeys(int key, int, int) {
    if (key == GLUT_KEY_DOWN) {
        cube.glParams.xRot += 3;
        if (cube.glParams.xRot >= 360)
            cube.glParams.xRot -= 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_UP) {
        cube.glParams.xRot -= 3;
        if (cube.glParams.xRot < 0)
            cube.glParams.xRot += 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_RIGHT) {
        cube.glParams.yRot += 3;
        if (cube.glParams.yRot >= 360)
            cube.glParams.yRot -= 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_LEFT) {
        cube.glParams.yRot -= 3;
        if (cube.glParams.yRot < 0)
            cube.glParams.yRot += 360;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_HOME) {
        cube.glParams.AXIS += 5;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_END) {
        cube.glParams.AXIS -= 5;
        glutPostRedisplay();
    }

    if (key == GLUT_KEY_F1) {
        cube.clear(cube.glParams.CUBE_SIZE, colour);
        glutPostRedisplay();
    }
    if (key == GLUT_KEY_F2) {
        cube.glParams.xRot = 24;
        cube.glParams.yRot = 44;
        cube.glParams.zRot = 0;
        cube.glParams.AXIS = -35.0;
        glutPostRedisplay();
    }
}


void keys(unsigned char key, int, int) {
    if (cube.glParams.CURRENT == -1 && key == '1') {
        cube.RotateGR();
    }
    else if (cube.glParams.CURRENT == -1 && key == '2') {
        cube.RotateGL();
    }
    else if (cube.glParams.CURRENT == -1 && key == '3') {
        cube.RotateGU();
    }
    else if (cube.glParams.CURRENT == -1 && key == '4') {
        cube.RotateGF();
    }
    else if (cube.glParams.CURRENT == -1 && key == '5') {
        cube.RotateGB();
    }
    else if (cube.glParams.CURRENT == -1 && key == '6') {
        cube.RotateGD();
    }
}

void timer(int) {
    glutTimerFunc(cube.glParams.TIMER, timer, 0);
    if (cube.glParams.CURRENT != -1) {
        cube.Rotate(cube.glParams.CURRENT, cube.glParams.SPEED, -1);
    }
    display();
}

void processMenu(int option) {
    switch (option) {
        case 1:
            cube.generate();
            break;
        case 2:
            cube.solve();
            break;
        case 3:
            cube.save();
            break;
        case 4:
            cube.read_from_file();
            break;
    }
}

void createGLUTMenus() {
    glutCreateMenu(processMenu);

    glutAddMenuEntry("Random Spin Cube", 1);
    glutAddMenuEntry("Solve Cube", 2);
    glutAddMenuEntry("Save cube to file", 3);
    glutAddMenuEntry("Read cube from file", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void run(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(1, 1);
    glutCreateWindow("Application");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keys);
    glutTimerFunc(cube.glParams.TIMER, timer, 0);
    glutSpecialFunc(specialKeys);
    createGLUTMenus();
    glutMainLoop();
}

int main(int argc, char** argv) {
    run(argc, argv);
    return 0;
}


