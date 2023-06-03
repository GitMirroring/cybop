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

#ifndef MODEL_LINEAR_SEARCHER_SOURCE
#define MODEL_LINEAR_SEARCHER_SOURCE

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Searches within the given part's model.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the part
 * @param p2 the searchword data
 * @param p3 the searchword count
 * @param p4 the searchword type
 */
void search_linear_model(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear model.");
    //?? fwprintf(stdout, L"Debug: Search linear model. part p1: %i\n", p1);

    // The part model item.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part type item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The part model item data, count.
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part type item data.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get part model item.
    copy_array_forward((void*) &m, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get part type item.
    copy_array_forward((void*) &t, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);

    // Get part name item data, count.
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get part type item data.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    compare_integer_equal((void*) &r, td, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The part model contains primitive data.
        //

        // Search through part model recursively.
        search_linear_fifo(p0, md, mc, td, *NULL_POINTER_STATE_CYBOI_MODEL, p2, p3, p4);

        //?? fwprintf(stdout, L"Debug: Search linear model. md: %i\n", md);
        //?? fwprintf(stdout, L"Debug: Search linear model. md as wchar_t: %ls\n", (wchar_t*) md);
        //?? fwprintf(stdout, L"Debug: Search linear model. mc: %i\n", mc);
        //?? fwprintf(stdout, L"Debug: Search linear model. *mc: %i\n", *((int*) mc));
        //?? fwprintf(stdout, L"Debug: Search linear model. td: %i\n", td);
        //?? fwprintf(stdout, L"Debug: Search linear model. *td: %i\n", *((int*) td));

    } else {

        //
        // The part model contains further parts.
        //

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not search linear model. The model does not contain primitive data but further parts, and arbitrarily deep trees do not make sense for search.");
        fwprintf(stdout, L"Warning: Could not search linear model. The model does not contain primitive data but further parts, and arbitrarily deep trees do not make sense for search. td: %i\n", td);
        fwprintf(stdout, L"Warning: Could not search linear model. The model does not contain primitive data but further parts, and arbitrarily deep trees do not make sense for search. *td: %i\n", *((int*) td));
    }
}

/* MODEL_LINEAR_SEARCHER_SOURCE */
#endif
