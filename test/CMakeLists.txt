# --- set output configuration --- #

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CTEST_OUTPUT_ON_FAILURE	ON)

# --- define tests as executables --- #
# TODO: would be great to add an executable for all the c files we found in the test
# so we don't need to adjust this config if we add new test files
add_executable(character_manipulator_test test/executor/manipulator/character_manipulator_tester.c)
add_executable(constant_test test/constant/constant_tester.c)
add_executable(double_caster_test test/executor/caster/double_caster_tester.c)
add_executable(integer_calculator_test test/executor/calculator/integer_calculator_tester.c)
add_executable(sleeper_test test/executor/runner/sleeper_tester.c)
add_executable(variable_test test/variable/variable_tester.c)

add_test(character_manipulator_test test/character_manipulator_test)
add_test(constant_test test/constant_test)
add_test(double_caster_test test/double_caster_test)
add_test(integer_calculator_test test/integer_calculator_test)
add_test(sleeper_test test/sleeper_test)
add_test(variable_test test/variable_test)

# --- load global CTest configuration --- #
include(CTest)
