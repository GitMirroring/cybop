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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ITEM_NORMALISER_SOURCE
#define ITEM_NORMALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../executor/modifier/normaliser/reference_normaliser.c"
#include "../../../executor/modifier/item_modifier.c"
#include "logger.h"

/**
 * Allocates a temporary string item.
 *
 * @param p0 the destination wide character array (pointer reference)
 * @param p1 the destination wide character array count
 * @param p2 the destination wide character array size
 * @param p3 the source wide character data
 * @param p4 the source wide character count
 */
void normalise_item(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise item.");
    //?? fwprintf(stdout, L"Debug: Normalise item. source count p4: %i\n", p4);
    //?? fwprintf(stdout, L"Debug: Normalise item. source count *p4: %i\n", *((int*) p4));
    //?? fwprintf(stdout, L"Debug: Normalise item. source data p3: %ls\n", (wchar_t*) p3);

    // The temporary string item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary string item data, count.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate temporary string item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Process source string.
    //
    // CAUTION! In most cases, source string and destination string
    // are identical. Therefore, direct manipulation of the
    // source string is NOT possible since otherwise, its content
    // would get changed yet before having been parsed completely.
    // In order to work properly, a TEMPORARY string item is
    // used as destination here.
    //
    normalise_reference(t, p3, p4);

    // Get temporary string item data, count.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tc, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Overwrite destination array with temporary string item data.
    modify_array(p0, td, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, tc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

    // Deallocate temporary string item.
    deallocate_item((void*) &t, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* ITEM_NORMALISER_SOURCE */
#endif
