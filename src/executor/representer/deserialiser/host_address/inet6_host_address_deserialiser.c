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

#ifndef INET6_HOST_ADDRESS_DESERIALISER_SOURCE
#define INET6_HOST_ADDRESS_DESERIALISER_SOURCE

#include <stdint.h> // uint32_t

#if defined(__linux__) || defined(__unix__)
    #include <netinet/in.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <netinet/in.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <winsock.h>
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/checker/operation_checker.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/symbolic_name/address_family_socket_symbolic_name.c"

/**
 * Deserialises inet6 host address.
 *
 * The internet (host) address is converted from
 * textual (presentation) to binary (network) format.
 *
 * CAUTION! It has to be made sure that the host address is
 * represented in a canonical format called "NETWORK BYTE ORDER".
 * That is specified by the internet protocols as convention
 * for data transmitted over the network, so that machines
 * with different byte order conventions can communicate.
 *
 * It would actually be possible to convert the host address
 * later and use HOST byte order for loopback and any.
 * But since the "inet_pton" function used below for
 * directly input addresses returns its address in
 * NETWORK byte order, that was used for local and any as well.
 *
 * @param p0 the inet6 host address (in network byte order)
 * @param p1 the host address data
 * @param p2 the host address count
 */
void deserialise_host_address_inet6(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

//?? TODO: This ifndef can be removed as soon as the mingw compiler supports ipv6.
#ifndef _WIN32
        //
        // This data type is used to store an IPv6 address.
        // It stores 128 bits of data, which can be
        // accessed via a union in a variety of ways.
        //
        struct in6_addr* a = (struct in6_addr*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise host address inet6.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_operation((void*) &r, p1, (void*) LOOPBACK_ADDRESS_SOCKET_CYBOL_MODEL, p2, (void*) LOOPBACK_ADDRESS_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Assign address.
                //
                // One can use the in6addr_loopback constant
                // to stand for the address of this machine,
                // instead of finding its actual address.
                // It is the IPv6 Internet address '::1',
                // which is usually called 'localhost'.
                // This special constant saves the trouble of
                // looking up the address of one's own machine.
                // Also, the system usually implements it specially,
                // avoiding any network traffic for the case
                // of one machine talking to itself.
                //
                // CAUTION! While ipv4 constants are all defined in host byte order,
                // the ipv6 constants are already defined in NETWORK byte order,
                // so that a conversion is NOT necessary here:
                // http://www.questionscompiled.com/ipv6-socket-api.html
                //
                *a = in6addr_loopback;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            check_operation((void*) &r, p1, (void*) ANY_ADDRESS_SOCKET_CYBOL_MODEL, p2, (void*) ANY_ADDRESS_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Assign address.
                //
                // One can use the in6addr_any constant to stand
                // for any incoming address, when binding to an address.
                // It is the IPv6 address '::', the unspecified address.
                // This is the usual address to give in
                // the sin_addr member of struct sockaddr_in
                // when you want to accept Internet connections.
                //
                // CAUTION! While ipv4 constants are all defined in host byte order,
                // the ipv6 constants are already defined in NETWORK byte order,
                // so that a conversion is NOT necessary here:
                // http://www.questionscompiled.com/ipv6-socket-api.html
                //
                *a = in6addr_any;
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // If none of the above address models was found, then the given
            // address is supposed to be the host address directly.
            //

            // The terminated address item.
            void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The terminated address item data.
            void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
            //
            // The internet address in network (binary) format.
            //
            // CAUTION! While ipv4 constants are all defined in host byte order,
            // the ipv6 constants are already defined in NETWORK byte order,
            // so that a conversion is NOT necessary here:
            // http://www.questionscompiled.com/ipv6-socket-api.html
            //
            // CAUTION! The loopback is used as default here.
            //
            struct in6_addr n = in6addr_loopback;

            //
            // Allocate terminated address item.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

            // Encode wide character name into multibyte character array.
            encode_utf_8(t, p1, p2);

            // Add null termination character.
            modify_item(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            //
            // Get terminated address item data.
            //
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            //
            copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            //
            // Convert internet address from presentation (textual)
            // to network (binary) format, the latter being an integer.
            //
            // CAUTION! The returned value is already in NETWORK byte order.
            //
            inet_pton(*INET6_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME, (char*) td, (void*) &n);

            // Assign address.
            *a = n;

            // Deallocate terminated address item.
            deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        }
#endif

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise host address inet6. The inet6 host address is null.");
    }
}

/* INET6_HOST_ADDRESS_DESERIALISER_SOURCE */
#endif
