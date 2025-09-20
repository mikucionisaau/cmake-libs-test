cmake_minimum_required(VERSION 3.15)
project(Catch2Example)

include(${CMAKE_SOURCE_DIR}/cmake-libs/catch2.cmake)

add_executable(factorial_catch2 factorial_catch2.cpp)
target_compile_features(factorial_catch2 PRIVATE cxx_std_23)
target_link_libraries(factorial_catch2 PRIVATE factorial Catch2::Catch2WithMain)
add_test(NAME factorial_catch2 COMMAND factorial_catch2)
