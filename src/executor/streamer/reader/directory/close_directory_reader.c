/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CLOSE_DIRECTORY_READER_SOURCE
#define CLOSE_DIRECTORY_READER_SOURCE

#include <dirent.h>
#include <errno.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Closes the given directory.
 *
 * @param p0 the directory stream
 */
void read_directory_close(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DIR* d = (DIR*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read directory close.");

        // Initialise error number.
        // It is a global variable/function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the procedure that might cause an error.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Close directory stream.
        int e = closedir(d);

        if (e != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // An error occured.

            if (errno == EBADF) {

                fwprintf(stdout, L"Could not read directory close. The stream closing return value is unequal zero. The dirstream argument is not valid. error EBADF: %i\n", errno);
                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory close. The stream closing return value is unequal zero. The dirstream argument is not valid.");

            } else {

                fwprintf(stdout, L"Could not read directory close. The stream closing return value is unequal zero. An unknown error occured. errno: %i\n", errno);
                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory close. The stream closing return value is unequal zero. An unknown error occured.");
            }

            // CAUTION! The gnu c library manual writes:
            // To avoid entering an infinite loop, you should stop
            // reading from the directory after the first error.
            // Therefore, the BREAK FLAG is set here, in order to
            // leave the loop that is processing directory entries.
//??            copy_integer(px??_break_flag, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory close. The directory is null.");
    }
}

/* CLOSE_DIRECTORY_READER_SOURCE */
#endif
