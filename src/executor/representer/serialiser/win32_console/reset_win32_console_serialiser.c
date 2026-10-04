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

#include <windows.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Resets the terminal to the original attributes handed over as parametre.
 *
 * Example:
 * BOOL b = SetConsoleTextAttribute(console_output, original_attributes);
 *
 * @param p0 the destination win32 console output data
 * @param p1 the source original attributes
 */
void serialise_win32_console_reset(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        WORD* s = (WORD*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* d = (int*) p0;

            // Cast DEREFERENCED value to handle.
            // CAUTION! The output data is stored as int value,
            // but actually references a win32 console handle.
            // This is just to be sure that the correct type is used.
            HANDLE dh = (HANDLE) *d;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console reset.");

            // Set attributes of characters written to the console screen buffer.
            //
            // CAUTION! Under win32 console, unfortunately,
            // the display mode is locked in background
            // intensity mode, thus BLINKING does NOT work.
            // Also, the UNDERSCORE attribute is NOT available.
            //
            // http://msdn.microsoft.com/en-us/library/ms686047(v=vs.85).aspx
            // http://msdn.microsoft.com/en-us/library/ms682088(v=vs.85).aspx#_win32_character_attributes
            BOOL b = SetConsoleTextAttribute(dh, *s);

            // If the return value is zero, then an error occured.
            if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Get the calling thread's last-error code.
                DWORD e = GetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console reset. The text attributes could not be set.");
                log_error((void*) &e);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console reset. The standard output is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console reset. The original attributes is null.");
    }
}
