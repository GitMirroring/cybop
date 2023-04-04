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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DOUBLE_INTEGER_CASTER_SOURCE
#define DOUBLE_INTEGER_CASTER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Casts the source of type double to the destination of type integer.
 *
 * CAUTION! The fractional/decimal post-point value gets lost.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void cast_integer_double(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        double* s = (double*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* d = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Cast integer double.");
            //?? fwprintf(stdout, L"Debug: Cast integer double. source *p1: %f\n", *((int*) p1));

            // Cast double to integer value.
            *d = (int) *s;

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast integer double. The destination is null.");
            fwprintf(stdout, L"Error: Could not cast integer double. The destination is null. p0: %i\n", p0);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not cast integer double. The source is null.");
        fwprintf(stdout, L"Error: Could not cast integer double. The source is null. p1: %i\n", p1);
    }
}

/* DOUBLE_INTEGER_CASTER_SOURCE */
#endif
