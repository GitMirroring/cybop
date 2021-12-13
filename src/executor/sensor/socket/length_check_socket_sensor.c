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

#ifndef LENGTH_CHECK_SOCKET_SENSOR_SOURCE
#define LENGTH_CHECK_SOCKET_SENSOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"
--
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/sensor/socket/count_check_socket_sensor.c"

/**
 * Checks if the message length is greater than its initial value of -1.
 *
 * @param p0 the complete flag
 * @param p1 the message length
 * @param p2 the buffer count
 */
void sense_socket_check_length(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket check length.");
    fwprintf(stdout, L"Debug: Sense socket check length. message length p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Sense socket check length. message length *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The length was initialised with -1.
    // Use >= operator and not only > since an otherwise EMPTY message
    // with length 0 might contain a termination suffix such as crlf anyway.
    //
    // CAUTION! The length has to be checked BEFORE comparing the buffer count
    // since otherwise, the buffer count would always be greater than the length.
    // Even the initial buffer count of 0 would be greater than
    // the initial message length of -1.
    //
    // if (*l >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
    //
    compare_integer_greater_or_equal((void*) &r, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The message length WAS DETECTED as prefix within the message.
        //

        sense_socket_check_count(p0, p1, p2);
    }
}

/* LENGTH_CHECK_SOCKET_SENSOR_SOURCE */
#endif
