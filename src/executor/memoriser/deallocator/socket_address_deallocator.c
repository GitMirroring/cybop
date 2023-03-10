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

#ifndef SOCKET_ADDRESS_DEALLOCATOR_SOURCE
#define SOCKET_ADDRESS_DEALLOCATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/symbolic_name/address_family_socket_symbolic_name.c"

/**
 * Deallocates the socket address.
 *
 * @param p0 the socket address data (pointer reference)
 * @param p1 the socket address size
 * @param p2 the address family (namespace)
 */
void deallocate_socket_address(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** ad = (void**) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deallocate socket address.");
            //?? fwprintf(stdout, L"Debug: Deallocate socket address. p2: %i\n", p2);
            //?? fwprintf(stdout, L"Debug: Deallocate socket address. *p2: %i\n", *((int*) p2));

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p2, (void*) BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //?? TODO: struct sockaddr_bth for Bluetooth
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p2, (void*) INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //
                    // Deallocate socket address.
                    //
                    // CAUTION! The second argument "count" is NULL,
                    // since it is only needed for looping elements of type PART,
                    // in order to decrement the rubbish (garbage) collection counter.
                    //
                    deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, (void*) IPV4_SOCKET_ADDRESS_STATE_CYBOI_TYPE);
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p2, (void*) INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? TODO: This ifndef can be removed as soon as the mingw compiler supports ipv6.
#ifndef _WIN32
                    //
                    // Deallocate socket address.
                    //
                    // CAUTION! The second argument "count" is NULL,
                    // since it is only needed for looping elements of type PART,
                    // in order to decrement the rubbish (garbage) collection counter.
                    //
                    deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, (void*) IPV6_SOCKET_ADDRESS_STATE_CYBOI_TYPE);
#endif
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p2, (void*) IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //?? TODO
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p2, (void*) LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#if defined(__linux__) || defined(__unix__)
                    //
                    // Deallocate socket address.
                    //
                    // CAUTION! The second argument "count" is NULL,
                    // since it is only needed for looping elements of type PART,
                    // in order to decrement the rubbish (garbage) collection counter.
                    //
                    deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, (void*) LOCAL_SOCKET_ADDRESS_STATE_CYBOI_TYPE);
#elif defined(__APPLE__) && defined(__MACH__)
                    //
                    // Deallocate socket address.
                    //
                    // CAUTION! The second argument "count" is NULL,
                    // since it is only needed for looping elements of type PART,
                    // in order to decrement the rubbish (garbage) collection counter.
                    //
                    deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, (void*) LOCAL_SOCKET_ADDRESS_STATE_CYBOI_TYPE);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
                    //
                    // CAUTION! The local or unix domain sockets are
                    // NOT implemented in the windows operating system.
                    //
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate socket address. The address family is unknown.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate socket address. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deallocate socket address. The address size is null.");
    }
}

/* SOCKET_ADDRESS_DEALLOCATOR_SOURCE */
#endif
