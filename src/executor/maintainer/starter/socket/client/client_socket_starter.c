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

#ifdef __APPLE__
    #include <sys/socket.h>
#elif WIN32
    #include <winsock.h>
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <sys/socket.h>
#else
    #include <sys/socket.h>
#endif

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/maintainer/starter/socket/client/connect_client_socket_starter.c"
#include "../../../../../executor/maintainer/starter/socket/socket_address/socket_address_socket_starter.c"
#include "../../../../../executor/maintainer/starter/socket/create_socket_starter.c"
#include "../../../../../executor/maintainer/starter/socket/family_socket_starter.c"
#include "../../../../../executor/maintainer/starter/socket/protocol_socket_starter.c"
#include "../../../../../executor/maintainer/starter/socket/style_socket_starter.c"
#include "../../../../../logger/logger.c"
#include "../../../../../variable/symbolic_name/address_family_socket_symbolic_name.c"
#include "../../../../../variable/symbolic_name/protocol_family_socket_symbolic_name.c"
#include "../../../../../variable/symbolic_name/protocol_socket_symbolic_name.c"

/**
 * Starts up socket in client mode.
 *
 * @param p0 the client socket
 * @param p1 the family data (namespace)
 * @param p2 the family count
 * @param p3 the style data (communication type)
 * @param p4 the style count
 * @param p5 the protocol data
 * @param p6 the protocol count
 * @param p7 the filename data
 * @param p8 the filename count
 * @param p9 the host address data
 * @param p10 the host address count
 * @param p11 the port
 */
void startup_socket_client(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket client.");

    // The protocol family (socket namespace).
    // By default, its value is set to: PF_INET6
    int pf = *UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME;
    // The address family (namespace).
    // By default, its value is set to: AF_INET6
    int af = *UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME;
    // The communication style.
    // By default, its value is set to: SOCK_STREAM
    int st = SOCK_STREAM;
    // The protocol.
    // By default, its value is set to: IPPROTO_TCP
    int p = *IP_PROTOCOL_SOCKET_SYMBOLIC_NAME;
    // The socket address data, size.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    int as = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get protocol- and address family.
    startup_socket_family((void*) &pf, (void*) &af, p1, p2);
    // Get socket communication style.
    startup_socket_style((void*) &st, p3, p4);
    // Get socket protocol.
    startup_socket_protocol((void*) &p, p5, p6);
    // Create socket.
    startup_socket_create(p0, (void*) &pf, (void*) &st, (void*) &p);
    // Allocate and initialise socket address depending on family.
    // CAUTION! Hand over address data as POINTER REFERENCE,
    // since it gets allocated inside the function and
    // has to be preserved as return value.
    startup_socket_socket_address((void*) &ad, (void*) &as, p7, p8, p9, p10, p11, (void*) &af);
    // Connect via socket with server.
    startup_socket_client_connect(p0, ad, (void*) &as);
    // Deallocate socket address.
    free(ad);
}

/* CLIENT_SOCKET_STARTER_SOURCE */
#endif
