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

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Serialises the position into win32 console function calls.
 *
 * Example:
 * BOOL b = SetConsoleCursorPosition(standard_output_handle, position_coordinates_structure);
 *
 * @param p0 the destination win32 console output data
 * @param p1 the source x coordinate
 * @param p2 the source y coordinate
 */
void serialise_win32_console_position(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        // Cast DEREFERENCED value to handle.
        // CAUTION! The output data is stored as int value,
        // but actually references a win32 console handle.
        // This is just to be sure that the correct type is used.
        HANDLE dh = (HANDLE) *d;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console position.");

        // The x, y coordinates.
        int cx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int cy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Initialise x, y coordinates.
        calculate_integer_add((void*) &cx, p1);
        calculate_integer_add((void*) &cy, p2);

        // The position coordinates in a console screen buffer.
        // The origin of the coordinate system (0,0)
        // is at the top, left cell of the buffer.
        COORD p;
        p.X = cx;
        p.Y = cy;

        BOOL b = SetConsoleCursorPosition(dh, p);

        // If the return value is zero, then an error occured.
        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console position. A windows system error occured.");
            log_error((void*) &e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console position. The standard output is null.");
    }
}
