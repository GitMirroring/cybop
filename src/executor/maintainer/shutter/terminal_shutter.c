/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_SHUTTER_SOURCE
#define TERMINAL_SHUTTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <termios.h>

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../logger/logger.c"

/**
 * Shuts down the terminal.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory array
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_terminal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown terminal.");

    // The terminal input- and output stream.
    FILE* ip = (FILE*) *NULL_POINTER_STATE_CYBOI_MODEL;
    FILE* op = (FILE*) *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get terminal input- and output stream.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only deallocate terminal resources if at least one,
    // the input- OR output stream internal is null.
    if ((ip != *NULL_POINTER_STATE_CYBOI_MODEL) && (op != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Interrupt terminal service thread.
        interrupt_thread(p1, p2);

        // The old termios settings.
        struct termios* to = (struct termios*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The new termios settings.
        struct termios* tn = (struct termios*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The character buffer used for input in the thread function.
        void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* bs = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get terminal internals.
        copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_INPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_OUTPUT_FILE_DESCRIPTOR_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &to, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_ORIGINAL_ATTRIBUTES_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &tn, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_WORKING_ATTRIBUTES_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        // Get character buffer.
        copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_THREAD_CHARACTER_BUFFER_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &bc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_THREAD_CHARACTER_BUFFER_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &bs, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_THREAD_CHARACTER_BUFFER_SIZE_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        // Get file descriptor for file stream.
        // CAUTION! The stream "stdin" must be used instead of "stdout" here!
        int d = fileno(ip);

        // Reset terminal to old settings.
        tcsetattr(d, TCSANOW, (void*) to);

/*??
        // Deallocate input- and output stream.
        //
        // CAUTION! DO NOT deallocate ip and op because they refer to stdin and stdout of the system!
        // This might be changed at a (much) later point in CYBOI development.
        deallocate((void*) &ip, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate((void*) &op, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
*/
        // Deallocate termios settings.
        free(to);
        free(tn);

        // Deallocate character buffer.
        deallocate_array((void*) &b, (void*) bs, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
        // Deallocate character buffer count, size.
        deallocate_array((void*) &bc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate_array((void*) &bs, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. There is no terminal running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* TERMINAL_SHUTTER_SOURCE */
#endif
