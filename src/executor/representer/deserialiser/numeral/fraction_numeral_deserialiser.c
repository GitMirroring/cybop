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

#ifndef FRACTION_NUMERAL_DESERIALISER_SOURCE
#define FRACTION_NUMERAL_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/calculator/double/add_double_calculator.c"
#include "../../../../executor/calculator/double/divide_double_calculator.c"
#include "../../../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../../../executor/caster/double/integer_double_caster.c"
#include "../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/double_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/wide_character_copier.c"
#include "logger.h"
#include "../../../../mapper/digit_wide_character_to_integer_mapper.c"

/**
 * Deserialises the fractional digits.
 *
 * @param p0 the destination double value
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 * @param p3 the number base
 */
void deserialise_numeral_fraction(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral fraction.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral fraction. source count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral fraction. source count *p2: %i\n", *((int*) p2));

    //
    // Declaration
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The digit wide character.
    wchar_t c = *NULL_UNICODE_CHARACTER_CODE_MODEL;
    // The integer value.
    int v = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The fractional digit.
    double f = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The divisor value.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The divisor as double.
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The result.
    double r = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    //
    // Initialisation
    //

    // Initialise divisor value with given number base for the first fractional digit.
    copy_integer((void*) &d, p3);

    //
    // Looping
    //

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

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Get digit wide character at given index.
        copy_array_forward((void*) &c, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j);

        //
        // Determine integer value from digit wide character.
        //
        // CAUTION! One could subtract the zero wide character UNICODE value
        // from the current digit wide character UNICODE value, in order to
        // get the actual numeric integer value.
        // However, using unicode values for calculation is NOT considered
        // proper here. Therefore, a MAPPING table is used instead.
        //
        map_digit_wide_character_to_integer((void*) &v, (void*) &c);

        // Cast integer value to fractional digit.
        cast_double_integer((void*) &f, (void*) &v);
        // Cast divisor to double.
        cast_double_integer((void*) &dd, (void*) &d);

        // Divide fractional digit by divisor to reflect the correct decimal position.
        calculate_double_divide((void*) &f, (void*) &dd);
        // Add fractional digit to result.
        calculate_double_add((void*) &r, (void*) &f);

        //
        // CAUTION! The reset of character AND value IS necessary since otherwise,
        // the PREVIOUS, then wrong character and value will be used,
        // if no valid character can be retrieved from the source or
        // the mapping fails due to an unknown character.
        //

        // Reset digit wide character.
        copy_wide_character((void*) &c, (void*) NULL_UNICODE_CHARACTER_CODE_MODEL);
        // Reset integer value.
        copy_integer((void*) &v, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        // Adjust divisor for next fractional digit on the right-hand side.
        calculate_integer_multiply((void*) &d, p3);

        // Increment loop variable.
        j++;
    }

    //?? fwprintf(stdout, L"Debug: Deserialise numeral fraction. r: %f\n", r);

    // Copy result.
    copy_double(p0, (void*) &r);
}

/* FRACTION_NUMERAL_DESERIALISER_SOURCE */
#endif
