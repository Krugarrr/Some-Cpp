#include <iostream>
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

    return 0;
}
