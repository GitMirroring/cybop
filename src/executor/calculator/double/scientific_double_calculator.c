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

#ifndef SCIENTIFIC_DOUBLE_CALCULATOR_SOURCE
#define SCIENTIFIC_DOUBLE_CALCULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/calculator/double/normalise_double_calculator.c"
#include "../../../executor/comparator/double/equal_double_comparator.c"
#include "logger.h"

/**
 * Converts the floating point number into scientific notation.
 *
 * Example 1:
 * - source floating point number: 123.4567
 * - destination scientific notation: 1.234567e2
 * - returned floating point number p0: 1.234567
 * - returned power exponent p1: 2
 *
 * Example 2:
 * - source floating point number: 0.000123
 * - destination scientific notation: 1.23e-4
 * - returned floating point number p0: 1.23
 * - returned power exponent p1: -4
 *
 * @param p0 the adjusted floating point number, which is the original value BEFORE the operation
 * @param p1 the power exponent
 * @param p2 the number base
 */
void calculate_double_scientific(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate double scientific.");
    fwprintf(stdout, L"Debug: Calculate double scientific. p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Calculate double scientific. *p0: %f\n", *((double*) p0));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_double_equal((void*) &r, p0, (void*) NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! This special case of a ZERO value has to be catched here since
            // otherwise, the loop inside the called function would NEVER come to an end.
            //
            // It would be possible to call the function as follows:
            // calculate_double_normalise(p0, p1, p2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL, NULL, NULL);
            //
            // However, this just lowers performance and is not useful since the
            // loop would break and the function return without doing anything.
            // Therefore, just do NOTHING here and leave the original number UNTOUCHED.
            //
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_double_less((void*) &r, p0, (void*) NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            calculate_double_normalise(p0, p1, p2, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) NUMBER_10_0_DOUBLE_STATE_CYBOI_MODEL, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_FORMAT, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! This branch covers the cases where p0 is GREATER or EQUAL to 1.0.
        //

        calculate_double_normalise(p0, p1, p2, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_FORMAT, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT);
    }
}

/* SCIENTIFIC_DOUBLE_CALCULATOR_SOURCE */
#endif
