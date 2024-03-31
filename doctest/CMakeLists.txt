cmake_minimum_required(VERSION 3.15)
project(SanitizerTest)

set(LSAN ON)
set(ASAN ON)
set(UBSAN ON)

include(../cmake-libs/doctest.cmake)

add_library(example OBJECT example.cpp)

add_executable(example_test example_test.cpp)
target_link_libraries(example_test PRIVATE example doctest::doctest_with_main)
add_test(NAME example_test COMMAND example_test)
