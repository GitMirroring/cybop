/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REDUCE_FRACTION_CALCULATOR_SOURCE
#define REDUCE_FRACTION_CALCULATOR_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Reduces the fraction.
 *
 * @param p0 the fraction
 */
void calculate_fraction_reduce(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate fraction reduce.");

    // The numerator and denominator.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The result numerator and denominator.
    int rn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int rd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get numerator and denominator.
    copy_array_forward((void*) &n, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
    // Determine absolute values.
    calculate_integer_absolute((void*) &rn, n);
    calculate_integer_absolute((void*) &rd, d);

    if ((rn > *NUMBER_1_INTEGER_STATE_CYBOI_MODEL) && (rd > *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

        // The loop variable.
        int i = rn;

        if (rd > i) {

            i = rd;
        }

        // The remainder of the numerator and denominator.
        int remn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int remd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Search numerator and denominator having a common factor
        // delivering an integral number as result (no remainder).
        // Start at the largest of both.
        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (i <= *NUMBER_1_INTEGER_STATE_CYBOI_MODEL) {

                break;
            }

            remn = rn % i;
            remd = rd % i;

            if ((remn == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) && (remd == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) {

                //
                // If both, the numerator and the denominator have been
                // divided successfully without leaving a remainder,
                // then the lowest common denominator has been found.
                //
                // Synonyms:
                // - lowest common denominator [kleinster gemeinsamer Nenner]
                // - least common factor (LCF) [kleinster gemeinsamer Teiler]
                //

                rn = (int) (rn / i);
                rd = (int) (rd / i);
            }

            // Decrement loop variable.
            i--;
        }
    }

    // Copy result numerator and denominator to fraction.
    copy_integer(n, (void*) &rn);
    copy_integer(d, (void*) &rd);

    //
    // Correct sign by setting it back to the original value + or -.
    //

    // The comparison results.
    int r1 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int r2 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_smaller((void*) &r1, n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    compare_integer_smaller((void*) &r2, d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r1 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_negate((void*) &rn, (void*) &rn);
    }

    if (r2 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_negate((void*) &rd, (void*) &rd);
    }
}

/* REDUCE_FRACTION_CALCULATOR_SOURCE */
#endif
