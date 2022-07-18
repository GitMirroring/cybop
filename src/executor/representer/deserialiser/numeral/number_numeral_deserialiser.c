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
 */

#ifndef NUMBER_NUMERAL_DESERIALISER_SOURCE
#define NUMBER_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/numeral/numeral_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the number value.
 *
 * CAUTION! The destination number item is a REFERENCE,
 * so that it can be assigned a new value, in case
 * a new number part had to be allocated inside.
 *
 * @param p0 the destination number item (pointer reference)
 * @param p1 the destination number part (pointer reference)
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the number part name data
 * @param p5 the number part name count
 */
void deserialise_numeral_number(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** i = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral number.");
        fwprintf(stdout, L"Debug: Deserialise numeral number. source count remaining p3: %i\n", p3);
        fwprintf(stdout, L"Debug: Deserialise numeral number. source count remaining *p3: %i\n", *((int*) p3));

        // The algebraic sign factor with PLUS (positive number one) as default.
        int s = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
        // The number base with DECIMAL as default.
        int b = *DECIMAL_BASE_NUMERAL_MODEL;
        // The format with INTEGER as default.
        int f = *INTEGER_NUMERAL_STATE_CYBOI_FORMAT;
        // The type with INTEGER as default.
        int t = *INTEGER_NUMERAL_STATE_CYBOI_TYPE;
        // The destination item count.
        void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
        //
        // The old destination item count.
        //
        // CAUTION! This variable is necessary for INSERTING values,
        // rather than appending them.
        // While parsing a vector, the programme DIVES into the vector FIRST,
        // so that last values are added first. If values were now just appended,
        // the order of vector values would be swapped, which is NOT wanted.
        // On the other hand, inserting values at the beginning of the
        // destination item is wrong if values are already present.
        // Therefore, the destination item's "old" element count
        // is remembered here, so that new values may be inserted
        // starting from that count used as index, which has the
        // effect that elements are appended in the correct order.
        //
        int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Skip any whitespace characters.
        deserialise_numeral_whitespace(p2, p3);

        // Deserialise algebraic sign.
        select_numeral_sign((void*) &s, p2, p3);

        // Deserialise number base.
        select_numeral_base((void*) &b, p2, p3);

        // Deserialise numeral value.
        //?? TODO
        deserialise_numeral_value(number_1, number_2, p2, p3, (void*) &f, (void*) &t);

        //
        // Make sure a destination number item exists.
        // If it does not, then a part gets allocated inside
        // and its model item assigned as destination number item.
        //
        deserialise_numeral_existence(p0, p1, p4, p5, (void*) &f, (void*) &t);

        // Get destination item count.
        copy_array_forward((void*) &dc, *i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        // Initialise old destination item count.
        copy_integer((void*) &oc, dc);

        //
        // Add data to number part model item.
        //
        // CAUTION! The "adjust count" flag is set to NULL here,
        // since the destination count gets ALWAYS adjusted.
        //
        //?? TODO
        modify_item(*i, (void*) &TODO_number, (void*) &t, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &oc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // CAUTION Do NOT append the part to some destination here,
        // since this is done in other deserialisers' files such as:
        //
        // - CYBOL: "standard_cybol_deserialiser.c"
        // - JSON: "number_json_deserialiser.c", "string_json_deserialiser.c"
        //

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise numeral number. The destination number item is null.");
        fwprintf(stdout, L"Error: Could not deserialise numeral number. The destination number item is null. p0: %i\n", p0);
    }
}

/* NUMBER_NUMERAL_DESERIALISER_SOURCE */
#endif
