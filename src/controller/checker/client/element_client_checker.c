/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ELEMENT_CLIENT_CHECKER_SOURCE
#define ELEMENT_CLIENT_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/lifeguard/sensor/socket/socket_sensor.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks open client for available data.
 *
 * @param p0 the destination sender client
 * @param p1 the source client list data
 * @param p2 the source client list index
 */
void check_client_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check client element.");

    // The data available flag.
    // CAUTION! It is actually the data count being returned.
    // Any value greater than zero means that data are available.
    int f = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The client.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get client at the given index.
    copy_array_forward((void*) &c, p1, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    // Sense data available on already open client.
    // CAUTION! It suffices to detect at least one byte,
    // which is why number 1 is forwarded as buffer size argument.
    sense_socket((void*) &f, (void*) &c, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (f > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // There are data available on the client.

        // Copy client.
        copy_integer(p0, (void*) &c);
    }
}

/* ELEMENT_CLIENT_CHECKER_SOURCE */
#endif
