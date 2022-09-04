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
 * @author Falk Müller <falk89@web.de>
 */

#ifndef VECTOR_NUMERAL_DESERIALISER_SOURCE
#define VECTOR_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Loops through the given source wide character array detecting numbers.
 *
 * @param p0 the destination number item (pointer reference)
 * @param p1 the destination number part (pointer reference)
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the number part name data
 * @param p5 the number part name count
 * @param p6 the destination number item format
 */
void deserialise_numeral_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral vector.");
    fwprintf(stdout, L"Debug: Deserialise numeral vector. count remaining p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Deserialise numeral vector. count remaining *p1: %i\n", *((int*) p1));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_less_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        //
        // Deserialise number.
        //
        // CAUTION! The destination number item is handed over as REFERENCE
        // since it may get assigned the model of a new allocated part inside.
        //
        deserialise_numeral_number(p0, p1, p2, p3, p4, p5, p6);
    }
}

/* VECTOR_NUMERAL_DESERIALISER_SOURCE */
#endif
