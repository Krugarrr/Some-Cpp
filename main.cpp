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
