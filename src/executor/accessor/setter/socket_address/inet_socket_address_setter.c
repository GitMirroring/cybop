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

#ifndef INET_SOCKET_ADDRESS_SETTER_SOURCE
#define INET_SOCKET_ADDRESS_SETTER_SOURCE

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

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/symbolic_name/address_family_socket_symbolic_name.c"

/**
 * Sets the inet socket address.
 *
 * @param p0 the inet socket address
 * @param p1 the host address (in network byte order)
 * @param p2 the port (in host byte order)
 */
void set_socket_address_inet(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* p = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* h = (int*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                struct sockaddr_in* a = (struct sockaddr_in*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set socket address inet.");

                //
                // Set address family (namespace).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                //
                // CAUTION! The "sin_family" field is of type
                // "sa_family_t", which is actually an "integer",
                // as well as the "AF_INET" constant.
                //
                (*a).sin_family = *INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME;

                //
                // Set host address.
                //
                // The "a.sin_addr" field is of type "struct in_addr".
                // This data type is used in certain contexts to contain an
                // IPv4 internet host address. It has just one field, named
                // "s_addr", which records the host address number as an "uint32_t".
                //
                // CAUTION! The host address has to be in NETWORK byte order.
                //
                (*a).sin_addr.s_addr = *h;

                //
                // Set socket port.
                //
                // CAUTION! The port has to be in NETWORK byte order.
                //
                (*a).sin_port = htons(*p);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set socket address inet. The socket address is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set socket address inet. The host address is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set socket address inet. The socket port is null.");
    }
}

/* INET_SOCKET_ADDRESS_SETTER_SOURCE */
#endif
