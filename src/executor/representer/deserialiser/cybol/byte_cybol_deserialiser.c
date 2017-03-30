/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BYTE_CYBOL_DESERIALISER_SOURCE
#define BYTE_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/format/cybol/logic/cast_logic_cybol_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises wide character data into byte numbers (unsigned char).
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_byte(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol byte.");

    // The integer item.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The integer item data, count.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ic = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The initial character data.
    char c = (char) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate integer item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    deserialise_cybol_integer(i, p1, p2);

    // Get integer item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &id, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ic, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

/*??
fwprintf(stdout, L"TEST deserialise cybol byte *p2: %i\n", *((int*) p2));
fwprintf(stdout, L"TEST deserialise cybol byte *ic: %i\n", *((int*) ic));
fwprintf(stdout, L"TEST deserialise cybol byte *id: %i\n", *((int*) id));
*/

    // Fill destination item with initial number zero byte elements.
    // The number of elements to fill in is determined by the integer item count.
    // CAUTION! This IS NECESSARY in order to ensure that
    // source- and destination have an equal count of elements.
    // Otherwise, the elements will not be casted.
    modify_item_element(p0, (void*) &c, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE, ic, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FILL_MODIFY_LOGIC_CYBOI_FORMAT, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Cast all source- into destination array elements.
    // CAUTION! Assigning the destination array to the destination item
    // is NOT necessary, since a reallocation does NOT happen here.
    // Neither the count, nor the size of the destination array gets changed.
    // They already got adjusted while filling the item with initial values above.
    cast_all_item_element(p0, id, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) BYTE_CAST_LOGIC_CYBOI_FORMAT, ic, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Deallocate integer item.
    deallocate_item((void*) &i, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/* BYTE_CYBOL_DESERIALISER_SOURCE */
#endif
