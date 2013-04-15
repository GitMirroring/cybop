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

#ifndef ATTRIBUTES_WIN32_CONSOLE_SERIALISER_SOURCE
#define ATTRIBUTES_WIN32_CONSOLE_SERIALISER_SOURCE

#include <stdio.h>
#include <wchar.h>
#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the attributes into win32 console function calls.
 *
 * Example:
 * BOOL b = SetConsoleTextAttribute(standard_output_handle, character_attributes);
 *
 * The character attributes are of type WORD and may be combined using OR, e.g.:
 * SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
 *
 * @param p0 the destination item
 * @param p1 the source background
 * @param p2 the source foreground
 * @param p3 the source hidden
 * @param p4 the source inverse
 * @param p5 the source blink
 * @param p6 the source underline
 * @param p7 the source bold
 */
void serialise_win32_console_attributes(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    // Get standard output.
    HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);

    if (((void*) o) != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console attributes.");

        // The screen information.
        // It is a structure that contains information
        // about the console screen buffer.
        PCONSOLE_SCREEN_BUFFER_INFO i;

        // Get current attributes.
        BOOL b = GetConsoleScreenBufferInfo(o, &i);

        // If the return value is zero, then an error occured.
        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get current attributes.
            WORD a = i.wAttributes;

            // Assign attributes.
            // CAUTION! The current attributes are manipulated
            // by adding new values using the OR operator.
            a = a | FOREGROUND_RED | FOREGROUND_INTENSITY;

            // Community comment on:
            // http://msdn.microsoft.com/en-us/library/ms682088(v=vs.85).aspx#_win32_character_attributes
            // COMMON_LVB_UNDERSCORE and COMMON_LVB_REVERSE_VIDEO does not work!

            // Set attributes of characters written to the console screen buffer.
            //
            // CAUTION! Under win32 console, unfortunately,
            // the display mode is locked in background
            // intensity mode, thus BLINKING does NOT work.
            // Also, the UNDERSCORE attribute is NOT available.
            //
            // http://msdn.microsoft.com/en-us/library/ms686047(v=vs.85).aspx
            // http://msdn.microsoft.com/en-us/library/ms682088(v=vs.85).aspx#_win32_character_attributes
            b = SetConsoleTextAttribute(o, a);

            // If the return value is zero, then an error occured.
            if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Get the calling thread's last-error code.
                DWORD e = GetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console attributes. The text attributes could not be set.");
                log_windows_system_error(e);
            }

        } else {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console attributes. The console screen buffer info could not be retrieved.");
            log_windows_system_error(e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console attributes. The standard output is null.");
    }
}

/* ATTRIBUTES_WIN32_CONSOLE_SERIALISER_SOURCE */
#endif

/* WIN32 */
#endif
