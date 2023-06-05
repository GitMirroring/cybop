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

#include <windows.h>

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Serialises the attributes into win32 console function calls.
 *
 * Example:
 * BOOL b = SetConsoleTextAttribute(standard_output_handle, character_attributes);
 *
 * The character attributes are of type WORD and may be combined using OR, e.g.:
 * SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
 *
 * @param p0 the destination win32 console output data
 * @param p1 the source background
 * @param p2 the source foreground
 * @param p3 the source hidden
 * @param p4 the source inverse
 * @param p5 the source blink
 * @param p6 the source underline
 * @param p7 the source bold (foreground text colour)
 * @param p8 the source intense (background colour)
 */
void serialise_win32_console_attributes(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        // Cast DEREFERENCED value to handle.
        // CAUTION! The output data is stored as int value,
        // but actually references a win32 console handle.
        // This is just to be sure that the correct type is used.
        HANDLE dh = (HANDLE) *d;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console attributes.");

        // The console screen buffer info.
        CONSOLE_SCREEN_BUFFER_INFO i;

        // Fill console screen buffer info.
        BOOL b = GetConsoleScreenBufferInfo(dh, &i);

        // If the return value is zero, then an error occured.
        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The attributes.
            // CAUTION! Do NOT just initialise them like:
            // WORD a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Otherwise, all values are reset and background
            // as well as foreground colour set to black,
            // leading to invisible output.
            WORD a = i.wAttributes;

            // Assign colours.
            //
            // CAUTION! The attributes are manipulated by
            // adding new values using the OR operator, e.g.:
            // *a = *a | FOREGROUND_RED | FOREGROUND_INTENSITY;
            //
            serialise_win32_console_background((void*) &a, p1);
            serialise_win32_console_foreground((void*) &a, p2);

            // CAUTION! The "intensity" constants below can NOT be
            // handed over as reference directly below since then,
            // the following error occurs:
            // "lvalue required as unary ‘&’ operand"
            // Therefore, the following variables had to be
            // introduced, in order to be forwarded as parametre.

            // The foreground (text) intensity attribute.
            WORD fi = FOREGROUND_INTENSITY;
            // The background intensity attribute.
            WORD bi = BACKGROUND_INTENSITY;

            // Set further attributes.
            //
            // - hidden: ??
            // - inverse: does NOT work (see community comment below)
            // - blink: ??
            // - underline: does NOT work (see community comment below)
            // - bold: intense foreground text colour
            // - intense: intense background colour (not supported by ansi escape code)
            //
            // Community comment on:
            // http://msdn.microsoft.com/en-us/library/ms682088(v=vs.85).aspx#_win32_character_attributes
            // COMMON_LVB_UNDERSCORE and COMMON_LVB_REVERSE_VIDEO does not work!
            //
            serialise_win32_console_effect((void*) &a, (void*) &fi, p7);
            serialise_win32_console_effect((void*) &a, (void*) &bi, p8);

            // Set attributes of characters written to the console screen buffer.
            //
            // CAUTION! Under win32 console, unfortunately,
            // the display mode is locked in background
            // intensity mode, thus BLINKING does NOT work.
            // Also, the UNDERSCORE attribute is NOT available.
            //
            // http://msdn.microsoft.com/en-us/library/ms686047(v=vs.85).aspx
            // http://msdn.microsoft.com/en-us/library/ms682088(v=vs.85).aspx#_win32_character_attributes
            b = SetConsoleTextAttribute(dh, a);

            // If the return value is zero, then an error occured.
            if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Get the calling thread's last-error code.
                DWORD e = GetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console attributes. The text attributes could not be set.");
                log_error((void*) &e);
            }

        } else {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console attributes. The console screen buffer info could not be retrieved.");
            log_error((void*) &e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console attributes. The standard output is null.");
    }
}
