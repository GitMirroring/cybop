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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CLIENT_HEADER
#define CLIENT_HEADER

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
// configurator
//

void finalise(void* p0, void* p1, void* p2);
void finalise_serial_port(void* p0, void* p1);
void finalise_terminal(void* p0, void* p1);

void initialise(void* p0, void* p1, void* p2, void* p3);
void initialise_bsd_socket(void* p0);
void initialise_serial_port(void* p0, void* p1, void* p2);
void initialise_serial_port_mode(void* p0, void* p1);
void initialise_terminal(void* p0, void* p1);
void initialise_terminal_mode(void* p0);
void initialise_unix_serial_port(void* p0, void* p1);
void initialise_unix_terminal(void* p0);
void initialise_win32_console_input(void* p0);
void initialise_win32_console_output(void* p0);
void initialise_win32_serial_port(void* p0);
void initialise_winsock();

//
// dispatcher
//

void close_basic(void* p0);
void close_client(void* p0, void* p1, void* p2, void* p3, void* p4);
void close_device(void* p0, void* p1, void* p2);
void close_display(void* p0, void* p1);
void close_lifecycle(void* p0, void* p1, void* p2, void* p3, void* p4);
void close_pipe(void* p0);
void close_socket(void* p0);
void close_unix_pipe(void* p0);
void close_win32_display(void* p0, void* p1);
void close_winsock(void* p0);
void close_winsock_cleanup();
void close_xcb(void* p0, void* p1);

void open_basic(void* p0, void* p1, void* p2, void* p3, void* p4);
void open_bsd_socket_connexion(void* p0, void* p1, void* p2);
void open_bsd_socket_device(void* p0, void* p1, void* p2, void* p3);
void open_client(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void open_device(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void open_display(void* p0, void* p1);
void open_entry(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void open_fifo(void* p0, void* p1, void* p2);
void open_file(void* p0, void* p1, void* p2, void* p3, void* p4);
void open_file_mode(void* p0, void* p1, void* p2);
void open_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void open_identification(void* p0, void* p1, void* p2, void* p3);
void open_pipe(void* p0);
void open_serial_port(void* p0, void* p1, void* p2);
void open_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void open_socket_connexion(void* p0, void* p1, void* p2);
void open_socket_device(void* p0, void* p1, void* p2, void* p3);
void open_stub(void* p0, void* p1);
void open_terminal(void* p0, void* p1, void* p2);
void open_unix_fifo(void* p0, void* p1, void* p2);
void open_unix_fifo_file(void* p0, void* p1, void* p2);
void open_unix_pipe(void* p0);
void open_win32_display(void* p0, void* p1);
void open_win32_display_register(void* p0, void* p1);
void open_winsock_connexion(void* p0, void* p1, void* p2);
void open_winsock_device(void* p0, void* p1, void* p2, void* p3);
void open_xcb(void* p0, void* p1);

//
// feeler
//

void sense(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void sense_entry(void* p0, void* p1, void* p2, void* p3);
int sense_function(void* p0);
void sense_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void sense_thread(void* p0);

void suspend(void* p0, void* p1, void* p2, void* p3, void* p4);
void suspend_thread(void* p0);

/* CLIENT_HEADER */
#endif
