cmake_minimum_required(VERSION 3.21)
project(6cpp_lab)

set(frameworks ${6cpp_lab_lib})

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/googletest-main)
include_directories(lib/googletest-main/googletest/include)
include_directories(lib/googletest-main/googlemock/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(SOURCE_FILES main.cpp polynomial.h tests.h)


add_executable(6cpp_lab ${SOURCE_FILES})
target_link_libraries(6cpp_lab gtest gtest_main)

