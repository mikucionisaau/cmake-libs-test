cmake_minimum_required(VERSION 3.15)
project(DoctestExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/doctest.cmake)

add_executable(factorial_doctest factorial_doctest.cpp)
target_link_libraries(factorial_doctest PRIVATE factorial doctest::doctest_with_main)
add_test(NAME factorial_doctest COMMAND factorial_doctest)
