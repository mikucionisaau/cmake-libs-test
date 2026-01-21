cmake_minimum_required(VERSION 3.15)
project(ApprovalsExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/doctest.cmake)
include(${CMAKE_SOURCE_DIR}/cmake-libs/catch2.cmake)
include(${CMAKE_SOURCE_DIR}/cmake-libs/approvals.cmake)

enable_testing()

add_executable(gcd_doctest gcd_doctest.cpp)
target_compile_features(gcd_doctest PRIVATE cxx_std_23)
target_link_libraries(gcd_doctest PRIVATE doctest::doctest_with_main ApprovalTests::ApprovalTests)
add_test(NAME gcd_doctest COMMAND gcd_doctest)

add_executable(gcd_catch2 gcd_catch2.cpp)
target_compile_features(gcd_catch2 PRIVATE cxx_std_23)
target_link_libraries(gcd_catch2 PRIVATE Catch2::Catch2WithMain ApprovalTests::ApprovalTests)
add_test(NAME gcd_catch2 COMMAND gcd_catch2)
