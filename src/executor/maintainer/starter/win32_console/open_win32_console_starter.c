/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPEN_WIN32_CONSOLE_STARTER_SOURCE
#define OPEN_WIN32_CONSOLE_STARTER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/win32_console/get_mode_win32_console_starter.c"
#include "../../../../logger/logger.c"

/**
 * Opens the win32 console.
 *
 * @param p0 the input handle item data
 * @param p1 the output handle item data
 * @param p2 the internal memory data
 */
void startup_win32_console_open(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* o = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* i = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup win32 console open.");

            // Retrieve handle to specified standard device.
            //
            // CAUTION! A win32 console handle is just an int value.
            // If the function fails, the return value is INVALID_HANDLE_VALUE.
            // To get extended error information, call GetLastError.
            // If an application does not have associated standard handles,
            // such as a service running on an interactive desktop,
            // and has not redirected them, the return value is NULL.
            HANDLE hi = GetStdHandle(STD_INPUT_HANDLE);
            HANDLE ho = GetStdHandle(STD_OUTPUT_HANDLE);

            if (hi != NULL) {

                if (hi != INVALID_HANDLE_VALUE) {

                    *i = (int) hi;

                    // Configure input events.
                    //
                    // The mode can be one or more of the following values:
                    // ENABLE_ECHO_INPUT
                    // ENABLE_EXTENDED_FLAGS
                    // ENABLE_INSERT_MODE
                    // ENABLE_LINE_INPUT
                    // ENABLE_MOUSE_INPUT
                    // ENABLE_PROCESSED_INPUT
                    // ENABLE_QUICK_EDIT_MODE
                    // ENABLE_WINDOW_INPUT
                    //
                    // CAUTION! When a console is created, all input modes
                    // EXCEPT ENABLE_WINDOW_INPUT are enabled by default.
                    //
                    DWORD mi = ENABLE_ECHO_INPUT | ENABLE_EXTENDED_FLAGS | ENABLE_INSERT_MODE | ENABLE_LINE_INPUT | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT | ENABLE_QUICK_EDIT_MODE | ENABLE_WINDOW_INPUT;

                    // Store original and set new input mode.
                    startup_win32_console_mode_get((void*) &hi, p2, (void*) INPUT_MODE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) &mi);

                } else {

                    // Get the calling thread's last-error code.
                    DWORD e = GetLastError();

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The input handle is invalid.");
                    log_windows_system_error((void*) &e);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The input handle is null.");
            }

            if (ho != NULL) {

                if (ho != INVALID_HANDLE_VALUE) {

                    *o = (int) ho;

                    // Configure output events.
                    //
                    // The mode can be one or more of the following values:
                    // ENABLE_PROCESSED_OUTPUT
                    // ENABLE_WRAP_AT_EOL_OUTPUT
                    //
                    // CAUTION! When a screen buffer is created,
                    // BOTH output modes are enabled by default.
                    //
                    DWORD mo = ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT;

                    // Store original and set new output mode.
                    startup_win32_console_mode_get((void*) &ho, p2, (void*) OUTPUT_MODE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) &mo);

                } else {

                    // Get the calling thread's last-error code.
                    DWORD e = GetLastError();

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The output handle is invalid.");
                    log_windows_system_error((void*) &e);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The output handle is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The input item data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The output item data is null.");
    }
}

/* OPEN_WIN32_CONSOLE_STARTER_SOURCE */
#endif
