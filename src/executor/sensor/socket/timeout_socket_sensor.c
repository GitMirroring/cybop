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

#ifndef TIMEOUT_SOCKET_SENSOR_SOURCE
#define TIMEOUT_SOCKET_SENSOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../executor/sensor/socket/request_accept_socket_sensor.c"
#include "../../../logger/logger.c"

/**
 * Senses server socket client timeouts.
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
int sense_socket_timeout(void* p0) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket timeout.");
    fwprintf(stdout, L"Debug: Sense socket timeout. p0: %i\n", p0);

    // The exit flag.
    void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket number.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // The local character buffer data, count.
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
    // Purpose of this local buffer:
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
    // Therefore, an additional LOCAL BUFFER needs to be used
    // for reading data in a blocking manner. The data received
    // are then copied to the actual destination buffer item,
    // whilst the mutex is set only for a short time.
    //
    // One more argument for this local buffer:
    //
    // The characters received have to be converted to wide characters,
    // so that this additional local buffer is needed anyway.
    //
    // Size of this local buffer:
    //
    // 1 It has to be GREATER than zero, so that there is place
    //   for the data to be read.
    //
    // 2 A peek into the APACHE http server showed values like 512 or 2048.
    //   So, the value of 1024 used here is probably acceptable.
    //
    char cd[*NUMBER_1024_INTEGER_STATE_CYBOI_MODEL];
    int cc = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get exit flag from input/output entry.
    copy_array_forward((void*) &ex, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get buffer item from input/output entry.
    copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BUFFER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get identification from input/output entry.
    copy_array_forward((void*) &id, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get mutex from input/output entry.
    copy_array_forward((void*) &m, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get socket number from input/output entry.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Get interrupt pipe write file descriptor.
    copy_array_forward((void*) &ipw, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"Debug: Sense socket timeout. s: %i\n", s);
    fwprintf(stdout, L"Debug: Sense socket timeout. *s: %i\n", *((int*) s));

    // Run loop neverendingly while sensing messages.
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, ex, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The exit flag was set in the main thread.
            // Therefore, leave this endless loop now.
            // The child thread exits when this function returns.
            //

            break;
        }

        sense_socket_timeout_check(b, s, id, m, cd, (void*) &cc, ex);
    }

    //
    // An implicit call to "thrd_exit" is made when this thread
    // (other than the thread in which "main" was first invoked)
    // returns from the function that was used to create it (this function).
    // The "thrd_exit" function does therefore NOT have to be called here.
    //

    return *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
}

/* TIMEOUT_SOCKET_SENSOR_SOURCE */
#endif
