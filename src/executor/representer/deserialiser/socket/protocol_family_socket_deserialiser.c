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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PROTOCOL_FAMILY_SOCKET_DESERIALISER_SOURCE
#define PROTOCOL_FAMILY_SOCKET_DESERIALISER_SOURCE

//
// System interface
//

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

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "variable.h"

//
// On the difference between prefix AF_ and PF_:
//
// The original design concept of the socket interface
// distinguished between protocol types (families) and
// the specific address types that each may use.
//
// It was envisioned that a protocol family may have
// several address types. Address types were defined by
// additional symbolic constants, using the prefix AF_
// instead of PF_. The AF_-identifiers are intended
// for all data structures that specifically deal with
// the address type and not the protocol family.
//
// However, this concept of separation of protocol
// and address type has not found implementation support
// and the AF_-constants were simply defined by the
// corresponding protocol identifier, rendering the
// distinction between AF_ versus PF_ constants a technical
// argument of no significant practical consequence.
//
// Indeed, much confusion exists in the proper usage of both forms.
// However, the current POSIX.1—2008 specification doesn't
// specify any of PF_-constants, but only AF_-constants.
//
// https://en.wikipedia.org/wiki/Berkeley_sockets#Protocol_and_address_families
//

/**
 * Converts namespace (family) string into protocol integer.
 *
 * @param p0 the protocol family
 * @param p1 the family data
 * @param p2 the family count
 */
void deserialise_socket_family_protocol(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise socket family protocol.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) APPLETALK_NAMESPACE_SOCKET_CYBOL_MODEL, p2, (void*) APPLETALK_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) APPLETALK_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) BLUETOOTH_NAMESPACE_SOCKET_CYBOL_MODEL, p2, (void*) BLUETOOTH_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) BLUETOOTH_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) INET_NAMESPACE_SOCKET_CYBOL_MODEL, p2, (void*) INET_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INET_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) INET6_NAMESPACE_SOCKET_CYBOL_MODEL, p2, (void*) INET6_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INET6_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) IPX_NAMESPACE_SOCKET_CYBOL_MODEL, p2, (void*) IPX_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) IPX_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) IRDA_NAMESPACE_SOCKET_CYBOL_MODEL, p2, (void*) IRDA_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) IRDA_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) LOCAL_NAMESPACE_SOCKET_CYBOL_MODEL, p2, (void*) LOCAL_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Alternatives: PF_LOCAL, PF_UNIX, PF_FILE
            copy_integer(p0, (void*) LOCAL_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) NETBIOS_NAMESPACE_SOCKET_CYBOL_MODEL, p2, (void*) NETBIOS_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NETBIOS_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise socket family protocol. The family is not known.");
    }
}

/* PROTOCOL_FAMILY_SOCKET_DESERIALISER_SOURCE */
#endif
