cmake_minimum_required(VERSION 3.15)
project(MathGLExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/mathgl.cmake)

add_executable(mathgl_main mathgl_main.cpp)
target_link_libraries(mathgl_main PRIVATE mgl-glut)
add_test(NAME mathgl_main COMMAND mathgl_main)
