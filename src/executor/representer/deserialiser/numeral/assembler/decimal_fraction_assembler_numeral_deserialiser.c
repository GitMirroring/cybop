/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DECIMAL_FRACTION_ASSEMBLER_NUMERAL_DESERIALISER_SOURCE
#define DECIMAL_FRACTION_ASSEMBLER_NUMERAL_DESERIALISER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../../../executor/calculator/double/add_double_calculator.c"
#include "../../../../../executor/calculator/double/multiply_double_calculator.c"
#include "../../../../../executor/caster/double/integer_double_caster.c"
#include "../../../../../executor/copier/double_copier.c"
#include "../../../../../logger/logger.c"

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
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. pre point value p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. pre point value *p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. decimals p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. decimals *p3: %i\n", *((int*) p3));
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. power p4: %i\n", p4);
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. power *p4: %i\n", *((int*) p4));

    // The algebraic sign factor as double.
    double s = *NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL;
    // The pre point value as double.
    double v = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The post point value as double.
    double d = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Cast algebraic sign factor to double.
    cast_double_integer((void*) &s, p1);
    // Cast pre point value to double.
    cast_double_integer((void*) &v, p2);
    // Cast post point value to double.
    cast_double_integer((void*) &d, p3);

    // Initialise destination decimal fraction with pre point value.
    copy_double(p0, (void*) &v);

    // Add post point value to destination decimal fraction.
    calculate_double_add(p0, (void*) &d);

    // Multiply destination decimal fraction with power factor.
    calculate_double_multiply(p0, p4);

    // Multiply destination decimal fraction with algebraic sign factor.
    calculate_double_multiply(p0, (void*) &s);
}

/* DECIMAL_FRACTION_ASSEMBLER_NUMERAL_DESERIALISER_SOURCE */
#endif
