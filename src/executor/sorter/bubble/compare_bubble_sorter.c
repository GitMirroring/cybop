/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_BUBBLE_SORTER_SOURCE
#define COMPARE_BUBBLE_SORTER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../executor/comparator/basic/value_comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
//?? #include "../../../executor/swapper/swapper.c"
#include "../../../logger/logger.c"

/*
 * Compares the given values and swaps them if necessary.
 *
 * @param p0 the data
 * @param p1 the type
 * @param p2 the swapped flag
 * @param p3 the current index
 * @param p4 the successor index
 */
void sort_bubble_compare(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble compare.");

    // The current value.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The successor value.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get current value.
    copy_array_forward((void*) &c, p0, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);
    // Get successor value.
    copy_array_forward((void*) &s, p0, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p4);

    // Compare current and successor value.
    compare_value((void*) &r, (void*) &c, (void*) &s, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, p1);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Swap values.
//??        swap((void*) &c, (void*) &s, p1);

        // Set swapped flag.
        copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* COMPARE_BUBBLE_SORTER_SOURCE */
#endif
