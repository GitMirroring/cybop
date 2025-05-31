/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef APPLICATOR_HEADER
#define APPLICATOR_HEADER

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
// access
//

void apply_count(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_indicate(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void apply_get(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void apply_get_index(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// activate
//

void apply_disable(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_enable(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// calculate
//

void apply_calculate(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void apply_calculate_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

//
// cast
//

void apply_cast(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// check and compare
//

void apply_compare(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void apply_compare_result(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void apply_compare_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);

//
// command
//

void apply_archive_file(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_change_directory(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_change_permission(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_clear_screen(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_compare_files(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_config_network(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_copy_file(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_create_directory(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_date(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_delay(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_diff(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_disk_free(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_disk_usage(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_display_content(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_echo_message(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_find_command(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_find_file(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_grep(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_help(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_hostname(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_id(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_ifconfig(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_ifup();
void apply_kill(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_list_directory_contents(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_list_open_files(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_list_tasks(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_memory_free(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_move_file(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_netstat(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_ping(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_pwd(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_remove_file(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_command_sort(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_spellcheck(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_system_messages(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_tape_archiver(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_top(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_touch(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_traceroute(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_userlog(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_who_am_i();
void apply_who(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_word_count(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// communicate
//

void apply_identify(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_receive(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_send(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// contain
//

void apply_contain(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// convert
//

void apply_decode(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_encode(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// dispatch
//

void apply_close(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_open(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// feel
//

void apply_sense(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_suspend(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// flow
//

void apply_branch(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void apply_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void apply_loop_each(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void apply_loop_for(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void apply_loop_times(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void apply_sequence(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

//
// logify
//

void apply_logify(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void apply_logify_type(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// maintain
//

void apply_shutdown(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_startup(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// manipulate
//

void apply_manipulate(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// memorise
//

void apply_create(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_create_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void apply_destroy(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// modify
//

void apply_modify(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void apply_modify_array(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_modify_deep(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void apply_modify_index(void* p0, void* p1);
void apply_modify_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);

//
// randomise
//

void apply_retrieve(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_sow(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// represent
//

void apply_deserialise(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_serialise(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// run
//

void apply_run(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_sleep(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// search
//

void apply_search(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// sort
//

void apply_sort(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// stream
//

void apply_read(void* p0, void* p1, void* p2, void* p3, void* p4);
void apply_write(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// time
//

void apply_time(void* p0, void* p1, void* p2, void* p3, void* p4);

/* APPLICATOR_HEADER */
#endif
