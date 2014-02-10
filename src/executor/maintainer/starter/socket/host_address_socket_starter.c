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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HOST_ADDRESS_SOCKET_STARTER_SOURCE
#define HOST_ADDRESS_SOCKET_STARTER_SOURCE

#ifdef __APPLE__
    //?? Check support for apple
#elif WIN32
    //?? Add WIN32 support
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <unistd.h>
#else
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <unistd.h>
#endif

#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

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
 * Starts up socket host address.
 *
 * @param p0 the ipv4 or ipv6 host address, depending on the address namespace (pointer reference)
 * @param p1 the address model data
 * @param p2 the address model count
 * @param p3 the address namespace
 */
void startup_socket_host_address(void* p0, void* p1, void* p2, void* p3) {

    // This test IS necessary, since the host address is assigned directly,
    // using the assignment operator and not a copy function.
    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket host address.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The ipv4 address.
        struct in_addr* a4 = (struct in_addr*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The ipv6 address.
        struct in6_addr* a6 = (struct in6_addr*) *NULL_POINTER_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p3, (void*) &AF_INET);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                a4 = (struct in_addr*) p0;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p3, (void*) &AF_INET6);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                a6 = (struct in6_addr*) p0;
            }
        }

        // The second comparison result.
        int r2 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r2 == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r2, p1, (void*) LOOPBACK_ADDRESS_CYBOL_MODEL);

            if (r2 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Reset comparison result.
                r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    compare_integer_equal((void*) &r, p3, (void*) &AF_INET);

                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        (*a4).s_addr = INADDR_LOOPBACK;
                    }
                }

                if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    compare_integer_equal((void*) &r, p3, (void*) &AF_INET6);

                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        *a6 = in6addr_loopback;
                    }
                }
            }
        }

        if (r2 == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r2, p1, (void*) ANY_ADDRESS_CYBOL_MODEL);

            if (r2 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Reset comparison result.
                r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    compare_integer_equal((void*) &r, p3, (void*) &AF_INET);

                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        (*a4).s_addr = INADDR_ANY;
                    }
                }

                if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    compare_integer_equal((void*) &r, p3, (void*) &AF_INET6);

                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        *a6 = in6addr_any;
                    }
                }
            }
        }

        if (r2 == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // If none of the above address models was found, then the given
            // address is supposed to be the host address directly.

            // The terminated address item.
            void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The terminated address item data.
            void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate terminated address item.
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

            // Encode wide character name into multibyte character array.
            encode_utf_8(s, p1, p2);

            // Add null termination character.
            append_item_element(s, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Get terminated address item data.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            // Convert uint16_t integer hostshort from host byte order
            // to network byte order.
            inet_pton(*((int*) p3), (char*) sd, p0);

            // Deallocate terminated address item.
            deallocate_item((void*) &s, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket host address. The host address is null.");
    }
}

/* HOST_ADDRESS_SOCKET_STARTER_SOURCE */
#endif
