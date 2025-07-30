cmake_minimum_required(VERSION 3.15)
project(LibraryTests)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(LIBS_WITH_BENCHMARKS "libs with benchmarks" OFF)

enable_testing()

add_subdirectory(sanitizers)
add_subdirectory(doctest)
if (LIBS_WITH_BENCHMARKS)
    add_subdirectory(benchmark)
endif (LIBS_WITH_BENCHMARKS)
add_subdirectory(matplotpp)
