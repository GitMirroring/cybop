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

#ifndef XCB_SENSOR_SOURCE
#define XCB_SENSOR_SOURCE

#include <xcb/xcb.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/sensor/xcb/event_xcb_sensor.c"
#include "../../../logger/logger.c"

/**
 * Senses xcb x window system messages.
 *
 * CAUTION! In cyboi, all functions by default have
 * NO return value. In relation with threads, however,
 * iso c defines the data type "thrd_start_t" as:
 *
 * int (*) (void*)
 *
 * with the following meaning:
 *
 * int      - the integer return type
 * *        - the function pointer with arbitrary name
 * void*    - the function argument
 *
 * Therefore, this function exceptionally has
 * the return type "int".
 *
 * @param p0 the input/output entry
 */
int sense_xcb(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense xcb.");
    fwprintf(stdout, L"Test: Sense xcb. p0: %i\n", p0);

    // The buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt pipe.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt mutex.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The character buffer data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The interrupt pipe write file descriptor.
    int ipw = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //?? TODO: buffer is an array and NOT item --> adapt io_entry ??
    // Get buffer item from input/output entry.
    //?? copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BUFFER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get connexion from input/output entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get interrupt pipe from input/output entry.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_PIPE_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get identification from input/output entry.
    copy_array_forward((void*) &id, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get mutex from input/output entry.
    copy_array_forward((void*) &m, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get interrupt mutex from input/output entry.
    copy_array_forward((void*) &im, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_MUTEX_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Get interrupt pipe write file descriptor.
    copy_array_forward((void*) &ipw, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A break condition does not exist here because the loop
            // is running neverendingly while sensing messages.
            //
            // The loop and this sensing thread CANNOT be exited.
            // Possibly, there will be a solution in the future, however.
            //

            sense_xcb_event(b, c, (void*) &ipw, id, m, im);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb. The connexion is null.");
    }

    //
    // An implicit call to "thrd_exit" is made when this thread
    // (other than the thread in which "main" was first invoked)
    // returns from the function that was used to create it (this function).
    // The "thrd_exit" function does therefore not have to be called here.
    // However, since this function runs an endless loop waiting for input,
    // it may only be left by using either (1) a flag (2) an external signal.
    //

    return *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
}

/* XCB_SENSOR_SOURCE */
#endif
