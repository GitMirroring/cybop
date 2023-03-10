/*
 * Copyright (C) 1999-2023. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI. If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef APPLICATOR_LIBRARY_SOURCE
#define APPLICATOR_LIBRARY_SOURCE

//
// Sum up all relevant source files via include.
//
// CAUTION! The instruction "add_library" of file "CMakeLists.txt" expects
// a list of all relevant source files to be added to the library.
// However, it is important to specify only ONE source file since otherwise,
// the following error will occur in almost all cases:
//
// /usr/bin/ld: CMakeFiles/[library].dir/[file].c.o: in function `[function]':
// [file].c:(.text+0xe53a): multiple definition of `[function]'; CMakeFiles/[library].dir/[file].c.o:[file].c:(.text+0xf274): first defined here
//
// The reason is that each source file added via "add_library" is treated
// SEPARATELY when it comes to adding its include files. But since cyboi
// does NOT use header files (*.h) and includes source files (*.c) DIRECTLY
// instead, the above "multiple definition" error occurs.
//
// In order to avoid this, ONE special source file has been created for EACH
// library, whose sole sense is to SUM UP all relevant source files via include.
//
// The reasons for cyboi NOT to use header files are:
// 1 Effort: There are hundreds of implementation files, one per function.
// 2 Dependencies: They are straightforward and clear between implementation files.
// 3 Simplicity: Other languages like java do not use header files either.
//

#include "../applicator/access/count.c"
#include "../applicator/access/get.c"
#include "../applicator/access/get_index.c"
#include "../applicator/access/indicate.c"
#include "../applicator/activate/disable.c"
#include "../applicator/activate/enable.c"
#include "../applicator/calculate/calculate.c"
#include "../applicator/cast/cast.c"
#include "../applicator/command/archive_file.c"
#include "../applicator/command/change_directory.c"
#include "../applicator/command/change_permission.c"
#include "../applicator/command/clear_screen.c"
#include "../applicator/command/compare_files.c"
#include "../applicator/command/config_network.c"
#include "../applicator/command/copy_file.c"
#include "../applicator/command/create_directory.c"
#include "../applicator/command/date.c"
#include "../applicator/command/delay.c"
#include "../applicator/command/diff.c"
#include "../applicator/command/disk_free.c"
#include "../applicator/command/disk_usage.c"
#include "../applicator/command/display_content.c"
#include "../applicator/command/echo_message.c"
#include "../applicator/command/find_command.c"
#include "../applicator/command/find_file.c"
#include "../applicator/command/grep.c"
#include "../applicator/command/help.c"
#include "../applicator/command/hostname.c"
#include "../applicator/command/id.c"
#include "../applicator/command/ifconfig.c"
#include "../applicator/command/ifup.c"
#include "../applicator/command/kill.c"
#include "../applicator/command/list_directory_contents.c"
#include "../applicator/command/list_open_files.c"
#include "../applicator/command/list_tasks.c"
#include "../applicator/command/memory_free.c"
#include "../applicator/command/move_file.c"
#include "../applicator/command/netstat.c"
#include "../applicator/command/ping.c"
#include "../applicator/command/present_working_directory.c"
#include "../applicator/command/remove_file.c"
#include "../applicator/command/sort.c"
#include "../applicator/command/spellcheck.c"
#include "../applicator/command/system_messages.c"
#include "../applicator/command/tape_archiver.c"
#include "../applicator/command/top.c"
#include "../applicator/command/touch.c"
#include "../applicator/command/traceroute.c"
#include "../applicator/command/userlog.c"
#include "../applicator/command/who.c"
#include "../applicator/command/who_am_i.c"
#include "../applicator/command/word_count.c"
#include "../applicator/communicate/identify.c"
#include "../applicator/communicate/receive.c"
#include "../applicator/communicate/send.c"
#include "../applicator/compare/compare.c"
#include "../applicator/contain/contain.c"
#include "../applicator/convert/decode.c"
#include "../applicator/convert/encode.c"
#include "../applicator/dispatch/close.c"
#include "../applicator/dispatch/open.c"
#include "../applicator/feel/sense.c"
#include "../applicator/feel/suspend.c"
#include "../applicator/flow/branch.c"
#include "../applicator/flow/loop.c"
#include "../applicator/flow/sequence.c"
#include "../applicator/logify/logify.c"
#include "../applicator/maintain/shutdown.c"
#include "../applicator/maintain/startup.c"
#include "../applicator/manipulate/manipulate.c"
#include "../applicator/memorise/create.c"
#include "../applicator/memorise/destroy.c"
#include "../applicator/modify/modify.c"
#include "../applicator/randomise/retrieve.c"
#include "../applicator/randomise/sow.c"
#include "../applicator/represent/deserialise.c"
#include "../applicator/represent/serialise.c"
#include "../applicator/run/run.c"
#include "../applicator/run/sleep.c"
#include "../applicator/sort/sort.c"
#include "../applicator/stream/read.c"
#include "../applicator/stream/write.c"
#include "../applicator/time/time.c"

/* APPLICATOR_LIBRARY_SOURCE */
#endif
