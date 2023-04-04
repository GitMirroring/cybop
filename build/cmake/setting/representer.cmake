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
# Set representer sources.
#

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

set(BINARY_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/binary_library.c)
set(CYBOI_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/cyboi_library.c)
set(CYBOL_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/cybol_library.c)
set(EMAIL_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/email_library.c)
set(GUI_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/gui_library.c)
set(JSON_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/json_library.c)
set(TEXT_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/text_library.c)
set(TUI_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/tui_library.c)
set(TYPE_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/type_library.c)
set(WEB_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/web_library.c)
set(WUI_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/wui_library.c)
set(XDT_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/xdt_library.c)
set(XML_REPRESENTER_EXECUTOR_CYBOI_LIBRARY_SOURCES ${ROOT_DIR}/src/library/executor/representer/xml_library.c)
