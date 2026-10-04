/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Reduces the fraction.
 *
 * @param p0 the fraction
 */
void calculate_fraction_reduce(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate fraction reduce.");

    // The numerator and denominator.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The negative numerator, denominator flag.
    int nn = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int nd = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The result numerator and denominator.
    int rn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int rd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get numerator and denominator.
    get_fraction_element((void*) &n, (void*) p0, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &d, (void*) p0, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    compare_integer_less((void*) &nn, (void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    compare_integer_less((void*) &nd, (void*) &d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    // Determine absolute values.
    calculate_integer_absolute((void*) &rn, (void*) &n);
    calculate_integer_absolute((void*) &rd, (void*) &d);

    if ((rn > *NUMBER_1_INTEGER_STATE_CYBOI_MODEL) && (rd > *NUMBER_1_INTEGER_STATE_CYBOI_MODEL)) {

        // The loop variable.
        int j = rn;

        if (rd < j) {

            //
            // CAUTION! Since j is used as divisor for both,
            // numerator and denominator, the smaller is used.
            //
            j = rd;
        }

        // The remainder of the numerator and denominator.
        int remn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int remd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Search numerator and denominator having a common factor
        // delivering an integral number as result (no remainder).
        // Start at the larger one of both.
        //
        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (j <= *NUMBER_1_INTEGER_STATE_CYBOI_MODEL) {

                break;
            }

            remn = rn % j;
            remd = rd % j;

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

                rn = (int) (rn / j);
                rd = (int) (rd / j);
            }

            // Decrement loop variable.
            j--;
        }
    }

    //
    // Correct sign by setting it back to the original value + or -.
    //

    if (nn != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_negate((void*) &rn, (void*) &rn);
    }

    if (nd != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        calculate_integer_negate((void*) &rd, (void*) &rd);
    }

    // Set destination numerator and denominator
    // (just copies the values inside).
    set_fraction_element((void*) p0, (void*) &rn, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    set_fraction_element((void*) p0, (void*) &rd, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
}
