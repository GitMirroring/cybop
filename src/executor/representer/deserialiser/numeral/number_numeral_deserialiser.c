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

#ifndef NUMBER_NUMERAL_DESERIALISER_SOURCE
#define NUMBER_NUMERAL_DESERIALISER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"
#include "type.h"

/**
 * Deserialises the number value.
 *
 * The consider number base prefix flag has the following meaning:
 * - true: CONSIDER integer prefixes like "0x" for hexadecimal,
 *   as used in c/c++, perl or python
 * - false: IGNORE prefixes as is needed in json and is the DEFAULT so that
 *   floating point numbers with zero as pre-point value get recognised
 *   correctly with decimal number base
 *
 * @param p0 the destination number
 * @param p1 the destination number part (pointer reference)
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the decimal separator data
 * @param p5 the decimal separator count
 * @param p6 the thousands separator data
 * @param p7 the thousands separator count
 * @param p8 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p9 the number part name data
 * @param p10 the number part name count
 * @param p11 the destination number format
 */
void deserialise_numeral_number(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral number.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral number. source count remaining p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral number. source count remaining *p3: %i\n", *((int*) p3));

    // The first algebraic sign factor with PLUS (positive number one) as default.
    int s1 = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    // The first pre point value (Vorkommastelle).
    int v1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The first post point value (Nachkommastelle, also called "decimals").
    double d1 = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The first number base power (Potenz).
    double po1 = *NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL;

    // The second algebraic sign factor with PLUS (positive number one) as default.
    int s2 = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    // The second pre point value (Vorkommastelle).
    int v2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The second post point value (Nachkommastelle, also called "decimals").
    double d2 = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The second number base power (Potenz).
    double po2 = *NUMBER_1_0_DOUBLE_STATE_CYBOI_MODEL;

    // The format with INTEGER as default.
    int f = *INTEGER_NUMBER_STATE_CYBOI_FORMAT;
    // The type with INTEGER as default.
    int t = *INTEGER_NUMBER_STATE_CYBOI_TYPE;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Deserialise FIRST part of number.
    deserialise_numeral_part((void*) &s1, (void*) &v1, (void*) &d1, (void*) &po1, p2, p3, p4, p5, p6, p7, (void*) &f, (void*) &t, p8);

    if ((t == *FRACTION_NUMBER_STATE_CYBOI_TYPE) || (t == *COMPLEX_NUMBER_STATE_CYBOI_TYPE)) {

        //
        // A second number part has been found.
        //

        //
        // Deserialise SECOND part of number.
        //
        // CAUTION! Do NOT hand over format and type parametre again
        // but NULL instead since otherwise, they would get overwritten
        // even though they should remain on fraction or complex.
        //
        // For fraction and complex it is clearly defined
        // which format and type the two parts have inside:
        // - fraction: numerator and denominator part as INTEGER
        // - complex: real and imaginary part as FLOAT
        //
        deserialise_numeral_part((void*) &s2, (void*) &v2, (void*) &d2, (void*) &po2, p2, p3, p4, p5, p6, p7, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p8);
    }

    // Verify detected format.
    deserialise_numeral_verification((void*) &r, (void*) &t, p11);

    //
    // CAUTION! When parsing json, for example, then a format is NOT given
    // but has to be detected instead.
    // In such cases, the destination number format parametre is NULL.
    // Therefore, do not only compare the detected and given FORMAT here,
    // but ALSO compare with NULL in order to cover these cases.
    //
    if ((p11 == *NULL_POINTER_STATE_CYBOI_MODEL) || (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

        // The temporary number.
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // A destination number format was NOT given
        // OR it is IDENTICAL to the detected format.
        //

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // The destination number is NOT null.
            //
            // This function was probably called from a cybol deserialiser,
            // so that the destination part p1 is NOT needed.
            //

            // Assign destination number as temporary number.
            n = p0;

        } else {

            //
            // The destination number is NULL.
            //
            // This function was probably called from a json deserialiser,
            // so that the destination part has to be ALLOCATED yet.
            //

            deserialise_numeral_null((void*) &n, p1, p9, p10, (void*) &f, (void*) &t);
        }

        // Assemble number.
        select_numeral_assembler(n, (void*) &s1, (void*) &v1, (void*) &d1, (void*) &po1, (void*) &s2, (void*) &v2, (void*) &d2, (void*) &po2, (void*) &f);

        //?? fwprintf(stdout, L"Debug: Deserialise numeral number. n as int: %i\n", *((int*) n));
        //?? fwprintf(stdout, L"Debug: Deserialise numeral number. n as double: %f\n", *((double*) n));

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise numeral number. The detected format and given destination number item format are not identical.");
        fwprintf(stdout, L"Error: Could not deserialise numeral number. The detected type %i (format: %i) and destination type (format p11: %i) are not identical.\n", t, f, p11);
        fwprintf(stdout, L"Error: Could not deserialise numeral number. The detected type %i (format: %i) and destination type (format *p11: %i) are not identical.\n", t, f, *((int*) p11));
    }
}

/* NUMBER_NUMERAL_DESERIALISER_SOURCE */
#endif
