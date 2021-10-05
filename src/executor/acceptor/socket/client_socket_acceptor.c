/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CLIENT_SOCKET_ACCEPTOR_SOURCE
#define CLIENT_SOCKET_ACCEPTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../executor/acceptor/bsd_socket/bsd_socket_acceptor.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../executor/acceptor/bsd_socket/bsd_socket_acceptor.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../executor/acceptor/winsock/winsock_acceptor.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Accepts a client request via server socket.
 *
 * @param p0 the sender client socket
 * @param p1 the receiver server socket
 */
void accept_socket_client(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept socket client.");

#if defined(__linux__) || defined(__unix__)
    accept_bsd_socket(p0, p1);
#elif defined(__APPLE__) && defined(__MACH__)
    accept_bsd_socket(p0, p1);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    accept_winsock(p0, p1);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* CLIENT_SOCKET_ACCEPTOR_SOURCE */
#endif
