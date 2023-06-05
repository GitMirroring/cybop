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

#include <math.h> // round
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
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. source number p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. source number *p1: %f\n", *((double*) p1));

    //
    // Declaration
    //

    //
    // The decimal places count with an arbitrarily chosen DEFAULT value
    // that may be changed here in cyboi if necessary one day.
    //
    int c = *NUMBER_4_INTEGER_STATE_CYBOI_MODEL;
    // The number base as double with DECIMAL as default.
    double base = (double) *DECIMAL_BASE_NUMERAL_MODEL;
    // The power factor.
    double p = *NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL;
    // The decimal places count as double.
    double cd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The decimals (post point value).
    double v = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The digit.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The digit as wide character.
    wchar_t wc = *NULL_UNICODE_CHARACTER_CODE_MODEL;
    // The digit as double.
    double dd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    //
    // Power
    //

    // Initialise decimal places count with parametre.
    copy_integer((void*) &c, p3);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. c: %i\n", c);
    // Cast number base to double.
    cast_double_integer((void*) &base, p2);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. base: %f\n", base);
    // Initialise power factor with number base.
    copy_double((void*) &p, (void*) &base);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. with base p: %f\n", p);
    // Cast decimal places count to double.
    cast_double_integer((void*) &cd, (void*) &c);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. cast cd: %f\n", cd);
    // Raise the number base to the power of the decimal places count.
    calculate_double_power((void*) &p, (void*) &cd);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. with cd power p: %f\n", p);

    //
    // Rounding
    //

    // Initialise decimals (post point value) with source floating point number.
    copy_double((void*) &v, p1);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. init v: %f\n", v);
    // Multiply decimals (post point value) with power factor.
    calculate_double_multiply((void*) &v, (void*) &p);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. multiply v: %f\n", v);
    // Round decimals (post point value).
    v = round(v);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. round v: %f\n", v);
    // Divide decimals (post point value) by power factor.
    calculate_double_divide((void*) &v, (void*) &p);
    //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. divide v: %f\n", v);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // Multiply decimals (post point value) with base.
            calculate_double_multiply((void*) &v, (void*) &base);
            //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. multiply v: %f\n", v);

            //
            // Determine pre-point value representing the next digit.
            //
            // CAUTION! Convert floating-point number to integer by CASTING it to int.
            // This is a legitimate method of truncating a floating-point value,
            // as mentioned in the glibc documentation:
            // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
            //
            cast_integer_double((void*) &d, (void*) &v);
            //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. d: %i\n", d);

            // Map integer value to a unicode digit wide character.
            map_integer_to_digit_wide_character((void*) &wc, (void*) &d);
            //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. wc: %lc\n", wc);

            // Append digit wide character to destination number string.
            modify_item(p0, (void*) &wc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            // Cast digit to double.
            cast_double_integer((void*) &dd, (void*) &d);
            //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. dd: %f\n", dd);

            // Subtract digit from decimals (post point value).
            calculate_double_subtract((void*) &v, (void*) &dd);
            //?? fwprintf(stdout, L"Debug: Serialise numeral decimals. v: %f\n", v);

            // Increment loop variable.
            j++;
        }
    }
}
