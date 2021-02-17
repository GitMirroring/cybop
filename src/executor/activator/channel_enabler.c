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

#ifndef CHANNEL_ENABLER_SOURCE
#define CHANNEL_ENABLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/accessor/setter/io_entry_setter.c"
#include "../../executor/calculator/integer/add_integer_calculator.c"
#include "../../executor/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Enables the channel with the given input/output base for message sensing.
 *
 * @param p0 the internal memory data
 * @param p1 the input/output base
 * @param p2 the service identification (e.g. socket port)
 * @param p3 the handler part (pointer reference)
 * @param p4 the sender client data (pointer reference, e.g. display connection, file descriptor, client socket)
 */
void enable_channel(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable channel.");

    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Calculate internal memory index.
    // - add input output base
    // - add service identification (input/output entry index)
    //
    calculate_integer_add((void*) &i, p1);
    calculate_integer_add((void*) &i, p2);

    // Get input/output entry from internal memory.
    copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // An input/output entry DOES exist for the service at the calculated internal memory index.

        //
        // Store various values in input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //
        // CAUTION! Hand over values as pointer REFERENCE.
        //

        // Set handler into input/output entry.
        set_io_entry_element(io, p3, (void*) HANDLER_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Set sender client into input/output entry.
        set_io_entry_element(io, p4, (void*) SENDER_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Set enable flag into input/output entry.
        set_io_entry_element(io, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);

        //?? fwprintf(stdout, L"TEST: Enable channel. Handler part *p3: %i\n", *((void**) p3));

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable channel. There exists no input/output entry at the given service identification.");

        fwprintf(stdout, L"Error: Could not enable channel. There exists no input/output entry at the given service identification. io: %i\n", io);
    }
}

/* CHANNEL_ENABLER_SOURCE */
#endif
