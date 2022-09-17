cmake_minimum_required(VERSION 3.21)
project(3lab_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(3lab_cpp main.cpp circular_buffer.h iterator.h algorithms.h)
