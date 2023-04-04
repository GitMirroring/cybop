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
# Include representer directories.
#

#
# CAUTION! The list does NOT contain interface include files provided by
# the library but those which are REQUIRED by the library source files.
#

target_include_directories(cyboi-executor-representer-binary PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-cyboi PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-cybol PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-email PUBLIC
    "${ROOT_DIR}/include"
)

target_include_directories(cyboi-executor-representer-gui PUBLIC
    "${XCB_INCLUDE_DIRS}"
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-json PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-text PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-tui PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-type PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-web PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-wui PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-xdt PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)

target_include_directories(cyboi-executor-representer-xml PUBLIC
    "${ROOT_DIR}/include"
    "${ROOT_DIR}/include/executor"
    "${ROOT_DIR}/include/executor/representer"
)
