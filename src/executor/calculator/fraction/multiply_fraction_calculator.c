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

#ifndef MULTIPLY_FRACTION_CALCULATOR_SOURCE
#define MULTIPLY_FRACTION_CALCULATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/calculator/fraction/reduce_fraction_calculator.c"
#include "../../../logger/logger.c"

/**
 * Multiplies the destination fraction with the source fraction.
 *
 * @param p0 the destination fraction
 * @param p1 the source fraction
 */
void calculate_fraction_multiply(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate fraction multiply.");

    // The destination numerator and denominator.
    int dn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int dd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The source numerator and denominator.
    int sn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int sd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get destination numerator and denominator.
    get_fraction_element((void*) &dn, (void*) p0, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &dd, (void*) p0, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
    // Get source numerator and denominator.
    get_fraction_element((void*) &sn, (void*) p1, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &sd, (void*) p1, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // Multiply destination- and source numerators and denominators.
    calculate_integer_multiply((void*) &dn, (void*) &sn);
    calculate_integer_multiply((void*) &dd, (void*) &sd);

    // Set destination numerator and denominator
    // (just copies the values inside).
    set_fraction_element((void*) p0, (void*) &dn, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    set_fraction_element((void*) p0, (void*) &dd, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    // Reduce fraction.
    calculate_fraction_reduce(p0);
}

/* MULTIPLY_FRACTION_CALCULATOR_SOURCE */
#endif
