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

#ifndef CHANNEL_SERVER_IDENTIFICATION_CALCULATOR_SOURCE
#define CHANNEL_SERVER_IDENTIFICATION_CALCULATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../executor/calculator/server_identification/base_server_identification_calculator.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Calculates the server identification by channel.
 *
 * @param p0 the resulting server identification
 * @param p1 the channel
 * @param p2 the service port
 */
void calculate_server_identification_channel(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate server identification channel.");
    fwprintf(stdout, L"Debug: Calculate server identification channel. p0: %i\n", p0);

    // The server base.
    int b = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get server base by channel.
    map_channel_to_internal_memory((void*) &b, p1);

    compare_integer_greater_or_equal((void*) &r, (void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_server_identification_base(p0, (void*) &b, p2);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate server identification channel. The server base is invalid.");
        fwprintf(stdout, L"Error: Could not calculate server identification channel. The server base is invalid. b: %i\n", b);
    }
}

/* CHANNEL_SERVER_IDENTIFICATION_CALCULATOR_SOURCE */
#endif
