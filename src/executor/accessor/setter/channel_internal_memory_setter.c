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

#ifndef CHANNEL_INTERNAL_MEMORY_SETTER_SOURCE
#define CHANNEL_INTERNAL_MEMORY_SETTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../executor/accessor/setter/internal_memory_setter.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Sets the server entry into internal memory by channel.
 *
 * @param p0 the internal memory data
 * @param p1 the server entry (pointer reference)
 * @param p2 the channel
 * @param p3 the service port
 */
void set_internal_memory_channel(void* p0, void* p1, void* p2, void* p3) {

    //
    // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set internal memory channel.");
    // fwprintf(stdout, L"Debug: Set internal memory channel. p2: %i\n", p2);
    //

    // The server base.
    int b = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get server base by channel.
    map_channel_to_internal_memory((void*) &b, p2);

    compare_integer_greater_or_equal((void*) &r, (void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The internal memory name (server base) is VALID.
        //
        // CAUTION! This check is IMPORTANT since otherwise,
        // the internal memory might be accessed with a
        // wrong index, which would lead to memory errors.
        //

        // Set server entry into internal memory.
        set_internal_memory_element(p0, p1, (void*) &b, p3);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set internal memory channel. The server base is invalid.");
        fwprintf(stdout, L"Error: Could not set internal memory channel. The server base is invalid. b: %i\n", b);
    }
}

/* CHANNEL_INTERNAL_MEMORY_SETTER_SOURCE */
#endif
