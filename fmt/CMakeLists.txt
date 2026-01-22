cmake_minimum_required(VERSION 3.15)
project(FmtExample)

include(${CMAKE_SOURCE_DIR}/cmake-libs/fmt.cmake)

enable_testing()
add_executable(fmt_example fmt_example.cpp)
target_link_libraries(fmt_example PRIVATE fmt::fmt)
add_test(NAME fmt_example COMMAND fmt_example)
