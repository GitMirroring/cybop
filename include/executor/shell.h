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

#ifndef SHELL_HEADER
#define SHELL_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/command/unix_command_model.h"
#include "constant/model/command/win32_command_model.h"

//
// name
//

#include "constant/name/command_option/unix/archive_unix_command_option_name.h"
#include "constant/name/command_option/unix/change_directory_unix_command_option_name.h"
#include "constant/name/command_option/unix/change_permission_unix_command_option_name.h"
#include "constant/name/command_option/unix/compare_files_unix_command_option_name.h"
#include "constant/name/command_option/unix/config_network_unix_command_option_name.h"
#include "constant/name/command_option/unix/copy_file_unix_command_option_name.h"
#include "constant/name/command_option/unix/create_directory_unix_command_option_name.h"
#include "constant/name/command_option/unix/date_unix_command_option_name.h"
#include "constant/name/command_option/unix/disk_free_unix_command_option_name.h"
#include "constant/name/command_option/unix/disk_usage_unix_command_option_name.h"
#include "constant/name/command_option/unix/display_content_unix_command_option_name.h"
#include "constant/name/command_option/unix/echo_message_unix_command_option_name.h"
#include "constant/name/command_option/unix/find_command_unix_command_option_name.h"
#include "constant/name/command_option/unix/find_file_unix_command_option_name.h"
#include "constant/name/command_option/unix/help_unix_command_option_name.h"
#include "constant/name/command_option/unix/hostname_unix_command_option_name.h"
#include "constant/name/command_option/unix/id_unix_command_option_name.h"
#include "constant/name/command_option/unix/ifconfig_unix_command_option_name.h"
#include "constant/name/command_option/unix/ifup_unix_command_option_name.h"
#include "constant/name/command_option/unix/kill_unix_command_option_name.h"
#include "constant/name/command_option/unix/list_directory_contents_unix_command_option_name.h"
#include "constant/name/command_option/unix/list_open_files_unix_command_option_name.h"
#include "constant/name/command_option/unix/list_tasks_unix_command_option_name.h"
#include "constant/name/command_option/unix/memory_free_unix_command_option_name.h"
#include "constant/name/command_option/unix/move_file_unix_command_option_name.h"
#include "constant/name/command_option/unix/netstat_unix_command_option_name.h"
#include "constant/name/command_option/unix/ping_unix_command_option_name.h"
#include "constant/name/command_option/unix/present_working_directory_unix_command_option_name.h"
#include "constant/name/command_option/unix/remove_file_unix_command_option_name.h"
#include "constant/name/command_option/unix/shell_unix_command_option_name.h"
#include "constant/name/command_option/unix/sort_unix_command_option_name.h"
#include "constant/name/command_option/unix/spellcheck_unix_command_option_name.h"
#include "constant/name/command_option/unix/system_messages_unix_command_option_name.h"
#include "constant/name/command_option/unix/tape_archiver_unix_command_option_name.h"
#include "constant/name/command_option/unix/top_unix_command_option_name.h"
#include "constant/name/command_option/unix/touch_unix_command_option_name.h"
#include "constant/name/command_option/unix/userlog_unix_command_option_name.h"
#include "constant/name/command_option/unix/who_unix_command_option_name.h"
#include "constant/name/command_option/unix/word_count_unix_command_option_name.h"

#include "constant/name/command_option/win32/change_directory_win32_command_option_name.h"
#include "constant/name/command_option/win32/compare_files_win32_command_option_name.h"
#include "constant/name/command_option/win32/config_network_win32_command_option_name.h"
#include "constant/name/command_option/win32/copy_file_win32_command_option_name.h"
#include "constant/name/command_option/win32/date_win32_command_option_name.h"
#include "constant/name/command_option/win32/display_content_win32_command_option_name.h"
#include "constant/name/command_option/win32/echo_message_win32_command_option_name.h"
#include "constant/name/command_option/win32/find_file_win32_command_option_name.h"
#include "constant/name/command_option/win32/help_win32_command_option_name.h"
#include "constant/name/command_option/win32/kill_win32_command_option_name.h"
#include "constant/name/command_option/win32/list_directory_contents_win32_command_option_name.h"
#include "constant/name/command_option/win32/list_tasks_win32_command_option_name.h"
#include "constant/name/command_option/win32/memory_free_win32_command_option_name.h"
#include "constant/name/command_option/win32/move_file_win32_command_option_name.h"
#include "constant/name/command_option/win32/ping_win32_command_option_name.h"
#include "constant/name/command_option/win32/remove_file_win32_command_option_name.h"
#include "constant/name/command_option/win32/sort_win32_command_option_name.h"
#include "constant/name/command_option/win32/tape_archiver_win32_command_option_name.h"

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

//
// commander
//

void command_adapt_unix_to_windows_path(void* p0, void* p1, void* p2);
void command_change_directory(void* pd, void* pc, void* p0, void* p1, void* p2);
void command_change_permission(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void command_clear_screen();
void command_compare_files(void* p1d, void* p1c, void* p2d, void* p2c, void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void command_config_network(void* p0, void* p1, void* p2, void* p3);
void command_copy_file(void* smd, void* smc, void* dmd, void* dmc, void* fmd, void* imd, void* paamd, void* plmd, void* rmd, void* umd, void* vmd);
void command_create_directory(void* p0, void* p1);
void command_date(void* nmd, void* nmc, void* tmd, void* imd, void* rmd, void* umd);
void command_delay(void* tmd, void* tmc);
void command_diff(void* f1md, void* f1mc, void* f2md, void* f2mc);
void command_disk_free(void* amd, void* hmd, void* kmd, void* lmd, void* mmd, void* tmd);
void command_disk_usage(void* hmd, void* smd, void* amd, void* bmd, void* tmd);
void command_display_content(void* pd, void* pc, void* ln, void* sqz, void* clr);
void command_echo_message(void* mmd, void* mmc);
void command_find_command(void* cmd, void* cmc, void* bmd, void* mmd, void* smd);
void command_find_file(void* pmd, void* pmc, void* nmd, void* nmc, void* imd, void* rmd);
void command_grep(void* pmd, void* pmc, void* fmd, void* fmc);
void command_help(void* cd, void* cc);
void command_hostname(void* dmd, void* fmd, void* imd, void* amd, void* smd);
void command_id(void* cmd, void* gmd, void* smd, void* nmd, void* umd);
void command_ifconfig(void* imd, void* imc, void* amd, void* smd, void* dmd, void* umd);
void command_ifup();
void command_kill(void* pd, void* pc);
void command_list_directory_contents(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void command_list_open_files(void* umd, void* smd, void* lmd, void* dmd, void* tmd);
void command_list_tasks(void* ld, void* ad, void* vd);
void command_memory_free(void* hmd, void* kmd, void* mmd, void* gmd, void* tmd);
void command_move_file(void* smd, void* smc, void* dmd, void* dmc, void* fmd, void* imd, void* vmd);
void command_netstat(void* rmd, void* imd, void* gmd, void* smd, void* mmd, void* vmd, void* nmd, void* emd, void* pmd, void* lmd, void* amd, void* omd, void* tmd);
void command_ping(void* hmd, void* hmc, void* cmd, void* cmc, void* imd, void* imc);
void command_pwd(void* lmd, void* pmd);
void command_remove_file(void* pmd, void* pmc, void* fmd, void* imd, void* rmd, void* vmd);
void command_sort(void* fmd, void* fmc, void* omd, void* omc, void* rmd, void* rmc);
void command_spellcheck(void* pd, void* pc, void* md, void* mc,void* smd, void* smc,void* ld, void* lc,void* ed, void* ec,void* kd, void* kc,void* mad, void* mac, void* db);
void command_system_messages(void* hmd, void* cmd, void* kmd, void* lmd, void* umd);
void command_tape_archiver(void* smd, void* smc, void* dmd, void* dmc, void* fmd, void* gmd, void* umd, void* vmd);
void command_top(void* bmd, void* cmd,void* hmd,void* imd,void* smd);
void command_touch(void* pmd, void* pmc, void* rmd, void* rmc, void* tmd, void* tmc);
void command_traceroute(void* hmd, void* hmc);
void command_userlog(void* hmd, void* cmd, void* smd, void* omd);
void command_who(void* amd, void* bmd, void* dmd, void* lmd, void* smd);
void command_who_am_i();
void command_word_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

/* SHELL_HEADER */
#endif
