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

#ifndef ELEMENT_LIST_FINDER_SOURCE
#define ELEMENT_LIST_FINDER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/copier/array/forward_array_copier.c"
#include "../../logger/logger.c"

/**
 * Compares entry element at the given element index with comparison data.
 *
 * @param p0 the comparison result
 * @param p1 the entry
 * @param p2 the comparison data
 * @param p3 the entry element index
 */
void find_list_element(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find list element.");
    //?? fwprintf(stdout, L"Debug: Find list element. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Find list element. *p2: %i\n", *((int*) p2));

    // The entry element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get entry element from entry by given element index.
    copy_array_forward((void*) &e, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);

    // Compare entry element with comparison data.
    compare_integer_equal(p0, e, p2);
}

/* ELEMENT_LIST_FINDER_SOURCE */
#endif
