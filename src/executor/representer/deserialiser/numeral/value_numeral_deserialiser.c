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

#ifndef VALUE_NUMERAL_DESERIALISER_SOURCE
#define VALUE_NUMERAL_DESERIALISER_SOURCE

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
 * Deserialises the numeral value.
 *
 * @param p0 the destination value
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the decimal separator data
 * @param p4 the decimal separator count
 * @param p5 the thousands separator data
 * @param p6 the thousands separator count
 * @param p7 the number base
 * @param p8 the post point value flag
 * @param p9 the number base power flag
 * @param p10 the detected format
 * @param p11 the detected type
 */
void deserialise_numeral_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral value.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral value. source count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral value. source count remaining *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral value. source count remaining *p1: %ls\n", (wchar_t*) *((void**) p1));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The value data, count.
    void* vd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int vc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise value data.
    copy_pointer((void*) &vd, p1);

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

        compare_integer_less_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Either an end character was found in the selector
            // OR the source count remaining is zero.
            //
            // In BOTH cases, the value can now be deserialised.
            //

            //?? fwprintf(stdout, L"Debug: Deserialise numeral value. vc: %i\n", vc);
            //?? fwprintf(stdout, L"Debug: Deserialise numeral value. vd: %ls\n", (wchar_t*) vd);

            //?? TODO:
            // Remove thousands separator using a string function (modify)

            // Deserialise integer value representing the destination value.
            deserialise_numeral_integer(p0, vd, (void*) &vc, p7);

            break;

        } else {

            // Select numeral value.
            select_numeral_value(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, (void*) &vc, (void*) &b);
        }
    }
}

/* VALUE_NUMERAL_DESERIALISER_SOURCE */
#endif
