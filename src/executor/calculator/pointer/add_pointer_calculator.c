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

#ifndef ADD_POINTER_CALCULATOR_SOURCE
#define ADD_POINTER_CALCULATOR_SOURCE

#include "../../../logger/logger.c"

/**
 * Adds the summand to the sum pointer.
 *
 * @param p0 the sum, which is the first summand BEFORE the operation
 * @param p1 the summand
 */
void calculate_pointer_add(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** sum = (void**) p0;

            //
            // CAUTION! This test of the dereferenced pointer for null IS IMPORTANT.
            // Functions like "add_offset" use pointer calculation
            // WITHOUT testing operands for null before.
            // Therefore, also the INTERNAL (encapsulated) pointer has to be tested here.
            // Otherwise, an offset might be added to a null pointer
            // leading to wild pointers with unpredictable behaviour.
            //
            if (*sum != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // CAUTION! Do NOT call the logger here.
                // It uses functions causing circular references.
                // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate pointer add.");

                *sum = (void*) ((size_t) *sum + *s);

            } else {

                // CAUTION! Do NOT call the logger here.
                // It uses functions causing circular references.
                // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer add. The dereferenced sum is null.");
            }

        } else {

            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer add. The sum is null.");
        }

    } else {

        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer add. The summand is null.");
    }
}

/* ADD_POINTER_CALCULATOR_SOURCE */
#endif
