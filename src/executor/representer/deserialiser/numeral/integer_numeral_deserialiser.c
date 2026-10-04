/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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
#include "mapper.h"

/**
 * Deserialises the integer value.
 *
 * @param p0 the destination integer value
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 * @param p3 the number base
 */
void deserialise_numeral_integer(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral integer.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral integer. source count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral integer. source count *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral integer. source count p1: %ls\n", (wchar_t*) p1);

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
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The digit wide character.
    wchar_t c = *NULL_UNICODE_CHARACTER_CODE_MODEL;
    // The integer value.
    int v = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The result.
    int res = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Initialisation
    //

    // Copy number base. If null, it gets ignored.
    copy_integer((void*) &nb, p3);

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
        //?? fwprintf(stdout, L"Debug: Deserialise numeral integer. v: %i\n", v);

        //
        // Move existing result by one digit.
        //
        // CAUTION! Walk through the single digits by multiplying them
        // with the numeral base that was handed over as paramere.
        //
        // CAUTION! In the FIRST loop cycle, the result is ZERO,
        // which is WANTED BEHAVIOUR, so that the value gets
        // added below on the FIRST position.
        //
        calculate_integer_multiply((void*) &res, (void*) &nb);
        // Add current digit.
        calculate_integer_add((void*) &res, (void*) &v);

        // Increment loop variable.
        j++;
    }

    // Copy result.
    copy_integer(p0, (void*) &res);
}
