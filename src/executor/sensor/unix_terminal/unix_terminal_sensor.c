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

#ifndef UNIX_TERMINAL_SENSOR_SOURCE
#define UNIX_TERMINAL_SENSOR_SOURCE

#include <stdio.h> // fdopen
#include <threads.h> // mtx_t, mtx_lock, mtx_unlock
#include <wchar.h> // fgetwc, fgetwc_unlocked

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/sensor/unix_terminal/message_unix_terminal_sensor.c"
#include "../../../logger/logger.c"

/**
 * Senses unix terminal message.
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
int sense_unix_terminal(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense unix terminal.");

    // The interrupt request.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // Get write pipe stream from input/output entry.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The file stream associated with the given file descriptor.
    //
    // CAUTION! The mode of the stream must be compatible with the mode of the
    // file descriptor. Possible modes are : "r", "r+", "w", "w+", "a", "a+"
    //
    // CAUTION! The file position indicator of the new stream is set to
    // that belonging to the file descriptor. The error and end-of-file
    // indicators are cleared.
    // Modes "w" or "w+" do not cause truncation of the file.
    //
    // CAUTION! The file descriptor is not duplicated. It will be closed
    // when the stream created by fdopen() is closed.
    // The result of applying fdopen() to a shared memory object is undefined.
    //
    // https://stackoverflow.com/questions/1516766/how-to-get-a-file-stream-from-a-file-descriptor
    //
    // CAUTION! The opentype string "r+" means an existing file
    // is opened for both reading and writing:
    // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Opening-Streams
    //
    // CAUTION! Don't confuse terminal attributes with file attributes.
    // A device special file which is associated with a terminal
    // has file attributes as described in File Attributes:
    // https://www.gnu.org/software/libc/manual/html_mono/libc.html#File-Attributes
    // These are unrelated to the attributes of the terminal device itself,
    // which are discussed in this section:
    // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Low_002dLevel-Terminal-Interface
    //
    //?? void* fs = (void*) fdopen(*f, "r+");
    void* f = (void*) stdin;

    // Get interrupt request from input/output entry.
    copy_array_forward((void*) &i, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get mutex from input/output entry.
    copy_array_forward((void*) &m, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get write pipe stream from input/output entry.
    copy_array_forward((void*) &p, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WRITE_STREAM_PIPE_INPUT_OUTPUT_STATE_CYBOI_NAME);

    //?? FILE* irq_stream = fdopen(INTERRUPT_PIPE[1], "w");
    //?? FILE* terminal_stream = fdopen(TERMINAL_PIPE[1], "w");

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A break condition does not exist here because the loop
        // is running neverendingly while sensing messages.
        //
        // The loop and this sensing thread CANNOT be exited.
        // Possibly, there will be a solution in the future, however.
        //

        sense_unix_terminal_message(i, m, f);

        //?? TEST BEGIN DELETE LATER

/*??
        fwprintf(stdout, L"Test: Sense unix terminal. Wait for input using fgetwc. *TRUE_BOOLEAN_STATE_CYBOI_MODEL: %i\n", *TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        volatile wint_t c = fgetwc(stdin);

        fwprintf(stdout, L"Test: Sense unix terminal. terminal_stream: %i\n", p);
        fwprintf(p, L"%lc", c);
        fflush(p);

        fwprintf(stdout, L"Test: Sense unix terminal. irq_stream: %i\n", irq_stream);
        fwprintf(irq_stream, L"%i", *TERMINAL_CYBOI_CHANNEL);
        fflush(irq_stream);
*/

        //?? TEST END DELETE LATER
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

/* UNIX_TERMINAL_SENSOR_SOURCE */
#endif
