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

#ifndef DESCRIPTOR_TO_STREAM_CONVERTER_SOURCE
#define DESCRIPTOR_TO_STREAM_CONVERTER_SOURCE

#include <errno.h> // errno
#include <stdio.h> // fdopen

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../logger/logger.c"

/**
 * Converts a file descriptor to a file stream.
 *
 * @param p0 the destination file stream (pointer reference)
 * @param p1 the source file descriptor
 * @param p2 the opentype
 */
void convert_descriptor_to_stream(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        char* t = (char*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* d = (int*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** s = (void**) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Convert descriptor to stream.");

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

                *s = (void*) fdopen(*d, t);

                if (*s != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Convert descriptor to stream. Success.");
                    fwprintf(stdout, L"Debug: Convert descriptor to stream. Success. *s: %i\n", *s);

                } else {

                    //
                    // An error occured.
                    //

                    fwprintf(stdout, L"Could not convert descriptor to stream. The file stream is null. *d: %i\n", *d);

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not convert descriptor to stream. An unknown error occured.");
                    fwprintf(stdout, L"Error: Could not convert descriptor to stream. An unknown error occured. errno: %i file descriptor *d: %i\n", errno, *d);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not convert descriptor to stream. The file stream is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not convert descriptor to stream. The file descriptor is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not convert descriptor to stream. The opentype is null.");
    }
}

/* DESCRIPTOR_TO_STREAM_CONVERTER_SOURCE */
#endif
