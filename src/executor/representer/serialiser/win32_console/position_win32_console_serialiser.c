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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifdef WIN32

#ifndef POSITION_WIN32_CONSOLE_SERIALISER_SOURCE
#define POSITION_WIN32_CONSOLE_SERIALISER_SOURCE

#include <stdio.h>
#include <wchar.h>
#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/cybol/integer/value_integer_cybol_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the position into win32 console function calls.
 *
 * Example:
 * BOOL b = SetConsoleCursorPosition(standard_output_handle, position_coordinates_structure);
 *
 * @param p0 the destination item
 * @param p1 the source x coordinate
 * @param p2 the source y coordinate
 */
void serialise_win32_console_position(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console position.");

    // The y, x coordinates.
    int cy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise y, x coordinates.
    calculate_integer_add((void*) &cy, p2);
    calculate_integer_add((void*) &cx, p1);

    // Get standard output.
    HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);

    if (((void*) o) != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The position coordinates in a console screen buffer.
        // The origin of the coordinate system (0,0)
        // is at the top, left cell of the buffer.
        COORD p;
        p.X = cx;
        p.Y = cy;

        BOOL b = SetConsoleCursorPosition(o, p);

        // If the return value is zero, then an error occured.
        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console position. A windows system error occured.");
            log_windows_system_error(e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console position. The standard output is null.");
    }
}

/* POSITION_WIN32_CONSOLE_SERIALISER_SOURCE */
#endif

/* WIN32 */
#endif
