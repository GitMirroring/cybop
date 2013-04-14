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

#ifndef CHARACTER_WIN32_CONSOLE_SERIALISER_SOURCE
#define CHARACTER_WIN32_CONSOLE_SERIALISER_SOURCE

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

//
// Win32 console applications are often mistaken for MS-DOS applications,
// especially on Windows 9x and Windows Me. However, a Win32 console
// application is, virtually, just a special form of a native Win32 application.
// Indeed, 32-bit Windows can run MS-DOS programs in Win32 console
// through the use of the NT Virtual DOS Machine (NTVDM).
//
// Programmes may access a Win32 console either via high-level functions
// (such as ReadConsole and WriteConsole) or via low-level functions
// (e.g. ReadConsoleInput and WriteConsoleOutput).
// These high-level functions are more limited than a Win32 GUI;
// for instance it is not possible for a programme to change the color palette,
// nor is it possible to modify the font used by the console using these functions.
//
// The input buffer is a queue where events are stored (from keyboard, mouse etc.).
// The output buffer is a rectangular grid where characters are stored,
// together with their attributes. A console window may have several output
// buffers, only one of which is active (i.e. displayed) for a given moment.
//

/**
 * Serialises the character into win32 console function calls.
 *
 * Example:
 * BOOL b = WriteConsole(standard_output_handle, character_array, character_array_count, number_of_characters_written, reserved_always_null);
 *
 * @param p0 the destination item
 * @param p1 the source character
 */
void serialise_win32_console_character(void* p0, void* p1) {

    // Get standard output.
    HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);

    if (((void*) o) != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 console character.");

        // The number of characters actually written.
        // It will be handed over below as pointer to a variable.
        DWORD n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Write to screen buffer.
        //
        // The "WriteConsole" function writes characters to the
        // console screen buffer at the current cursor position.
        //
        // CAUTION! The cursor position ADVANCES as characters are written.
        //
        // Characters are written using the foreground and background
        // colour attributes associated with the console screen buffer.
        // Information: To determine the current color attributes and
        // the current cursor position, use "GetConsoleScreenBufferInfo".
        //
        // The function uses either Unicode characters or
        // ANSI characters from the console's current code page.
        // Since cyboi uses wide characters only, there should be no problem.
        //
        // Be sure to prefix a Unicode plain text file with a byte order mark.
        // It informs an application receiving the file that the file is byte-ordered.
        // Available byte order marks are listed in the following table.
        // Because Unicode plain text is a sequence of 16-bit code values,
        // it is sensitive to the byte ordering used when the text is written.
        // Note: A byte order mark is NOT a control character
        // that selects the byte order of the text.
        //
        // -----------------------------------------
        // Byte order mark  | Description
        // -----------------------------------------
        // EF BB BF         | UTF-8
        // FF FE            | UTF-16, little endian
        // FE FF            | UTF-16, big endian
        // FF FE 00 00      | UTF-32, little endian
        // 00 00 FE FF      | UTF-32, big-endian
        // -----------------------------------------
        //
        // http://msdn.microsoft.com/en-us/library/dd374101(v=vs.85).aspx
        //
        BOOL b = WriteConsole(o, p1, *NUMBER_1_INTEGER_STATE_CYBOI_MODEL, &n, *NULL_POINTER_STATE_CYBOI_MODEL);

        // If the return value is zero, then an error occured.
        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console character. A windows system error occured.");
            log_windows_system_error(e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console character. The standard output is null.");
    }
}

/* CHARACTER_WIN32_CONSOLE_SERIALISER_SOURCE */
#endif

/* WIN32 */
#endif
