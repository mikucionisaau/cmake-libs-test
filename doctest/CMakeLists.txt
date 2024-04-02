cmake_minimum_required(VERSION 3.15)
project(DoctestExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/doctest.cmake)

add_library(factorial OBJECT factorial.cpp)

add_executable(factorial_test factorial_test.cpp)
target_link_libraries(factorial_test PRIVATE factorial doctest::doctest_with_main)
add_test(NAME factorial_test COMMAND factorial_test)
