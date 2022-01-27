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

#ifndef OPENER_SOURCE
#define OPENER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
//?? #include "../../../executor/dispatcher/opener/forwarder_opener.c"
#include "../../../executor/memoriser/allocator/client_entry_allocator.c"
#include "../../../executor/memoriser/allocator/server_entry_allocator.c"
#include "../../../logger/logger.c"

/**
 * Accepts new clients via the given channel.
 *
 * CAUTION! Do NOT rename this function to "open",
 * as that name is already used by low-level file descriptor functionality:
 * /usr/include/fcntl.h:168
 * extern int open (const char *__file, int __oflag, ...) __nonnull ((1));
 *
 * @param p0 the client identification (e.g. file descriptor, socket number)
 * @param p1 the device name data
 * @param p2 the device name count
 * @param px the ...
 * @param p3 the channel
 */
void open_client(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open client.");
    fwprintf(stdout, L"Debug: Open client. p2: %i\n", p2);

    //
    // Declaration.
    //

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The device identification.
    int id = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Allocation.
    //

    // Get server entry from internal memory.
    get_server_entry((void*) &se);

    if (se == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Allocate server entry.
        allocate_server_entry((void*) &se);
    }

    // Allocate client entry.
    allocate_client_entry((void*) &ce);

    //
    // Initialisation.
    //

    // Forward server entry data to client entry.
    open_forwarder(e, p1);
    // Open device.
    open_device((void*) &id, p1, p2);
    // Copy client identification to destination.
    copy_integer(p0, (void*) &id);
}

/* OPENER_SOURCE */
#endif
