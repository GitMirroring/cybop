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
# Link representer libraries.
#

target_link_libraries(cyboi-executor-representer-binary
    # cyboi-logger
)

target_link_libraries(cyboi-executor-representer-cyboi
)

target_link_libraries(cyboi-executor-representer-cybol
    cyboi-executor-representer-type
)

target_link_libraries(cyboi-executor-representer-email
)

target_link_libraries(cyboi-executor-representer-gui
    ${XCB_LIBRARIES}
)

target_link_libraries(cyboi-executor-representer-json
)

target_link_libraries(cyboi-executor-representer-text
)

target_link_libraries(cyboi-executor-representer-tui
)

target_link_libraries(cyboi-executor-representer-type
)

if(UNIX)
target_link_libraries(cyboi-executor-representer-type
    # math library
    m
)
endif(UNIX)

target_link_libraries(cyboi-executor-representer-web
)

target_link_libraries(cyboi-executor-representer-wui
)

target_link_libraries(cyboi-executor-representer-xdt
)

target_link_libraries(cyboi-executor-representer-xml
)
