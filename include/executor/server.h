/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SERVER_HEADER
#define SERVER_HEADER

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
// activator
//

void disable(void* p0, void* p1, void* p2);
void disable_thread(void* p0);

void enable(void* p0, void* p1, void* p2, void* p3);
void enable_bsd_socket(void* p0, void* p1);
void enable_client(void* p0, void* p1, void* p2);
void enable_display(void* p0);
void enable_entry(void* p0, void* p1);
int enable_function(void* p0);
void enable_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void enable_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void enable_socket(void* p0, void* p1);
void enable_socket_request(void* p0, void* p1);
void enable_thread(void* p0);
void enable_win32_display(void* p0, void* p1);
void enable_winsock(void* p0, void* p1);
void enable_xcb(void* p0);
void enable_xcb_buffer(void* p0, void* p1, void* p2);
void enable_xcb_client(void* p0, void* p1);
void enable_xcb_event(void* p0, void* p1);

//
// awakener
//

void awake_display(void* p0);
void awake_serial_port(void* p0);
void awake_socket(void* p0);
void awake_terminal(void* p0);
void awaken(void* p0, void* p1);

//
// maintainer
//

void shutdown_display(void* p0);
void shutdown_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void shutdown_lifecycle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void shutdown_list(void* p0, void* p1, void* p2, void* p3, void* p4);
void shutdown_server(void* p0, void* p1, void* p2);
void shutdown_service(void* p0, void* p1);
void shutdown_socket(void* p0);
void shutdown_xcb(void* p0);

void startup_bsd_socket_bind(void* p0, void* p1, void* p2);
void startup_bsd_socket_listen(void* p0, void* p1);
void startup_display(void* p0);
void startup_entry(void* p0, void* p1, void* p2, void* p3, void* p4);
void startup_server(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void startup_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void startup_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void startup_socket_bind(void* p0, void* p1, void* p2);
void startup_socket_lifecycle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void startup_socket_listen(void* p0, void* p1);
void startup_winsock_bind(void* p0, void* p1, void* p2);
void startup_winsock_listen(void* p0, void* p1);
void startup_xcb(void* p0);

/* SERVER_HEADER */
#endif
