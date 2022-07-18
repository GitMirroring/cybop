# --- CMake configuration --- #
# set minimum required cmake version
cmake_minimum_required(VERSION 3.13.4)

# set project name
project(cybop C)

set (BINARY_NAME cyboi)

SET(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "root dir" FORCE)

# set output directory to controller-subdirectory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/src/controller)

# define the binary to be create by make
add_executable(${BINARY_NAME} ${ROOT_DIR}/src/controller/cyboi.c)

# --- doxygen definition --- #
include(cmake/doxygen.cmake)

# --- libraries linking --- #
include(cmake/libraries.cmake)

# --- codestyling Configuration --- #
include(cmake/codestyling.cmake)

# --- api generator --- #
include(cmake/api.cmake)

# --- api generator --- #
include(cmake/test.cmake)

# --- CPack Configuration --- #
include(cmake/packaging.cmake)