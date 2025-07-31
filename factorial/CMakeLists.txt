# Simple library for testing unit testing frameworks
add_library(factorial OBJECT factorial.cpp)
target_include_directories(factorial PUBLIC ${CMAKE_SOURCE_DIR}/factorial)
