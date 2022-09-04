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

#ifndef PART_NUMERAL_DESERIALISER_SOURCE
#define PART_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the first or second part numeral.
 *
 * @param p0 the destination algebraic sign
 * @param p1 the destination number base (relevant for integer only)
 * @param p2 the destination value
 * @param p3 the destination decimal places (decimals)
 * @param p4 the destination decimal power
 * @param p5 the source data position (pointer reference)
 * @param p6 the source count remaining
 * @param p7 the detected format
 * @param p8 the detected type
 * @param p9 the second part flag
 */
void deserialise_numeral_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral part.");
    fwprintf(stdout, L"Debug: Deserialise numeral part. source count remaining p6: %i\n", p6);
    fwprintf(stdout, L"Debug: Deserialise numeral part. source count remaining *p6: %i\n", *((int*) p6));

    // The decimal places (decimals) flag.
    int d = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The decimal power flag.
    int p = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The second part flag.
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Skip any whitespace characters.
    deserialise_numeral_whitespace(p5, p6);

    // Deserialise algebraic sign.
    select_numeral_sign(p0, p5, p6);

    // Deserialise number base.
    select_numeral_base(p1, p5, p6);

    // Deserialise number value.
    deserialise_numeral_value(p2, p5, p6, (void*) &d, (void*) &p, (void*) &s);

    if (d != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a decimal fraction.
        //

        // Assign correct format and type.
        copy_integer(p7, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        copy_integer(p8, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

        // Deserialise decimal places (decimals).
        deserialise_numeral_decimals(p3, p5, p6, (void*) &p, (void*) &s);
    }

    if (p != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a decimal fraction.
        //

        // Assign correct format and type.
        copy_integer(p7, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
        copy_integer(p8, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

        // Deserialise decimal power.
        deserialise_decimal_power(p4, p5, p6, (void*) &s);
    }

    if (s != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A NEXT (probably second) number part exists.
        //

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        compare_integer_equal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is the FIRST part being processed.
            //

            // Set second part flag.
            copy_integer(p9, (void*) &s);

        } else {

            //
            // This already is the SECOND part being processed.
            //

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise numeral part. A third number part was detected, which is not permitted.");
            fwprintf(stdout, L"Warning: Could not deserialise numeral part. A third number part was detected, which is not permitted. source count remaining p6: %i\n", p6);
            fwprintf(stdout, L"Warning: Could not deserialise numeral part. A third number part was detected, which is not permitted. source count remaining *p6: %i\n", *((int*) p6));
        }
    }
}

/* PART_NUMERAL_DESERIALISER_SOURCE */
#endif
