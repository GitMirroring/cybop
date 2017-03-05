# --- CMake configuration --- #
# set minimum required cmake version
cmake_minimum_required(VERSION 3.8.0)

# set project name
project(cyboi)

# set output directory to controller-subdirectory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/controller)

# define the binary to be create by make
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/controller/cyboi.c)

# --- CPACK Configuration --- #

# set the version information
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "19")
SET(CPACK_PACKAGE_VERSION_PATCH "0")

# add the binary to the release
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/Controller/cyboi
              DESTINATION .)
# pack it to the dist directory
SET(CPACK_TOPLEVEL_TAG ../dist)

# activate CPack
include(CPack)