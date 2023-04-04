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

#ifndef STARTER_SOURCE
#define STARTER_SOURCE

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
 * Starts up the given server.
 *
 * CAUTION! Do NOT rename this function to "startup",
 * since it should be consistent with "shutdown_server",
 * which cannot be renamed to "shutdown",
 * as that name is already used by low-level socket functionality:
 * /usr/include/i386-linux-gnu/sys/socket.h:232:12
 *
 * @param p0 the internal memory
 * @param p1 the port (service identification)
 * @param p2 the host address data (network communication) OR filename data (local unix domain socket)
 * @param p3 the host address count (network communication) OR filename count (local unix domain socket)
 * @param p4 the family data (namespace)
 * @param p5 the family count
 * @param p6 the style data (communication type)
 * @param p7 the style count
 * @param p8 the protocol data
 * @param p9 the protocol count
 * @param p10 the connexions (number of possible pending client requests)
 * @param p11 the socket timeout
 * @param p12 the channel
 * @param p13 the internal memory (pointer reference)
 */
void startup_server(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup server.");
    //?? fwprintf(stdout, L"Information: Startup server. p1: %i\n", p1);
    //?? fwprintf(stdout, L"Information: Startup server. *p1: %i\n", *((int*) p1));

    // The internal memory name.
    int n = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server list.
    void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get internal memory name by channel.
    map_channel_to_internal_memory((void*) &n, p12);
    // Get input output entry from internal memory.
    copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &n);
    // Get server list from input output entry.
    copy_array_forward((void*) &sl, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVERS_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get server entry from server list by service identification (port number).
    find_list((void*) &se, sl, p1, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME);

    if (se == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Allocate server entry.
        allocate_server_entry((void*) &se);

        // Initialise server entry.
        startup_entry(se, p1, p12, p13, (void*) &io);

        // Startup service.
        startup_service(se, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p12);

        // Append server entry to server list.
        modify_item(sl, (void*) &se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup server. A server entry with the given service identification (port) does already exist.");
        fwprintf(stdout, L"Warning: Could not startup server. A server entry with the given service identification (port) does already exist. p1: %i\n", p1);
        fwprintf(stdout, L"Warning: Could not startup server. A server entry with the given service identification (port) does already exist. *p1: %i\n", *((int*) p1));
    }
}

/* STARTER_SOURCE */
#endif
