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

#ifndef AVAILABLE_ELEMENT_CLIENT_CHECKER_SOURCE
#define AVAILABLE_ELEMENT_CLIENT_CHECKER_SOURCE

#include <time.h> // time_t

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "logger.h"

/**
 * Checks open client for available data.
 *
 * @param p0 the destination client
 * @param p1 the accepttime list data (pointer reference)
 * @param p2 the list index
 * @param p3 the source client
 * @param p4 the current calendar time
 */
void check_client_element_available(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        time_t* t = (time_t*) p4;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** al = (void**) p1;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check client element available.");

            // Copy client.
            copy_integer(p0, p3);

            // The current calendar time as integer value.
            int ti = (int) *t;

            //
            // Reset sender client accepttime in accepttime list item
            // at the given index, using the current calendar time.
            //
            copy_array_forward(*al, (void*) &ti, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check client element empty. The accepttime list data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check client element available. The current calendar time is null.");
    }
}

/* AVAILABLE_ELEMENT_CLIENT_CHECKER_SOURCE */
#endif
