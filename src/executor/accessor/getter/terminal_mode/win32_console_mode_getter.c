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
#include <windows.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Gets the win32 console mode from the device pointed to by the file descriptor.
 *
 * @param p0 the destination console mode
 * @param p1 the source file descriptor
 */
void get_console_mode_win32(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The file descriptor is an integer and may be casted to a windows handle.
        HANDLE* h = (HANDLE*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            DWORD* m = (DWORD*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get console mode win32.");

            // Get console mode.
            BOOL b = GetConsoleMode(*h, m);

            // If the return value is zero, then an error occured.
            if (b == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Get the calling thread's last-error code.
                DWORD e = GetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get console mode win32. The GetConsoleMode function failed.");
                fwprintf(stdout, L"Error: Could not get console mode win32. The GetConsoleMode function failed. b: %i\n", b);
                log_error((void*) &e);
            }

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get console mode win32. The destination console mode is null.");
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get console mode win32. The source file descriptor is null.");
    }
}
