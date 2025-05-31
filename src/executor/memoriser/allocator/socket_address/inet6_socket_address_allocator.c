/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <string.h> // memset
#include <wchar.h> // fwprintf

#if defined(__linux__) || defined(__unix__)
    #include <netinet/in.h> // struct in6_addr
#elif defined(__APPLE__) && defined(__MACH__)
    #include <netinet/in.h> // struct in6_addr
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <winsock.h> // struct in6_addr
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "variable.h"

//
// Forward declaration
//

void deserialise_host_address_inet6(void* p0, void* p1, void* p2);

/**
 * Allocate inet6 socket address.
 *
 * @param p0 the socket address data (pointer reference)
 * @param p1 the socket address size
 * @param p2 the port
 * @param p3 the host address data
 * @param p4 the host address count
 */
void allocate_socket_address_inet6(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** ad = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate socket address inet6.");

        // The host address.
        struct in6_addr ha;
        //
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
        //
        size_t has = (size_t) *IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE;
        //
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
        //
        memset((void*) &ha, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, has);
        //
        // Get host address.
        //
        // CAUTION! The returned host address
        // is already in network byte order.
        //
        deserialise_host_address_inet6((void*) &ha, p3, p4);

        //
        // Allocate socket address.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IPV6_SOCKET_ADDRESS_STATE_CYBOI_TYPE);
        //
        // Initialise socket address size.
        //
        // CAUTION! For the allocation above, the size gets determined inside
        // the "allocate_array" function, so that it is not needed as argument.
        // However, socket functions DO REQUIRE the socket address size
        // as argument, so that it has to be assigned here explicitly.
        //
        copy_integer(p1, (void*) IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
        //
        // Initialise socket address.
        //
        // CAUTION! The forwarded host address
        // is already in network byte order.
        //
        set_socket_address_inet6(*ad, (void*) &ha, p2);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate socket address inet6. The address data is null.");
        fwprintf(stdout, L"Error: Could not allocate socket address inet6. The address data is null. p0: %i\n", p0);
    }
}
