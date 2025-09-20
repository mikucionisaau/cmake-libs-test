cmake_minimum_required(VERSION 3.15)
project(BenchmarkExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/benchmark.cmake)

add_library(fastsort OBJECT fastsort.cpp)
target_compile_features(fastsort PRIVATE cxx_std_20)

add_executable(fastsort_bm fastsort_bm.cpp)
target_link_libraries(fastsort_bm PRIVATE fastsort benchmark::benchmark_main)
add_test(NAME fastsort_cmp COMMAND ${benchmark_cmp} filters $<TARGET_FILE:fastsort_bm> sort_ranges_bm sort_libc_bm)

set_tests_properties(fastsort_cmp PROPERTIES RUN_SERIAL ON)
