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

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Assembles the decimal fraction from the given values.
 *
 * @param p0 the destination decimal fraction
 * @param p1 the algebraic sign
 * @param p2 the value
 * @param p3 the decimal places (decimals)
 * @param p4 the decimal power
 */
void deserialise_numeral_assembler_fraction_decimal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral assembler fraction decimal.");
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. value p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. value *p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. decimals p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. decimals *p3: %i\n", *((int*) p3));
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. power p4: %i\n", p4);
    fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction decimal. power *p4: %i\n", *((int*) p4));

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The potency.
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Calculate decimal power.
    calculate_power((void*) &p, p2, (void*) &j);

    // Copy value to destination decimal fraction.
    copy_double(p0, p2);

    // Add decimal places (decimals) to destination decimal fraction.
    calculate_double_add(p0, p3);

    // Multiply product (digit) with potency.
    calculate_double_multiply(p0, p);

    // Multiplicate decimal fraction with algebraic sign factor.
    calculate_double_multiply(p0, p1);
}

/* DECIMAL_FRACTION_ASSEMBLER_NUMERAL_DESERIALISER_SOURCE */
#endif
