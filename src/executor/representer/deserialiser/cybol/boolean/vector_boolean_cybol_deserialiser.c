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

#ifndef VECTOR_BOOLEAN_CYBOL_DESERIALISER_SOURCE
#define VECTOR_BOOLEAN_CYBOL_DESERIALISER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../../executor/copier/array_copier.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "../../../../../executor/copier/pointer_copier.c"
#include "../../../../../executor/representer/deserialiser/cybol/boolean/value_boolean_cybol_deserialiser.c"
#include "../../../../../executor/selector/cybol/boolean_cybol_selector.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the comma-separated wide character data into integer values
 * representing boolean values of 0 or 1.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_cybol_boolean_vector(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol boolean vector.");

    // The destination item count.
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The old destination item count.
    //
    // CAUTION! This variable is necessary for inserting
    // values, rather than appending them.
    //
    // While parsing a vector, the programme "dives" into
    // the vector first, so that last values are added first.
    // If values were now just appended, the order of
    // vector values would be swapped, which is not wanted.
    //
    // On the other hand, inserting values at the beginning of the
    // destination item is wrong if values are already present.
    //
    // Therefore, the destination item's "old" element count
    // is remembered here, so that new values may be inserted
    // starting from that count used as index, which has the
    // effect that elements are appended in the correct order.
    //
    int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The boolean values data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get destination item count.
    copy_array_forward((void*) &dc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Initialise old destination item count.
    copy_integer((void*) &oc, dc);

    // Initialise boolean values data.
    copy_pointer((void*) &bd, p1);

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

            break;
        }

        select_cybol_boolean(p0, p1, p2, (void*) &bc, (void*) &b);
    }

    //
    // Prepend element to destination.
    //
    // CAUTION! Hand over number base 0 as parametre
    // (automatic identification of the correct number base).
    //
    // ??TODO: TEMPORARY SOLUTION! The number base 10 is handed over for now,
    // since it is needed for proper conversion of xdt field names.
    //
    // Some of them start with zero and would  be interpreted as octal number.
    // In the future, a cybol property or constraint for the given numbers
    // should be provided indicating their number base being interpreted here then.
    //
    deserialise_cybol_boolean_value(p0, bd, (void*) &bc, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &oc);
}

/* VECTOR_BOOLEAN_CYBOL_DESERIALISER_SOURCE */
#endif
