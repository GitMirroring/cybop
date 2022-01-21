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
#include "../../../logger/logger.c"
--
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../executor/activator/service_enabler.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Enables the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the server base
 * @param p2 the service port
 * @param p2 the handler part (pointer reference)
 * @param p3 the sender client data (pointer reference, e.g. client socket id, window id, file descriptor)
 * @param p4 the language (pointer reference, protocol)
 * @param p5 the channel (pointer reference)
 * @param p6 the channel
 */
void enable(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable.");
    fwprintf(stdout, L"Debug: Enable. channel p6: %i\n", p6);
    fwprintf(stdout, L"Debug: Enable. channel *p6: %i\n", *((int*) p6));

    // The internal memory name (server base).
    int n = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The server entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get internal memory name.
    map_channel_to_internal_memory((void*) &n, p6);

    compare_integer_greater_or_equal((void*) &r, (void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The internal memory name (server base) is VALID.
        //
        // CAUTION! This check is important since otherwise,
        // the internal memory is accessed with a wrong index,
        // which may lead to memory errors.
        //

        // Assign data handed over from cybol application to server entry.
        enable_entry(e, (void*) &n, p1, p2, p3, p4, p5, p6);

        // Invoke enable function WITHIN a new thread.
        enable_thread(e);
    }
}

/* ENABLER_SOURCE */
#endif
