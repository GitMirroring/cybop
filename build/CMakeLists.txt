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
# CMake core configuration file
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

# configure file to pass version number to cyboi source code
configure_file(cmake_configuration.c.in ${ROOT_DIR}/src/variable/cmake_configuration.c)

# set project root directory
set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "root dir" FORCE)

# set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_DIR}/src/controller)

# define binary executable to be created by make
add_executable(${BINARY_NAME} ${ROOT_DIR}/src/controller/cyboi.c)

add_custom_target(clean-all
        COMMAND ${CMAKE_MAKE_PROGRAM} clean
        COMMAND ${CMAKE_COMMAND} -P cmake/clean_all.cmake)

# link libraries
include(cmake/libraries.cmake)

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

