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

#ifndef DISABLER_SOURCE
#define DISABLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../executor/activator/service_disabler.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../logger/logger.c"
#include "../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Disables the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the socket port (service identification)
 * @param p2 the channel
 */
void disable(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Disable.");
    fwprintf(stdout, L"Debug: Disable. channel p2: %i\n", *((int*) p2));

    // The internal memory name (input/output base).
    int n = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get internal memory name.
    map_channel_to_internal_memory((void*) &n, p2);

    compare_integer_greater_or_equal((void*) &r, (void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The internal memory name (input/output base) is VALID.
        //
        // CAUTION! This check is important since otherwise,
        // the internal memory is accessed with a wrong index,
        // which may lead to memory errors.
        //

        disable_service(p0, (void*) &n, p1, p2);
    }
}

/* DISABLER_SOURCE */
#endif
