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

#ifndef SOCKET_ADDRESS_SOCKET_STARTER_SOURCE
#define SOCKET_ADDRESS_SOCKET_STARTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../../executor/maintainer/starter/socket/socket_address/inet_socket_address_socket_starter.c"
//?? TODO: This ifndef can be removed as soon as the mingw compiler supports ipv6.
#ifndef WIN32
    #include "../../../../../executor/maintainer/starter/socket/socket_address/inet6_socket_address_socket_starter.c"
#endif
#include "../../../../../logger/logger.c"

#ifdef __APPLE__
    #include "../../../../../executor/maintainer/starter/socket/socket_address/local_socket_address_socket_starter.c"
#elif WIN32
    // CAUTION! The local or unix domain sockets are
    // NOT implemented in the windows operating system.
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../../executor/maintainer/starter/socket/socket_address/local_socket_address_socket_starter.c"
#else
    #include "../../../../../executor/maintainer/starter/socket/socket_address/local_socket_address_socket_starter.c"
#endif

/**
 * Startup socket address depending on the given address family.
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
 * @param p2 the filename data
 * @param p3 the filename count
 * @param p4 the host address data
 * @param p5 the host address count
 * @param p6 the port
 * @param p7 the address family (namespace)
 */
void startup_socket_socket_address(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* as = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** ad = (void**) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket socket address.");

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_BLUETOOTH);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //?? TODO: struct sockaddr_bth for Bluetooth
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_INET);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    startup_socket_socket_address_inet(p0, p1, p4, p5, p6);
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_INET6);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? TODO: This ifndef can be removed as soon as the mingw compiler supports ipv6.
#ifndef WIN32
                    startup_socket_socket_address_inet6(p0, p1, p4, p5, p6);
#endif
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_IRDA);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //?? TODO
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p7, (void*) AF_LOCAL);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#ifdef __APPLE__
                    startup_socket_socket_address_local(p0, p1, p2, p3);
#elif WIN32
                    // CAUTION! The local or unix domain sockets are
                    // NOT implemented in the windows operating system.
#elif GNU_LINUX_OPERATING_SYSTEM
                    startup_socket_socket_address_local(p0, p1, p2, p3);
#else
                    startup_socket_socket_address_local(p0, p1, p2, p3);
#endif
                }
            }

            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address. The address family is unknown.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address. The address data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address. The address size is null.");
    }
}

/* SOCKET_ADDRESS_SOCKET_STARTER_SOURCE */
#endif
