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

#ifndef ENABLER_SOURCE
#define ENABLER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/accessor/getter/internal_memory_getter.c"
#include "../../../executor/activator/enabler/entry_enabler.c"
#include "../../../executor/activator/enabler/thread_enabler.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Enables the given service.
 *
 * @param p0 the internal memory data
 * @param p3 the handler part (pointer reference)
 * @param p6 the channel (pointer reference)
 * @param p6 the port (pointer reference)
 */
void enable(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable.");
    fwprintf(stdout, L"Debug: Enable. p0: %i\n", p0);

    // The server entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from internal memory.
    get_internal_memory_channel((void*) &e, internal-memory, channel, port);

    if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A server entry exists.
        //

        // Assign parametres to server entry.
        enable_entry(e, p2, p3, p4, p5, p6);

        // Invoke enable function within a new thread.
        enable_thread(e);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable. There exists no server entry at the given server base.");
        fwprintf(stdout, L"Error: Could not enable. There exists no server entry at the given server base. se: %i\n", se);
    }
}

/* ENABLER_SOURCE */
#endif
