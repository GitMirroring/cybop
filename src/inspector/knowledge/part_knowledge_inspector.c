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
 * Inspects the given part.
 *
 * It gets written into a file in model diagram format.
 *
 * Usage example:
 *
 * #include "inspector.h"
 * fwprintf(stdout, L"Debug: Deserialise cybol decision. inspect destination part p0: %i\n", p0);
 * inspect_knowledge_part((void*) L"inspect_part", (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL, p0, p13, p14, p15);
 *
 * @param p0 the filename data
 * @param p1 the filename count
 * @param p2 the part
 * @param p3 the knowledge memory part (pointer reference)
 * @param p4 the stack memory item
 * @param p5 the internal memory data
 */
void inspect_knowledge_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    // The part model item.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part model item.
    copy_array_forward((void*) &m, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Inspect part model item.
    inspect_knowledge_item(p0, p1, m, p3, p4, p5);
}
