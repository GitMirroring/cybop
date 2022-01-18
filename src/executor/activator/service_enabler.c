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

#ifndef SERVICE_ENABLER_SOURCE
#define SERVICE_ENABLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/internal_memory_getter.c"
#include "../../executor/activator/function_enabler.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/pointer_copier.c"
#include "../../executor/dispatcher/opener/opener.c"
#include "../../logger/logger.c"

/**
 * Enables the service on the given channel.
 *
 * @param p0 the internal memory data
 * @param p1 the input/output base
 * @param p2 the socket port (service identification)
 * @param p3 the handler part (pointer reference)
 * @param p4 the sender client data (pointer reference, e.g. client socket id, window id, file descriptor)
 * @param p5 the language (pointer reference, protocol)
 * @param p6 the channel (pointer reference)
 * @param p7 the channel
 */
void enable_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable service.");
    fwprintf(stdout, L"Debug: Enable service. language p5: %i\n", p5);
    fwprintf(stdout, L"Debug: Enable service. language *p5: %i\n", *((int*) p5));

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p0, p1, p2);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"Debug: Enable service. io: %i\n", io);

        //
        // An input/output entry DOES exist for the service
        // at the given service identification.
        //

        // The thread identification.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The thread function.
        //?? void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The function argument.
        //?? void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The actual thread function.
        //?? void* ff = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The actual function argument.
        //?? void* aa = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get thread identification from input/output entry.
        copy_array_forward((void*) &t, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Get thread function from input/output entry.
        //?? copy_array_forward((void*) &f, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FUNCTION_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Get function argument from input/output entry.
        //?? copy_array_forward((void*) &a, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ARGUMENT_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Set handler into input/output entry.
        copy_array_forward(io, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set sender client into input/output entry.
        copy_array_forward(io, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SENDER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set language (protocol) into input/output entry.
        copy_array_forward(io, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) LANGUAGE_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set channel into input/output entry.
        copy_array_forward(io, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHANNEL_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Extract actual thread function from pointer array.
        //?? copy_pointer((void*) &ff, f);
        // Extract actual function argument from pointer array.
        //?? copy_pointer((void*) &aa, a);

        //?? TODO: Better local function than that from input/output entry?
        void* f = (void*) &open_client;

        // Handle requests arriving via channel.
        //?? enable_function(t, ff, aa, p7);
        enable_function(t, f, io, p7);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable service. There exists no input/output entry at the given service identification.");
        fwprintf(stdout, L"Error: Could not enable service. There exists no input/output entry at the given service identification. io: %i\n", io);
    }
}

/* SERVICE_ENABLER_SOURCE */
#endif
