# --- set output configuration --- #
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/test)

FILE(GLOB ALL_CONSTANT_TEST_FILES ${ROOT_DIR}/test/constant/*.c)
FILE(GLOB ALL_EXECUTOR_TEST_FILES ${ROOT_DIR}/test/executor/calculator/*.c)
#FILE(GLOB ALL_EXECUTOR_TEST_FILES ${ROOT_DIR}/test/executor/**/*.c)
FILE(GLOB ALL_VARIABLE_TEST_FILES ${ROOT_DIR}/test/variable/*.c)

# activate coverage flag
SET(CMAKE_C_FLAGS "--coverage")

# --- define tests as executables --- #
add_executable(constant_tests ${ALL_CONSTANT_TEST_FILES})
add_executable(variable_tests ${ALL_VARIABLE_TEST_FILES})
add_executable(executor_tests ${ALL_EXECUTOR_TEST_FILES})

add_test(NAME constant_tests COMMAND constant_tests)
add_test(NAME variable_tests COMMAND variable_tests)
add_test(NAME executor_tests COMMAND executor_tests)