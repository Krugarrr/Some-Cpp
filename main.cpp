#include <iostream>
#include "polynomial.h"
#include "geometry.h"


int main(){

    std::cout << "\nPOLYNOMIAL_____________________________________" << std::endl;
    Polynomial first_poly({1, 2, 0});
    Polynomial e({1});
    Polynomial second_poly(first_poly); //copy
    Polynomial third_poly({9, 8, 3});
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


    return 0;
}
