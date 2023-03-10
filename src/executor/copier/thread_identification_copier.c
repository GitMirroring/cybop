/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef THREAD_IDENTIFICATION_COPIER_SOURCE
#define THREAD_IDENTIFICATION_COPIER_SOURCE

#include <threads.h> // thrd_t

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../logger/logger.c"

/**
 * Copies the thread identification.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_thread_identification(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        thrd_t* s = (thrd_t*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            thrd_t* d = (thrd_t*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy thread identification.");
            //?? fwprintf(stdout, L"Debug: Copy thread identification. p0: %i\n", p0);

            *d = *s;

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy thread identification. The destination is null.");
            fwprintf(stdout, L"Error: Could not copy thread identification. The destination is null. p0: %i\n", p0);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy thread identification. The source is null.");
        fwprintf(stdout, L"Error: Could not copy thread identification. The source is null. p1: %i\n", p1);
    }
}

/* THREAD_IDENTIFICATION_COPIER_SOURCE */
#endif
