/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SOCKET_STARTER_SOURCE
#define SOCKET_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/maintainer/starter/socket/lifecycle_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up server socket.
 *
 * @param p0 the server entry
 * @param p1 the family data (namespace)
 * @param p2 the family count
 * @param p3 the style data (communication type)
 * @param p4 the style count
 * @param p5 the protocol data
 * @param p6 the protocol count
 * @param p7 the filename data
 * @param p8 the filename count
 * @param p9 the host address data
 * @param p10 the host address count
 * @param p11 the port (service identification)
 * @param p12 the connexions (number of possible pending client requests)
 * @param p13 the timeout
 */
void startup_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket.");

    //
    // Declaration.
    //

    // The socket number.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocation.
    //

    //
    // Allocate socket number.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    //
    // Opening.
    //

    // Startup server socket.
    startup_socket_lifecycle(s, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);

    //
    // Storage.
    //

    // Set socket number into server entry.
    copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_SOCKET_SERVER_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* SOCKET_STARTER_SOURCE */
#endif
