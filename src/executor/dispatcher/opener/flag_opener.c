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

#ifndef FLAG_OPENER_SOURCE
#define FLAG_OPENER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/dispatcher/opener/device_opener.c"
#include "../../../logger/logger.c"

/**
 * Checks the given stub flag.
 *
 * If this is a client stub socket, then do NOT open a new device.
 *
 * @param p0 the client identification (e.g. file descriptor, socket number)
 * @param p1 the device name data
 * @param p2 the device name count
 * @param p3 the channel
 * @param p4 the stub flag
 */
void open_flag(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open flag.");
    fwprintf(stdout, L"Debug: Open flag. channel p2: %i\n", p2);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! The stub flag is either FALSE or NULL.
        // This is the DEFAULT.
        //

        // Open device.
        open_device(p0, p1, p2, p3);

    } else {

        //
        // This is a client stub on the server side.
        //
        // CAUTION! Do NOTHING here!
        //
        // When a server socket receives a client request, then
        // that request is stored as client socket number (stub).
        // It is pre-configured by the server socket and
        // thus does NOT need to be configured here again.
        //
    }
}

/* FLAG_OPENER_SOURCE */
#endif
