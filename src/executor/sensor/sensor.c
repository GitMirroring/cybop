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

#ifndef SENSOR_SOURCE
#define SENSOR_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/sensor/loop_sensor.c"
#include "../../logger/logger.c"

/**
 * Senses data on the given channel.
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
int sense(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");
    //?? fwprintf(stdout, L"Debug: Sense. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Sense. *p0: %i\n", *((int*) p0));

    // The buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item mutex.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input file descriptor.
    //?? int f = STDIN_FILENO;
    // The identification (client socket number).
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The connexion.
    //?? void* co = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt pipe.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt mutex.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input/output identification (input/output base + socket port).
    void* ioid = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The language (protocol).
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The exit flag.
    void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client mode.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The channel.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // The local character buffer data, size.
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
    // Therefore, this additional LOCAL BUFFER needs to be used
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
    int cs = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;
    // The interrupt pipe write file descriptor.
    int ipw = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
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

    // Get buffer item from client entry.
    copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BUFFER_MESSAGE_CLIENT_STATE_CYBOI_NAME);
    // Get buffer item mutex from client entry.
    copy_array_forward((void*) &bm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_MESSAGE_CLIENT_STATE_CYBOI_NAME);
    // Get input file descriptor from input/output entry.
    //?? copy_array_forward((void*) &f, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_FILE_DESCRIPTOR_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get identification (client socket number) from client entry.
    copy_array_forward((void*) &id, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_CLIENT_STATE_CYBOI_NAME);
    // Get connexion from input/output entry.
    //?? copy_array_forward((void*) &co, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get interrupt pipe from client entry.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PIPE_INTERRUPT_CLIENT_STATE_CYBOI_NAME);
    // Get interrupt mutex from client entry.
    copy_array_forward((void*) &im, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_INTERRUPT_CLIENT_STATE_CYBOI_NAME);
    // Get input/output identification (input/output base + socket port) from client entry.
    copy_array_forward((void*) &ioid, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_OUTPUT_IDENTIFICATION_CLIENT_STATE_CYBOI_NAME);
    // Get language (protocol) from client entry.
    copy_array_forward((void*) &l, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) LANGUAGE_CLIENT_STATE_CYBOI_NAME);
    // Get exit flag from client entry.
    copy_array_forward((void*) &ex, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_CLIENT_STATE_CYBOI_NAME);
    // Get client mode from client entry.
    //?? copy_array_forward((void*) &cm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TODO_CLIENT_STATE_CYBOI_NAME);
    // Get channel from client entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CHANNEL_CLIENT_STATE_CYBOI_NAME);

    // Get interrupt pipe write file descriptor.
    copy_array_forward((void*) &ipw, ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"Debug: Sense. ioid: %i\n", ioid);
    fwprintf(stdout, L"Debug: Sense. *ioid: %i\n", *((int*) ioid));
    fwprintf(stdout, L"Debug: Sense. id: %i\n", id);
    fwprintf(stdout, L"Debug: Sense. *id: %i\n", *((int*) id));
    fwprintf(stdout, L"Debug: Sense. c: %i\n", c);
    fwprintf(stdout, L"Debug: Sense. *c: %i\n", *((int*) c));

    // Sense messages in loop.
    sense_loop(b, id, cd, (void*) &cs, bm, (void*) &ipw, im, ioid, l, (void*) &ml, ex, *NULL_POINTER_STATE_CYBOI_MODEL, c);

    //
    // An implicit call to "thrd_exit" is made when this thread
    // (other than the thread in which "main" was first invoked)
    // returns from the function that was used to create it (this function).
    // The "thrd_exit" function does therefore NOT have to be called here.
    //

    fwprintf(stdout, L"Debug: Sense. Exit thread now. ex: %i\n", ex);
    fwprintf(stdout, L"Debug: Sense. Exit thread now. *ex: %i\n", *((int*) ex));

    return *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
}

/* SENSOR_SOURCE */
#endif
