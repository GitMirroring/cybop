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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "algorithm.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/*
 * Swap the given values depending on comparison.
 *
 * @param p0 the data (pointer reference only if type is part or pointer)
 * @param p1 the type
 * @param p2 the swapped flag
 * @param p3 the left value (pointer reference only if type is part or pointer)
 * @param p4 the right value (pointer reference only if type is part or pointer)
 * @param p5 the left index
 * @param p6 the right index
 * @param p7 the criterion data (pointer reference)
 * @param p8 the criterion count
 * @param p9 the criterion type
 * @param p10 the knowledge memory part (pointer reference)
 * @param p11 the stack memory item
 * @param p12 the internal memory data
 * @param p13 the descending flag
 */
void sort_bubble_swap(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble swap.");

    // The operation type.
    // CAUTION! The default is "ascending", which means "greater" comparison.
    int o = *GREATER_COMPARE_LOGIC_CYBOI_FORMAT;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Determine sort operation type.
    sort_bubble_operation((void*) &o, p13);

    // Get current value.
    copy_array_forward(p3, p0, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p5);
    // Get successor value.
    copy_array_forward(p4, p0, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

    // Determine type of current and successor value and compare them.
    sort_bubble_type((void*) &r, p3, p4, (void*) &o, p1, p7, p8, p9, p10, p11, p12);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Set current value.
        copy_array_forward(p0, p4, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p5, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        // Set successor value.
        copy_array_forward(p0, p3, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p6, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Set swapped flag.
        copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}
