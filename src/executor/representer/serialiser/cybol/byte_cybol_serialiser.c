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
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises byte numbers (unsigned char) into wide character data.
 *
 * @param p0 the destination wide character item
 * @param p1 the source byte data
 * @param p2 the source byte count
 */
void serialise_cybol_byte(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol byte.");

    // The integer item.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The integer item data, count.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ic = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The initial integer data.
    int ii = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Allocate integer item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    //
    // Fill integer item with initial number zero byte elements.
    //
    // The number of elements to fill in is determined by the source count.
    //
    // CAUTION! This IS NECESSARY in order to ensure that
    // source- and destination have an equal count of elements.
    // Otherwise, the elements will not be casted.
    //
    modify_item(i, (void*) &ii, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FILL_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Get integer item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &id, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ic, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Cast source data (array) elements into integer item data (array) elements.
    //
    // CAUTION! A reallocation of the integer item data (array) does NOT happen here,
    // since it already got adjusted while filling the item with initial values above.
    // Therefore, the values of ic and p2 should be equal.
    //
    // However, to be on the safe side, the integer item count ic and NOT p2 is used here,
    // so that its array bounds do not get injured.
    //
    cast_array(id, p1, (void*) BYTE_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_CAST_LOGIC_CYBOI_FORMAT, ic, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    serialise_numeral_integer(p0, id, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DECIMAL_BASE_NUMERAL_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Deallocate integer item.
    deallocate_item((void*) &i, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}
