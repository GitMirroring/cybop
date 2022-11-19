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
#include "../../../../executor/calculator/double/add_double_calculator.c"
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
 * CAUTION! The source number has to have been prepared to NOT contain
 * any relevant PRE-POINT values, but just ZERO.
 *
 * CAUTION! The source number is expected to be GREATER or EQUAL to zero.
 * A negative number will produce wrong results, since precision handling
 * will not work.
 *
 * @param p0 the destination wide character item
 * @param p1 the source floating point number as POSITIVE (greater or equal to zero) floating point value with just ZERO before the decimal separator
 * @param p2 the number base
 * @param p3 the decimal places
 */
void serialise_numeral_decimals(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral decimals.");
    fwprintf(stdout, L"Debug: Serialise numeral decimals. source number p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Serialise numeral decimals. source number *p1: %f\n", *((double*) p1));

    // The decimal places flag.
    int dp = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The number base as double with decimal base as default.
    double base = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    //
    // The decimal places count with an arbitrarily chosen default value
    // that may be changed here in cyboi if necessary one day.
    //
    int c = *NUMBER_4_INTEGER_STATE_CYBOI_MODEL;
    // The last digit index.
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The decimals (post point value).
    double v = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    //
    // The decimals (post point value) prepared for casting.
    //
    // CAUTION! It is necessary in order to avoid manipulation of
    // the original decimals (post point value) v.
    //
    double p = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The digit.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The digit as wide character.
    wchar_t wc = *NULL_UNICODE_CHARACTER_CODE_MODEL;
    // The digit as double.
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    //
    // CAUTION! This check is necessary in order to filter out TOO LARGE numbers
    // which would cause calculation errors due to injuring the number value range
    // or just too many loop cycles below.
    //
    compare_integer_less_or_equal((void*) &dp, p3, (void*) NUMBER_100_INTEGER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"Debug: Serialise numeral decimals. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Serialise numeral decimals. *p3: %i\n", *((int*) p3));

    if (dp != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Assign decimal places count parametre.
        copy_integer((void*) &c, p3);
        fwprintf(stdout, L"Debug: Serialise numeral decimals. inside c: %i\n", c);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise numeral decimals. The given decimal places value is too large. The cyboi system uses a maximum of 100.");
        fwprintf(stdout, L"Warning: Could not serialise numeral decimals. The given decimal places value is too large. The cyboi system uses a maximum of 100. decimal places p3: %i\n", p3);
        fwprintf(stdout, L"Warning: Could not serialise numeral decimals. The given decimal places value is too large. The cyboi system uses a maximum of 100. decimal places *p3: %i\n", *((int*) p3));
    }

    fwprintf(stdout, L"Debug: Serialise numeral decimals. c: %i\n", c);

    // Cast number base to double.
    cast_double_integer((void*) &base, p2);
    fwprintf(stdout, L"Debug: Serialise numeral decimals. base: %f\n", base);
    // Initialise last digit index with decimal places count.
    copy_integer((void*) &l, (void*) &c);
    fwprintf(stdout, L"Debug: Serialise numeral decimals. l: %i\n", l);
    // Subtract ONE from last digit index, since it is an INDEX.
    copy_integer((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Debug: Serialise numeral decimals. sub l: %i\n", l);
    // Initialise decimals (post point value) with source floating point number.
    copy_double((void*) &v, p1);
    fwprintf(stdout, L"Debug: Serialise numeral decimals. v: %f\n", v);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // Multiply decimals (post point value) with base.
            calculate_double_multiply((void*) &v, (void*) &base);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. multiply v: %f\n", v);

            // Reset comparison result.
            r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_equal((void*) &r, (void*) &j, (void*) &l);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. j: %i\n", j);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. l: %i\n", l);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Round pre-point value upwards to the nearest integer,
                // returning that value as a double. Thus, ceil (1.5) is 2.0.
                //
                fwprintf(stdout, L"Debug: Serialise numeral decimals. pre ceil v: %f\n", v);
                v = ceil(v);
                fwprintf(stdout, L"Debug: Serialise numeral decimals. post ceil v: %f\n", v);
            }

            // Copy decimals (post point value) to that prepared for casting.
            copy_double((void*) &p, (void*) &v);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. pre-cast v: %f\n", v);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. pre-cast d: %i\n", d);
            calculate_double_add((void*) &p, (void*) NUMBER_0_5_DOUBLE_STATE_CYBOI_MODEL);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. added 0.5 v: %f\n", v);
            //
            // Determine pre-point value representing the next digit.
            //
            // CAUTION! Convert floating-point number to integer by CASTING it to int.
            // This is a legitimate method of truncating a floating-point value,
            // as mentioned in the glibc documentation:
            // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
            //
            // CAUTION! However, special handling is necessary, since floating
            // point numbers are precision-dependent and have an inaccuracy.
            // For example, the decimal number 9.2 is never exactly equal to 9.2:
            // - 32-bit "single precision" float: 9.19999980926513671875
            // - 64-bit "double precision" float: 9.199999999999999289457264239899814128875732421875
            // https://stackoverflow.com/questions/21895756/why-are-floating-point-numbers-inaccurate
            //
            // This has the effect that when casting for example the double value 4.0
            // which is internally represented as 3.999... to integer it becomes 3,
            // even though 4 would be expected.
            //
            // Therefore, the following preparation has to be applied BEFORE casting:
            // v > 0: add 0.5
            // v < 0: subtract 0.5
            // https://stackoverflow.com/questions/9695329/c-how-to-round-a-double-to-an-int
            //
            // But since only POSITIVE (greater or equal to zero) values are
            // expected as source here, the 0.5 may always be ADDED.
            //
            cast_integer_double((void*) &d, (void*) &p);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. post-cast v: %f\n", v);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. post-cast d: %i\n", d);

            // Map integer value to a unicode digit wide character.
            map_integer_to_digit_wide_character((void*) &wc, (void*) &d);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. wc: %lc\n", wc);

            // Append digit wide character to destination number string.
            modify_item(p0, (void*) &wc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            // Cast digit to double.
            cast_double_integer((void*) &dd, (void*) &d);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. dd: %f\n", dd);

            // Subtract digit from decimals (post point value).
            calculate_double_subtract((void*) &v, (void*) &dd);
            fwprintf(stdout, L"Debug: Serialise numeral decimals. v: %f\n", v);

            // Increment loop variable.
            j++;
        }
    }
}

/* DECIMALS_NUMERAL_SERIALISER_SOURCE */
#endif
