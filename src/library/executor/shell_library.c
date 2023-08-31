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
// commander
//

#include "../../executor/commander/adapt_unix_to_windows_path_commander.c"
#include "../../executor/commander/change_directory_commander.c"
#include "../../executor/commander/change_permission_commander.c"
#include "../../executor/commander/clear_screen_commander.c"
#include "../../executor/commander/compare_files_commander.c"
#include "../../executor/commander/config_network_commander.c"
#include "../../executor/commander/copy_file_commander.c"
#include "../../executor/commander/create_directory_commander.c"
#include "../../executor/commander/date_commander.c"
#include "../../executor/commander/delay_commander.c"
#include "../../executor/commander/diff_commander.c"
#include "../../executor/commander/disk_free_commander.c"
#include "../../executor/commander/disk_usage_commander.c"
#include "../../executor/commander/display_content_commander.c"
#include "../../executor/commander/echo_message_commander.c"
#include "../../executor/commander/find_command_commander.c"
#include "../../executor/commander/find_file_commander.c"
#include "../../executor/commander/grep_commander.c"
#include "../../executor/commander/help_commander.c"
#include "../../executor/commander/hostname_commander.c"
#include "../../executor/commander/id_commander.c"
#include "../../executor/commander/ifconfig_commander.c"
#include "../../executor/commander/ifup_commander.c"
#include "../../executor/commander/kill_commander.c"
#include "../../executor/commander/list_directory_contents_commander.c"
#include "../../executor/commander/list_open_files_commander.c"
#include "../../executor/commander/list_tasks_commander.c"
#include "../../executor/commander/memory_free_commander.c"
#include "../../executor/commander/move_file_commander.c"
#include "../../executor/commander/netstat_commander.c"
#include "../../executor/commander/ping_commander.c"
#include "../../executor/commander/present_working_directory_commander.c"
#include "../../executor/commander/remove_file_commander.c"
#include "../../executor/commander/sort_commander.c"
#include "../../executor/commander/spellcheck_commander.c"
#include "../../executor/commander/system_messages_commander.c"
#include "../../executor/commander/tape_archiver_commander.c"
#include "../../executor/commander/top_commander.c"
#include "../../executor/commander/touch_commander.c"
#include "../../executor/commander/traceroute_commander.c"
#include "../../executor/commander/userlog_commander.c"
#include "../../executor/commander/who_am_i_commander.c"
#include "../../executor/commander/who_commander.c"
#include "../../executor/commander/word_count_commander.c"
