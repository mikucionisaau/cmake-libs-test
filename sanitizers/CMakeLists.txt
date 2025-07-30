cmake_minimum_required(VERSION 3.15)
project(SanitizerExamples)

include(${CMAKE_SOURCE_DIR}/cmake-libs/sanitizers.cmake)

add_library(abort_exit OBJECT abort_exit.cpp)

add_executable(stack_smashing stack_smashing.cpp)
target_link_libraries(stack_smashing PRIVATE abort_exit)
add_test(NAME stack_smashing COMMAND stack_smashing)

add_executable(undefined_behavior undefined_behavior.cpp)
add_test(NAME undefined_behavior COMMAND undefined_behavior)
set_tests_properties(undefined_behavior PROPERTIES FAIL_REGULAR_EXPRESSION "runtime error:")

add_executable(memory_leak memory_leak.cpp)
add_test(NAME memory_leak COMMAND memory_leak)
set_tests_properties(memory_leak PROPERTIES FAIL_REGULAR_EXPRESSION "detected memory leaks")

add_executable(heap_overflow heap_overflow.cpp)
add_test(NAME heap_overflow COMMAND heap_overflow)
set_tests_properties(heap_overflow PROPERTIES FAIL_REGULAR_EXPRESSION "runtime error:")

add_executable(double_free double_free.cpp)
target_link_libraries(double_free PRIVATE abort_exit)
add_test(NAME double_free COMMAND double_free)

add_executable(use_after_free use_after_free.cpp)
add_test(NAME use_after_free COMMAND use_after_free)

add_executable(noinit noinit.cpp)
add_test(NAME noinit COMMAND noinit)

add_executable(data_race data_race.cpp)
add_test(NAME data_race COMMAND data_race)

if (SSP OR HARDENED)
    set_tests_properties(stack_smashing PROPERTIES WILL_FAIL ON)
endif ()

if (LSAN)
    set_tests_properties(memory_leak PROPERTIES WILL_FAIL $<CONFIG:Debug,ON,OFF>)
elseif (TSAN)
    set_tests_properties(use_after_free PROPERTIES WILL_FAIL $<CONFIG:Debug,ON,OFF>)
elseif (MSAN)
    set_tests_properties(double_free PROPERTIES WILL_FAIL OFF)
else ()
    set_tests_properties(double_free PROPERTIES WILL_FAIL $<CONFIG:Debug,ON,OFF>)
endif ()

if (UBSAN AND ASAN)
    set_tests_properties(undefined_behavior PROPERTIES WILL_FAIL ON)
    set_tests_properties(double_free PROPERTIES WILL_FAIL ON)
    set_tests_properties(stack_smashing PROPERTIES WILL_FAIL ON)
    if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
        set_tests_properties(memory_leak PROPERTIES WILL_FAIL $<CONFIG:Release,ON,OFF>)
        set_tests_properties(noinit PROPERTIES WILL_FAIL $<CONFIG:Release,ON,OFF>)
    else ()
        set_tests_properties(memory_leak PROPERTIES WILL_FAIL ON)
    endif ()
    set_tests_properties(heap_overflow PROPERTIES WILL_FAIL ON)
    set_tests_properties(use_after_free PROPERTIES WILL_FAIL ON)
elseif (UBSAN)
    set_tests_properties(undefined_behavior PROPERTIES WILL_FAIL ON)
    set_tests_properties(double_free PROPERTIES WILL_FAIL ON)
    set_tests_properties(heap_overflow PROPERTIES WILL_FAIL $<CONFIG:Release,ON,OFF>)
elseif (ASAN)
    set_tests_properties(stack_smashing PROPERTIES WILL_FAIL ON)
    set_tests_properties(memory_leak PROPERTIES WILL_FAIL $<CONFIG:Debug,ON,OFF>)
    set_tests_properties(double_free PROPERTIES WILL_FAIL $<CONFIG:Debug,ON,OFF>)
    set_tests_properties(heap_overflow PROPERTIES WILL_FAIL $<CONFIG:Debug,ON,OFF>)
    set_tests_properties(use_after_free PROPERTIES WILL_FAIL $<CONFIG:Debug,ON,OFF>)
endif ()

if (MSAN)
    set_tests_properties(noinit PROPERTIES WILL_FAIL ON)
    set_tests_properties(stack_smashing PROPERTIES DISABLED TRUE) # random outcomes
elseif (CMAKE_CXX_COMPILER_ID MATCHES Clang)
    set_tests_properties(noinit PROPERTIES WILL_FAIL $<CONFIG:Release,ON,OFF>)
endif (MSAN)

if (TSAN)
    set_tests_properties(data_race PROPERTIES WILL_FAIL ON)
endif (TSAN)
