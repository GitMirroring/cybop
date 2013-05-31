/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef IPV6_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE
#define IPV6_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/address_cybol_model.c"
#include "../../../../constant/model/cybol/communication_style_cybol_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cybol/namespace_cybol_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/memoriser/allocator.c"
#include "../../../../variable/type_size/socket_type_size.c"

/**
 * Startup socket socket address ipv6.
 *
 * @param p0 the ipv6 socket address (pointer reference)
 * @param p1 the host address (in network byte order)
 * @param p2 the socket port (in host byte order)
 */
void startup_socket_initialise_ipv6_socket_address(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* p = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct in6_addr* h = (struct in6_addr*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                struct sockaddr_in6** a = (struct sockaddr_in6**) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket socket address ipv6.");

                // Set namespace (address format/ family).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                (*a)->sin6_family = AF_INET6;

                // Set host address.
                //
                // The "a.sin_addr" field is of type "struct in_addr".
                // This data type is used in certain contexts to contain an
                // IPv4 internet host address. It has just one field, named
                // "s_addr", which records the host address number as an "uint32_t".
                //
                // CAUTION! The host address parametre is already given in
                // network byte order, so that it does NOT have to be converted!
                (*a)->sin6_addr = *h;

                // Set flow information.
                //
                // CAUTION! This is a currently unimplemented field,
                // as written in the gnu c library documentation.
                // (*a)->sin6_flowinfo = ??

                // Set socket port.
                //
                // CAUTION! The port number is given in host byte order and
                // HAS TO BE converted into network byte order!
                (*a)->sin6_port = htons(*p);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address ipv6. The socket address is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address ipv6. The host address is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address ipv6. The socket port is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* IPV6_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE */
#endif
