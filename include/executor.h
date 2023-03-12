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

#ifndef EXECUTOR_HEADER
#define EXECUTOR_HEADER

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
// accessor
//

void count_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void get(void* p0, void* p1, void* p2);
void get_part_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void indicate_part(void* p0, void* p1, void* p2);
void get_name_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// activator
//

void disable(void* p0, void* p1, void* p2);
void enable(void* p0, void* p1, void* p2, void* p3);

//
// calculator
//

void calculate_integer_minimum(void* p0, void* p1);
void calculate_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

//
// caster
//

void cast_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

//
// commander
//

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
void command_who_am_i();
void command_who(void* amd, void* bmd, void* dmd, void* lmd, void* smd);
void command_word_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

//
// communicator
//

void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
void send_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18);

//
// comparator
//

void compare_integer_equal(void* p0, void* p1, void* p2);
void compare_integer_unequal(void* p0, void* p1, void* p2);
void compare_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

//
// container
//

//?? void contain_integer_left(void* p0, void* p1, void* p2, void* p3);

//
// converter
//

void decode(void* p0, void* p1, void* p2, void* p3);
void encode(void* p0, void* p1, void* p2, void* p3);

//
// copier
//

void copy_array_forward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void copy_integer(void* p0, void* p1);
void copy_pointer(void* p0, void* p1);

//
// dispatcher
//

void close_client(void* p0, void* p1, void* p2, void* p3, void* p4);
void open_client(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);

//
// feeler
//

void sense(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void suspend(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// finder
//

void find_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// logifier
//

void logify(void* p0, void* p1, void* p2, void* p3);

//
// maintainer
//

void shutdown_server(void* p0, void* p1, void* p2);
void startup_server(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);

//
// manipulator
//

void manipulate_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

//
// memoriser
//

void allocate_item(void* p0, void* p1, void* p2);
void allocate_part(void* p0, void* p1, void* p2);
void deallocate_item(void* p0, void* p1);
void deallocate_part(void* p0);

//
// modifier
//

void modify_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void modify_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

//
// randomiser
//

void retrieve(void* p0, void* p1, void* p2);
void sow(void* p0);

//
// representer
//

void deserialise_cybol_type(void* p0, void* p1);
void deserialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

//
// runner
//

void execute(void* p0, void* p1);
void sleep_duration(void* p0, void* p1);

//
// sorter
//

void sort(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);

//
// streamer
//

void read_deallocation(void* p0, void* p1, void* p2, void* p3);
void read_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void write_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

//
// timer
//

void time_current(void* p0);

/* EXECUTOR_HEADER */
#endif
