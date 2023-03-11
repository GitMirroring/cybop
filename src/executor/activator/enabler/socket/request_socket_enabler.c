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

#ifndef REQUEST_SOCKET_ENABLER_SOURCE
#define REQUEST_SOCKET_ENABLER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "logger.h"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/activator/enabler/bsd_socket/bsd_socket_enabler.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/activator/enabler/bsd_socket/bsd_socket_enabler.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/activator/enabler/winsock/winsock_enabler.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Accepts a client request via server socket.
 *
 * @param p0 the destination sender client socket
 * @param p1 the source receiver server socket
 */
void enable_socket_request(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable socket request.");
    //?? fwprintf(stdout, L"Debug: Enable socket request. p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Enable socket request. *p1: %i\n", *((int*) p1));

#if defined(__linux__) || defined(__unix__)
    enable_bsd_socket(p0, p1);
#elif defined(__APPLE__) && defined(__MACH__)
    enable_bsd_socket(p0, p1);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    enable_winsock(p0, p1);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* REQUEST_SOCKET_ENABLER_SOURCE */
#endif
