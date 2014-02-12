/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIN32_CONSOLE_SENSOR_SOURCE
#define WIN32_CONSOLE_SENSOR_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Senses win32 console messages.
 *
 * @param p0 the interrupt request
 * @param p1 the break flag
 * @param p2 the internal memory data
 */
void sense_win32_console(void* p0, void* p1, void* p2) {

    // The input console.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input console.
    copy_array_forward((void*) &c, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ci = (int*) c;

        // Cast DEREFERENCED value to handle.
        // CAUTION! The input data is stored as int value,
        // but actually references a win32 console handle.
        // This is just to be sure that the correct type is used.
        HANDLE h = (HANDLE) *ci;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense win32 console.");

        // The input buffer size.
        // CAUTION! The size HAS TO HAVE a value of one.
        // The reason is that each input needs to be processed
        // and deserialised, in order to identify the command
        // corresponding e.g. to the button pressed by key or mouse.
        // Afterwards, that command gets processed in cyboi's
        // MAIN LOOP, before the next input may be received.
        // One advantage of this kind of relying on the main loop
        // is the possibility of real-time processing.
        DWORD is = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
        // The input buffer.
        // It is an array of INPUT_RECORD structures
        // that receives the input buffer data.

#ifdef _MSC_VER
        //Changed Benno Schilling 05.02.2014
        //VLA's (variable length arrays) are supported by c99, but not by the visual studio compiler
        //INPUT_RECORD i[is];
        //To Workaround simply use dynamic array allocation with malloc
        //TODO: You have to free the allocated memory (due to the complexity of the program i dont know where and when to free)
        INPUT_RECORD* i = (INPUT_RECORD*) malloc(is * sizeof(DWORD));
#else
        INPUT_RECORD i[is];
#endif

        // The input count (number of records read).
        DWORD ic = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Read data from console input buffer WITHOUT removing it.
        //
        // CAUTION! The message MUST NOT be removed here,
        // since it has to be read again in a "receive" function,
        // where the actual processing happens.
        // This call here is just made to detect available input.
        BOOL b = PeekConsoleInputW(h, i, is, &ic);

        // If the return value is zero, then an error occured.
        if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // CAUTION! Setting a mutex is NOT necessary here,
            // since this is the main thread and no other threads
            // are writing to the interrupt request variable.

            if (ic > (DWORD) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Set console interrupt request to indicate
                // that a message has been received via console,
                // which may now be processed in the main thread of this system.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                // Set break flag.
                copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense win32 console. The peek console input failed.");
            log_windows_system_error((void*) &e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense win32 console. The input console item data is null.");
    }
}

/* WIN32_CONSOLE_SENSOR_SOURCE */
#endif
