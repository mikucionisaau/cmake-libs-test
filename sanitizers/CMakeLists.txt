cmake_minimum_required(VERSION 3.15)
project(SanitizerExamples)

set(LSAN ON)
set(ASAN ON)
set(UBSAN ON)

include(../cmake-libs/sanitizers.cmake)

add_executable(ubsan ubsan.cpp)
add_test(NAME ubsan COMMAND ubsan)

add_executable(lsan lsan.cpp)
add_test(NAME lsan COMMAND lsan)

add_executable(asan asan.cpp)
add_test(NAME asan COMMAND asan)