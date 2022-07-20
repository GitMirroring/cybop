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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INTEGER_ASSEMBLER_DESERIALISER_SOURCE
#define INTEGER_ASSEMBLER_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/numeral/numeral_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Assembles the integer from the given values.
 *
 * @param p0 the destination integer item
 * @param p1 the algebraic sign
 * @param p2 the number base
 * @param p3 the value
 */
void deserialise_numeral_assembler_integer(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral assembler integer.");
    fwprintf(stdout, L"Debug: Deserialise numeral assembler integer. value p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise numeral assembler integer. value *p3: %i\n", *((int*) p3));

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The potency.
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The digit.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The product.
    int pr = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    while (TRUE) {

        //
        // Calculate given base raised to the power of the loop variable as exponent.
        //
        // Example: 16^0 = 1, 16^1 = 16, 16^2 = 256 etc.
        //
        //?? TODO: Just multiply with the given number base in each loop cycle.
        // Exception: exponent zero with result 1
        //
        calculate_power((void*) &p, p2, (void*) &j);

        // Retrieve next digit from value.
        //?? TODO: See retrieval of digit in decimal places (decimals)
        copy_array_forward(digit, p3, index);

        // Initialise product with digit.
        copy_integer((void*) &pr, (void*) &digit);

        // Multiply product (digit) with potency.
        calculate_integer_multiply((void*) &pr, p);

        // Add product (digit times potency) to result.
        calculate_integer_add((void*) &r, (void*) &pr);
    }

    // Multiplicate value with algebraic sign factor.
    calculate_integer_multiply((void*) &r, p1);

    copy_integer(p0, (void*) &r);
}

/* INTEGER_ASSEMBLER_DESERIALISER_SOURCE */
#endif
