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

#ifndef INTEGER_NUMERAL_SERIALISER_SOURCE
#define INTEGER_NUMERAL_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the integer value into a wide character sequence.
 *
 * @param p0 the destination item
 * @param p1 the source number
 * @param p2 the number base
 * @param p3 the sign flag
 * @param p4 the number prefix flag
 * @param p5 the decimal separator
 * @param p6 the decimal places
 * @param p7 the scientific notation flag
 * @param p8 the format
 */
void serialise_numeral_integer(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral integer.");
    //?? fwprintf(stdout, L"Debug: Serialise numeral integer. format p8: %i\n", p8);
    //?? fwprintf(stdout, L"Debug: Serialise numeral integer. format *p8: %i\n", *((int*) p8));

    // The normalised floating point number in scientific notation.
    double n = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The power exponent.
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (zahl < 0) {

        // Append minus sign to destination item.
        append(p0, MINUS);

    } else {

        if (sign-flag != FALSE) {

            // Append plus sign to destination item.
            append(p0, PLUS);
        }
    }

    // Eliminate sign from number.
    //?? TODO: calculate_absolute((void*) &n);

    // ---------- START -- only if double
    if (p8-format == DOUBLE_CYBOI_FORMAT) {

        if (scientific notation flag != FALSE) {

            // Initialise normalised floating point number in scientific notation.
            copy_double((void*) &n, p1);

            // Convert floating point number into scientific notation.
            calculate_double_scientific((void*) &n, (void*) &p, p3);
        }
    }
    // ---------- END

    if (prefix-flag != FALSE) {

        if (base == BINARY) {
            // Append binary prefix 0b.
        } else if (base == DECIMAL) {
            // Append NOTHING, since decimal numbers do NOT have a prefix.
        } else if (base == OCTAL) {
            // Append octal prefix 0o.
        } else if (base == HEXADECIMAL) {
            // Append hexadecimal prefix 0x.
        } else {
            log(Warning: unknown);
        }
    }

    //
    // Determine pre-point value.
    //
    // CAUTION! Convert floating-point number to integer by CASTING it to int.
    // This is a legitimate method of truncating a floating-point value,
    // as mentioned in the glibc documentation:
    // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
    //
    pre = (int) orig-zahl;

    // Determine post-point value (decimal places).
    post = orig-zahl - pre;

    //
    // Append pre-point value.
    //
    // Beispielzahl: 124
    // Basis: 10
    //
    while (TRUE) {
        rest(4) = zahl mod 10;
        insert_at_pos_zero(rest);
        zahl = zahl / 10;
        // ?? Cast zahl from double to int
    }

    // Append decimal separator.
    append(SEPARATOR);

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
        tmp = zahl * 10;
        if (j < last-number-index) {
            //
            // Determine pre-point value representing the next digit.
            //
            // CAUTION! Convert floating-point number to integer by CASTING it to int.
            // This is a legitimate method of truncating a floating-point value,
            // as mentioned in the glibc documentation:
            // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
            //
            digit = (int) tmp;
        } else {
            //?? TODO: #include <math.h>
            //
            // Round pre-point value upwards to the nearest integer,
            // returning that value as a double. Thus, ceil (1.5) is 2.0.
            //
            //?? TODO:
            // Cast to double as needed:
            // double ceil(double x)
            //
            double d = (double) tmp;
            d = ceil(d);
            digit = (int) d;
        }
        append(digit);
        zahl = tmp - digit;
    }
}

/* INTEGER_NUMERAL_SERIALISER_SOURCE */
#endif
