/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <errno.h> // errno
#include <stdio.h> // stdout
#include <unistd.h> // pipe
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Opens up a unix pipeline (pipe), also called "anonymous pipe".
 *
 * @param p0 the file descriptor array
 */
void open_unix_pipe(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open unix pipe.");
        // fwprintf(stdout, L"Debug: Open unix pipe. p0: %i\n", p0);

        //
        // Initialise error number.
        //
        // It is a global variable and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Create pipe.
        int r = pipe(f);

        // fwprintf(stdout, L"Debug: Open unix pipe. f[0]: %i\n", f[0]);
        // fwprintf(stdout, L"Debug: Open unix pipe. f[1]: %i\n", f[1]);

        if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open unix pipe. success.");
            // fwprintf(stdout, L"Debug: Open unix pipe. success. r: %i\n", r);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open unix pipe. An error occured.");
            fwprintf(stdout, L"Error: Could not open unix pipe. An error occured. %i\n", r);
            log_error((void*) &errno);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open unix pipe. The file descriptor array is null.");
    }
}
