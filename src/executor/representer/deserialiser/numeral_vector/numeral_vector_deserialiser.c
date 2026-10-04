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
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "text.h"
#include "type.h"

/**
 * Deserialises the source numeral vector into elements of the destination number item.
 *
 * CAUTION! This function is applicable to CYBOL but NOT to json, since:
 * - in cybol, EACH number gets interpreted as vector (array)
 * - in json, arrays and numbers are treated DIFFERENTLY
 *
 * Since in json, each number stands for itself, it may call the function
 * "deserialise_numeral" DIRECTLY, without having to care about vectors.
 * This also solves the problem that in json, the number type is unknown and
 * has to get detected from the value, which would complicate vector handling.
 *
 * @param p0 the destination number item
 * @param p1 the source wide character vector data
 * @param p2 the source wide character vector count
 * @param p3 the decimal separator data
 * @param p4 the decimal separator count
 * @param p5 the thousands separator data
 * @param p6 the thousands separator count
 * @param p7 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p8 the destination number item format
 */
void deserialise_numeral_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral vector.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral vector. source count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral vector. source count *p2: %i\n", *((int*) p2));

    // The temporary item storing wide character parts representing a number each.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary item data, count.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate temporary part element item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    // Deserialise numeral vector storing the single numbers as child nodes of the temporary part element item.
    deserialise_joined_string(t, p1, p2, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Get temporary part element item data, count.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tc, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Iterates through the list items in order to deserialise them into numbers.
    deserialise_numeral_vector_list(p0, td, tc, p3, p4, p5, p6, p7, p8);

    // Deallocate temporary part element item.
    deallocate_item((void*) &t, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
}
