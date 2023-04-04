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

#ifndef SOCKET_OPENER_SOURCE
#define SOCKET_OPENER_SOURCE

//
// Library interface
//

#include "client.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "variable.h"
#include "web.h"

/**
 * Connects the given socket to the server given by the address.
 *
 * @param p0 the destination socket
 * @param p1 the port
 * @param p2 the host address data (network communication) OR filename data (local unix domain socket)
 * @param p3 the host address count (network communication) OR filename count (local unix domain socket)
 * @param p4 the family data (namespace)
 * @param p5 the family count
 * @param p6 the style data (communication type)
 * @param p7 the style count
 * @param p8 the protocol data
 * @param p9 the protocol count
 */
void open_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open socket.");

    // The protocol family (socket namespace).
    int pf = *UNSPEC_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME;
    // The address family (namespace).
    int af = *UNSPEC_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME;
    // The communication style.
    int st = *STREAM_STYLE_SOCKET_SYMBOLIC_NAME;
    // The protocol.
    int p = *IP_PROTOCOL_SOCKET_SYMBOLIC_NAME;
    // The socket address data, size.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    int as = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get protocol family.
    deserialise_socket_family_protocol((void*) &pf, p4, p5);
    // Get address family.
    deserialise_socket_family_address((void*) &af, p4, p5);
    // Get communication style.
    deserialise_socket_style((void*) &st, p6, p7);
    // Get protocol.
    deserialise_socket_protocol((void*) &p, p8, p9);

    // Create socket.
    open_socket_device(p0, (void*) &pf, (void*) &st, (void*) &p);

    //
    // Allocate and initialise socket address depending on family.
    //
    // CAUTION! Hand over address data as POINTER REFERENCE,
    // since it gets allocated inside the function and
    // has to be preserved as return value.
    //
    allocate_socket_address((void*) &ad, (void*) &as, p1, p2, p3, (void*) &af);

    // Connect via socket with server whose address is given.
    open_socket_connexion(p0, ad, (void*) &as);

    // Deallocate socket address.
    deallocate_socket_address((void*) &ad, (void*) &as, (void*) &af);
}

/* SOCKET_OPENER_SOURCE */
#endif
