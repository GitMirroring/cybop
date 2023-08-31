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
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"

/**
 * Compares the left- with the right double for lessness and equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void compare_fraction_less_or_equal(void* p0, void* p1, void* p2) {

    // The left numerator, denominator.
    int ln = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ld = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The right numerator, denominator.
    int rn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int rd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get left numerator, denominator.
    get_fraction_element((void*) &ln, (void*) p1, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &ld, (void*) p1, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
    // Get right numerator, denominator.
    get_fraction_element((void*) &rn, (void*) p2, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &rd, (void*) p2, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // The expanded left numerator, right numerator.
    // CAUTION! Initialise with ln and rn, respectively,
    // since they are multiplied with their denominators below.
    int eln = ln;
    int ern = rn;

    // Calculate expanded left numerator, right numerator.
    // CAUTION! Multiplicate CROSS-WISE.
    calculate_integer_multiply((void*) &eln, (void*) &rd);
    calculate_integer_multiply((void*) &ern, (void*) &ld);

    // Compare expanded numerators.
    compare_integer_less_or_equal(p0, (void*) &eln, (void*) &ern);
}
