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

#ifndef STATE_WIN32_CONSOLE_SERIALISER_SOURCE
#define STATE_WIN32_CONSOLE_SERIALISER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Stores the original attributes, that is the console's state.
 *
 * Example:
 *
 * CONSOLE_SCREEN_BUFFER_INFO i;
 * BOOL b = GetConsoleScreenBufferInfo(o, &i);
 * WORD a = i.wAttributes;
 *
 * @param p0 the destination original attributes
 * @param p1 the source win32 console output data
 */
void serialise_win32_console_state(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p1;

        // Cast DEREFERENCED value to handle.
        // CAUTION! The output data is stored as int value,
        // but actually references a win32 console handle.
        // This is just to be sure that the correct type is used.
        HANDLE sh = (HANDLE) *s;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            WORD* d = (WORD*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console state.");

            // The console screen buffer info.
            CONSOLE_SCREEN_BUFFER_INFO i;

            // Fill console screen buffer info.
            BOOL b = GetConsoleScreenBufferInfo(sh, &i);

            // If the return value is zero, then an error occured.
            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Get current attributes.
                *d = i.wAttributes;

            } else {

                // Get the calling thread's last-error code.
                DWORD e = GetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console state. The console screen buffer info could not be retrieved.");
                log_windows_system_error((void*) &e);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console state. The destination original attributes is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console state. The source win32 console output data is null.");
    }
}

/* STATE_WIN32_CONSOLE_SERIALISER_SOURCE */
#endif
