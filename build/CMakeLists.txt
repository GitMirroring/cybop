# --- CMake configuration --- #
# set minimum required cmake version
cmake_minimum_required(VERSION 3.18.4)

# set project name
project(cybop LANGUAGES C VERSION 0.23.0)

set(BINARY_NAME cyboi)

SET(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "root dir" FORCE)

# set output directory to controller-subdirectory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/src/controller)

configure_file(cmake_config.h.in ${ROOT_DIR}/src/variable/cmake_config.h)

# define the binary to be create by make
add_executable(${BINARY_NAME} ${ROOT_DIR}/src/controller/cyboi.c)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${ROOT_DIR}/build/run")

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