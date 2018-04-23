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

#ifndef TYPE_BUBBLE_SORTER_SOURCE
#define TYPE_BUBBLE_SORTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/comparator.c"
#include "../../../executor/sorter/bubble/part_bubble_sorter.c"
#include "../../../logger/logger.c"

/*
 * Distinguishes operands between part and primitive type.
 *
 * @param p0 the result
 * @param p1 the left operand
 * @param p2 the right operand
 * @param p3 the operation type
 * @param p4 the string operation type
 * @param p5 the operand type
 * @param p6 the criterion data (pointer reference)
 * @param p7 the criterion count
 * @param p8 the criterion type
 */
void sort_bubble_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble type.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p5, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        sort_bubble_part(p0, p1, p2, p3, p4, p6, p7, p8);

    } else {

        //
        // Use standard comparison for all other cases.
        //

        compare(p0, p1, p2, p3, p5);
    }
}

/* TYPE_BUBBLE_SORTER_SOURCE */
#endif
