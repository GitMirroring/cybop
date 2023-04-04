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
# Link executor libraries.
#

target_link_libraries(cyboi-executor-algorithm
)

target_link_libraries(cyboi-executor-arithmetic
)

if(UNIX)
target_link_libraries(cyboi-executor-arithmetic
    # math library
    m
)
endif(UNIX)

target_link_libraries(cyboi-executor-client
    ${XCB_LIBRARIES}
    cyboi-executor-representer-gui
    cyboi-executor-representer-tui
    cyboi-executor-representer-web
)

target_link_libraries(cyboi-executor-communication
    ${XCB_LIBRARIES}
    cyboi-executor-representer-binary
    cyboi-executor-representer-cybol
    cyboi-executor-representer-gui
    cyboi-executor-representer-json
    cyboi-executor-representer-text
    cyboi-executor-representer-tui
    cyboi-executor-representer-web
    cyboi-executor-representer-wui
    cyboi-executor-representer-xdt
    cyboi-executor-representer-xml
)

target_link_libraries(cyboi-executor-knowledge
    ${CMAKE_THREAD_LIBS_INIT}
    cyboi-executor-representer-text
    cyboi-executor-representer-web
)

target_link_libraries(cyboi-executor-server
    ${XCB_LIBRARIES}
    cyboi-executor-representer-gui
)

target_link_libraries(cyboi-executor-shell
)

target_link_libraries(cyboi-executor-system
    ${CMAKE_THREAD_LIBS_INIT}
)

#
# TODO:
#
#if(GLUT_FOUND)
#    include_directories(${GLUT_INCLUDE_DIRS})
    # overwrite _glut_libraries only with entries that exist
#    set(_glut_libraries)
#    foreach(_lib ${GLUT_LIBRARIES})
#        if(_lib)
#            list(APPEND _glut_libraries ${_lib})
#        endif()
#    endforeach()
#    set(GLUT_LIBRARIES ${_glut_libraries})
#    target_link_libraries(${BINARY_NAME} ${GLUT_LIBRARIES})
#endif(GLUT_FOUND)

#if(OPENGL_FOUND)
#    include_directories(${OpenGL_INCLUDE_DIRS})
#    target_link_libraries(${BINARY_NAME} ${OPENGL_LIBRARIES})
#endif(OPENGL_FOUND)
