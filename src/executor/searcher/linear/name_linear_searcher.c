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

#include "algorithm.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Searches within the given part's name.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the part
 * @param p2 the searchword data
 * @param p3 the searchword count
 * @param p4 the searchword type
 */
void search_linear_name(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear name.");
    //?? fwprintf(stdout, L"Debug: Search linear name. part p1: %i\n", p1);

    // The part name item.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part name item data, count.
    void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part name item.
    copy_array_forward((void*) &n, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    // Get part name item data, count.
    copy_array_forward((void*) &nd, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nc, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Search through part name.
    //
    // CAUTION! The name is ALWAYS of type "wide character".
    // Therefore, the type does NOT have to be determined above.
    // A part's type is always related to its MODEL, but NOT the name.
    //
    // CAUTION! Call function "search_linear_primitive" instead of recursively
    // "search_linear_fifo", since a 1:1 matching is necessary for part name
    // (other than for the model further below).
    //
    search_linear_primitive(p0, nd, nc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, p3, p4);

    //?? fwprintf(stdout, L"Debug: Search linear name. nd: %i\n", nd);
    //?? fwprintf(stdout, L"Debug: Search linear name. nd as wchar_t: %ls\n", (wchar_t*) nd);
    //?? fwprintf(stdout, L"Debug: Search linear name. nc: %i\n", nc);
    //?? fwprintf(stdout, L"Debug: Search linear name. *nc: %i\n", *((int*) nc));
}
