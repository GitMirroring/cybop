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

#ifndef CLOSER_SOURCE
#define CLOSER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"
--
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
//?? #include "../../../executor/dispatcher/closer/channel_closer.c"
#include "../../../executor/copier/array_copier.c"

/**
 * Closes the client with the given identification on the given channel.
 *
 * CAUTION! Do NOT rename this function to "close",
 * as that name is already used by low-level functionality:
 * /usr/include/unistd.h:353:12
 * extern int close (int __fd);
 *
 * @param p0 the client identification (e.g. file descriptor, socket number)
 * @param p1 the internal memory
 * @param p2 the channel
 * @param p3 the port
 */
void close_client(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close client.");
    fwprintf(stdout, L"Debug: Close client. p0: %i\n", p0);

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from internal memory.
    get_internal_memory_channel((void*) &se, p1, p2, p3);

    if (se != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Get client entry from server entry by device identification.
        find_server_entry((void*) &ce, se, p0);

        if (ce == *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // The client entry could not be found.
            //
            // Possibly, the given client identification was null.
            // Therefore, search client entry by device name now.
            //
            // Example: A file is to be closed from cybol, but the
            // file path and name given instead of a file descriptor.
            //

            // Get client entry from server entry by device identification.
            find_server_entry_name((void*) &ce, se, device-name);
        }

        // Close device.
        close_device(p0, p2);

        // Deallocate client entry.
        deallocate_client_entry((void*) &ce, channel);

        //
        // CAUTION! Do NOT deallocate server entry here.
        // It might still contain other clients.
        // Therefore, the server entry should only be
        // deallocated when the server is shut down.
        // If this is forgotten, then cyboi cares about
        // deallocation on system exit.
        //

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close client. The server entry is null.");
        fwprintf(stdout, L"Error: Could not close client. The server entry is null. se: %i\n", se);
    }
}

/* CLOSER_SOURCE */
#endif
