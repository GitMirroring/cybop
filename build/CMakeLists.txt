#
# Copyright (C) 1999-2023. Christian Heller.
#
# This file is part of the Cybernetics Oriented Interpreter (CYBOI).
#
# CYBOI is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# CYBOI is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty
# of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with CYBOI. If not, see <http://www.gnu.org/licenses/>.
#
# Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
# CYBOP Developers <cybop-developers@nongnu.org>
#
# @version CYBOP 0.25.0 2023-03-01
# @author Enrico Gallus <enrico.gallus@googlemail.com>
# @author Christian Heller <christian.heller@cybop.org>
#

#
# cyboi executable
#

# set minimum required cmake version
cmake_minimum_required(VERSION 3.18.4)

# set project name
project(cybop LANGUAGES C VERSION 0.26.0)

# set binary executable name
set(BINARY_NAME cyboi)

# get current year
string(TIMESTAMP CURRENT_YEAR %Y)

# set copyright information
string(CONCAT COPYRIGHT_INFO "Copyright (C) 1999-" ${CURRENT_YEAR} ". Christian Heller.")

# set project root directory
set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "root dir" FORCE)

# set cyboi executable cyboi sources
set(CYBOI_EXECUTABLE_CYBOI_SOURCES ${ROOT_DIR}/src/controller/cyboi.c)

# set xdt library cyboi sources by searching recursively
set(XDT_LIBRARY_CYBOI_SOURCES
    ${ROOT_DIR}/src/executor/representer/deserialiser/xdt/xdt_deserialiser.c
)

#
# define filesystem paths for output files
#
# CMAKE_ARCHIVE_OUTPUT_DIRECTORY: .a .lib .imp
# CMAKE_LIBRARY_OUTPUT_DIRECTORY: .so .dll .dylib
# CMAKE_RUNTIME_OUTPUT_DIRECTORY: executable-file .exe .dll
#
# https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
#
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/bin)

#
# add option as boolean flag
#
# This option will be displayed in the cmake-gui and ccmake with a
# default value of ON that can be changed by the user.
#
# This setting will be stored in the cache so that the user does NOT
# need to set the value each time he runs cmake on a build directory.
#
# Reference:
# https://cmake.org/cmake/help/v3.18/guide/tutorial/index.html
#
#option(XDT_LIBRARY_CMAKE_CONFIGURATION "Use cyboi xdt library" ON)

#
# configure file with macros to pass values to cyboi source code
#
# CAUTION! Configure file AFTER having added the option above.
# Do NOT invert the two.
#
configure_file(cmake_configuration.c.in ${ROOT_DIR}/src/variable/cmake_configuration.c)

#
# add library
#
# CAUTION! It would be possible to write a separate "CMakeLists.txt"
# for each single library. The configuration file for a library
# (static or shared) resembles that of an application.
# However, for reasons of better overview and to have everything
# in just one place it was decided to add all libraries here.
#
# CAUTION! It is NOT necessary to list all source files.
# Instead, just mention the file that keeps the entry function.
# All other files are added automatically from there via included dependencies.
#
# CAUTION! Avoid using "file(GLOB ...)" to add all files of a directory.
# This feature does not provide attended mastery of the compilation process.
# Instead, use the copy-paste output of: ls -1 src/*.c
# (The argument is minus one and NOT letter L.)
#
# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
#
# CAUTION! The prefix "lib" is added automatically by cmake.
# Therefore, define only "xdt" and NOT "libxdt" as name here
# since otherwise, the resulting name would be "liblibxdt".
#
#add_library(xdt SHARED test.c)
add_library(xdt SHARED ${XDT_LIBRARY_CYBOI_SOURCES})

# define binary executable to be created by make
add_executable(${BINARY_NAME} ${CYBOI_EXECUTABLE_CYBOI_SOURCES})

# add make target
add_custom_target(clean-all
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND ${CMAKE_COMMAND} -P cmake/clean_all.cmake)

# link internal libraries
include(cmake/internal_libraries.cmake)

# link external libraries
include(cmake/external_libraries.cmake)

# apply codestyling
# include(cmake/codestyling.cmake)

# generate api
include(cmake/api.cmake)

# run tests
# include(cmake/test.cmake)

# adjust copyright
# include(cmake/versioning.cmake)

# pack distributable using cpack
include(cmake/packaging.cmake)

# add make targets
# add_custom_target(dev COMMAND ${CMAKE_MAKE_PROGRAM} clean cyboi test analysis formatting api)
add_custom_target(dev COMMAND ${CMAKE_MAKE_PROGRAM} clean cyboi api)
