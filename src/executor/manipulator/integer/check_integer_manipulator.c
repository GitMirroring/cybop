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

#ifndef CHECK_INTEGER_MANIPULATOR_SOURCE
#define CHECK_INTEGER_MANIPULATOR_SOURCE

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Checks (in other words: gets) the bit at the given position.
 *
 * @param p0 the value
 * @param p1 the position
 */
void manipulate_integer_check(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* v = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate integer check.");

        // The bit mask.
        int b = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        // Prepare bit mask.
        manipulate_integer_shift_left((void*) &b, p1);

        // Apply and.
        //
        // CAUTION! The following code will NOT
        // get the bit value at position p,
        // unless the value is of type _Bool (<stdbool.h>).
        // Therefore, use double-NOT !! as workaround.
        // The first NOT characterises the number as boolean value.
        // The second NOT corrects the value back again.
        //
        // http://stackoverflow.com/questions/47981/how-do-you-set-clear-and-toggle-a-single-bit-in-c
        //
        //??logify_integer_and(p0, (void*) &b);
        *v = !!(*v & b);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate integer check. The value is null.");
    }
}

/* CHECK_INTEGER_MANIPULATOR_SOURCE */
#endif
