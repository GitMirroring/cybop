/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <threads.h> // mtx_t, mtx_init, thrd_error
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "variable.h"

/**
 * Allocates the mutex.
 *
 * @param p0 the mutex (pointer reference)
 */
void allocate_mutex(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** m = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate mutex.");
        //?? fwprintf(stdout, L"Debug: Allocate mutex. p0: %i\n", p0);
        //?? fwprintf(stdout, L"Debug: Allocate mutex. *p0: %i\n", *((int*) p0));

        //
        // Allocate mutex.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);

        if (*m != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Cast mutex to correct type.
            mtx_t* t = (mtx_t*) *m;

            // Initialise mutex.
            int r = mtx_init(t, *PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME);

            // Evaluate mutex object creation result.
            if (r == thrd_error) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate mutex. The mutex object creation failed.");
                fwprintf(stdout, L"Error: Could not allocate mutex. The mutex object creation failed. mr: %i\n", r);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate mutex. The dereferenced mutex is null.");
            fwprintf(stdout, L"Error: Could not allocate mutex. The dereferenced mutex is null. *m: %i\n", *m);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not allocate mutex. The mutex is null.");
        fwprintf(stdout, L"Error: Could not allocate mutex. The mutex is null. p0: %i\n", p0);
    }
}
