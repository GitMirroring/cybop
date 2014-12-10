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

#ifndef FAMILY_SOCKET_STARTER_SOURCE
#define FAMILY_SOCKET_STARTER_SOURCE

#ifdef __APPLE__
    #include <sys/socket.h>
#elif WIN32
    #include <winsock.h>
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <sys/socket.h>
#else
    #include <sys/socket.h>
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cybol/socket/namespace_socket_cybol_model.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Converts family string into socket- and address integer.
 *
 * @param p0 the protocol family
 * @param p1 the address family
 * @param p2 the family data
 * @param p3 the family count
 */
void startup_socket_family(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket family.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The protocol family.
    //
    // CAUTION! The symbolic names (pre-processor-defined constants)
    // used below CANNOT be handed over as reference to a function
    // since otherwise, the compiler will show an error like:
    // error: lvalue required as unary ‘&’ operand
    //
    // Therefore, they are used to assign a value to this local variable,
    // which then gets copied to the destination parametre.
    int pf = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The address family.
    //
    // CAUTION! The symbolic names (pre-processor-defined constants)
    // used below CANNOT be handed over as reference to a function
    // since otherwise, the compiler will show an error like:
    // error: lvalue required as unary ‘&’ operand
    //
    // Therefore, they are used to assign a value to this local variable,
    // which then gets copied to the destination parametre.
    int af = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise protocol family.
    // CAUTION! This is IMPORTANT in case none of the values below matches.
    // Just leaving the zero assigned above might falsify the original value
    // that was handed over as argument to this function.
    copy_integer((void*) &pf, p0);
    // Initialise address family.
    // CAUTION! This is IMPORTANT in case none of the values below matches.
    // Just leaving the zero assigned above might falsify the original value
    // that was handed over as argument to this function.
    copy_integer((void*) &af, p1);

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p2, (void*) APPLETALK_NAMESPACE_SOCKET_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) APPLETALK_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            pf = PF_APPLETALK;
            af = AF_APPLETALK;
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p2, (void*) BLUETOOTH_NAMESPACE_SOCKET_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) BLUETOOTH_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

#ifdef __APPLE__
            pf = PF_BLUETOOTH;
            af = AF_BLUETOOTH;
#elif WIN32
            pf = PF_BTH;
            af = AF_BTH;
#elif GNU_LINUX_OPERATING_SYSTEM
            pf = PF_BLUETOOTH;
            af = AF_BLUETOOTH;
#else
            pf = PF_BLUETOOTH;
            af = AF_BLUETOOTH;
#endif
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p2, (void*) INET_NAMESPACE_SOCKET_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) INET_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            pf = PF_INET;
            af = AF_INET;
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p2, (void*) INET6_NAMESPACE_SOCKET_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) INET6_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            pf = PF_INET6;
            af = AF_INET6;
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p2, (void*) IPX_NAMESPACE_SOCKET_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) IPX_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            pf = PF_IPX;
            af = AF_IPX;
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p2, (void*) IRDA_NAMESPACE_SOCKET_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) IRDA_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

#ifdef __APPLE__
            pf = PF_IRDA;
            af = AF_IRDA;
#elif WIN32
            // CAUTION! With "winsock.h", these symbolic names are
            // NOT implemented in the windows operating system.
#elif GNU_LINUX_OPERATING_SYSTEM
            pf = PF_IRDA;
            af = AF_IRDA;
#else
            pf = PF_IRDA;
            af = AF_IRDA;
#endif
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p2, (void*) LOCAL_NAMESPACE_SOCKET_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) LOCAL_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

#ifdef __APPLE__
            // Alternatives: PF_LOCAL, PF_UNIX, PF_FILE
            pf = PF_LOCAL;
            af = AF_LOCAL;
#elif WIN32
            // CAUTION! The local or unix domain sockets are
            // NOT implemented in the windows operating system.
#elif GNU_LINUX_OPERATING_SYSTEM
            // Alternatives: PF_LOCAL, PF_UNIX, PF_FILE
            pf = PF_LOCAL;
            af = AF_LOCAL;
#else
            // Alternatives: PF_LOCAL, PF_UNIX, PF_FILE
            pf = PF_LOCAL;
            af = AF_LOCAL;
#endif
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p2, (void*) NETBIOS_NAMESPACE_SOCKET_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) NETBIOS_NAMESPACE_SOCKET_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

#ifdef __APPLE__
#elif WIN32
            //?? This is commented out since it is not known in "winsock.h".
            //?? TODO: Reactivate later, when using the "Winsock2.h".
            //?? pf = PF_NETBIOS;
            //?? af = AF_NETBIOS;
#elif GNU_LINUX_OPERATING_SYSTEM
#else
#endif
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket family. The family is not known.");
    }

/*?? TODO:
    PF_ASH          Ash
    PF_ATMPVC       ATM PVCs
    PF_ATMSVC       ATM SVCs
    PF_AX25         Amateur Radio AX.25
    PF_BRIDGE       Multiprotocol bridge
    PF_DECnet       Reserved for DECnet project
    PF_ECONET       Acorn Econet
    PF_KEY          PF_KEY key management API
    PF_NETBEUI      Reserved for 802.2LLC project
    PF_NETLINK, PF_ROUTE routing API
    PF_NETROM       Amateur radio NetROM
    PF_PACKET       Packet family
    PF_PPPOX        PPP over X sockets
    PF_ROSE         Amateur Radio X.25 PLP
    PF_SECURITY     Security callback pseudo AF
    PF_SNA          Linux SNA Project
    PF_WANPIPE      Wanpipe API sockets
    PF_X25          Reserved for X.25 project
*/

    // Assign protocol family.
    copy_integer(p0, (void*) &pf);
    // Assign address family.
    copy_integer(p1, (void*) &af);
}

/* FAMILY_SOCKET_STARTER_SOURCE */
#endif
