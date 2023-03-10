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

#ifndef SOCKET_ADDRESS_ALLOCATOR_SOURCE
#define SOCKET_ADDRESS_ALLOCATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/memoriser/allocator/socket_address/inet_socket_address_allocator.c"
//
//?? TODO: This ifndef can be removed as soon as the mingw compiler supports ipv6.
//
#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/memoriser/allocator/socket_address/inet6_socket_address_allocator.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/memoriser/allocator/socket_address/inet6_socket_address_allocator.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    // Empty, since the mingw compiler does NOT support ipv6.
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
#include "../../../../logger/logger.c"
#include "../../../../variable/symbolic_name/address_family_socket_symbolic_name.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/memoriser/allocator/socket_address/local_socket_address_allocator.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/memoriser/allocator/socket_address/local_socket_address_allocator.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    //
    // CAUTION! The local or unix domain sockets are
    // NOT implemented in the windows operating system.
    //
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Allocates a socket address depending on the given address family.
 *
 * A socket address is handed over as argument of type
 * "struct sockaddr" to functions like: bind, connect, sendto.
 * The functions that use "struct sockaddr" will only read
 * the field "sa_family" and do the opposite cast internally:
 *
 * https://stackoverflow.com/questions/13723971/struct-type-conversion-in-c
 *
 * However, an allocated variable of type "struct sockaddr"
 * is NOT able to represent all kinds of socket addresses,
 * since many types have BIGGER SIZES.
 *
 * Therefore, the type "struct sockaddr_storage" was introduced
 * to serve as universal store for address information of any kind.
 * It is as large as the largest address type in an architecture:
 *
 * https://stackoverflow.com/questions/8835322/api-using-sockaddr-storage
 * http://msdn.microsoft.com/en-us/library/windows/desktop/ms740504%28v=vs.85%29.aspx
 *
 * But in order to gain independence and flexibility, it was decided
 * NOT to use "struct sockaddr_storage" on the function's stack memory,
 * but rather allocate space manually on the heap memory.
 *
 * @param p0 the socket address data (pointer reference)
 * @param p1 the socket address size
 * @param p2 the port
 * @param p3 the host address data (network communication) OR filename data (local unix domain socket)
 * @param p4 the host address count (network communication) OR filename count (local unix domain socket)
 * @param p5 the address family (namespace)
 */
void allocate_socket_address(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** ad = (void**) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate socket address.");

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p5, (void*) BLUETOOTH_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //?? TODO: struct sockaddr_bth for Bluetooth
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p5, (void*) INET_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    allocate_socket_address_inet(p0, p1, p2, p3, p4);
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p5, (void*) INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? TODO: This ifndef can be removed as soon as the mingw compiler supports ipv6.
#ifndef _WIN32
                    allocate_socket_address_inet6(p0, p1, p2, p3, p4);
#endif
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p5, (void*) IRDA_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //?? TODO
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p5, (void*) LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#if defined(__linux__) || defined(__unix__)
                    allocate_socket_address_local(p0, p1, p3, p4);
#elif defined(__APPLE__) && defined(__MACH__)
                    allocate_socket_address_local(p0, p1, p3, p4);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
                    // CAUTION! The local or unix domain sockets are
                    // NOT implemented in the windows operating system.
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate socket address. The address family is unknown.");
                fwprintf(stdout, L"Warning: Could not allocate socket address. The address family is unknown. r: %i\n", r);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate socket address. The address data is null.");
            fwprintf(stdout, L"Error: Could not allocate socket address. The address data is null. p0: %i\n", p0);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate socket address. The address size is null.");
        fwprintf(stdout, L"Error: Could not allocate socket address. The address size is null. p1: %i\n", p1);
    }
}

/* SOCKET_ADDRESS_ALLOCATOR_SOURCE */
#endif
