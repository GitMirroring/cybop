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

#ifndef MODULO_INTEGER_CALCULATOR_SOURCE
#define MODULO_INTEGER_CALCULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../logger/logger.c"

/**
 * Determines the remainder of dividing the dividend by the divisor integer.
 *
 * Examples:
 * 14 % 7 = 0
 * 15 % 7 = 1
 *
 * @param p0 the remainder, which is the dividend BEFORE the operation
 * @param p1 the divisor
 */
void calculate_integer_modulo(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* r = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate integer modulo.");

            *r = *r % *d;

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate integer modulo. The remainder (dividend before) is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate integer modulo. The divisor is null.");
    }
}

/* MODULO_INTEGER_CALCULATOR_SOURCE */
#endif
