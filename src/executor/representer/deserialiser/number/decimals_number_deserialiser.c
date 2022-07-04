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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Falk Müller <falk89@web.de>
 */

#ifndef DECIMALS_NUMBER_DESERIALISER_SOURCE
#define DECIMALS_NUMBER_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the number decimal places (decimals).
 *
 * @param p0 the destination format
 * @param p1 the destination type
 * @param p2 the destination integer value one
 * @param p3 the destination integer value two
 * @param p4 the destination double value one
 * @param p5 the destination double value two
 * @param p6 the source data position (pointer reference)
 * @param p7 the source count remaining
 */
void deserialise_number_decimals(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise number decimals.");
    fwprintf(stdout, L"Debug: Deserialise number decimals. count remaining p8: %i\n", p8);
    fwprintf(stdout, L"Debug: Deserialise number decimals. count remaining *p8: %i\n", *((int*) p8));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The decimals data, count.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise decimals data.
    copy_pointer((void*) &dd, p6);

    if (p7 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_less_or_equal((void*) &b, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Either a number end character was found in the selector
            // OR the source count remaining is zero.
            //
            // In BOTH cases, the value can now be deserialised.
            //

            fwprintf(stdout, L"Debug: Deserialise number decimals. dc: %i\n", dc);
            fwprintf(stdout, L"Debug: Deserialise number decimals. dd: %ls\n", (wchar_t*) dd);

            // Deserialise fractional digits.
            deserialise_number_fraction(p2, dd, (void*) &dc);

            break;
        }

        // Select number decimals.
        select_number_decimals(p0, p1, p2, p3, p4, p5, p6, p7, (void*) &dc, (void*) &b);
    }
}

/* DECIMALS_NUMBER_DESERIALISER_SOURCE */
#endif
