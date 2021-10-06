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

#ifndef CLIENT_CHANNEL_ENABLER_SOURCE
#define CLIENT_CHANNEL_ENABLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../executor/accessor/getter/internal_memory_getter.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/threader/spinner.c"
#include "../../logger/logger.c"

/**
 * Enables the client for message sensing.
 *
 * @param p0 the client entry
 */
void enable_channel_client(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable channel client.");
    fwprintf(stdout, L"Debug: Enable channel client. p0: %i\n", p0);

    //
    // An input/output entry DOES exist for the service
    // at the given service identification.
    //

    // The thread identification.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The thread function.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The function argument.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get thread identification from client entry.
    copy_array_forward((void*) &t, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_CLIENT_STATE_CYBOI_NAME);
    // Get thread function from client entry.
    copy_array_forward((void*) &f, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FUNCTION_THREAD_CLIENT_STATE_CYBOI_NAME);
    // Get function argument from client entry.
    copy_array_forward((void*) &a, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ARGUMENT_THREAD_CLIENT_STATE_CYBOI_NAME);

    // Set handler into client entry.
    //?? copy_array_forward(p0, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    // Set sender client into client entry.
    //?? copy_array_forward(p0, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SENDER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A sensing function exists.
        //

        // The actual thread function.
        void* ff = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The actual function argument.
        void* aa = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Extract actual thread function from pointer array.
        copy_pointer((void*) &ff, f);
        // Extract actual function argument from pointer array.
        copy_pointer((void*) &aa, a);

        // Create thread and invoke sensing function.
        spin(t, ff, aa);
    }
}

/* CLIENT_CHANNEL_ENABLER_SOURCE */
#endif
