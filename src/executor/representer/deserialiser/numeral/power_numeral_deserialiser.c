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

#ifndef POWER_NUMERAL_DESERIALISER_SOURCE
#define POWER_NUMERAL_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/calculator/double/multiply_double_calculator.c"
#include "../../../../executor/calculator/double/power_double_calculator.c"
#include "../../../../executor/caster/double/integer_double_caster.c"
#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/double_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/numeral/integer_numeral_deserialiser.c"
#include "../../../../executor/selector/numeral/sign_numeral_selector.c"
#include "../../../../executor/selector/numeral/value_numeral_selector.c"
#include "logger.h"

/**
 * Deserialises the power of the given number base.
 *
 * @param p0 the destination power factor double value
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the number base
 * @param p4 the detected format
 * @param p5 the detected type
 */
void deserialise_numeral_power(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral power.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral power. source count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral power. source count *p2: %i\n", *((int*) p2));

    //
    // Declaration
    //

    //
    // The number base with DECIMAL as default.
    //
    // CAUTION! Using this local variable is IMPORTANT to assign a default value.
    // If the parametre got used directly and were null, calculations below would fail.
    //
    int nb = *DECIMAL_BASE_NUMERAL_MODEL;
    // The algebraic sign factor with PLUS (positive number one) as default.
    int s = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    // The power data, count.
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int pc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The power as integer and double value.
    int powi = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    double powd = *NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL;

    //
    // Initialisation
    //

    // Copy number base. If null, it gets ignored.
    copy_integer((void*) &nb, p3);

    // Deserialise algebraic sign.
    select_numeral_sign((void*) &s, p1, p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral power. sign s: %i\n", s);

    //
    // Initialise power data.
    //
    // CAUTION! Do this only AFTER having detected the algebraic sign above,
    // so that the data position now points to the first digit.
    //
    copy_pointer((void*) &pd, p1);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

    //
    // Assignment
    //

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        //?? fwprintf(stdout, L"Debug: Deserialise numeral power. break flag b: %i\n", b);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Either an end character was found in the selector
            // OR the source count remaining is zero.
            //
            // In BOTH cases, the power can now be deserialised.
            //

            //?? fwprintf(stdout, L"Debug: Deserialise numeral power. pc: %i\n", pc);
            //?? fwprintf(stdout, L"Debug: Deserialise numeral power. pd: %ls\n", (wchar_t*) pd);

            //
            // Example: 0x123.456e-3
            //
            // This is a hexadecimal number due to the prefix "0x".
            //
            // All three parts are expected to be HEXADECIMAL:
            // - pre point value
            // - post point value
            // - number base power
            //
            // 1 The prefix "e" already got detected in the selector.
            // 2 The algebraic sign "-" already got extracted further above.
            // 3 Now, the following steps are to be executed:
            // - deserialise power value "3" as integer with the given hexadecimal number base
            // - raise the number base "16" (hexadecimal) to the power of the deserialised power value "3"
            //

            // Deserialise power value as integer with the given number base.
            deserialise_numeral_integer((void*) &powi, pd, (void*) &pc, (void*) &nb);
            //?? fwprintf(stdout, L"Debug: Deserialise numeral power. powi: %i\n", powi);

            // Multiply power value with algebraic sign factor.
            calculate_integer_multiply((void*) &powi, (void*) &s);
            //?? fwprintf(stdout, L"Debug: Deserialise numeral power. with sign powi: %i\n", powi);

            // Cast integer to double.
            cast_double_integer((void*) &powd, (void*) &powi);
            //?? fwprintf(stdout, L"Debug: Deserialise numeral power. powd: %f\n", powd);

            // Initialise destination power factor with number base.
            cast_double_integer(p0, (void*) &nb);
            //?? fwprintf(stdout, L"Debug: Deserialise numeral power. nb: %i\n", nb);
            //?? fwprintf(stdout, L"Debug: Deserialise numeral power. base *p0: %f\n", *((double*) p0));

            // Raise the number base to the power of the given value.
            calculate_double_power(p0, (void*) &powd);
            //?? fwprintf(stdout, L"Debug: Deserialise numeral power. power *p0: %f\n", *((double*) p0));

            break;

        } else {

            // Select number base power.
            select_numeral_value(p1, p2, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &nb, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p4, p5, (void*) &pc, (void*) &b);
        }
    }
}

/* POWER_NUMERAL_DESERIALISER_SOURCE */
#endif
