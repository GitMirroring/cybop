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

#ifndef DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE
#define DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "type.h"

/**
 * Serialises the decimal fraction into a wide character sequence.
 *
 * @param p0 the destination wide character item
 * @param p1 the source double value
 * @param p2 the sign flag
 * @param p3 the number base
 * @param p4 the prefix flag (some conversions like html numeric references do not want a "0x" prefix and prepend "&#x" themselves instead)
 * @param p5 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p6 the decimal separator data
 * @param p7 the decimal separator count
 * @param p8 the decimal places
 * @param p9 the scientific notation flag
 */
void serialise_numeral_fraction_decimal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral fraction decimal.");
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. source number p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. source number *p1: %f\n", *((double*) p1));

    //
    // Declaration
    //

    // The decimal separator with FULL STOP (dot) as default data, count.
    void* sd = (void*) SEPARATOR_DECIMAL_NUMERAL_NAME;
    int sc = *SEPARATOR_DECIMAL_NUMERAL_NAME_COUNT;
    // The scientific notation flag comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The temporary floating point number.
    double n = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The power exponent.
    int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The pre-point value.
    int pre = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The post-point value.
    double post = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The pre-point value as double.
    double pred = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The pre-point absolute value.
    double prea = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The sign comparison result.
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The sign flag comparison result.
    int sf = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Initialisation
    //

    //
    // CAUTION! This check IS necessary since function "copy_pointer" tests
    // for NULL inside, but the argument handed over is a local variable's
    // pointer reference and thus NOT null, even if the actual value IS null.
    //
    if ((p6 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p7 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        copy_pointer((void*) &sd, (void*) &p6);
        copy_integer((void*) &sc, p7);
    }

    // Initialise temporary floating point number.
    copy_double((void*) &n, p1);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. n: %f\n", n);

    //
    // Eliminate negative sign from temporary floating point number.
    //
    // CAUTION! The sign gets considered separately below.
    // Negative values might only falsify calculation.
    // Therefore, calculate with POSITIVE values only.
    //
    calculate_double_absolute((void*) &n, (void*) &n);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. absolute n: %f\n", n);

    // Check scientific notation flag.
    compare_integer_unequal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The scientific notation flag is set.
        //

        // Convert floating point number into scientific notation.
        calculate_double_scientific((void*) &n, (void*) &p, p3);
        //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. sci n: %f\n", n);
        //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. sci p: %i\n", p);
    }

    //
    // Determine pre-point value
    //

    //
    // Convert floating-point number to integer by CASTING it to int.
    //
    // CAUTION! This is a legitimate method of truncating a floating-point
    // value, as mentioned in the glibc documentation:
    // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Rounding-Functions
    //
    cast_integer_double((void*) &pre, (void*) &n);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. pre: %i\n", pre);

    //
    // Determine post-point value (decimal places)
    //

    // Initialise post-point value with original number.
    copy_double((void*) &post, (void*) &n);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. post: %f\n", post);
    // Eliminate sign from post-point value.
    calculate_double_absolute((void*) &post, (void*) &post);
    // Cast pre-point value to double.
    cast_double_integer((void*) &pred, (void*) &pre);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. pred: %f\n", pred);
    // Eliminate sign from pre-point value.
    calculate_double_absolute((void*) &prea, (void*) &pred);
    //
    // Subtract pre-point value so that only the relevant decimal places (decimals)
    // remain and a ZERO is standing before the decimal separator.
    //
    // CAUTION! For this to work properly, the ABSOLUTE value greater or
    // equal to zero needs to be handed over as subtrahend since otherwise,
    // wrong values will be calculated as result.
    //
    calculate_double_subtract((void*) &post, (void*) &prea);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. sub post: %f\n", post);

    //
    // Serialisation
    //

    //
    // Check for negative number.
    //
    // CAUTION! The sign needs to be treated SEPARATELY here,
    // since the function "serialise_numeral_integer" called below
    // does NOT append a minus sign in case of a ZERO value.
    //
    compare_double_less((void*) &s, p1, (void*) NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. s: %i\n", s);

    if (s != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The number is NEGATIVE.
        //

        // Append minus sign wide character to destination item.
        modify_item(p0, (void*) MINUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MINUS_SIGN_NUMERAL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        //
        // The number is POSITIVE or ZERO.
        //

        // Check sign flag.
        compare_integer_unequal((void*) &sf, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (sf != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append plus sign wide character to destination item.
            modify_item(p0, (void*) PLUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PLUS_SIGN_NUMERAL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    // Determine ABSOLUTE pre-point value.
    calculate_integer_absolute((void*) &pre, (void*) &pre);
    //?? fwprintf(stdout, L"Debug: Serialise numeral fraction decimal. absolute pre: %i\n", pre);

    //
    // Serialise pre-point value.
    //
    // CAUTION! Hand over the ABSOLUTE value as source here,
    // since the SIGN got already appended above.
    //
    // CAUTION! Set sign flag to FALSE, since the SIGN got already appended above.
    // Otherwise, the destination wide character item would receive TWO signs.
    //
    serialise_numeral_integer(p0, (void*) &pre, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5);

    // Append decimal separator wide character to destination item.
    modify_item(p0, sd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &sc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Serialise post-point value.
    serialise_numeral_decimals(p0, (void*) &post, p3, p8);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append power exponent letter "e" wide character to destination item.
        modify_item(p0, (void*) SMALL_POWER_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) SMALL_POWER_NUMERAL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Serialise power exponent value.
        serialise_numeral_integer(p0, (void*) &p, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5);
    }
}

/* DECIMAL_FRACTION_NUMERAL_SERIALISER_SOURCE */
#endif
