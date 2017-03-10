/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOCKET_STARTER_SOURCE
#define CREATE_SOCKET_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/maintainer/starter/bsd_socket/create_bsd_socket_starter.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/maintainer/starter/bsd_socket/create_bsd_socket_starter.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/maintainer/starter/winsock/create_winsock_starter.c"
    #include "../../../../executor/maintainer/starter/winsock/initialise_winsock_starter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Creates the socket.
 *
 * @param p0 the socket
 * @param p1 the protocol family (socket namespace)
 * @param p2 the communication style
 * @param p3 the protocol
 * @param p4 the blocking flag
 */
void startup_socket_create(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket create.");

#if defined(__linux__) || defined(__unix__)
    // Nothing to be done here.
#elif defined(__APPLE__) && defined(__MACH__)
    // Nothing to be done here.
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    startup_winsock_initialise();
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#if defined(__linux__) || defined(__unix__)
    startup_bsd_socket_create(p0, p1, p2, p3, p4);
#elif defined(__APPLE__) && defined(__MACH__)
    startup_bsd_socket_create(p0, p1, p2, p3, p4);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    startup_winsock_create(p0, p1, p2, p3, p4);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* CREATE_SOCKET_STARTER_SOURCE */
#endif
