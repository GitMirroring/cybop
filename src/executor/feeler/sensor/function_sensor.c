/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FUNCTION_SENSOR_SOURCE
#define FUNCTION_SENSOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/feeler/sensor/loop_sensor.c"
#include "../../../logger/logger.c"

/**
 * Runs the sense function in its own thread.
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
 * Therefore, this function exceptionally has the return type "int",
 * since it may be used within a thread.
 *
 * @param p0 the client entry
 */
int sense_function(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense function.");
    //?? fwprintf(stdout, L"Debug: Sense function. client entry p0: %i\n", p0);

    //
    // Declaration.
    //

    // The input buffer item.
    void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input buffer mutex.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client identification.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language (protocol).
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The channel.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server flag.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sense thread exit flag.
    void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval.
    //

    // Get buffer item from client entry.
    copy_array_forward((void*) &bi, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);
    // Get buffer mutex from client entry.
    copy_array_forward((void*) &bm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);
    // Get client identification from client entry.
    copy_array_forward((void*) &id, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);
    // Get language from client entry.
    copy_array_forward((void*) &l, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
    // Get internal memory from client entry.
    copy_array_forward((void*) &i, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERNAL_MEMORY_BACKLINK_CLIENT_STATE_CYBOI_NAME);
    // Get channel from client entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
    // Get server flag from client entry.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVER_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
    // Get port from client entry.
    copy_array_forward((void*) &p, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PORT_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
    // Get sense thread exit flag from client entry.
    copy_array_forward((void*) &ex, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME);

    //
    // Functionality.
    //

    //
    // Sense input data via endless loop.
    //
    // CAUTION! Set asynchronicity flag to FALSE,
    // since data are NOT to be read from internal input buffer,
    // but DIRECTLY from client device INTO the internal input buffer.
    //
    sense_loop(bi, id, bm, l, i, c, s, p, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, ex);

    //
    // An implicit call to "thrd_exit" is made when this thread
    // (other than the thread in which "main" was first invoked)
    // returns from the function that was used to create it (this function).
    // The "thrd_exit" function does therefore NOT have to be called here.
    //

    //?? fwprintf(stdout, L"Debug: Sense function. Exit thread now. ex: %i\n", ex);
    //?? fwprintf(stdout, L"Debug: Sense function. Exit thread now. *ex: %i\n", *((int*) ex));

    return *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
}

/* FUNCTION_SENSOR_SOURCE */
#endif
