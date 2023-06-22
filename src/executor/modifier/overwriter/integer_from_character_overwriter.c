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

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Converts the given ascii characters into wide characters,
 * then converts the wide characters into an integer primitive
 * and finally overwrites the destination item.
 *
 * This is a convenience method to avoid redundant code
 * when deserialising ascii data.
 *
 * @param p0 the destination wide character item
 * @param p1 the source ascii character data
 * @param p2 the source ascii character count
 */
void overwrite_integer_from_character(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Overwrite integer from character.");

    // The wide character item.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The wide character item data, count.
    void* wd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* wc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The integer primitive.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Allocate wide character item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &w, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Decode multibyte character array into wide character item.
    decode_utf_8(w, p1, p2);

    //
    // Get wide character item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &wd, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wc, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Deserialise wide character data as integer primitive.
    deserialise_numeral_integer((void*) &i, wd, wc, (void*) DECIMAL_BASE_NUMERAL_MODEL);

    // Overwrite destination item with integer primitive.
    modify_item(p0, (void*) &i, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

    // Deallocate wide character item.
    deallocate_item((void*) &w, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
