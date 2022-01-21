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
 * @param p1 the service port
 * @param p2 the client mode (pointer reference)
 * @param p3 the handler part (pointer reference)
 * @param p4 the sender client (pointer reference)
 * @param p5 the language (pointer reference)
 * @param p6 the channel (pointer reference)
 * @param p7 the channel
 */
void enable(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable.");
    fwprintf(stdout, L"Debug: Enable. p0: %i\n", p0);

    // The server base.
    int b = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The server entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server base by channel.
    map_channel_to_internal_memory((void*) &b, p7);

    compare_integer_greater_or_equal((void*) &r, (void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The internal memory name (server base) is VALID.
        //
        // CAUTION! This check is important since otherwise,
        // the internal memory is accessed with a wrong index,
        // which may lead to memory errors.
        //

        // Get server entry.
        get_internal_memory_element((void*) &e, p0, b, p1);

        if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // A server entry exists.
            //

            // Assign parametres to server entry.
            enable_entry(e, p2, p3, p4, p5, p6);

            // Invoke enable function WITHIN a new thread.
            enable_thread(e);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable. There exists no server entry at the given server base.");
            fwprintf(stdout, L"Error: Could not enable. There exists no server entry at the given server base. se: %i\n", se);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable. The server base is invalid.");
        fwprintf(stdout, L"Error: Could not enable. The server base is invalid. base: %i\n", b);
    }
}

/* ENABLER_SOURCE */
#endif
