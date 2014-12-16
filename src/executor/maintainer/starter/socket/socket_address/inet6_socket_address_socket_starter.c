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

#ifndef INET6_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE
#define INET6_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE

#include <stddef.h> // size_t
#include <stdlib.h> // malloc
#include <string.h> // memset

#ifdef __APPLE__
    #include <netinet/in.h>
#elif WIN32
    #include <winsock.h>
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <netinet/in.h>
#else
    #include <netinet/in.h>
#endif

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/maintainer/starter/socket/host_address/inet6_host_address_socket_starter.c"
#include "../../../../../executor/maintainer/starter/socket/socket_address/initialise_inet6_socket_address_socket_starter.c"
#include "../../../../../logger/logger.c"
#include "../../../../../variable/type_size/socket_type_size.c"

/**
 * Startup inet6 socket address.
 *
 * @param p0 the socket address data (pointer reference)
 * @param p1 the socket address size
 * @param p2 the host address data
 * @param p3 the host address count
 * @param p4 the port
 */
void startup_socket_socket_address_inet6(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** ad = (void**) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket socket address inet6.");

            // The host address.
            struct in6_addr ha;
            // The host address size.
            //
            // CAUTION! It IS NECESSARY because on 64 Bit machines,
            // the "size_t" type has a size of 8 Byte,
            // whereas the "int" type has the usual size of 4 Byte.
            // When trying to cast between the two, memory errors
            // will occur and the valgrind memcheck tool report:
            // "Invalid read of size 8".
            //
            // CAUTION! Initialise temporary size_t variable with final int value
            // JUST BEFORE handing that over to the glibc function requiring it.
            //
            // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
            // because values are casted to int* internally again.
            size_t has = (size_t) *IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE;
            // Initialise array elements.
            //
            // CAUTION! Initialising with zero values is essential,
            // since cyboi frequently tests variables for null pointer values.
            // Otherwise, unpredictable pre-existing values might reside in memory.
            //
            // Whether the values will be interpreted as
            // zero integer or zero float or null pointer or
            // something else, depends on the programming
            // context, i.e. where the array got allocated.
            memset((void*) &ha, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, has);
            // Get host address.
            // CAUTION! The returned host address
            // is already in network byte order.
            startup_socket_host_address_inet6((void*) &ha, p2, p3);

            // Initialise socket address size.
            copy_integer(p1, (void*) IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
            // The temporary size_t variable.
            //
            // CAUTION! It IS NECESSARY because on 64 Bit machines,
            // the "size_t" type has a size of 8 Byte,
            // whereas the "int" type has the usual size of 4 Byte.
            // When trying to cast between the two, memory errors
            // will occur and the valgrind memcheck tool report:
            // "Invalid read of size 8".
            //
            // CAUTION! Initialise temporary size_t variable with final int value
            // JUST BEFORE handing that over to the glibc function requiring it.
            //
            // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
            // because values are casted to int* internally again.
            size_t tas = (size_t) *as;
            // Allocate socket address.
            *ad = malloc(tas);
            // Initialise array elements.
            //
            // CAUTION! Initialising with zero values is essential,
            // since cyboi frequently tests variables for null pointer values.
            // Otherwise, unpredictable old values might reside in memory.
            //
            // Whether the values will be interpreted as
            // zero integer or zero float or null pointer or
            // something else, depends on the programming
            // context, i.e. where the array got allocated.
            memset(*ad, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, tas);
            // Initialise socket address.
            // CAUTION! The forwarded host address
            // is already in network byte order.
            startup_socket_socket_address_inet6_initialise(*ad, (void*) &ha, p4);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address inet6. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address inet6. The address size is null.");
    }
}

/* INET6_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE */
#endif
