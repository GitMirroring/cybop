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
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../executor/accessor/getter/internal_memory_getter.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Enables the channel with the given input/output base for message sensing.
 *
 * @param p0 the internal memory data
 * @param p1 the input/output base
 * @param p2 the service identification (e.g. socket port)
 * @param p3 the handler part (pointer reference)
 * @param p4 the sender client data (pointer reference, e.g. client socket id, window id, file descriptor)
 */
void enable_channel(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable channel.");

    //?? CAUTION! Uncomment only for socket test since otherwise, the id is null.
    //?? fwprintf(stdout, L"Test: Enable channel. service id p2: %i\n", p2);
    //?? fwprintf(stdout, L"Test: Enable channel. service id *p2: %i\n", *((int*) p2));

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p0, p1, p2);

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

        // The enable flag.
        void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Set handler into input/output entry.
        copy_array_forward(io, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set sender client into input/output entry.
        copy_array_forward(io, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SENDER_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Get enable flag from input/output entry.
        copy_array_forward((void*) &e, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Copy enable flag.
        copy_integer(e, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable channel. There exists no input/output entry at the given service identification.");
        fwprintf(stdout, L"Error: Could not enable channel. There exists no input/output entry at the given service identification. io: %i\n", io);
    }
}

/* CHANNEL_ENABLER_SOURCE */
#endif
