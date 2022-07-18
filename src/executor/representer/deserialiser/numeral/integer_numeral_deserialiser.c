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

#ifndef INTEGER_NUMERAL_DESERIALISER_SOURCE
#define INTEGER_NUMERAL_DESERIALISER_SOURCE

#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/numeral/numeral_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the integer value.
 *
 * @param p0 the destination integer value
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 */
void deserialise_numeral_integer(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral integer.");
    fwprintf(stdout, L"Debug: Deserialise numeral integer. source count p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Deserialise numeral integer. source count *p2: %i\n", *((int*) p2));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The digit wide character.
    wchar_t c = *NULL_UNICODE_CHARACTER_CODE_MODEL;
    // The integer value.
    int v = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

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

        //
        // Move existing result by one digit.
        //
        // CAUTION! In the FIRST loop cycle, the result is zero,
        // which is WANTED BEHAVIOUR, so that the value gets
        // added below on the FIRST position.
        //
        calculate_integer_multiply((void*) &r, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
        // Add current digit.
        calculate_integer_add((void*) &r, (void*) &v);

        // Increment loop variable.
        j++;
    }

    // Copy result.
    copy_integer(p0, (void*) &r);
}

/* INTEGER_NUMERAL_DESERIALISER_SOURCE */
#endif
