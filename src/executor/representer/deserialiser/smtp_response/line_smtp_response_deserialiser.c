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
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the smtp response line.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source response line data
 * @param p3 the source response line count
 */
void deserialise_smtp_response_line(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise smtp response line.");
    fwprintf(stdout, L"Debug: Deserialise smtp response line. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise smtp response line. *p3: %i\n", *((int*) p3));

    // The string list item.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The string list item data, count.
    void* ld = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate string list item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    // Deserialise (split) joined string by SPACE into string list item.
    deserialise_joined_string(l, p2, p3, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Get string list item data, count.
    copy_array_forward((void*) &ld, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lc, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Iterate through string list.
    deserialise_smtp_response_strings(p0, p1, ld, lc);

    //
    // Deallocate string list item.
    //
    // CAUTION! The item data array gets EMPTIED automatically inside,
    // so that all contained elements get removed and their
    // REFERENCE count decremented for rubbish (garbage) collection.
    // That is, the elements and their contained elements get deallocated
    // automatically as well, in case their reference counter has fallen to ZERO.
    // Therefore, there is NOTHING else to do here.
    //
    deallocate_item((void*) &l, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
}
