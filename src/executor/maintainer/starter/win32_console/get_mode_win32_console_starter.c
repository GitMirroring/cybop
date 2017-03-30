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

#ifndef GET_MODE_WIN32_CONSOLE_STARTER_SOURCE
#define GET_MODE_WIN32_CONSOLE_STARTER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/win32_console/set_mode_win32_console_starter.c"
#include "../../../../logger/logger.c"

/**
 * Gets the win32 console mode.
 *
 * @param p0 the input or output handle data
 * @param p1 the internal memory data
 * @param p2 the internal memory index
 * @param p3 the new input or output mode
 */
void startup_win32_console_mode_get(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        HANDLE* h = (HANDLE*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup win32 console mode get.");

        // The mode.
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate mode.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_array((void*) &m, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        if (m != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get current mode.
            BOOL b = GetConsoleMode(*h, (DWORD*) m);

            // If the return value is zero, then an error occured.
            if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Store original mode in internal memory,
                // in order to be restored on exit.
                copy_array_forward(p1, (void*) &m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                // Set new mode.
                startup_win32_console_mode_set(p0, p3);

            } else {

                //?? Close win32 console on error.

                // Get the calling thread's last-error code.
                DWORD e = GetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console mode get. The get console mode failed.");
                log_windows_system_error((void*) &e);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console mode get. The mode is null.");
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console mode get. The input or output handle data is null.");
    }
}

/* GET_MODE_WIN32_CONSOLE_STARTER_SOURCE */
#endif
