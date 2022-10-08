cmake_minimum_required(VERSION 3.21.1)
project(last)

set(CMAKE_CXX_STANDARD 20)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(last main.cpp Models/SmallCubeModel/tiny_cube.h simple_include/include.h Models/SmallCubeModel/tiny_cube.cpp Models/DrawModel/drawer.h Models/DrawModel/drawer.cpp Entities/CubeEntity/cube.h Entities/CubeEntity/cube.cpp Models/CubeChecker/fair_cube_checker.h Models/CubeChecker/fair_cube_check.cpp Tools/gl_params.h)
target_link_libraries(last ${OPENGL_LIBRARIES})
target_link_libraries(last ${GLUT_LIBRARIES})
target_link_libraries(last -lOpenGL32 -g -lfreeGLUT)
