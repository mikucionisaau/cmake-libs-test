cmake_minimum_required(VERSION 3.15)
project(LibraryTests)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

add_subdirectory(sanitizers)
add_subdirectory(doctest)
add_subdirectory(benchmark)
add_subdirectory(matplotpp)
