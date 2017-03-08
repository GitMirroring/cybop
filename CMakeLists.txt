# --- CMake configuration --- #
# set minimum required cmake version
cmake_minimum_required(VERSION 3.0.2)

# set project name
project(cyboi C)

# set output directory to controller-subdirectory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/controller)

# define the binary to be create by make
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/controller/cyboi.c)

# --- libraries linking --- #
include(build/libraries.cmake)

# --- codestyling Configuration --- #
include(build/codestyling.cmake)

# --- CTest Configuration --- #
include(test/CMakeLists.txt)
include(CTest)

# --- CPack Configuration --- #
include(build/cpack.cmake)
include(CPack)