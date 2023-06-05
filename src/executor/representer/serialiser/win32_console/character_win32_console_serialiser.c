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

#include "constant.h"
#include "logger.h"

//
// Win32 console applications are often mistaken for MS-DOS applications,
// especially on Windows 9x and Windows ME. However, a Win32 console application is,
// virtually, just a special form of a native Win32 application.
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
 * @param p0 the destination win32 console output data
 * @param p1 the source character data
 * @param p2 the source character count
 */
void serialise_win32_console_character(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* d = (int*) p0;

                // Cast DEREFERENCED value to handle.
                // CAUTION! The output data is stored as int value,
                // but actually references a win32 console handle.
                // This is just to be sure that the correct type is used.
                HANDLE dh = (HANDLE) *d;

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
                // But this should not matter, since the position of each
                // character is set before writing it.
                //
                // Characters are written using the foreground and background
                // colour attributes associated with the console screen buffer.
                //
                // There is a Unicode version of the function called "WriteConsoleW".
                //
                // However, mind the following bug report:
                // "WriteConsoleW fails when more than about 26000 characters are written"
                // http://msdn.microsoft.com/en-us/library/ms687401(v=vs.85).aspx
                //
                // While the documentation claims that up to 65536 bytes can be written
                // (presumably that means 32767 UTF-16 characters + NUL),
                // the actual limit is smaller. It varies between machines,
                // but typically is between 26000 and 32000 characters.
                // Attempting to write more than this in a single call
                // to WriteConsoleW will fail; see for example:
                // http://www.mail-archive.com/log4net-dev@logging.apache.org/msg00661.html
                // and:
                // http://tahoe-lafs.org/trac/tahoe-lafs/ticket/1232
                //
                // It's not clear whether this also applies to WriteConsoleA.
                // This issue has been submitted to Microsoft Connect at:
                // https://connect.microsoft.com/VisualStudio/feedback/details/635230/writeconsolew-fails-for-strings-larger-than-about-26000-characters
                //
                // The Win32 API provides two approaches for console I/O:
                // - high-level: Read/WriteConsole and Read/WriteFile functions,
                // - low-level: requiring access to console screen and input buffers,
                //   keyboard, mouse, and buffer-resizing events
                //
                // Only high-level functions are used here.
                //
                // Both WriteConsole and WriteFile can take Unicode parameters.
                // The difference between them is:
                // - WriteConsole writes Unicode characters to console,
                //   but works on console handles only.
                //   It does not work if the output is redirected to a disk file.
                // - WriteFile can take a handle of any file, so that the output
                //   can be redirected to a file or a pipe.
                //   However, the encoding is assumed to be in the current
                //   console-output code page.
                //   A Unicode input array will be displayed as garbage.
                //
                // http://automatismo.ru/32ch03g.shtml
                //
                BOOL b = WriteConsoleW(dh, p1, *sc, &n, *NULL_POINTER_STATE_CYBOI_MODEL);

                // If the return value is zero, then an error occured.
                if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // Get the calling thread's last-error code.
                    DWORD e = GetLastError();

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console character. A windows system error occured.");
                    log_error((void*) &e);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console character. The standard output is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console character. The source character data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 console character. The source character count is null.");
    }
}
