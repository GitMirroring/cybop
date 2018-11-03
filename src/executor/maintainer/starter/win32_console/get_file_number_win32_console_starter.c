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

#ifndef GET_FILE_NUMBER_WIN32_CONSOLE_STARTER_SOURCE
#define GET_FILE_NUMBER_WIN32_CONSOLE_STARTER_SOURCE

#include <stdio.h> // FILE, _fileno
#include <windows.h> // DWORD

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Gets the file number from the given file stream.
 *
 * The file number has various synonyms:
 * - posix: file descriptor of type int, used in direct file access functions
 * - win32: file handle of type DWORD, used in alternative input/output functions
 *
 * @param p0 the file number
 * @param p1 the file stream
 */
void startup_win32_console_file_number_get(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE* s = (FILE*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup win32 console file number get.");

        // Get terminal file number (descriptor) from file stream.
        int n = _fileno(s);

        if (n >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Copy file number (descriptor) to destination.
            copy_integer(p0, (void*) &n);

        } else {

            // The return value is negative, which means that an error occured.

            //
            // CAUTION! Do NOT close win32 console on error,
            // since stdin and stdout were used and have to remain open.
            //

            // Get the calling thread's last-error code.
            DWORD e = GetLastError();

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console file number get. The _fileno function failed.");
            log_windows_system_error((void*) &e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 console file number get. The file stream is null.");
    }
}

/* GET_FILE_NUMBER_WIN32_CONSOLE_STARTER_SOURCE */
#endif
