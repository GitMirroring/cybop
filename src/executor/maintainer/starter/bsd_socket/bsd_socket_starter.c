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
#include "../../../../executor/maintainer/starter/bsd_socket/create_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/family_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/style_bsd_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the bsd socket.
 *
 * @param p0 the internal memory data (pointer reference)
 * @param p1 the family data (namespace)
 * @param p2 the family count
 * @param p3 the style data
 * @param p4 the style count
 * @param p5 the filename data
 * @param p6 the filename count
 * @param p7 the host address data
 * @param p8 the host address count
 * @param p9 the port
 * @param p10 the internal memory base
 */
void startup_bsd_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    // The socket.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Calculate internal memory index.
    copy_integer((void*) &i, p10);
    calculate_integer_add((void*) &i, (void*) SERVER_INDEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get socket.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    // Only create socket if not existent.
    if (s == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket.");

        // The socket.
        int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
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
        // Create socket.
        // CAUTION! A value of ZERO is usually right for the "protocol".
        startup_bsd_socket_create((void*) &s, (void*) &pf, (void*) &st, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p5, p6, p7, p8, p9, (void*) &af);

        // Store socket in internal memory.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the internal array's count and size are CONSTANT.
        copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket. The socket at the given internal memory base (port) already exists.");
    }
}

/* BSD_SOCKET_STARTER_SOURCE */
#endif
