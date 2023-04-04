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

#ifndef MULTIPLY_POINTER_CALCULATOR_SOURCE
#define MULTIPLY_POINTER_CALCULATOR_SOURCE

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Calculates the difference between two pointers.
 *
 * @param p0 the difference
 * @param p1 the minuend
 * @param p2 the subtrahend
 */
void calculate_pointer_difference(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** s = (void**) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** m = (void**) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* d = (int*) p0;

                //
                // CAUTION! This test of the dereferenced pointer for null IS IMPORTANT.
                // Functions like "add_offset" use pointer calculation
                // WITHOUT testing operands for null before.
                // Therefore, also the INTERNAL (encapsulated) pointer has to be tested here.
                // Otherwise, an offset might be added to a null pointer
                // leading to wild pointers with unpredictable behaviour.
                //
                if (*s != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    //
                    // CAUTION! This test of the dereferenced pointer for null IS IMPORTANT.
                    // Functions like "add_offset" use pointer calculation
                    // WITHOUT testing operands for null before.
                    // Therefore, also the INTERNAL (encapsulated) pointer has to be tested here.
                    // Otherwise, an offset might be added to a null pointer
                    // leading to wild pointers with unpredictable behaviour.
                    //
                    if (*m != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate pointer difference.");

                        *d = *m - *s;

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer difference. The dereferenced minuend is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer difference. The dereferenced subtrahend is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer difference. The difference is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer difference. The minuend is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate pointer difference. The subtrahend is null.");
    }
}

/* DIFFERENCE_POINTER_CALCULATOR_SOURCE */
#endif
