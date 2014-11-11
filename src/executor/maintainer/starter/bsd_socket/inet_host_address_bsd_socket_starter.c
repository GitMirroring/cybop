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

#ifndef INET_HOST_ADDRESS_BSD_SOCKET_STARTER_SOURCE
#define INET_HOST_ADDRESS_BSD_SOCKET_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Determines inet host address.
 *
 * @param p0 the inet host address
 * @param p1 the host address data
 * @param p2 the host address count
 */
void startup_bsd_socket_host_address_inet(void* p0, void* p1, void* p2) {

    // This test IS necessary, since the host address is assigned directly,
    // using the assignment operator and not a copy function.
    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        struct in_addr* a = (struct in_addr*) p0;
        struct in6_addr* a = (struct in6_addr*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket host address inet.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_all_array((void*) &r, p1, (void*) LOOPBACK_ADDRESS_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) LOOPBACK_ADDRESS_CYBOL_MODEL_COUNT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                (*a).s_addr = INADDR_LOOPBACK;
                *a = in6addr_loopback;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_all_array((void*) &r, p1, (void*) ANY_ADDRESS_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ANY_ADDRESS_CYBOL_MODEL_COUNT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                (*a).s_addr = INADDR_ANY;
                *a = in6addr_any;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // If none of the above address models was found, then the given
            // address is supposed to be the host address directly.

            // The terminated address item.
            void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The terminated address item data.
            void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate terminated address item.
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

            // Encode wide character name into multibyte character array.
            encode_utf_8(t, p1, p2);

            // Add null termination character.
            append_item_element(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Get terminated address item data.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            // Convert uint16_t integer hostshort from host byte order
            // to network byte order.
            //
            // CAUTION! It is the caller's responsibility to make sure
            // the destination parametre p0 is large enough.
            inet_pton(AF_INET, (char*) td, p0);
            inet_pton(AF_INET6, (char*) td, p0);

            // Deallocate terminated address item.
            deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket host address inet. The host address is null.");
    }
}

/* INET_HOST_ADDRESS_BSD_SOCKET_STARTER_SOURCE */
#endif
