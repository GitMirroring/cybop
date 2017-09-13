/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Falk Müller <falk89@web.de>
 */

#ifndef VECTOR_DECIMAL_FRACTION_CYBOL_DESERIALISER_SOURCE
#define VECTOR_DECIMAL_FRACTION_CYBOL_DESERIALISER_SOURCE

#ifdef WIN32
#include <windows.h>
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../executor/representer/deserialiser/cybol/fraction/decimal/value_decimal_fraction_cybol_deserialiser.c"
#include "../../../../../../executor/searcher/selector/cybol/decimal_fraction_cybol_selector.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the comma-separated wide character data into double values.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_cybol_fraction_decimal_vector(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol fraction decimal vector.");

    // The destination item count.
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The old destination item count.
    // CAUTION! This variable is necessary for inserting
    // values, rather than appending them.
    // While parsing a vector, the programme "dives" into
    // the vector first, so that last values are added first.
    // If values were now just appended, the order of
    // vector values would be swapped, which is not wanted.
    // On the other hand, inserting values at the beginning of the
    // destination item is wrong if values are already present.
    // Therefore, the destination item's "old" element count
    // is remembered here, so that new values may be inserted
    // starting from that count used as index, which has the
    // effect that elements are appended in the correct order.
    int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get destination item count.
    copy_array_forward((void*) &dc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Initialise old destination item count.
    copy_integer((void*) &oc, dc);

    // Initialise element.
    copy_pointer((void*) &e, p1);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_cybol_fraction_decimal(p0, (void*) &b, p1, p2);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment element count.
            ec++;
        }
    }

    // Prepend element to destination.
    deserialise_cybol_fraction_decimal_value(p0, e, (void*) &ec, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &oc);
}

/* VECTOR_DECIMAL_FRACTION_CYBOL_DESERIALISER_SOURCE */
#endif
