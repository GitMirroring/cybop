/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef OPEN_WIN32_CONSOLE_STARTER_SOURCE
#define OPEN_WIN32_CONSOLE_STARTER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Opens the win32 console.
 *
 * @param p0 the destination output file descriptor
 * @param p1 the destination input file descriptor
 */
void startup_win32_console_open(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup win32 console open.");

    // The terminal output- and input identification.
    DWORD oi = STD_OUTPUT_HANDLE;
    DWORD ii = STD_INPUT_HANDLE;

    //
    // Retrieve handle to specified standard device.
    //
    // CAUTION! A win32 console handle is just an int value.
    // If the function fails, the return value is INVALID_HANDLE_VALUE.
    // To get extended error information, call GetLastError.
    // If an application does not have associated standard handles,
    // such as a service running on an interactive desktop,
    // and has not redirected them, the return value is NULL.
    //
    HANDLE oh = GetStdHandle(oi);
    HANDLE ih = GetStdHandle(ii);

    // Get terminal file descriptors from file streams.
    int o = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    if (oh != NULL) {

        if (oh != INVALID_HANDLE_VALUE) {

            // Cast file descriptor.
            o = (int) oh;

            // Copy file descriptor to destination.
            copy_integer(p0, (void*) &o);

        } else {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The output handle is invalid.");
            log_windows_system_error((void*) &e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The output handle is null.");
    }

    if (ih != NULL) {

        if (ih != INVALID_HANDLE_VALUE) {

            // Cast file descriptor.
            i = (int) ih;

            // Copy file descriptor to destination.
            copy_integer(p1, (void*) &i);

        } else {

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The input handle is invalid.");
            log_windows_system_error((void*) &e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console open. The input handle is null.");
    }
}

/* OPEN_WIN32_CONSOLE_STARTER_SOURCE */
#endif
