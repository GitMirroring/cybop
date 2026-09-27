/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "constant.h"
#include "inspector.h"
#include "knowledge.h"

//
// Forward declaration
//

void calculate_integer_add(void* p0, void* p1);

/**
 * Inspects the given part model item.
 *
 * It gets written into a file in model diagram format.
 *
 * Usage example:
 *
 * #include "inspector.h"
 * fwprintf(stdout, L"Debug: Deserialise cybol decision. inspect destination model item p0: %i\n", p0);
 * inspect_knowledge_item((void*) L"inspect_xml", (void*) NUMBER_11_INTEGER_STATE_CYBOI_MODEL, p0, p6, p7, p8);
 *
 * @param p0 the filename data
 * @param p1 the filename count
 * @param p2 the part model item
 * @param p3 the knowledge memory part (pointer reference)
 * @param p4 the stack memory item
 * @param p5 the internal memory data
 */
void inspect_knowledge_item(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    // The part model item data, count.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part model item data, count.
    copy_array_forward((void*) &d, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &c, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Inspect part model item data, count.
    inspect_knowledge_data(p0, p1, d, c, p3, p4, p5);
}
