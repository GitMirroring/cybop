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

#ifndef CHANNEL_INTERNAL_MEMORY_GETTER_SOURCE
#define CHANNEL_INTERNAL_MEMORY_GETTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/server_identification/channel_server_identification_calculator.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../logger/logger.c"

/**
 * Gets the server entry from internal memory by channel.
 *
 * @param p0 the server entry (pointer reference)
 * @param p1 the internal memory data
 * @param p2 the channel
 * @param p3 the service port
 */
void get_internal_memory_channel(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get internal memory channel.");
    fwprintf(stdout, L"Debug: Get internal memory channel. p2: %i\n", p2);

    // The server identification.
    int id = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    calculate_server_identification_channel((void*) &id, p2, p3);

    compare_integer_greater_or_equal((void*) &r, (void*) &id, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Get server entry from internal memory.
        copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &id);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get internal memory channel. The server base is invalid.");
        fwprintf(stdout, L"Error: Could not get internal memory channel. The server base is invalid. b: %i\n", b);
    }
}

/* CHANNEL_INTERNAL_MEMORY_GETTER_SOURCE */
#endif
