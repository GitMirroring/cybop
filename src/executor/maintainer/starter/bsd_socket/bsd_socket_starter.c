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

#ifndef BSD_SOCKET_STARTER_SOURCE
#define BSD_SOCKET_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/maintainer/starter/bsd_socket/family_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/style_bsd_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the bsd socket.
 *
 * @param p0 the internal memory data
 * @param p1 the family (namespace) data
 * @param p2 the family (namespace) count
 * @param p3 the style data
 * @param p4 the style count
 * @param p5 the host address or file name data, depending on the family
 * @param p6 the host address or file name count, depending on the family
 * @param p7 the port model
 * @param p8 the base internal
 */
void startup_bsd_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* base = (int*) p8;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket.");

        // The protocol family (socket namespace).
        int pf = PF_INET6;
        // The address family (namespace).
        int af = AF_INET6;
        // The communication style.
        int st = SOCK_STREAM;

        // Get protocol- and address family.
        startup_bsd_socket_family((void*) &pf, (void*) &af, p1, p2);
        // Get socket communication style.
        startup_bsd_socket_style((void*) &st, p3, p4);
        // CAUTION! The third parametre is the protocol,
        // for which a value of zero is usually right.
        startup_bsd_socket_create((void*) &pf, (void*) &st, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, host_address (network byte order), socket_port (host byte order), file_name_data, file_name_count, (void*) &af);

/*??
        //
        // CAUTION! Do use pointers for the addresses declared below,
        // and not only the structure as type, so that the different
        // socket addresses can be processed uniformly below!
        //
        // The communication partner local socket address.
        struct sockaddr_un* pla = (struct sockaddr_un*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner ipv4 internet socket address.
        struct sockaddr_in* pia4 = (struct sockaddr_in*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner ipv6 internet socket address.
        struct sockaddr_in6* pia6 = (struct sockaddr_in6*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner socket address size.
        int* pas = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The communication partner socket.
        int* ps = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The character buffer being used in the thread procedure receiving messages via socket.
        void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
        int* bc = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        int* bs = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The result.
        int r = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // Allocate communication partner socket address size.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &pas, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Allocate socket of this system.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Allocate communication partner socket.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &ps, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Initialise communication partner socket address size.
        copy_integer(pas, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (af == AF_LOCAL) {

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
            calculate_integer_add(pas, (void*) SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
            calculate_integer_add(pas, (void*) NUMBER_108_INTEGER_STATE_CYBOI_MODEL);

        } else if (af == AF_INET) {

            calculate_integer_add(pas, (void*) INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);

        } else if (af == AF_INET6) {

            calculate_integer_add(pas, (void*) INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE);
        }

        // Allocate socket address of this system.
        // Allocate communication partner socket address.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        if (af == AF_LOCAL) {

            pla = (struct sockaddr_un*) malloc(*pas);

        } else if (af == AF_INET) {

            pia4 = (struct sockaddr_in*) malloc(*pas);

        } else if (af == AF_INET6) {

            pia6 = (struct sockaddr_in6*) malloc(*pas);
        }

        // Initialise socket address of this system.
        // CAUTION! Do NOT initialise communication partner socket address!
        // It gets initialised only before sending, or at reception of a message.

        // Allocate character buffer count and size.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate((void*) &bc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate((void*) &bs, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Initialise character buffer count, size.
        // A possible initial size is 2048, which should
        // suffice for transferring standard data over tcp/ip.
        // Another possible size could be 8192.
        copy_integer(bc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        copy_integer(bs, (void*) NUMBER_2048_INTEGER_STATE_CYBOI_MODEL);

        // Allocate character buffer.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        // CAUTION! Allocate character buffer only AFTER
        // the buffer size has been initialised above!
        allocate((void*) &b, (void*) bs, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Set socket address of this system.
        // Set communication partner socket address.
        if (af == AF_LOCAL) {

            i = *base + *DATA_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &la, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *base + *ADDRESS_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &pla, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else if (af == AF_INET) {

            i = *base + *DATA_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &ia4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *base + *ADDRESS_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &pia4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else if (af == AF_INET6) {

            i = *base + *DATA_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &ia6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *base + *ADDRESS_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) &pia6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }

        // Set socket address size of this system.
        i = *base + *SIZE_ADDRESS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &as, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set communication partner socket address size.
        i = *base + *ADDRESS_SIZE_COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &pas, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set socket of this system.
        i = *base + *SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set communication partner socket.
        i = *base + *COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &ps, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set character buffer.
        i = *base + *DATA_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        i = *base + *COUNT_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &bc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        i = *base + *SIZE_CHARACTER_BUFFER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
        copy_array_forward(p0, (void*) &bs, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
*/

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket. The base internal is null.");
    }
}

/* BSD_SOCKET_STARTER_SOURCE */
#endif
