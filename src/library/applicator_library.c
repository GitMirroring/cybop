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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// access
//

#include "../applicator/access/count.c"
#include "../applicator/access/get.c"
#include "../applicator/access/indicate.c"

//
// activate
//

#include "../applicator/activate/disable.c"
#include "../applicator/activate/enable.c"

//
// calculate
//

#include "../applicator/calculate/calculate.c"
#include "../applicator/calculate/type_calculate.c"

//
// cast
//

#include "../applicator/cast/cast.c"

//
// command
//

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

//
// communicate
//

#include "../applicator/communicate/identify.c"
#include "../applicator/communicate/receive.c"
#include "../applicator/communicate/send.c"

//
// compare and check
//

#include "../applicator/compare/compare.c"
#include "../applicator/compare/result_compare.c"
#include "../applicator/compare/type_compare.c"

//
// contain
//

#include "../applicator/contain/contain.c"

//
// convert
//

#include "../applicator/convert/decode.c"
#include "../applicator/convert/encode.c"

//
// dispatch
//

#include "../applicator/dispatch/close.c"
#include "../applicator/dispatch/open.c"

//
// feel
//

#include "../applicator/feel/sense.c"
#include "../applicator/feel/suspend.c"

//
// flow
//

#include "../applicator/flow/branch.c"
#include "../applicator/flow/loop.c"
#include "../applicator/flow/each_loop.c"
#include "../applicator/flow/for_loop.c"
#include "../applicator/flow/times_loop.c"
#include "../applicator/flow/sequence.c"

//
// logify
//

#include "../applicator/logify/logify.c"
#include "../applicator/logify/type_logify.c"

//
// maintain
//

#include "../applicator/maintain/shutdown.c"
#include "../applicator/maintain/startup.c"

//
// manipulate
//

#include "../applicator/manipulate/manipulate.c"

//
// memorise
//

#include "../applicator/memorise/create.c"
#include "../applicator/memorise/destroy.c"
#include "../applicator/memorise/part_create.c"

//
// modify
//

#include "../applicator/modify/array_modify.c"
#include "../applicator/modify/deep_modify.c"
#include "../applicator/modify/index_modify.c"
#include "../applicator/modify/modify.c"
#include "../applicator/modify/type_modify.c"

//
// randomise
//

#include "../applicator/randomise/retrieve.c"
#include "../applicator/randomise/sow.c"

//
// represent
//

#include "../applicator/represent/deserialise.c"
#include "../applicator/represent/serialise.c"

//
// run
//

#include "../applicator/run/run.c"
#include "../applicator/run/sleep.c"

//
// search
//

#include "../applicator/search/search.c"

//
// sort
//

#include "../applicator/sort/sort.c"

//
// stream
//

#include "../applicator/stream/read.c"
#include "../applicator/stream/write.c"

//
// time
//

#include "../applicator/time/time.c"
