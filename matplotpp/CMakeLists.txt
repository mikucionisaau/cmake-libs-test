cmake_minimum_required(VERSION 3.15)
project(MatplotppExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/matplotpp.cmake)

add_executable(matplotpp_main matplotpp_main.cpp)
target_link_libraries(matplotpp_main PRIVATE matplot)
#add_test(NAME matplotpp_main COMMAND matplotpp_main)
