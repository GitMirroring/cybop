/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "algorithm.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "mapper.h"
#include "server.h"

/**
 * Disables the service on the given channel.
 *
 * @param p0 the internal memory
 * @param p1 the port (service identification)
 * @param p2 the channel
 */
void disable(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Disable.");
    //?? fwprintf(stdout, L"Information: Disable. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Information: Disable. *p2: %i\n", *((int*) p2));

    //
    // Declaration
    //

    // The internal memory name.
    int n = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server list.
    void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get internal memory name by channel.
    map_channel_to_internal_memory((void*) &n, p2);
    // Get input output entry from internal memory.
    copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &n);
    // Get server list from input output entry.
    copy_array_forward((void*) &sl, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVERS_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get server entry from server list by service identification (port number).
    find_list((void*) &se, sl, p1, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME);

    if (se != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Disable service by exiting enable thread.
        disable_thread(se);

        //
        // CAUTION! Do NOT close the clients of this service here.
        //
        // The enable service is just disabled (suspended),
        // but it might get enabled (resumed) again later.
        //
        // For disabling this service AND closing all clients,
        // this service has to be SHUT DOWN.
        //

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not disable. A server entry with the given service identification (port) does not exist.");
        fwprintf(stdout, L"Warning: Could not disable. A server entry with the given service identification (port) does not exist. p1: %i\n", p1);
    }
}
