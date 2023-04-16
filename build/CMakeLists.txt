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
# @version CYBOP 0.26.0 2023-04-04
# @author Enrico Gallus <enrico.gallus@googlemail.com>
# @author Christian Heller <christian.heller@cybop.org>
#

#
# cyboi executable
#

# Set minimum required cmake version.
cmake_minimum_required(VERSION 3.18.4)

# Set project name.
project(cybop LANGUAGES C VERSION 0.27.0)

# Set binary executable name.
set(BINARY_NAME cyboi)

# Get current year.
string(TIMESTAMP CURRENT_YEAR %Y)

# Set copyright information.
string(CONCAT COPYRIGHT_INFO "Copyright (C) 1999-" ${CURRENT_YEAR} ". Christian Heller.")

# Set project root directory.
set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "root dir" FORCE)

# Set cyboi executable sources.
set(CYBOI_EXECUTABLE_SOURCES ${ROOT_DIR}/src/cyboi/cyboi.c)

#
# Set module path for finding external libraries.
#
# CAUTION! This path has to be set BEFORE calling any "find" command.
#
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Find library packages.
include(cmake/finding/finding.cmake)

# Set library sources.
include(cmake/setting/setting.cmake)

#
# Define filesystem paths for output files.
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

# Configure file with macros to pass values to cyboi source code.
configure_file(cmake_configuration.h.in ${ROOT_DIR}/include/variable/cmake_configuration.h)

# Add libraries.
include(cmake/adding/adding.cmake)

# Add executable to be created by make.
add_executable(${BINARY_NAME} ${CYBOI_EXECUTABLE_SOURCES})

# Link libraries.
include(cmake/linking/linking.cmake)

# Include directories.
include(cmake/inclusion/inclusion.cmake)

# Define library specifics.
include(cmake/definition/definition.cmake)

# Generate api.
include(cmake/api.cmake)

# Adjust copyright.
# include(cmake/versioning.cmake)

# Pack distributable using cpack.
include(cmake/packaging.cmake)

# Add make target.
add_custom_target(clean-all
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND ${CMAKE_COMMAND} -P cmake/clean_all.cmake)

# Add make targets.
add_custom_target(dev COMMAND ${CMAKE_MAKE_PROGRAM} clean cyboi api)
