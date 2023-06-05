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
 * Reads a win32 console message.
 *
 * @param p0 the input buffer data
 * @param p1 the input buffer count
 * @param p2 the input buffer size
 * @param p3 the internal memory data
 */
void read_win32_console_message(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DWORD* is = (DWORD*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            DWORD* ic = (DWORD*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                INPUT_RECORD* id = (INPUT_RECORD*) p0;

                // The input console.
                void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

                // Get input console.
                copy_array_forward((void*) &c, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

                if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* ci = (int*) c;

                    // Cast DEREFERENCED value to handle.
                    // CAUTION! The input data is stored as int value,
                    // but actually references a win32 console handle.
                    // This is just to be sure that the correct type is used.
                    HANDLE h = (HANDLE) *ci;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read win32 console message.");

                    // Read and REMOVE data from console input buffer.
                    //
                    // CAUTION! The function does not return until
                    // at least one input record has been read.
                    //
                    // CAUTION! The standard c function:
                    // wint_t c = fgetwc(stdin);
                    // does NOT work here, since it does not
                    // reliably detect arrow- and other keys.
                    // Therefore, a win32 function is used,
                    // since the KEY_EVENT_RECORD's elements
                    // "wVirtualScanCode" and "wVirtualKeyCode"
                    // help identify each (physical) key.
                    BOOL b = ReadConsoleInputW(h, id, *is, ic);

                    //?? fwprintf(stdout, L"Debug: read win32 console message *id.Event.uChar: %i\n", (*id).Event.KeyEvent.uChar);
                    //?? fwprintf(stdout, L"vread win32 console message *id.Event.uChar as char: %lc\n", (*id).Event.KeyEvent.uChar);

                    // If the return value is zero, then an error occured.
                    if (b == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        fwprintf(stdout, L"Debug: read win32 console message ERROR returned from ReadConsoleInputW b: %i\n", b);

                        // Get the calling thread's last-error code.
                        DWORD e = GetLastError();

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 console message. The read console input failed.");
                        log_error((void*) &e);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 console message. The input console item data is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 console message. The input buffer data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 console message. The input buffer count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 console message. The input buffer size is null.");
    }
}
