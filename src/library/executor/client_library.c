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

#ifndef CLIENT_LIBRARY_SOURCE
#define CLIENT_LIBRARY_SOURCE

//
// configurator
//

#include "../../executor/configurator/finaliser/finaliser.c"
#include "../../executor/configurator/finaliser/serial_port/serial_port_finaliser.c"
#include "../../executor/configurator/finaliser/terminal/terminal_finaliser.c"

#include "../../executor/configurator/initialiser/initialiser.c"
#include "../../executor/configurator/initialiser/serial_port/mode_serial_port_initialiser.c"
#include "../../executor/configurator/initialiser/serial_port/serial_port_initialiser.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/configurator/initialiser/bsd_socket/bsd_socket_initialiser.c"
    #include "../../executor/configurator/initialiser/terminal/mode_terminal_initialiser.c"
    #include "../../executor/configurator/initialiser/terminal/terminal_initialiser.c"
    #include "../../executor/configurator/initialiser/unix_serial_port/unix_serial_port_initialiser.c"
    #include "../../executor/configurator/initialiser/unix_terminal/unix_terminal_initialiser.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/configurator/initialiser/bsd_socket/bsd_socket_initialiser.c"
    #include "../../executor/configurator/initialiser/terminal/mode_terminal_initialiser.c"
    #include "../../executor/configurator/initialiser/terminal/terminal_initialiser.c"
    #include "../../executor/configurator/initialiser/unix_serial_port/unix_serial_port_initialiser.c"
    #include "../../executor/configurator/initialiser/unix_terminal/unix_terminal_initialiser.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/configurator/initialiser/win32_console/input_win32_console_initialiser.c"
    #include "../../executor/configurator/initialiser/win32_console/output_win32_console_initialiser.c"
    #include "../../executor/configurator/initialiser/win32_serial_port/win32_serial_port_initialiser.c"
    #include "../../executor/configurator/initialiser/winsock/winsock_initialiser.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// dispatcher
//

#include "../../executor/dispatcher/closer/basic/basic_closer.c"
#include "../../executor/dispatcher/closer/closer.c"
#include "../../executor/dispatcher/closer/device_closer.c"
#include "../../executor/dispatcher/closer/display/display_closer.c"
#include "../../executor/dispatcher/closer/lifecycle_closer.c"
#include "../../executor/dispatcher/closer/pipe/pipe_closer.c"
#include "../../executor/dispatcher/closer/socket/socket_closer.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/dispatcher/closer/unix_pipe/unix_pipe_closer.c"
    #include "../../executor/dispatcher/closer/xcb/xcb_closer.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/dispatcher/closer/unix_pipe/unix_pipe_closer.c"
    #include "../../executor/dispatcher/closer/xcb/xcb_closer.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/dispatcher/closer/win32_display/win32_display_closer.c"
    #include "../../executor/dispatcher/closer/winsock/cleanup_winsock_closer.c"
    #include "../../executor/dispatcher/closer/winsock/winsock_closer.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../executor/dispatcher/opener/basic/basic_opener.c"
#include "../../executor/dispatcher/opener/device_opener.c"
#include "../../executor/dispatcher/opener/display/display_opener.c"
#include "../../executor/dispatcher/opener/entry_opener.c"
#include "../../executor/dispatcher/opener/fifo/fifo_opener.c"
#include "../../executor/dispatcher/opener/file/file_opener.c"
#include "../../executor/dispatcher/opener/file/mode_file_opener.c"
#include "../../executor/dispatcher/opener/flag_opener.c"
#include "../../executor/dispatcher/opener/identification_opener.c"
#include "../../executor/dispatcher/opener/opener.c"
#include "../../executor/dispatcher/opener/pipe/pipe_opener.c"
#include "../../executor/dispatcher/opener/serial_port/serial_port_opener.c"
#include "../../executor/dispatcher/opener/socket/connexion_socket_opener.c"
#include "../../executor/dispatcher/opener/socket/device_socket_opener.c"
#include "../../executor/dispatcher/opener/socket/socket_opener.c"
#include "../../executor/dispatcher/opener/stub_opener.c"
#include "../../executor/dispatcher/opener/terminal/terminal_opener.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/dispatcher/opener/bsd_socket/connexion_bsd_socket_opener.c"
    #include "../../executor/dispatcher/opener/bsd_socket/device_bsd_socket_opener.c"
    #include "../../executor/dispatcher/opener/unix_fifo/file_unix_fifo_opener.c"
    #include "../../executor/dispatcher/opener/unix_fifo/unix_fifo_opener.c"
    #include "../../executor/dispatcher/opener/unix_pipe/unix_pipe_opener.c"
    #include "../../executor/dispatcher/opener/xcb/xcb_opener.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/dispatcher/opener/bsd_socket/connexion_bsd_socket_opener.c"
    #include "../../executor/dispatcher/opener/bsd_socket/device_bsd_socket_opener.c"
    #include "../../executor/dispatcher/opener/unix_fifo/file_unix_fifo_opener.c"
    #include "../../executor/dispatcher/opener/unix_fifo/unix_fifo_opener.c"
    #include "../../executor/dispatcher/opener/unix_pipe/unix_pipe_opener.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/dispatcher/opener/win32_display/register_win32_display_opener.c"
    #include "../../executor/dispatcher/opener/win32_display/win32_display_opener.c"
    #include "../../executor/dispatcher/opener/winsock/connexion_winsock_opener.c"
    #include "../../executor/dispatcher/opener/winsock/device_winsock_opener.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// feeler
//

#include "../../executor/feeler/sensor/entry_sensor.c"
#include "../../executor/feeler/sensor/function_sensor.c"
#include "../../executor/feeler/sensor/loop_sensor.c"
#include "../../executor/feeler/sensor/sensor.c"
#include "../../executor/feeler/sensor/thread_sensor.c"

#include "../../executor/feeler/suspender/suspender.c"
#include "../../executor/feeler/suspender/thread_suspender.c"

/* CLIENT_LIBRARY_SOURCE */
#endif
