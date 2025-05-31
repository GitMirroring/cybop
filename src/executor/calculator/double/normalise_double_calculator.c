/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Normalises the floating point number into scientific notation.
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
 * The given operation parametres differ depending on whether this is a number:
 * - smaller than one: it has to be MULTIPLIED with the base until
 *   a non-zero number is standing before the decimal point
 * - greater than one: it has to be DIVIDED by the base until
 *   only one non-zero number is standing before the decimal point
 *
 * Here are the three possible cases:
 *
 * if (*((double*) p0) == 0.0) {
 *     calculate_double_normalise(p0, p1, p2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL, NULL, NULL);
 * } else if (*((double*) p0) < 1.0) {
 *     calculate_double_normalise(p0, p1, p2, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) NUMBER_10_0_DOUBLE_STATE_CYBOI_MODEL, (void*) MULTIPLY_CALCULATE_LOGIC_CYBOI_FORMAT, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT);
 * } else {
 *     // Covers the case (*((double*) p0) >= 1.0)
 *     calculate_double_normalise(p0, p1, p2, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT, (void*) NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL, (void*) DIVIDE_CALCULATE_LOGIC_CYBOI_FORMAT, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT);
 * }
 *
 * @param p0 the adjusted floating point number, which is the original value BEFORE the operation
 * @param p1 the power exponent
 * @param p2 the number base
 * @param p3 the comparison operation
 * @param p4 the comparison number
 * @param p5 the move operation
 * @param p6 the direction operation
 */
void calculate_double_normalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate double normalise.");
    fwprintf(stdout, L"Debug: Calculate double normalise. p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Calculate double normalise. *p0: %f\n", *((double*) p0));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The temporary number.
    double n = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The number base as double.
    double nb = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    //
    // The loop variable counting decimal separator position moves.
    //
    // CAUTION! Initialise with ZERO since for the original value,
    // the position has NOT been moved yet.
    //
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise temporary number with original floating point number.
    copy_double((void*) &n, p0);
    // Cast number base parametre to double.
    cast_double_integer((void*) &nb, p2);

    if ((p3 == *NULL_POINTER_STATE_CYBOI_MODEL) || (p4 == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Compare temporary number with comparison number.
        //
        // The three possible cases:
        // - equal 0.0
        // - greater 10.0
        // - less 1.0
        //
        compare_double((void*) &b, (void*) &n, p4, p3);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // Assign current value as destination floating point number.
            copy_double(p0, (void*) &n);
            // Assign current loop variable as destination power exponent.
            copy_integer(p1, (void*) &j);

            //
            // Calculate number using base.
            //
            // The two possible cases:
            // - multiply if number < 1.0
            // - divide if number >= 1.0
            //
            calculate_double((void*) &n, (void*) &nb, p5);

            //
            // Adjust loop variable.
            //
            // The two possible cases:
            // - decrement if number < 1.0
            // - increment if number >= 1.0
            //
            calculate_integer((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, p6);
        }
    }
}
