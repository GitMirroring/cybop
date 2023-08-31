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
 * @author Falk Müller <falk89@web.de>
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <math.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Round the source downwards to the nearest integer and
 * store it in destination, which, however, is of type "double".
 *
 * Example:
 * floor (1.5) is 1.0 and floor (-1.5) is -2.0
 *
 * @param p0 the destination
 * @param p1 the source
 */
void calculate_double_floor(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

       double* s = (double*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            double* d = (double*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate double floor.");

            // CAUTION! Do NOT use the "abs" function,
            // which is for integer values.

            *d = floor(*s);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate double floor. The destination is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate double floor. The source is null.");
    }
}
