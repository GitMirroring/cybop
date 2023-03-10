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

#ifndef CONNEXION_SOCKET_OPENER_SOURCE
#define CONNEXION_SOCKET_OPENER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/dispatcher/opener/bsd_socket/connexion_bsd_socket_opener.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/dispatcher/opener/bsd_socket/connexion_bsd_socket_opener.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/dispatcher/opener/winsock/connexion_winsock_opener.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Connects the socket to the server given by the address.
 *
 * @param p0 the socket
 * @param p1 the host (server) address data
 * @param p2 the host (server) address size
 */
void open_socket_connexion(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open socket connexion.");
    //?? fwprintf(stdout, L"Debug: Open socket connexion. socket p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Open socket connexion. socket *p0: %i\n", *((int*) p0));

#if defined(__linux__) || defined(__unix__)
    open_bsd_socket_connexion(p0, p1, p2);
#elif defined(__APPLE__) && defined(__MACH__)
    open_bsd_socket_connexion(p0, p1, p2);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    open_winsock_connexion(p0, p1, p2);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* CONNEXION_SOCKET_OPENER_SOURCE */
#endif
