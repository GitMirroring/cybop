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

#ifndef FILE_STREAM_CLOSER_SOURCE
#define FILE_STREAM_CLOSER_SOURCE

#include <errno.h> // errno
#include <stdio.h> // FILE, fclose

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../logger/logger.c"

/**
 * Closes a file stream.
 *
 * @param p0 the file stream
 */
void close_file_stream(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE* s = (FILE*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close file stream.");

        //
        // Initialise error number.
        //
        // It is a global variable/function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Close file.
        //
        // CAUTION! Check file for null pointer above
        // in order to avoid a segmentation fault here!
        //
        int r = fclose(s);

        if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close file stream. Success.");
            //?? fwprintf(stdout, L"Debug: Close file stream. Success. r: %i\n", r);

        } else {

            //
            // An error occured.
            //

            fwprintf(stdout, L"Could not close file stream. The function returned a value unequal to zero. s: %i\n", s);

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close file stream. An unknown error occured.");
            fwprintf(stdout, L"Error: Could not close file stream. An unknown error occured. errno: %i file stream s: %i\n", errno, s);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close file stream. The file stream is null.");
    }
}

/* FILE_STREAM_CLOSER_SOURCE */
#endif
