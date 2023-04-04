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
# @author Christian Heller <christian.heller@cybop.org>
#

#
# Add representer library.
#

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

add_library(cyboi-executor-representer-binary SHARED ${BINARY_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-cyboi SHARED ${CYBOI_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-cybol SHARED ${CYBOL_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-email SHARED ${EMAIL_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-gui SHARED ${GUI_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-json SHARED ${JSON_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-text SHARED ${TEXT_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-tui SHARED ${TUI_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-type SHARED ${TYPE_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-web SHARED ${WEB_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-wui SHARED ${WUI_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-xdt SHARED ${XDT_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
add_library(cyboi-executor-representer-xml SHARED ${XML_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES})
