<<<<<<< lab-6
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

=======
<<<<<<< lab-4
cmake_minimum_required(VERSION 3.21.1)
project(last)

set(CMAKE_CXX_STANDARD 20)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(last main.cpp Models/SmallCubeModel/tiny_cube.h simple_include/include.h Models/SmallCubeModel/tiny_cube.cpp Models/DrawModel/drawer.h Models/DrawModel/drawer.cpp Entities/CubeEntity/cube.h Entities/CubeEntity/cube.cpp Models/CubeChecker/fair_cube_checker.h Models/CubeChecker/fair_cube_check.cpp Tools/gl_params.h)
target_link_libraries(last ${OPENGL_LIBRARIES})
target_link_libraries(last ${GLUT_LIBRARIES})
target_link_libraries(last -lOpenGL32 -g -lfreeGLUT)
=======
cmake_minimum_required(VERSION 3.21)
<<<<<<< lab-5
project(5lab_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(5lab_cpp main.cpp allocator.h)
=======
project(1cpp_lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(1cpp_lab main.cpp polynomial.cpp polynomial.h geometry.cpp geometry.h)
>>>>>>> main
>>>>>>> main
>>>>>>> main
