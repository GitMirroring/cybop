/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONNECT_CLIENT_SOCKET_STARTER_SOURCE
#define CONNECT_CLIENT_SOCKET_STARTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../../executor/maintainer/starter/bsd_socket/connect_bsd_socket_starter.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../../executor/maintainer/starter/bsd_socket/connect_bsd_socket_starter.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../../executor/maintainer/starter/winsock/connect_winsock_starter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Connects a client socket.
 *
 * @param p0 the socket
 * @param p1 the socket address data
 * @param p2 the socket address size
 */
void startup_socket_client_connect(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket client connect.");

fwprintf(stdout, L"TEST: startup socket client connect s: %i \n", *((int*) p0));
sleep(2);

#if defined(__linux__) || defined(__unix__)
    startup_bsd_socket_connect(p0, p1, p2);
#elif defined(__APPLE__) && defined(__MACH__)
    startup_bsd_socket_connect(p0, p1, p2);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    startup_winsock_connect(p0, p1, p2);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* CONNECT_CLIENT_SOCKET_STARTER_SOURCE */
#endif
