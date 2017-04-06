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

#ifndef CLOSE_UNIX_TERMINAL_SHUTTER_SOURCE
#define CLOSE_UNIX_TERMINAL_SHUTTER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Closes the unix terminal.
 *
 * @param p0 the file descriptor data
 */
void shutdown_unix_terminal_close(void* p0) {

    //
    // CAUTION! Do NOT close the file descriptor here.
    //
    // The standard input/output were assigned
    // at startup, and they MUST NOT be closed.
    // Therefore, this whole block ist disabled.
    //
    // This might change later, in case a new
    // pseudo terminal (not standard input/output)
    // is created and assigned at startup.
    //

/*??
    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown unix terminal close.");

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        // Close file descriptor.
        int e = close(*d);

        // The normal return value from "close" is zero;
        // a value of minus one is returned in case of failure.
        if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            if (errno == EBADF) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. The filedes argument is not a valid file descriptor.");

            } else if (errno == EINTR) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. The close call was interrupted by a signal.");

            } else if (errno == ENOSPC) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. ENOSPC.");

            } else if (errno == EIO) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. EIO.");

            } else if (errno == EDQUOT) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. When the file is accessed by NFS, these errors from write can sometimes not be detected until close.");

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. An unknown error occured.");
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal close. The file descriptor data is null.");
    }
*/
}

/* CLOSE_UNIX_TERMINAL_SHUTTER_SOURCE */
#endif
