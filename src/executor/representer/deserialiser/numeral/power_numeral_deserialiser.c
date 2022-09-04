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

#ifndef POWER_NUMERAL_DESERIALISER_SOURCE
#define POWER_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the decimal power (power of 10).
 *
 * @param p0 the destination double value
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_numeral_power(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral power.");
    fwprintf(stdout, L"Debug: Deserialise numeral power. source count p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Deserialise numeral power. source count *p2: %i\n", *((int*) p2));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The power data, count.
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int pc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise power data.
    copy_pointer((void*) &pd, p1);

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

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Either an end character was found in the selector
            // OR the source count remaining is zero.
            //
            // In BOTH cases, the power can now be deserialised.
            //

            fwprintf(stdout, L"Debug: Deserialise numeral power. pc: %i\n", pc);
            fwprintf(stdout, L"Debug: Deserialise numeral power. pd: %ls\n", (wchar_t*) pd);

            // Deserialise integer value representing the decimal power (power of 10).
            deserialise_numeral_integer(p2, pd, (void*) &pc);

            break;
        }

        // Select decimal power (power of 10).
        select_numeral_power(p0, p1, p2, p3, p4, p5, p6, p7, p8);
    }
}

/* POWER_NUMERAL_DESERIALISER_SOURCE */
#endif
