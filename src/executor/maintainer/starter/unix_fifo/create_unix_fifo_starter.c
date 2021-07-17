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

#ifndef CREATE_UNIX_FIFO_STARTER_SOURCE
#define CREATE_UNIX_FIFO_STARTER_SOURCE

#include <unistd.h> // pipe
#include <errno.h> // errno

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../logger/logger.c"

/**
 * Creates a unix fifo, also called "named pipe".
 *
 * The reading and writing ends of the pipe are stored in the array.
 * An easy way to remember that the input end comes first is that
 * file descriptor 0 is standard input, and file descriptor 1 is standard output.
 *
 * @param p0 the file descriptors array (pointer reference)
 */
void startup_unix_fifo_create(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** f = (void**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix fifo create.");

        //
        // Allocate file descriptors array.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        fwprintf(stdout, L"Test: Startup unix fifo create. *f: %i\n", *f);

        //
        // Initialise error number.
        // It is a global variable/function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling the
        // function that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // The file descriptors array with casted type.
        int* ft = (int*) *f;

        // Create pipe.
        int r = pipe(ft);

        fwprintf(stdout, L"Test: Startup unix fifo create. r: %i\n", r);
        fwprintf(stdout, L"Test: Startup unix fifo create. ft[0]: %i\n", ft + 0);
        fwprintf(stdout, L"Test: Startup unix fifo create. *ft[0]: %i\n", *(ft + 0));
        fwprintf(stdout, L"Test: Startup unix fifo create. ft[1]: %i\n", ft + 1);
        fwprintf(stdout, L"Test: Startup unix fifo create. *ft[1]: %i\n", *(ft + 1));

        if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix fifo create success.");
            fwprintf(stdout, L"Information: Startup unix fifo create success. r: %i\n", r);

        } else {

            //
            // An error occured.
            //

            fwprintf(stdout, L"Error: Could not startup unix fifo create. errno: %i\n", errno);

            if (errno == EMFILE) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. The process has too many files open.");
                fwprintf(stdout, L"Error: Could not startup unix fifo create. The process has too many files open. EMFILE: %i\n", errno);

            } else if (errno == ENFILE) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. There are too many open files in the entire system.");
                fwprintf(stdout, L"Error: Could not startup unix fifo create. There are too many open files in the entire system. ENFILE: %i\n", errno);
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. The file descriptor array is null.");
    }
}

/* CREATE_UNIX_FIFO_STARTER_SOURCE */
#endif
