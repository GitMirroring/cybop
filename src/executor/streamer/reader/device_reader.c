/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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

/**
 * Reads data directly from device (synchronous mode).
 *
 * @param p0 the destination item
 * @param p1 the source data (identification e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p2 the source count
 * @param p3 the destination mutex
 * @param p4 the client entry
 * @param p5 the language (protocol)
 * @param p6 the channel
 */
void read_device(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read device.");
    //?? fwprintf(stdout, L"Debug: Read device. p0: %i\n", p0);

    //
    // Declaration.
    //

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The interrupt pipe.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt mutex.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The sensor handler.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The closer handler.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sense thread exit flag.
    void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // The message fragment array data, size.
    //
    // CAUTION! Do NOT declare these variables inside
    // the called function, for two reasons:
    //
    // 1 It is more EFFICIENT not to have to reserve
    //   the buffer on stack with each loop cycle.
    //
    // 2 The buffer does NOT have to be emptied, since only
    //   the number of data received is processed further.
    //
    // Purpose:
    //
    // Received data are to be stored in the buffer item.
    // However, this buffer item CANNOT be used directly
    // for reading data, since read calls are BLOCKING.
    // Since the main thread needs to have access to
    // the buffer as well, a mutex has to be used.
    //
    // It could thus happen that the mutex is set,
    // in order to protect access to the buffer item,
    // while the sensing child thread waits for input.
    // In this case, the main thread would be blocked
    // while waiting for the mutex to be reset.
    //
    // Therefore, this LOCAL message fragment array
    // needs to be used for reading data in a blocking manner.
    // The data received are then copied to the actual destination
    // buffer item, whilst the mutex is set only for a short time.
    //
    // Size:
    //
    // 1 It has to be GREATER than zero, so that there is place
    //   for the data to be read.
    //
    // 2 A peek into the APACHE http server showed values like 512 or 2048.
    //   So, the value of 1024 used here is probably acceptable.
    //
    // Type:
    //
    // The character type "char" is used here, since it
    // covers ALL channels using the function "read_basic".
    // Other types are NOT necessary here, since channels
    // like "display", "inline" or "signal" do NOT use
    // this local message fragment buffer array.
    //
    char fd[*NUMBER_1024_INTEGER_STATE_CYBOI_MODEL];
    int fs = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;
    // The interrupt pipe write file descriptor.
    int ipw = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    //
    // The message length.
    //
    // CAUTION! This variable is NOT read from client entry.
    // It serves just as a value-holder across many loop cycles,
    // so that a "message length" header found in the data
    // (e.g. "Content-Length: " in http) can be compared with
    // the actual number of bytes that have been read, in each loop cycle.
    //
    // Since it gets compared inside, it should be initialised
    // with a value < 0, e.g. with -1.
    //
    int ml = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Retrieval.
    //

    // Get server entry from client entry.
    copy_array_forward((void*) &se, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME);
    // Get input output entry from server entry.
    copy_array_forward((void*) &io, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_OUTPUT_BACKLINK_CLIENT_STATE_CYBOI_NAME);
    // Get internal memory from input output entry.
    copy_array_forward((void*) &i, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERNAL_MEMORY_BACKLINK_CLIENT_STATE_CYBOI_NAME);

    // Get interrupt pipe from internal memory.
    copy_array_forward((void*) &ip, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PIPE_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get interrupt mutex from internal memory.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get sensor handler from client entry.
    copy_array_forward((void*) &h, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SENSOR_HANDLER_INPUT_CLIENT_STATE_CYBOI_NAME);
    // Get closer handler from client entry.
    copy_array_forward((void*) &cl, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CLOSER_HANDLER_INPUT_CLIENT_STATE_CYBOI_NAME);
    // Get thread exit flag from client entry.
    copy_array_forward((void*) &ex, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME);

    // Get interrupt pipe write file descriptor from interrupt pipe.
    copy_array_forward((void*) &ipw, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //
    // Functionality.
    //

    // Call endless loop waiting for data input.
    read_loop(p0, p1, p2, fd, (void*) &fs, p3, (void*) &ipw, im, (void*) &h, (void*) &cl, ex, p5, (void*) &ml, p6);
}
