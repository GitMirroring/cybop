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

#ifndef SUBTRACT_POINTER_CALCULATOR_SOURCE
#define SUBTRACT_POINTER_CALCULATOR_SOURCE

#include "logger.h"

/**
 * Subtracts the subtrahend from the minuend pointer.
 *
 * @param p0 the difference, which is the minuend BEFORE the operation
 * @param p1 the subtrahend
 */
void calculate_pointer_subtract(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** d = (void**) p0;

            //
            // CAUTION! This test of the dereferenced pointer for null IS IMPORTANT.
            // Functions like "add_offset" use pointer calculation
            // WITHOUT testing operands for null before.
            // Therefore, also the INTERNAL (encapsulated) pointer has to be tested here.
            // Otherwise, an offset might be added to a null pointer
            // leading to wild pointers with unpredictable behaviour.
            //
            if (*d != *NULL_POINTER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate pointer subtract.");

                *d = (void*) ((size_t) *d - *s);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer subtract. The dereferenced difference is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer subtract. The difference is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer subtract. The subtrahend is null.");
    }
}

/* SUBTRACT_POINTER_CALCULATOR_SOURCE */
#endif
