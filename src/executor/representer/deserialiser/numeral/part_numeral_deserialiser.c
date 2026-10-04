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
#include "communication.h"
#include "constant.h"
#include "logger.h"
#include "text.h"
#include "type.h"

/**
 * Deserialises the first or second part numeral.
 *
 * A vulgar fraction or a complex number consist of TWO parts.
 *
 * The consider number base prefix flag has the following meaning:
 * - true: CONSIDER integer prefixes like "0x" for hexadecimal,
 *   as used in c/c++, perl or python
 * - false: IGNORE prefixes as is needed in json and is the DEFAULT so that
 *   floating point numbers with zero as pre-point value get recognised
 *   correctly with decimal number base
 *
 * @param p0 the destination algebraic sign
 * @param p1 the destination pre point value
 * @param p2 the destination post point value
 * @param p3 the destination number base power
 * @param p4 the source data position (pointer reference)
 * @param p5 the source count remaining
 * @param p6 the decimal separator data
 * @param p7 the decimal separator count
 * @param p8 the thousands separator data
 * @param p9 the thousands separator count
 * @param p10 the detected format
 * @param p11 the detected type
 * @param p12 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 */
void deserialise_numeral_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral part.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. source count remaining p5: %i\n", p5);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. source count remaining *p5: %i\n", *((int*) p5));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The number base with DECIMAL as default.
    int b = *DECIMAL_BASE_NUMERAL_MODEL;
    // The post point value flag.
    int post = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The number base power flag.
    int p = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Skip any whitespace characters.
    deserialise_whitespace(p4, p5);

    // Deserialise algebraic sign.
    select_numeral_sign(p0, p4, p5);

    //
    // Check consider number base prefix flag.
    //
    // CAUTION! The json specification does not allow using number
    // prefixes like "0x" for hexadecimal or just "0" for octal numbers.
    // If a number literal with LEADING ZERO is found in some json data,
    // then it has to be interpreted as DECIMAL number by default,
    // by just IGNORING any leading zeros.
    //
    // Therefore, the consider number base prefix flag may be used to
    // enable number base prefix detection when necessary.
    //
    compare_integer_unequal((void*) &r, p12, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The consider number base prefix flag IS set.
        //

        // Deserialise number base by evaluating prefix.
        select_numeral_base((void*) &b, p4, p5);
    }

    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. b: %i\n", b);

    // Deserialise number value.
    deserialise_numeral_value(p1, p4, p5, p6, p7, p8, p9, (void*) &b, (void*) &post, (void*) &p, p10, p11);

    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. pre point value p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. pre point value *p1: %i\n", *((int*) p1));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. post point value flag post: %i\n", post);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. number base power flag p: %i\n", p);

    if (post != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"Debug: Deserialise numeral part. post: %i\n", post);

        //
        // This is a decimal fraction with post point value.
        //

        // Deserialise post point value.
        deserialise_numeral_decimals(p2, p4, p5, (void*) &b, (void*) &p, p10, p11);
    }

    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. post point value p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. post point value *p2: %f\n", *((double*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. number base power flag p: %i\n", p);

    if (p != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"Debug: Deserialise numeral part. p: %i\n", p);

        //
        // This is a decimal fraction with number base power.
        //

        // Deserialise number base power.
        deserialise_numeral_power(p3, p4, p5, (void*) &b, p10, p11);
    }

    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. number base power p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral part. number base power *p3: %f\n", *((double*) p3));
}
