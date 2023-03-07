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

# set module path for library finds
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake")

#
# opengl library
#

#
# Add support for OpenGL.
#
# Legacy: GL
# New: GLVND (GL vendor-neutral)
#
# Old solution:
# find_package (OpenGL REQUIRED)
#
# New solution:
# find_package(OpenGL REQUIRED COMPONENTS OpenGL)
#
find_package(OpenGL REQUIRED COMPONENTS OpenGL)

if(OPENGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIRS})
    target_link_libraries(${BINARY_NAME} ${OPENGL_LIBRARIES})
endif(OPENGL_FOUND)

#
# pthread library
#

find_package(Threads REQUIRED)
# link posix thread (pthread) library to cyboi target
target_link_libraries(${BINARY_NAME} ${CMAKE_THREAD_LIBS_INIT})

#
# glut library
#

find_package(GLUT)

if(GLUT_FOUND)
    include_directories(${GLUT_INCLUDE_DIRS})
    # overwrite _glut_libraries only with entries that exist
    set(_glut_libraries)
    foreach(_lib ${GLUT_LIBRARIES})
        if(_lib)
            list(APPEND _glut_libraries ${_lib})
        endif()
    endforeach()
    set(GLUT_LIBRARIES ${_glut_libraries})
    target_link_libraries(${BINARY_NAME} ${GLUT_LIBRARIES})
endif(GLUT_FOUND)

#
# x11 library
#

find_package(X11)

if(X11_FOUND)
    include_directories(${X11_INCLUDE_DIR})
    target_link_libraries(${BINARY_NAME} ${X11_LIBRARIES})
endif(X11_FOUND)

#
# xcb library
#

find_package(XCB)

if(XCB_FOUND)
    include_directories(${XCB_INCLUDE_DIRS})
    add_definitions(${XCB_DEFINITIONS})
    target_link_libraries(${BINARY_NAME} ${XCB_LIBRARIES})
endif(XCB_FOUND)

#
# mathematics library
#

if(UNIX)
    # link math library to cyboi target
    target_link_libraries(${BINARY_NAME} m)
endif(UNIX)
