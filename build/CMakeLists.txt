# --- CMake configuration --- #
# set minimum required cmake version
cmake_minimum_required(VERSION 3.0.2)

# set project name
project(cybop C)

set (BINARY_NAME cyboi)

SET(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "root dir" FORCE)

# set output directory to controller-subdirectory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/src/controller)

# define the binary to be create by make
add_executable(${BINARY_NAME} ${ROOT_DIR}/src/controller/cyboi.c)

# --- libraries linking --- #
include(cmake/libraries.cmake)

# --- codestyling Configuration --- #
include(cmake/codestyling.cmake)

# --- CTest Configuration --- #
include(../test/CMakeLists.txt)

# --- codecovarage command --- #
include(cmake/codecoverage.cmake)

# --- CPack Configuration --- #
include(cmake/packaging.cmake)