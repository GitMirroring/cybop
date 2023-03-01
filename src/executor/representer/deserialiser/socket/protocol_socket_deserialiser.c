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

#ifndef PROTOCOL_SOCKET_DESERIALISER_SOURCE
#define PROTOCOL_SOCKET_DESERIALISER_SOURCE

#if defined(__linux__) || defined(__unix__)
    #include <sys/socket.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/socket.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <winsock.h>
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cybol/socket/protocol_socket_cybol_model.c"
#include "../../../../executor/checker/operation_checker.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Converts protocol string into integer.
 *
 * @param p0 the protocol
 * @param p1 the protocol data
 * @param p2 the protocol count
 */
void deserialise_socket_protocol(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise socket protocol.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The protocol.
    //
    // CAUTION! The symbolic names (pre-processor-defined constants)
    // used below CANNOT be handed over as reference to a function
    // since otherwise, the compiler will show an error like:
    // error: lvalue required as unary ‘&’ operand
    //
    // Therefore, they are used to assign a value to this local variable,
    // which then gets copied to the destination parametre.
    //
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Initialise protocol.
    //
    // CAUTION! This is IMPORTANT in case none of the values below matches.
    // Just leaving the zero assigned above might falsify the original value
    // that was handed over as argument to this function.
    //
    copy_integer((void*) &p, p0);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) BTHPROTO_RFCOMM_PROTOCOL_SOCKET_CYBOL_MODEL, p2, (void*) BTHPROTO_RFCOMM_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? p = BTHPROTO_RFCOMM;
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) ICMP_PROTOCOL_SOCKET_CYBOL_MODEL, p2, (void*) ICMP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            p = IPPROTO_ICMP;
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) ICMPV6_PROTOCOL_SOCKET_CYBOL_MODEL, p2, (void*) ICMPV6_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? TODO: This ifndef can be removed as soon as the mingw compiler supports ipv6.
#ifndef _WIN32
            p = IPPROTO_ICMPV6;
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) IGMP_PROTOCOL_SOCKET_CYBOL_MODEL, p2, (void*) IGMP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            p = IPPROTO_IGMP;
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) RAW_PROTOCOL_SOCKET_CYBOL_MODEL, p2, (void*) RAW_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            p = IPPROTO_RAW;
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) RM_PROTOCOL_SOCKET_CYBOL_MODEL, p2, (void*) RM_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? p = IPPROTO_RM;
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) TCP_PROTOCOL_SOCKET_CYBOL_MODEL, p2, (void*) TCP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            p = IPPROTO_TCP;
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) UDP_PROTOCOL_SOCKET_CYBOL_MODEL, p2, (void*) UDP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            p = IPPROTO_UDP;
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise socket protocol. The protocol is not known.");
    }

    // Assign protocol.
    copy_integer(p0, (void*) &p);
}

/* PROTOCOL_SOCKET_DESERIALISER_SOURCE */
#endif
