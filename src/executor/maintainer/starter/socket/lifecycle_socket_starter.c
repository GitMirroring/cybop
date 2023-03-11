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

#ifndef LIFECYCLE_SOCKET_STARTER_SOURCE
#define LIFECYCLE_SOCKET_STARTER_SOURCE

//
// System interface
//

#if defined(__linux__) || defined(__unix__)
    #include <sys/socket.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/socket.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <winsock.h>
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "constant.h"
#include "variable.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/dispatcher/opener/socket/device_socket_opener.c"
#include "../../../../executor/maintainer/starter/socket/bind_socket_starter.c"
#include "../../../../executor/maintainer/starter/socket/listen_socket_starter.c"
#include "../../../../executor/memoriser/allocator/socket_address/socket_address_allocator.c"
#include "../../../../executor/memoriser/deallocator/socket_address_deallocator.c"
#include "../../../../executor/representer/deserialiser/socket/address_family_socket_deserialiser.c"
#include "../../../../executor/representer/deserialiser/socket/protocol_family_socket_deserialiser.c"
#include "../../../../executor/representer/deserialiser/socket/protocol_socket_deserialiser.c"
#include "../../../../executor/representer/deserialiser/socket/style_socket_deserialiser.c"
#include "logger.h"

/**
 * Starts up server socket lifecycle.
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
 * @param p10 the connexions (number of possible pending client requests)
 */
void startup_socket_lifecycle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket lifecycle.");
    //?? fwprintf(stdout, L"Debug: Startup socket lifecycle. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Startup socket lifecycle. *p0: %i\n", *((int*) p0));

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
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

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

    // Bind address to socket.
    startup_socket_bind(p0, ad, (void*) &as);

    // Deallocate socket address.
    deallocate_socket_address((void*) &ad, (void*) &as, (void*) &af);

    compare_integer_equal((void*) &r, (void*) &st, (void*) STREAM_STYLE_SOCKET_SYMBOLIC_NAME);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a stream socket.
        //
        // CAUTION! Datagram sockets do NOT have connexions,
        // which is why the "listen" function is ONLY called
        // for stream sockets here.
        //

        //
        // Listen for client requests.
        //
        // The second argument specifies the length
        // of the queue for pending connexions.
        // When the queue fills, new clients attempting to connect
        // fail with ECONNREFUSED until the server calls accept
        // to accept a connexion from the queue.
        //
        startup_socket_listen(p0, p10);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket lifecycle. The socket communication style is NOT stream socket.");
        fwprintf(stdout, L"Error: Could not startup socket lifecycle. The socket communication style is NOT stream socket. p0: %i\n", p0);
        fwprintf(stdout, L"Error: Could not startup socket lifecycle. The socket communication style is NOT stream socket. *p0: %i\n", *((int*) p0));
    }
}

/* LIFECYCLE_SOCKET_STARTER_SOURCE */
#endif
