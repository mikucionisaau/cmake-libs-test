cmake_minimum_required(VERSION 3.15)
project(ArmadilloExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/armadillo.cmake)

add_executable(armadillo_main armadillo_main.cpp)
target_link_libraries(armadillo_main PRIVATE Armadillo::Armadillo)
add_test(NAME armadillo_main COMMAND armadillo_main)
