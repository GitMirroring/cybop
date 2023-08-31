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
 * @version CYBOP 0.27.0 2023-08-31
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

/**
 * Deserialises the character separated value (csv) wide character sequence into separate parts.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source text data
 * @param p3 the source text count
 * @param p4 the language properties (constraints) data
 * @param p5 the language properties (constraints) count
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 */
void deserialise_csv(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise csv.");
    //?? fwprintf(stdout, L"Debug: Deserialise csv. source wide character count p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise csv. source wide character count *p3: %i\n", *((int*) p3));

    // The textline list item.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The textline list item data, count.
    void* ld = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate textline list item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    // Deserialise source text data into textline list item.
    deserialise_textline_list(l, p2, p3);

    // Get textline list item data, count.
    copy_array_forward((void*) &ld, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lc, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Deserialise content.
    deserialise_csv_properties(p0, p1, ld, lc, p4, p5, p6, p7, p8);

    //
    // Deallocate textline list item.
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
