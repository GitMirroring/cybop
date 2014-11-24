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

#ifndef SOCKET_ADDRESS_BSD_SOCKET_STARTER_SOURCE
#define SOCKET_ADDRESS_BSD_SOCKET_STARTER_SOURCE

#include <sys/socket.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/maintainer/starter/bsd_socket/inet_host_address_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/inet_socket_address_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/inet6_host_address_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/inet6_socket_address_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/local_socket_address_bsd_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Startup socket address depending on the given address family.
 *
 * @param p0 the socket address data (pointer reference)
 * @param p1 the socket address size
 * @param p2 the filename data
 * @param p3 the filename count
 * @param p4 the host address data
 * @param p5 the host address count
 * @param p6 the port
 * @param p7 the address family (namespace)
 */
void startup_bsd_socket_socket_address(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** ad = (void**) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket socket address.");

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_BLUETOOTH);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_INET);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // The host address.
                    struct in_addr ha;
                    // Get host address.
                    // CAUTION! The returned host address
                    // is already in network byte order.
                    startup_bsd_socket_host_address_inet((void*) &ha, p4, p5);

                    // Initialise socket address size.
                    calculate_integer_add(as, (void*) INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
                    // Allocate socket address.
                    *ad = malloc(*as);
                    // Initialise socket address.
                    // CAUTION! The forwarded host address
                    // is already in network byte order.
                    startup_bsd_socket_socket_address_inet(*ad, (void*) &ha, p6);
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_INET6);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // The host address.
                    struct in6_addr ha;
                    // Get host address.
                    // CAUTION! The returned host address
                    // is already in network byte order.
                    startup_bsd_socket_host_address_inet6((void*) &ha, p4, p5);

                    // Initialise socket address size.
                    calculate_integer_add(as, (void*) INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
                    // Allocate socket address.
                    *ad = malloc(*as);
                    // Initialise socket address.
                    // CAUTION! The forwarded host address
                    // is already in network byte order.
                    startup_bsd_socket_socket_address_inet6(*ad, (void*) &ha, p6);
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_IRDA);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_LOCAL);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // Initialise address size.
                    //
                    // CAUTION! The following line CANNOT be used:
                    // *as = sizeof(struct sockaddr_un);
                    // because the compiler brings the error
                    // "invalid application of 'sizeof' to incomplete type 'struct sockaddr_un'".
                    // The reason is the "sun_path" field of the "sockaddr_un" structure,
                    // which is a character array whose size is unknown at compilation time.
                    //
                    // The size of the "sun_path" character array is therefore set
                    // to the fixed size of 108.
                    // The number "108" is the limit as set by the gnu c library!
                    // Its documentation called it a "magic number" and does not
                    // know why this limit exists.
                    //
                    // With the known type "short int" of the "sun_family" field and
                    // a fixed size "108" of the "sun_path" field, the overall size of
                    // the "sockaddr_un" structure can be calculated as sum.
                    calculate_integer_add(as, (void*) SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
                    calculate_integer_add(as, (void*) NUMBER_108_INTEGER_STATE_CYBOI_MODEL);

                    // Allocate address.
                    *ad = malloc(*as);

                    // Initialise address.
                    startup_bsd_socket_socket_address_local(*ad, p2, p3);
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket socket address. The address family is unknown.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket socket address. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket socket address. The address size is null.");
    }
}

/* SOCKET_ADDRESS_BSD_SOCKET_STARTER_SOURCE */
#endif
