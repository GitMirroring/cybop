# --- set output configuration --- #
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CTEST_OUTPUT_ON_FAILURE	ON)

# activate coverage flag
SET(CMAKE_C_FLAGS "--coverage")

# --- define tests as executables --- #
# TODO: would be great to add an executable for all the c files we found in the test
# so we don't need to adjust this config if we add new test files
add_executable(character_manipulator_test ../test/executor/manipulator/character_manipulator_tester.c)
add_executable(constant_test ../test/constant/constant_tester.c)
add_executable(compare_all_array_test ../test/executor/comparator/compare_all_array_tester.c)
add_executable(compare_double_test ../test/executor/comparator/compare_double_tester.c)
add_executable(compare_pointer_test ../test/executor/comparator/compare_pointer_tester.c)
add_executable(compare_subsequence_array_test ../test/executor/comparator/compare_subsequence_array_tester.c)
add_executable(double_caster_test ../test/executor/caster/double_caster_tester.c)
add_executable(integer_calculator_test ../test/executor/calculator/integer_calculator_tester.c)
add_executable(sleeper_test ../test/executor/runner/sleeper_tester.c)
add_executable(variable_test ../test/variable/variable_tester.c)

add_test(character_manipulator_test ../test/character_manipulator_test)
add_test(constant_test ../test/constant_test)
add_test(compare_all_array_test ../test/compare_all_array_test)
add_test(compare_double_test ../test/compare_double_test)
add_test(compare_pointer_test ../test/compare_pointer_test)
add_test(compare_subsequence_array_test ../test/compare_subsequence_array_test)
add_test(double_caster_test ../test/double_caster_test)
add_test(integer_calculator_test ../test/integer_calculator_test)
add_test(sleeper_test ../test/sleeper_test)
add_test(variable_test ../test/variable_test)

# --- load global CTest configuration --- #
include(CTest)
