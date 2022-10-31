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

#ifndef DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE
#define DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the decimal fraction into a wide character sequence.
 *
 * @param p0 the destination item
 * @param p1 the source number
 * @param p2 the sign flag
 * @param p3 the number base
 * @param p4 the prefix flag
 * @param p5 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p6 the decimal separator
 * @param p7 the decimal places
 * @param p8 the scientific notation flag
 */
void serialise_numeral_fraction_decimal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral fraction decimal.");
    fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. sign flag p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. sign flag *p2: %i\n", *((int*) p2));

    // The normalised floating point number in scientific notation.
    double n = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The power exponent.
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (scientific_notation_flag != FALSE) {

        // Initialise normalised floating point number in scientific notation.
        copy_double((void*) &n, p1);

        // Convert floating point number into scientific notation.
        calculate_double_scientific((void*) &n, (void*) &p, p3);
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

    // Serialise pre-point value.
    serialise_numeral_integer(p0, pre);

    // Append decimal separator.
    modify_item(".", APPEND);

    // Serialise post-point value.
    serialise_numeral_decimals(p0, (void*) &post);

    if (scientific_notation_flag != FALSE) {

        // Append "e".
        modify_item("e", APPEND);

        // Serialise power exponent value.
        serialise_numeral_integer(p0, p);
    }
}

/* DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE */
#endif
