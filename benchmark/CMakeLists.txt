cmake_minimum_required(VERSION 3.15)
project(BenchmarkExample)

include(../cmake-libs/benchmark.cmake)

add_library(fastsort OBJECT fastsort.cpp)

add_executable(fastsort_bm fastsort_bm.cpp)
target_link_libraries(fastsort_bm PRIVATE fastsort benchmark::benchmark_main)
add_test(NAME fastsort_bm COMMAND fastsort_bm)

set_tests_properties(fastsort_bm PROPERTIES RUN_SERIAL ON)
