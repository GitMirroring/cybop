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

# Set minimum required cmake version.
cmake_minimum_required(VERSION 3.18.4)

# Set project name.
project(cybop LANGUAGES C VERSION 0.26.0)

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
# Set cyboi library sources.
#
# CAUTION! The instruction "add_library" of file "CMakeLists.txt" expects
# a list of all relevant source files to be added to the library.
# However, it is important to specify only ONE source file since otherwise,
# the following error will occur in almost all cases:
#
# /usr/bin/ld: CMakeFiles/[library].dir/[file].c.o: in function `[function]':
# [file].c:(.text+0xe53a): multiple definition of `[function]'; CMakeFiles/[library].dir/[file].c.o:[file].c:(.text+0xf274): first defined here
#
# The reason is that each source file added via "add_library" is treated
# SEPARATELY when it comes to adding its include files. But since cyboi
# does NOT use header files (*.h) and includes source files (*.c) DIRECTLY
# instead, the above "multiple definition" error occurs.
#
# In order to avoid this, ONE special source file has been created for EACH
# library, whose sole sense is to SUM UP all relevant source files via include.
#
# The reasons for cyboi NOT to use header files are:
# 1 Effort: There are hundreds of implementation files, one per function.
# 2 Dependencies: They are straightforward and clear between implementation files.
# 3 Simplicity: Other languages like java do not use header files either.
#
#set(VARIABLE_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/variable_library.c)
#set(LOGGER_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/logger_library.c)
set(XDT_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/xdt_library.c)
#set(EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor_library.c)
set(APPLICATOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/applicator_library.c)
set(CONTROLLER_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/controller_library.c)

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
configure_file(cmake_configuration.c.in ${ROOT_DIR}/src/variable/cmake_configuration.c)

#
# Add library.
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
#
# Example:
#
# Define only "xdt" and NOT "libxdt" as name since otherwise,
# the resulting name would be "liblibxdt".
#
#add_library(cyboi-variable SHARED ${VARIABLE_CYBOI_LIBRARY_SOURCES})
#add_library(cyboi-logger SHARED ${LOGGER_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-xdt SHARED ${XDT_CYBOI_LIBRARY_SOURCES})
#add_library(cyboi-executor SHARED ${EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-applicator SHARED ${APPLICATOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-controller SHARED ${CONTROLLER_CYBOI_LIBRARY_SOURCES})

# Add executable to be created by make.
add_executable(${BINARY_NAME} ${CYBOI_EXECUTABLE_SOURCES})

# Add make target.
add_custom_target(clean-all
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND ${CMAKE_COMMAND} -P cmake/clean_all.cmake)

# Link internal libraries.
include(cmake/internal_libraries.cmake)

# Link external libraries.
include(cmake/external_libraries.cmake)

# Apply codestyling.
# include(cmake/codestyling.cmake)

# Generate api.
include(cmake/api.cmake)

# Run tests.
# include(cmake/test.cmake)

# Adjust copyright.
# include(cmake/versioning.cmake)

# Pack distributable using cpack.
include(cmake/packaging.cmake)

# Add make targets.
# add_custom_target(dev COMMAND ${CMAKE_MAKE_PROGRAM} clean cyboi test analysis formatting api)
add_custom_target(dev COMMAND ${CMAKE_MAKE_PROGRAM} clean cyboi api)
