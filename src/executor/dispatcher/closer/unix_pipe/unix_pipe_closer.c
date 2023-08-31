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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "client.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Closes down a unix pipeline (pipe), also called "anonymous pipe".
 *
 * @param p0 the file descriptor array
 */
void close_unix_pipe(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close unix pipe.");
        //?? fwprintf(stdout, L"Debug: Close unix pipe. p0: %i\n", p0);

        // The read file descriptor.
        int r = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The write file descriptor.
        int w = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // Get read file descriptor.
        copy_array_forward((void*) &r, p0, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        // Get write file descriptor.
        copy_array_forward((void*) &w, p0, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        //?? fwprintf(stdout, L"Debug: Close unix pipe. r: %i\n", r);
        //?? fwprintf(stdout, L"Debug: Close unix pipe. w: %i\n", w);

        // Close read file descriptor.
        close_basic((void*) &r);
        // Close write file descriptor.
        close_basic((void*) &w);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close unix pipe. The file descriptor array is null.");
        fwprintf(stdout, L"Error: Could not close unix pipe. The file descriptor array is null. p0: %i\n", p0);
    }
}
