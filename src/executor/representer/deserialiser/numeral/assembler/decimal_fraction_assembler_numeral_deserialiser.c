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
#include "logger.h"

/**
 * Assembles the decimal fraction from the given values.
 *
 * @param p0 the destination decimal fraction
 * @param p1 the algebraic sign factor
 * @param p2 the pre point value
 * @param p3 the post point value
 * @param p4 the power factor
 */
void deserialise_numeral_assembler_fraction_decimal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral assembler fraction decimal.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. pre point value p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. pre point value *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. decimals p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. decimals *p3: %f\n", *((double*) p3));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. power p4: %i\n", p4);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. power *p4: %f\n", *((double*) p4));

    // The algebraic sign factor as double.
    double s = *NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL;
    // The pre point value as double.
    double v = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Cast algebraic sign factor to double.
    cast_double_integer((void*) &s, p1);

    // Initialise destination decimal fraction with pre point value.
    cast_double_integer(p0, p2);
    // Add post point value to destination decimal fraction.
    calculate_double_add(p0, p3);

    // Multiply destination decimal fraction with power factor.
    calculate_double_multiply(p0, p4);
    // Multiply destination decimal fraction with algebraic sign factor.
    calculate_double_multiply(p0, (void*) &s);
}
