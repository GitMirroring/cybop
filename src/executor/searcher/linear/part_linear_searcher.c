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

#ifndef PART_LINEAR_SEARCHER_SOURCE
#define PART_LINEAR_SEARCHER_SOURCE

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Retrieves the part's name or model and searches within it.
 *
 * @param p0 the element data (pointer reference)
 * @param p1 the element count
 * @param p2 the element type
 * @param p3 the part (list data position)
 * @param p4 the model flag (false = name, true = model)
 */
void search_linear_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear part.");
    fwprintf(stdout, L"Debug: Search linear part. model flag p4: %i\n", p4);
    //?? fwprintf(stdout, L"Debug: Search linear part. model flag *p4: %i\n", *((int*) p4));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Compare if part name (false) or model (true) is to be retrieved.
    compare_integer_unequal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Retrieve part name
        //

        // The part name item.
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The part name item data, count.
        void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* nc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get part name item.
        copy_array_forward((void*) &n, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        // Get part name item data, count.
        copy_array_forward((void*) &nd, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &nc, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Copy element data, count.
        copy_pointer(p0, (void*) &nd);
        copy_integer(p1, nc);
        //
        // Copy element type.
        //
        // CAUTION! The name is ALWAYS of type "wide character".
        // Therefore, it does NOT have to be determined here.
        // The part's type is always related to its MODEL, but NOT the name.
        //
        copy_integer(p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        fwprintf(stdout, L"Debug: Search linear part. nd: %i\n", nd);
        fwprintf(stdout, L"Debug: Search linear part. nd as wchar_t: %ls\n", (wchar_t*) nd);
        fwprintf(stdout, L"Debug: Search linear part. nc: %i\n", nc);
        fwprintf(stdout, L"Debug: Search linear part. *nc: %i\n", *((int*) nc));
        fwprintf(stdout, L"Debug: Search linear part. type: %i\n", *((int*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE));
        fwprintf(stdout, L"Debug: Search linear part. *nc: %i\n", *((int*) *((void**) nc)));

    } else {

        //
        // Retrieve part model
        //

        // The part model item.
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The part type item.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

        // The part model item data, count.
        void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The part type item data.
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get part model item.
        copy_array_forward((void*) &m, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        // Get part type item.
        copy_array_forward((void*) &t, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);

        // Get part name item data, count.
        copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        // Get part type item data.
        copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Copy element data, count.
        copy_pointer(p0, (void*) &md);
        copy_integer(p1, mc);
        // Copy element type.
        copy_integer(p2, td);

        fwprintf(stdout, L"Debug: Search linear part. md: %i\n", md);
        fwprintf(stdout, L"Debug: Search linear part. mc: %i\n", mc);
        fwprintf(stdout, L"Debug: Search linear part. *mc: %i\n", *((int*) mc));
        fwprintf(stdout, L"Debug: Search linear part. td: %i\n", td);
        fwprintf(stdout, L"Debug: Search linear part. *td: %i\n", *((int*) td));
    }
}

/* PART_LINEAR_SEARCHER_SOURCE */
#endif
