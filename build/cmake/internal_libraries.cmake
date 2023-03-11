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
# @author Christian Heller <christian.heller@cybop.org>
#

#
# Library linking
#

#target_link_libraries(cyboi-executor
#    cyboi-xdt
#)

target_link_libraries(cyboi-applicator
    cyboi-logger
#    cyboi-executor
    cyboi-xdt
)

target_link_libraries(cyboi-controller
    cyboi-logger
    cyboi-applicator
)

target_link_libraries(${BINARY_NAME}
    cyboi-logger
    cyboi-controller
)

#
# Include file search path definition
#

target_include_directories(cyboi-logger PUBLIC
    "${ROOT_DIR}/include"
)

target_include_directories(cyboi-xdt PUBLIC
    "${ROOT_DIR}/include"
)

#target_include_directories(cyboi-executor PUBLIC
#    "${ROOT_DIR}/include"
#)

target_include_directories(cyboi-applicator PUBLIC
    "${ROOT_DIR}/include"
)

target_include_directories(cyboi-controller PUBLIC
    "${ROOT_DIR}/include"
)

target_include_directories(${BINARY_NAME} PUBLIC
    "${ROOT_DIR}/include"
)
