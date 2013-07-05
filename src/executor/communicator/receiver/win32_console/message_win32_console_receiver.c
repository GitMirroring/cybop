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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MESSAGE_WIN32_CONSOLE_RECEIVER_SOURCE
#define MESSAGE_WIN32_CONSOLE_RECEIVER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Receives a win32 console message.
 *
 * @param p0 the input buffer data
 * @param p1 the input buffer count
 * @param p2 the input buffer size
 */
void receive_win32_console_message(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DWORD* is = (DWORD*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            DWORD* ic = (DWORD*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                INPUT_RECORD* id = (INPUT_RECORD*) p0;

                // The input console item.
                void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
                // The input console item data.
                void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;

                // Get input console item.
                copy_array_forward((void*) &c, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
                // Get input console item data.
                // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                // Inside the structure, arrays may have been reallocated,
                // with elements pointing to different memory areas now.
                copy_array_forward((void*) &cd, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

                if (cd != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* cdi = (int*) cd;

                    // Cast DEREFERENCED value to handle.
                    // CAUTION! The input data is stored as int value,
                    // but actually references a win32 console handle.
                    // This is just to be sure that the correct type is used.
                    HANDLE h = (HANDLE) *cdi;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive win32 console.");

                    // Receive and REMOVE data from console input buffer.
                    // CAUTION! The function does not return until
                    // at least one input record has been read.
                    BOOL b = ReadConsoleInputW(h, id, *is, ic);

                    // If the return value is zero, then an error occured.
                    if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // CAUTION! Setting a mutex is NOT necessary here,
                        // since this is the main thread and no other threads
                        // are writing to the interrupt request variable.

                        if (*ic > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                            fwprintf(stdout, L"TEST events received ic: %i\n", *ic);
                        }

                    } else {

                        // Get the calling thread's last-error code.
                        DWORD e = GetLastError();

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense win32 console. The peek console input failed.");
                        log_windows_system_error((void*) &e);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console. The input console item data is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console. The input buffer data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console. The input buffer count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console. The input buffer size is null.");
    }
}

/* MESSAGE_WIN32_CONSOLE_RECEIVER_SOURCE */
#endif
