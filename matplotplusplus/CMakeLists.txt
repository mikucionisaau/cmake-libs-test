cmake_minimum_required(VERSION 3.15)
project(MatplotppExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/matplotplusplus.cmake)

add_executable(matplotplusplus_main matplotplusplus_main.cpp)
target_link_libraries(matplotplusplus_main PRIVATE matplot)
#add_test(NAME matplotplusplus_main COMMAND matplotplusplus_main)
