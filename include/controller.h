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

#ifndef CONTROLLER_HEADER
#define CONTROLLER_HEADER

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
// CAUTION! The sort order of the following sections is NOT alphabetically.
// For better overview, it follows the system LIFECYCLE.
//

//
// globaliser
//

void globalise();

void globalise_log();

void globalise_reference_counter();

void globalise_symbolic_name();
void globalise_symbolic_name_serial_baudrate();
void globalise_symbolic_name_socket_address_family();
void globalise_symbolic_name_socket_protocol();
void globalise_symbolic_name_socket_protocol_family();
void globalise_symbolic_name_socket_style();
void globalise_symbolic_name_thread_mutex();

void globalise_type_size();
void globalise_type_size_compound();
void globalise_type_size_display();
void globalise_type_size_integral();
void globalise_type_size_pointer();
void globalise_type_size_real();
void globalise_type_size_socket();
void globalise_type_size_terminal();
void globalise_type_size_thread();

//
// orienter
//

void orient(void* p0, void* p1);

//
// optionaliser
//

void optionalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void optionalise_log_file(void* p0, void* p1);

//
// helper
//

void help(void* p0);

//
// informer
//

void inform(void* p0);

//
// manager
//

void manage(void* p0);

//
// initiator
//

void initiate(void* p0, void* p1, void* p2, void* p3);

//
// checker
//

void check(void* p0, void* p1);
void check_empty(void* p0, void* p1, void* p2);
void check_found(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

//
// handler
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void handle_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void handle_operation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void handle_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

//
// deoptionaliser
//

void deoptionalise(void* p0);
void deoptionalise_log_file(void* p0);

//
// unglobaliser
//

void unglobalise();
void unglobalise_log();

/* CONTROLLER_HEADER */
#endif
