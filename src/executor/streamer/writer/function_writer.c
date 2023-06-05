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
 * @version CYBOP 0.26.0 2023-04-04
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

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "mapper.h"

/**
 * Runs the write function in its own thread.
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
int write_function(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write function.");
    //?? fwprintf(stdout, L"Debug: Write function. p0: %i\n", p0);

    //
    // Declaration.
    //

    // The destination device identification item.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output buffer mutex.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output writer handler.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part (pointer reference).
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The channel.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The interrupt pipe.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt mutex.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The destination device identification item data.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The interrupt pipe write file descriptor.
    int ipw = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The output buffer item type.
    int t = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Retrieval.
    //

    // Get destination device identification item from client entry.
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_GENERAL_CLIENT_STATE_CYBOI_NAME);
    // Get output buffer item from client entry.
    copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME);
    // Get output buffer mutex from client entry.
    copy_array_forward((void*) &bm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME);
    // Get output handler writer from client entry.
    copy_array_forward((void*) &h, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WRITER_HANDLER_OUTPUT_CLIENT_STATE_CYBOI_NAME);
    // Get source part from client entry.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SOURCE_PART_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
    // Get channel from client entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_COMMUNICATION_CLIENT_STATE_CYBOI_NAME);
    // Get internal memory from client entry.
    copy_array_forward((void*) &i, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERNAL_MEMORY_BACKLINK_CLIENT_STATE_CYBOI_NAME);

    // Get interrupt pipe from internal memory.
    copy_array_forward((void*) &ip, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PIPE_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get interrupt mutex from internal memory.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get destination device identification item data.
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get interrupt pipe write file descriptor from interrupt pipe.
    copy_array_forward((void*) &ipw, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Map channel to datatype.
    map_channel_to_type((void*) &t, c);

    //
    // Functionality.
    //

    // Write output data via loop, until all data have been transmitted.
    write_loop(d, b, (void*) &t, (void*) &s, bm, p0, i, c);

    // Write output finished handler into interrupt pipe.
    write_interrupt_pipe((void*) &ipw, (void*) &h, dd, im);

    //
    // An implicit call to "thrd_exit" is made when this thread
    // (other than the thread in which "main" was first invoked)
    // returns from the function that was used to create it (this function).
    // The "thrd_exit" function does therefore NOT have to be called here.
    //

    fwprintf(stdout, L"Debug: Write function. Exit thread now. p0: %i\n", p0);

    return *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
}
