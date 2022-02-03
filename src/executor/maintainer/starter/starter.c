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

#ifndef STARTER_SOURCE
#define STARTER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/maintainer/channel_starter.c"
#include "../../executor/maintainer/general_starter.c"
#include "../../logger/logger.c"

/**
 * Starts up the given server.
 *
 * CAUTION! Do NOT rename this function to "startup",
 * since it should be consistent with "shutdown_server",
 * which cannot be renamed to "shutdown",
 * as that name is already used by low-level socket functionality:
 * /usr/include/i386-linux-gnu/sys/socket.h:232:12
 *
 * @param p0 the internal memory (pointer reference)
 * @param p2 the channel
 * @param p3 the port
 * @param p4 the device name data
 * @param p5 the device name count
--
 * @param p3 the serial filename data
 * @param p4 the serial filename count
 * @param p5 the serial baudrate
 * @param p6 the socket family data (namespace)
 * @param p7 the socket family count
 * @param p8 the socket style data (communication type)
 * @param p9 the socket style count
 * @param p10 the socket protocol data
 * @param p11 the socket protocol count
 * @param p12 the socket filename data
 * @param p13 the socket filename count
 * @param p14 the socket host address data
 * @param p15 the socket host address count
 * @param p16 the socket port (service identification)
 * @param p17 the socket connexions (number of possible pending client requests)
 * @param p18 the socket timeout
 * @param p19 the channel
 */
void startup_server(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup server.");
    fwprintf(stdout, L"Information: Startup server. p19: %i\n", p19);

    // The server entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from internal memory.
    get_internal_memory_channel((void*) &e, internal-memory, channel, port);

    if (e == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A server entry does NOT exist yet.
        //

        // Allocate server entry.
        allocate_server_entry((void*) &e);

        // Execute general startup functions.
        startup_general(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, (void*) &b, (void*) &f, p20);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup server. A server entry does already exist.");
        fwprintf(stdout, L"Warning: Could not startup server. A server entry does already exist. p19: %i\n", p19);
    }
}

/* STARTER_SOURCE */
#endif
