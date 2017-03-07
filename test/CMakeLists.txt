# set minimum required cmake version
cmake_minimum_required(VERSION 3.0.2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CTEST_OUTPUT_ON_FAILURE	ON)

add_executable(constant_test test/constant/constant_tester.c)
add_executable(variable_test test/variable/variable_tester.c)

add_test(constant_test test/constant_test)
add_test(variable_test test/variable_test)
