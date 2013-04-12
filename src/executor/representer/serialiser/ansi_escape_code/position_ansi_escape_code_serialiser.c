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

#ifndef POSITION_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define POSITION_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#ifdef WIN32
    #include <windows.h>
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/cybol/integer/value_integer_cybol_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the position into an ansi escape code.
 *
 * Example:
 * printf("\033[%d;%dH", y_row, x_column)
 *
 * @param p0 the destination item
 * @param p1 the source x coordinate
 * @param p2 the source y coordinate
 */
void serialise_ansi_escape_code_position(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code position.");

    // CAUTION! The top-left terminal corner is 1:1,
    // but the given cybol positions start counting from 0,
    // so that 1 has to be added to all positions!
    // Therefore, the coordinates handed over need to be corrected.

    // The y, x coordinates.
    int cy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
#ifdef WIN32
    // The standard output.
    HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);

    if (((void*) o) != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The position coordinates in a console screen buffer.
        // The origin of the coordinate system (0,0)
        // is at the top, left cell of the buffer.
        COORD p;
        p.X = cx;
        p.Y = cy;

        BOOL b = SetConsoleCursorPosition(o, p);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise ansi escape code position.");
            log_windows_system_error(e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise ansi escape code position. The standard output is null.");
    }
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    // Correct y, x coordinates.
    // The origin of the coordinate system (1,1)
    // is at the top, left cell of the terminal.
    calculate_integer_add((void*) &cy, p2);
    calculate_integer_add((void*) &cy, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_add((void*) &cx, p1);
    calculate_integer_add((void*) &cx, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //
    // Position cursor.
    //

    append_item_element(p0, (void*) ESCAPE_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ANSI_ESCAPE_CODE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    serialise_cybol_integer_value(p0, (void*) &cy, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    append_item_element(p0, (void*) SEMICOLON_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    serialise_cybol_integer_value(p0, (void*) &cx, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    append_item_element(p0, (void*) LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#endif
}

/* POSITION_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
