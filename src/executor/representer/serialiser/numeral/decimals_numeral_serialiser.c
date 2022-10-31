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

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the numeral post point value.
 *
 * It is also called decimal places (decimals), which is not
 * quite correct, since other number bases than ten may be used.
 *
 * @param p0 the destination item
 * @param p1 the source number
 * @param p2 the sign flag
 * @param p3 the number base
 * @param p4 the prefix flag
 * @param p5 the decimal separator
 * @param p6 the decimal places
 * @param p7 the scientific notation flag
 */
void serialise_numeral_decimals(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral decimals.");
    fwprintf(stdout, L"Debug: Serialise numeral decimals. format p8: %i\n", p8);
    fwprintf(stdout, L"Debug: Serialise numeral decimals. format *p8: %i\n", *((int*) p8));

    // The number base as double with decimal base as default.
    double b = *NUMBER_10_0_FLOAT;
    // The decimal places count with default value.
    int c = *NUMBER_6_INTEGER;
    // The last number index.
    int l = *NUMBER_0_INTEGER;
    // The decimals (post point value).
    double v = *NUMBER_0_0_FLOAT;
    // The digit.
    int d = *NUMBER_0_INTEGER;
    // The digit as wide character.
    wchar_t wc = *NULL_WIDE_CHARACTER;
    // The digit as double.
    double dd = NUMBER_0_0_FLOAT;

    // Initialise decimal places count.
    if (decimal places count parametre < MAX_COUNT(see glibc constants and count manually and enter here as literal integer constant)) {

        // Assign decimal places count parametre.
        copy_integer((void*) &c, px);

    } else {

        // Assign maximum decimal places count as determined from glibc maximum double value constant.
        copy_integer((void*) &c, MAX);
    }

    // Cast number base to double.
    cast_double_integer((void*) &b, px-base-param);
    // Initialise last number index with decimal places count.
    copy_integer((void*) &l, (void*) &c);
    // Subtract one from last number index, since it is an index.
    copy_integer((void*) &l, (void*) NUMBER_1_INTEGER);
    // Initialise decimals (post point value) with source floating point number.
    copy_double((void*) &v, px);

    //
    // Append post-point value (decimal places).
    //
    // Beispielzahl: 0.24
    // Basis: 10
    //
    while (TRUE) {

        if (j >= param-decimal-places) {

            break;
        }

        // Multiply decimals (post point value) with base.
        calculate_double_multiply((void*) &v, base-param);

        if (j < last-number-index) {

            //
            // Determine pre-point value representing the next digit.
            //
            // CAUTION! Convert floating-point number to integer by CASTING it to int.
            // This is a legitimate method of truncating a floating-point value,
            // as mentioned in the glibc documentation:
            // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
            //
            d = (int) n;

        } else {

            //?? TODO: #include <math.h>

            //
            // Round pre-point value upwards to the nearest integer,
            // returning that value as a double. Thus, ceil (1.5) is 2.0.
            //
            n = ceil(n);

            //
            // Determine pre-point value representing the next digit.
            //
            // CAUTION! Convert floating-point number to integer by CASTING it to int.
            // This is a legitimate method of truncating a floating-point value,
            // as mentioned in the glibc documentation:
            // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
            //
            d = (int) n;
        }

        // Map integer value to a unicode digit wide character.
        map_integer_to_digit_wide_character((void*) &wc, (void*) &d);

        // Append digit wide character to destination number string.
        modify_item(p0, (void*) &wc, APPEND);

        // Cast digit to double.
        cast_double_integer((void*) &dd, (void*) &d);

        // Subtract digit from decimals (post point value).
        calculate_double_subtract((void*) &v, (void*) &dd);
    }
}

/* DECIMALS_NUMERAL_SERIALISER_SOURCE */
#endif
