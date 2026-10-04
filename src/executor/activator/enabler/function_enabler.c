/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "server.h"

/**
 * Runs the enable function in its own thread.
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
 * @param p0 the server entry
 */
int enable_function(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable function.");
    //?? fwprintf(stdout, L"Debug: Enable function. p0: %i\n", p0);

    //
    // Declaration
    //

    // The channel.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The handler.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The request buffer item.
    void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The request buffer mutex.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The enable thread exit flag.
    void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The interrupt pipe.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt mutex.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The interrupt pipe write file descriptor.
    int ipw = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get channel from server entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_COMMUNICATION_SERVER_STATE_CYBOI_NAME);
    // Get handler from server entry.
    copy_array_forward((void*) &h, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLER_COMMUNICATION_SERVER_STATE_CYBOI_NAME);
    // Get request buffer item from server entry.
    copy_array_forward((void*) &bi, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME);
    // Get request buffer mutex from server entry.
    copy_array_forward((void*) &bm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME);
    // Get enable thread exit flag from server entry.
    copy_array_forward((void*) &ex, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_INPUT_SERVER_STATE_CYBOI_NAME);
    // Get internal memory from server entry.
    copy_array_forward((void*) &i, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERNAL_MEMORY_BACKLINK_SERVER_STATE_CYBOI_NAME);

    // Get interrupt pipe from internal memory.
    copy_array_forward((void*) &ip, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PIPE_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get interrupt mutex from internal memory.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get interrupt pipe write file descriptor from interrupt pipe.
    copy_array_forward((void*) &ipw, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //
    // Functionality
    //

    // Enable client requests or events via endless loop.
    enable_loop(bi, bm, p0, c, (void*) &ipw, (void*) &h, im, ex);

    //
    // An implicit call to "thrd_exit" is made when this thread
    // (other than the thread in which "main" was first invoked)
    // returns from the function that was used to create it (this function).
    // The "thrd_exit" function does therefore NOT have to be called here.
    //

    //?? fwprintf(stdout, L"Debug: Enable function. Exit thread now. ex: %i\n", ex);
    //?? fwprintf(stdout, L"Debug: Enable function. Exit thread now. *ex: %i\n", *((int*) ex));

    return *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
}
