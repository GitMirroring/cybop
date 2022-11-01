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

#ifndef DECIMALS_NUMERAL_SERIALISER_SOURCE
#define DECIMALS_NUMERAL_SERIALISER_SOURCE

#include <math.h> // ceil

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/double/multiply_double_calculator.c"
#include "../../../../executor/calculator/double/subtract_double_calculator.c"
#include "../../../../executor/caster/double/integer_double_caster.c"
#include "../../../../executor/caster/integer/double_integer_caster.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/double_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"
#include "../../../../mapper/integer_to_digit_wide_character_mapper.c"

/**
 * Serialises the numeral post point value.
 *
 * It is also called decimal places (decimals), which is not
 * quite correct, since other number bases than ten may be used.
 *
 * CAUTION! The source floating point number handed over must have been
 * prepared to NOT contain any relevant PRE-POINT values, but just ZERO.
 *
 * @param p0 the destination wide character item
 * @param p1 the source number (a floating point value with just ZERO before the decimal separator)
 * @param p2 the number base
 * @param p3 the decimal places
 */
void serialise_numeral_decimals(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral decimals.");
    fwprintf(stdout, L"Debug: Serialise numeral decimals. source number p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Serialise numeral decimals. source number *p1: %f\n", *((double*) p1));

    // The number base as double with decimal base as default.
    double base = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The decimal places count with an arbitrarily chosen default value that may be changed here in cyboi if necessary one day.
    int c = *NUMBER_4_INTEGER_STATE_CYBOI_MODEL;
    // The last number index.
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The decimals (post point value).
    double v = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The digit.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The digit as wide character.
    wchar_t wc = *NULL_UNICODE_CHARACTER_CODE_MODEL;
    // The digit as double.
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The decimal places flag.
    int dp = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! This check is necessary in order to filter out TOO LARGE numbers
    // which would cause calculation errors due to injuring the number value range
    // or just too many loop cycles below.
    //
    compare_integer_less_or_equal((void*) &dp, p3, (void*) NUMBER_100_INTEGER_STATE_CYBOI_MODEL);

    if (dp != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Assign decimal places count parametre.
        copy_integer((void*) &c, p3);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise numeral decimals. The given decimal places value is too large. The cyboi system uses a maximum of 100.");
        fwprintf(stdout, L"Warning: Could not serialise numeral decimals. The given decimal places value is too large. The cyboi system uses a maximum of 100. decimal places p3: %i\n", p3);
        fwprintf(stdout, L"Warning: Could not serialise numeral decimals. The given decimal places value is too large. The cyboi system uses a maximum of 100. decimal places *p3: %i\n", *((int*) p3));
    }

    // Cast number base to double.
    cast_double_integer((void*) &base, p2);
    // Initialise last number index with decimal places count.
    copy_integer((void*) &l, (void*) &c);
    // Subtract ONE from last number index, since it is an INDEX.
    copy_integer((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    // Initialise decimals (post point value) with source floating point number.
    copy_double((void*) &v, p1);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // Multiply decimals (post point value) with base.
            calculate_double_multiply((void*) &v, (void*) &base);

            compare_integer_equal((void*) &r, (void*) &j, (void*) &l);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Round pre-point value upwards to the nearest integer,
                // returning that value as a double. Thus, ceil (1.5) is 2.0.
                //
                v = ceil(v);
            }

            //
            // Determine pre-point value representing the next digit.
            //
            // CAUTION! Convert floating-point number to integer by CASTING it to int.
            // This is a legitimate method of truncating a floating-point value,
            // as mentioned in the glibc documentation:
            // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
            //
            cast_integer_double((void*) &d, (void*) &v);

            // Map integer value to a unicode digit wide character.
            map_integer_to_digit_wide_character((void*) &wc, (void*) &d);

            // Append digit wide character to destination number string.
            modify_item(p0, (void*) &wc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            // Cast digit to double.
            cast_double_integer((void*) &dd, (void*) &d);

            // Subtract digit from decimals (post point value).
            calculate_double_subtract((void*) &v, (void*) &dd);
        }
    }
}

/* DECIMALS_NUMERAL_SERIALISER_SOURCE */
#endif
