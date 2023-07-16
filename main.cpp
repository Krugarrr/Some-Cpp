<<<<<<< lab-6
#include <iostream>
#include "tests.h"


int main(int argc, char* argv[]) {

    Polynomial<3, 2, 1> p;
    std::cout << p << std::endl;

    std::cout << Polynomial<10000, 4, 3, 2, 1>::Count<5>::result << std::endl;
    std::chrono::steady_clock::steady_clock::time_point t2 = std::chrono::steady_clock::steady_clock::now();
    std::chrono::duration<double> vector_time_span = duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "It took me " << vector_time_span.count() << " seconds " << std::endl;
    static_assert(gpoly::Count<5>::result == 6250586, "False");
    ::testing::InitGoogleTest(& argc, argv);
    return RUN_ALL_TESTS();
}
=======
<<<<<<< lab-4
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


=======
#include <iostream>
<<<<<<< lab-5
#include "allocator.h"
#include <chrono>
#include <list>
#include <set>
#include <string>

using namespace std::chrono;
const size_t iterations = 1000;
const unsigned size = 20;


int main() {

    //_____________________________________//
    //comparing allocation time for vectors//
    //_____________________________________//
    std::vector<long long> standart_vector;
    std::vector<long long, Custom_allocator<long long, size>> custom_vector;

    //standart
    steady_clock::time_point t1 = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        standart_vector.push_back(i);
    }
    for (int i = 0; i < iterations; ++i) {
        standart_vector.pop_back();
    }

    steady_clock::time_point t2 = steady_clock::now();
    duration<double> vector_time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << vector_time_span.count() << " seconds for STD Allocator for vector" << std::endl;

    //custom
    t1 = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        custom_vector.push_back(i);
    }
    for (int i = 0; i < iterations; ++i) {
        custom_vector.pop_back();
    }

    t2 = steady_clock::now();
    vector_time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << vector_time_span.count() << " seconds for Custom Allocator for vector" << std::endl;
    std::cout << std::endl;


    //_____________________________________//
    //comparing allocation time for lists  //
    //_____________________________________//

    std::list<int> standart_list;
    std::list<int, Custom_allocator<int, size>> custom_list;

    //standart
    t1 = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        standart_list.push_back(i);
    }
    for (int i = 0; i < iterations; ++i) {
        standart_list.pop_back();
    }
    t2 = steady_clock::now();
    duration<double>list_time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << list_time_span.count() << " seconds for STD Allocator for list" << std::endl;

    //custom
    t1 = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        custom_list.push_back(i);
    }
    for (int i = 0; i < iterations; ++i) {
        custom_list.pop_back();
    }
    t2 = steady_clock::now();
    list_time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << list_time_span.count() << " seconds for Custom Allocator for list" << std::endl;
    std::cout << std::endl;


    //_____________________________________//
    // comparing allocation time for sets  //
    //_____________________________________//

    std::set<double> standart_set;
    std::set<double, std::less<double>, Custom_allocator<double, size>> custom_set;

    //standart
    t1 = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        standart_set.insert(i);
    }
    for (int i = 0; i < iterations; ++i) {
        standart_set.erase(i);
    }
    t2 = steady_clock::now();
    duration<double>set_time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << set_time_span.count() << " seconds for STD Allocator for set" << std::endl;

    //custom
    t1 = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        custom_set.insert(i);
    }
    for (int i = 0; i < iterations; ++i) {
        custom_set.erase(i);
    }
    t2 = steady_clock::now();
    set_time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << set_time_span.count() << " seconds for Custom Allocator for set" << std::endl;
    std::cout << std::endl;

    //_____________________________________________//
    //comparing allocation time for string vectors//
    //___________________________________________//
    std::vector<std::string> s_standart_vector;
    std::vector<std::string, Custom_allocator<std::string, size>> s_custom_vector;

    //standart
    t1 = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        standart_vector.push_back('aboba');
    }
    for (int i = 0; i < iterations; ++i) {
        standart_vector.pop_back();
    }

    t2 = steady_clock::now();
    duration<double> s_vector_time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << s_vector_time_span.count() << " seconds for STD Allocator for string vector" << std::endl;

    //custom
    t1 = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        custom_vector.push_back('aboba');
    }
    for (int i = 0; i < iterations; ++i) {
        custom_vector.pop_back();
    }

    t2 = steady_clock::now();
    s_vector_time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << s_vector_time_span.count() << " seconds for Custom Allocator for string vector" << std::endl;
    std::cout << std::endl;

=======
#include "polynomial.h"
#include "geometry.h"


int main(){

    std::cout << "\nPOLYNOMIAL_____________________________________" << std::endl;
    Polynomial first_poly({1, 2, 0});
    Polynomial e({1});
    Polynomial second_poly(first_poly); //copy
    Polynomial third_poly({10, 9, 8, 3});
    Polynomial fourth_poly;
    fourth_poly = third_poly; //assign

    std::cout << "First: " << first_poly << std::endl;
    std::cout << "Second: " << second_poly << std::endl;
    std::cout << "Third: " << third_poly << std::endl;
    std::cout << "Fourth: " << fourth_poly << std::endl;


    std::cout << "\nEquation______________________________ " << std::endl;
    if (third_poly == fourth_poly){
        std::cout << "Third == fourth" << std::endl;
    }
    if (fourth_poly != second_poly){
        std::cout << "Fourth != second" << std::endl;
    }

    std::cout << "\nAddiction______________________________ " << std::endl;
    third_poly += fourth_poly;
    std::cout << "Third: " << third_poly << std::endl;
    fourth_poly = third_poly + fourth_poly;
    std::cout << "Fourth: " << fourth_poly << std::endl;

    std::cout << "\nSubtraction______________________________ " << std::endl;
    third_poly -= fourth_poly;
    std::cout << "Third: " << third_poly << std::endl;
    fourth_poly = fourth_poly - third_poly;
    std::cout << "Fourth: " << fourth_poly << std::endl;

    std::cout << "\nMultiplication______________________________ " << std::endl;
    first_poly *= second_poly;
    std::cout << "First: " << first_poly << std::endl;
    second_poly = second_poly * second_poly;
    std::cout << "Second: " << second_poly << std::endl;
    fourth_poly *= 2;
    std::cout << "Fourth: " << fourth_poly << std::endl;
    fourth_poly = fourth_poly * 2;
    std::cout << "Fourth: " << fourth_poly << std::endl;
    fourth_poly = fourth_poly * second_poly;
    std::cout << "Fourth: " << fourth_poly << std::endl;

    std::cout << "\nDivision______________________________ " << std::endl;
    fourth_poly = fourth_poly / 2;
    std::cout << "Fourth: " << fourth_poly << std::endl;
    fourth_poly /= 2;
    std::cout << "Fourth: " << fourth_poly << std::endl;

    std::cout << "\nIstream___________________________________ " << std::endl;
    //Polynomial fifth_poly(4);
    //std::cin >> fifth_poly;
    //std::cout << "Fifth: " << fifth_poly << std::endl;

    //----------------------------------------------------------------------------------
    std::cout << "\nGEOMETRY_____________________________________" << std::endl;
    Point dot(0, 0), sdot(2, 0), tdot(2, 2), fdot(0, 2), fidot(3, 0);
    std::cout << "First point: "<< dot << std::endl;
    std::cout << "_____________________________________ " << std::endl;

    Polyline poly({dot, sdot});
    std::cout << "Polyline's first point: " << poly[0] << std::endl;
    std::cout << "Polyline: " << poly << std::endl;
    std::cout << "_____________________________________ " << std::endl;

    Closed_polyline cpoly({dot, tdot, fdot});
    std::cout << "Closed_polyline: " << cpoly << std::endl;
    std::cout << "Closed_polyline's perimeter: " << cpoly.perimeter() << std::endl;
    Closed_polyline tripoly;
    tripoly = cpoly;
    std::cout << "Assigned closed polyline: " << tripoly << std::endl;
    std::cout << "_____________________________________ " << std::endl;

    Polygon fp({dot, tdot, fdot});
    Polygon sp(fp);
    std::cout << "Copied polygon:  \n" << sp << std::endl;
    std::cout << "_____________________________________ " << std::endl;

    Triangle triangle({dot, sdot, fdot});
    std::cout << "Triangle: \n" << triangle << std::endl;
    std::cout << "Triangle's perimeter: " << triangle.perimeter() << std::endl;
    std::cout << "Triangle's area: " << triangle.area() << std::endl;
    std::cout << "_____________________________________ " << std::endl;

    Trapezoid trapez{dot, fidot, tdot, fdot};
    std::cout << "Trapezoid: \n" << trapez << std::endl;
    std::cout << "Trapezoid's perimeter: " << trapez.perimeter() << std::endl;
    std::cout << "Trapezoid's area: " << trapez.area() << std::endl;
    std::cout << "_____________________________________ " << std::endl;


    Regular_polygon reg_poly{dot, sdot, tdot, fdot};
    std::cout << "Regular polygon: \n" << reg_poly << std::endl;
    std::cout << "Regular polygon's perimeter: " << reg_poly.perimeter() << std::endl;
    std::cout << "Regular polygon's area: " << reg_poly.area() << std::endl;
    std::cout << "_____________________________________ " << std::endl;
>>>>>>> main
    return 0;
}
>>>>>>> main
>>>>>>> main
