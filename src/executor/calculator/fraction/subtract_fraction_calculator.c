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

#ifndef SUBTRACT_FRACTION_CALCULATOR_SOURCE
#define SUBTRACT_FRACTION_CALCULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/accessor/getter/fraction_getter.c"
#include "../../../executor/accessor/setter/fraction_setter.c"
#include "../../../executor/calculator/fraction/reduce_fraction_calculator.c"
#include "../../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Subtracts the source fraction from the destination fraction.
 *
 * @param p0 the destination fraction
 * @param p1 the source fraction
 */
void calculate_fraction_subtract(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate fraction subtract.");

    // The destination numerator and denominator.
    int dn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int dd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The source numerator and denominator.
    int sn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int sd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The temporary source numerator value.
    // CAUTION! The original *sn should NOT be altered,
    // since a source should always be left untouched.
    int tsn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get destination numerator and denominator.
    get_fraction_element((void*) &dn, (void*) p0, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &dd, (void*) p0, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
    // Get source numerator and denominator.
    get_fraction_element((void*) &sn, (void*) p1, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &sd, (void*) p1, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // Copy temporary source numerator value.
    copy_integer((void*) &tsn, (void*) &sn);

    // Expand numerators by multiplying them with denominators cross-wise.
    calculate_integer_multiply((void*) &dn, (void*) &sd);
    calculate_integer_multiply((void*) &tsn, (void*) &dd);

    // Subtract numerators and multiply denominators.
    calculate_integer_subtract((void*) &dn, (void*) &tsn);
    calculate_integer_multiply((void*) &dd, (void*) &sd);

    // Set destination numerator and denominator
    // (just copies the values inside).
    set_fraction_element((void*) p0, (void*) &dn, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    set_fraction_element((void*) p0, (void*) &dd, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // Reduce fraction.
    calculate_fraction_reduce(p0);
}

/* SUBTRACT_FRACTION_CALCULATOR_SOURCE */
#endif
