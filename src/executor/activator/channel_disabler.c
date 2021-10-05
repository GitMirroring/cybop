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

#ifndef CHANNEL_DISABLER_SOURCE
#define CHANNEL_DISABLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../executor/awakener/awakener.c"
#include "../../executor/calculator/integer/add_integer_calculator.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/threader/cutter.c"
#include "../../logger/logger.c"

/**
 * Disables the channel with the given input/output base for message sensing.
 *
 * @param p0 the internal memory data
 * @param p1 the input/output base
 * @param p2 the socket port (service identification)
 * @param p3 the channel
 */
void disable_channel(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Disable channel.");
    fwprintf(stdout, L"Debug: Disable channel. base: %i\n", *((int*) p1));
    //?? CAUTION! Uncomment only for socket test since otherwise, the id is null.
    //?? fwprintf(stdout, L"Debug: Disable channel. service id *p2: %i\n", *((int*) p2));

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p0, p1, p2);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // An input/output entry DOES exist for the service
        // at the given service identification.
        //

        fwprintf(stdout, L"Test: Disable channel. The input/output entry does exist. io: %i\n", io);

        // The thread identification.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The exit flag.
        void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get thread identification from input/output entry.
        copy_array_forward((void*) &t, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Get exit flag from input/output entry.
        copy_array_forward((void*) &ex, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME);

        //
        // CAUTION! Do NOT reset handler to null,
        // since the service may get reenabled later again.
        //
        // CAUTION! Do NOT reset sender client to null,
        // since the service may get reenabled later again.
        //

        //
        // Set exit flag.
        //
        // CAUTION! A mutex is NOT needed here, since only the main thread
        // does set (write) the flag and child threads ONLY READ it.
        //
        copy_integer(ex, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Awake channel sensing thread so that it can detect the exit flag set above.
        //
        // CAUTION! Mind the order. The exit flag has to be set FIRST.
        // Otherwise, the fake input might be processed and be lost,
        // if the exit flag were not found to be set before.
        //
        awake(io, p3);

        // Cut thread (wait for it to exit).
        cut(t);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not disable channel. There exists no input/output entry at the given service identification.");
        fwprintf(stdout, L"Error: Could not disable channel. There exists no input/output entry at the given service identification. io: %i\n", io);
        fwprintf(stdout, L"Error: Could not disable channel. There exists no input/output entry at the given service identification. base: %i\n", *((int*) p1));
    }
}

/* CHANNEL_DISABLER_SOURCE */
#endif
