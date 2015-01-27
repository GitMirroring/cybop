/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_IO_CHECKER_SOURCE
#define ELEMENT_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../executor/modifier/copier/array_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/lifeguard/sensor/socket/socket_sensor.c"
#include "../../../logger/logger.c"

/**
 * Checks input output entry data.
 *
 * @param p0 the io flag
 * @param p1 the internal memory data
 * @param p2 the internal memory index (already initialised with input output base)
 * @param p3 the io entry index
 */
void check_io_element(void* p0, void* p1, void* p2, void* p3) {

    // CAUTION! Do NOT log messages here, since checking runs in an endless loop.
    // Otherwise, the log file would be filled up with useless entries.
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io element.");

    // The internal memory index.
    int idx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The io entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Calculate internal memory index.
    calculate_integer_add((void*) &idx, p2);
    calculate_integer_add((void*) &idx, p3);

    // Get io entry.
    copy_array_forward((void*) &io, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &idx);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // An io entry exists for the service at the calculated internal memory index.

        // The enable flag.
        int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Get enable flag from io entry.
        get_io_entry_element((void*) &e, (void*) &io, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);

        if (e != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

    fwprintf(stdout, L"TEST: check io element io index p2: %i \n", *((int*) p2));
    fwprintf(stdout, L"TEST: check io element port p3: %i \n", *((int*) p3));

    fwprintf(stdout, L"TEST: check io element io index with port: %i \n", idx);

            // The enable flag is set.

            // The server socket.
            int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The sender client socket.
            void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The interrupt request.
            int i = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // Get server socket from io entry.
            get_io_entry_element((void*) &s, (void*) &io, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);
            // Set sender client socket into io entry.
            get_io_entry_element((void*) &c, (void*) &io, (void*) SENDER_INPUT_OUTPUT_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST: check io element s: %i \n", s);
    fwprintf(stdout, L"TEST: check io element c pre: %i \n", *((int*) c));

            // Sense data on server socket.
            sense_socket((void*) &i, c, (void*) &s);

            if (i != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

    fwprintf(stdout, L"TEST: check io element c post: %i \n", *((int*) c));

                // Set interrupt request into io entry.
                set_io_entry_element((void*) &io, (void*) &i, (void*) INTERRUPT_REQUEST_INPUT_OUTPUT_STATE_CYBOI_NAME);

                // Set result.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }
        }
    }
}

/* ELEMENT_IO_CHECKER_SOURCE */
#endif
