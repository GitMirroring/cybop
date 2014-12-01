/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CLIENT_SOCKET_STARTER_SOURCE
#define CLIENT_SOCKET_STARTER_SOURCE

#include <sys/socket.h>

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../logger/logger.c"

/**
 * Starts up socket in client mode.
 *
 * @param p0 the socket
 * @param p1 the filename data
 * @param p2 the filename count
 * @param p3 the host address data
 * @param p4 the host address count
 * @param p5 the port
 * @param p6 the protocol data
 * @param p7 the protocol count
 * @param p8 the style data
 * @param p9 the style count
 * @param p10 the family data
 * @param p11 the family count
 */
void startup_socket_client(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket client.");

    // The protocol family (socket namespace).
    // By default, its value is set to: PF_INET6
    int pf = PF_INET6;
    // The address family (namespace).
    // By default, its value is set to: AF_INET6
    int af = AF_INET6;
    // The communication style.
    // By default, its value is set to: SOCK_STREAM
    int st = SOCK_STREAM;
    // By default, its value is set to: 0
    // CAUTION! A value of ZERO is usually right for the "protocol".
    // It causes the default protocol of the chosen socket style to be used.
    // Examples: IPPROTO_TCP, IPPROTO_UDP, IPPROTO_ICMP, IPPROTO_RAW
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The socket address data, size.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    int as = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get protocol- and address family.
    startup_socket_family((void*) &pf, (void*) &af, p10, p11);
    // Get socket communication style.
    startup_socket_style((void*) &st, p8, p9);
    // Get socket protocol.
    startup_socket_protocol((void*) &p, p6, p7);

    // Create socket.
    startup_socket_create(p0, (void*) &pf, (void*) &st, (void*) &p);

    // Initialise socket address depending on family.
    // CAUTION! Hand over address data as pointer reference,
    // since it gets allocated inside the function and
    // has to be preserved as return value.
    startup_socket_socket_address((void*) &ad, (void*) &as, p1, p2, p3, p4, p5, (void*) &af);

    // CAUTION! The "select" function was NOT used to make
    // this socket non-blocking, because it has some overhead
    // in that other sockets need to be considered and
    // their file descriptors handed over as argument.
    // If nonblocking mode is necessary, then using a thread
    // is considered to be a more simple and clean solution here.

    // Connect via socket with server.
    startup_socket_client_connect(p0, ad, (void*) &as);
}

/* CLIENT_SOCKET_STARTER_SOURCE */
#endif
