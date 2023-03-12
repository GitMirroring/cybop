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

#ifndef EXECUTOR_LIBRARY_SOURCE
#define EXECUTOR_LIBRARY_SOURCE

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

//
// accessor
//

#include "../executor/accessor/counter/part_counter.c"
#include "../executor/accessor/getter/getter.c"
#include "../executor/accessor/getter/part/name_part_getter.c"
#include "../executor/accessor/indicator/part_indicator.c"
#include "../executor/accessor/name_getter/array_name_getter.c"

//
// activator
//

#include "../executor/activator/disabler/disabler.c"
#include "../executor/activator/enabler/enabler.c"

//
// calculator
//

#include "../executor/calculator/integer/minimum_integer_calculator.c"
#include "../executor/calculator/part_calculator.c"

//
// caster
//

#include "../executor/caster/part_caster.c"

//
// commander
//

#include "../executor/commander/change_directory_commander.c"
#include "../executor/commander/change_permission_commander.c"
#include "../executor/commander/clear_screen_commander.c"
#include "../executor/commander/compare_files_commander.c"
#include "../executor/commander/config_network_commander.c"
#include "../executor/commander/copy_file_commander.c"
#include "../executor/commander/create_directory_commander.c"
#include "../executor/commander/date_commander.c"
#include "../executor/commander/delay_commander.c"
#include "../executor/commander/diff_commander.c"
#include "../executor/commander/disk_free_commander.c"
#include "../executor/commander/disk_usage_commander.c"
#include "../executor/commander/display_content_commander.c"
#include "../executor/commander/echo_message_commander.c"
#include "../executor/commander/find_command_commander.c"
#include "../executor/commander/find_file_commander.c"
#include "../executor/commander/grep_commander.c"
#include "../executor/commander/help_commander.c"
#include "../executor/commander/hostname_commander.c"
#include "../executor/commander/id_commander.c"
#include "../executor/commander/ifconfig_commander.c"
#include "../executor/commander/ifup_commander.c"
#include "../executor/commander/kill_commander.c"
#include "../executor/commander/list_directory_contents_commander.c"
#include "../executor/commander/list_open_files_commander.c"
#include "../executor/commander/list_tasks_commander.c"
#include "../executor/commander/memory_free_commander.c"
#include "../executor/commander/move_file_commander.c"
#include "../executor/commander/netstat_commander.c"
#include "../executor/commander/ping_commander.c"
#include "../executor/commander/present_working_directory_commander.c"
#include "../executor/commander/remove_file_commander.c"
#include "../executor/commander/sort_commander.c"
#include "../executor/commander/spellcheck_commander.c"
#include "../executor/commander/system_messages_commander.c"
#include "../executor/commander/tape_archiver_commander.c"
#include "../executor/commander/top_commander.c"
#include "../executor/commander/touch_commander.c"
#include "../executor/commander/traceroute_commander.c"
#include "../executor/commander/userlog_commander.c"
#include "../executor/commander/who_am_i_commander.c"
#include "../executor/commander/who_commander.c"
#include "../executor/commander/word_count_commander.c"

//
// communicator
//

#include "../executor/communicator/receiver/receiver.c"
#include "../executor/communicator/sender/sender.c"

//
// comparator
//

#include "../executor/comparator/integer/equal_integer_comparator.c"
#include "../executor/comparator/part_comparator.c"

//
// container
//

//?? #include "../executor/container/container.c"

//
// converter
//

#include "../executor/converter/decoder/decoder.c"
#include "../executor/converter/encoder/encoder.c"

//
// copier
//

#include "../executor/copier/array/forward_array_copier.c"
#include "../executor/copier/integer_copier.c"
#include "../executor/copier/pointer_copier.c"

//
// dispatcher
//

#include "../executor/dispatcher/closer/closer.c"
#include "../executor/dispatcher/opener/opener.c"

//
// feeler
//

#include "../executor/feeler/sensor/sensor.c"
#include "../executor/feeler/suspender/suspender.c"

//
// finder
//

#include "../executor/finder/array_finder.c"

//
// logifier
//

#include "../executor/logifier/logifier.c"

//
// maintainer
//

#include "../executor/maintainer/shutter/shutter.c"
#include "../executor/maintainer/starter/starter.c"

//
// manipulator
//

#include "../executor/manipulator/part_manipulator.c"

//
// memoriser
//

#include "../executor/memoriser/allocator/item_allocator.c"
#include "../executor/memoriser/allocator/part_allocator.c"
#include "../executor/memoriser/deallocator/item_deallocator.c"
#include "../executor/memoriser/deallocator/part_deallocator.c"

//
// modifier
//

#include "../executor/modifier/item_modifier.c"
#include "../executor/modifier/part_modifier.c"

//
// randomiser
//

#include "../executor/randomiser/retriever.c"
#include "../executor/randomiser/sower.c"

//
// representer
//

#include "../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"
#include "../executor/representer/deserialiser/deserialiser.c"
#include "../executor/representer/serialiser/serialiser.c"

//
// runner
//

#include "../executor/runner/executor.c"
#include "../executor/runner/sleeper.c"

//
// sorter
//

#include "../executor/sorter/sorter.c"

//
// streamer
//

#include "../executor/streamer/reader/deallocation_reader.c"
#include "../executor/streamer/reader/reader.c"
#include "../executor/streamer/writer/writer.c"

//
// timer
//

#include "../executor/timer/current_timer.c"

/* EXECUTOR_LIBRARY_SOURCE */
#endif
