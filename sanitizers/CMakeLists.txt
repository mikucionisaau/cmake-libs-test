cmake_minimum_required(VERSION 3.15)
project(SanitizerExamples)

set(SSP ON CACHE BOOL "Stack Smashing Protector")
set(UBSAN ON CACHE BOOL "Undefined Behavior Sanitizer")
set(LSAN ON CACHE BOOL "Leak Sanitizer")
set(ASAN ON CACHE BOOL "Address Sanitizer")
set(TSAN OFF CACHE BOOL "Thread Sanitizer")

include(${CMAKE_SOURCE_DIR}/cmake-libs/sanitizers.cmake)

add_executable(stack_smashing stack_smashing.cpp)
add_test(NAME stack_smashing COMMAND stack_smashing)

add_executable(undefined_behavior undefined_behavior.cpp)
add_test(NAME undefined_behavior COMMAND undefined_behavior)
set_property(TEST undefined_behavior PROPERTY FAIL_REGULAR_EXPRESSION "runtime error")

add_executable(memory_leak memory_leak.cpp)
add_test(NAME memory_leak COMMAND memory_leak)

add_executable(memory_abuse memory_abuse.cpp)
add_test(NAME memory_abuse COMMAND memory_abuse)

if (SSP)
    set_tests_properties(stack_smashing PROPERTIES WILL_FAIL ON)
endif (SSP)

if (UBSAN)
    set_tests_properties(undefined_behavior PROPERTIES WILL_FAIL ON)
endif (UBSAN)

if (LSAN)
    set_tests_properties(memory_leak PROPERTIES WILL_FAIL ON)
endif (LSAN)

if (ASAN)
    set_tests_properties(stack_smashing PROPERTIES WILL_FAIL ON)
    set_tests_properties(memory_leak PROPERTIES WILL_FAIL ON)
    set_tests_properties(memory_abuse PROPERTIES WILL_FAIL ON)
endif (ASAN)

if (TSAN)
    set_tests_properties(tsan PROPERTIES WILL_FAIL ON)
endif (TSAN)
