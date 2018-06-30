/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INSERT_MODIFIER_SOURCE
#define INSERT_MODIFIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/comparator/integer/less_integer_comparator.c"
#include "../../executor/modifier/inside_insert_modifier.c"
#include "../../executor/modifier/overwrite_modifier.c"
#include "../../logger/logger.c"

/**
 * Inserts the source- into the destination array,
 * starting from the given index.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 * @param p7 the destination array count
 * @param p8 the destination array size
 */
void modify_insert(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify insert.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &r, p5, p7);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Inserting elements outside the current array
            // boundaries is equivalent to just overwriting
            // elements, since none have to be moved.
            //
            // CAUTION! Don't forget to set the "adjust count" flag!
            modify_overwrite(p0, p1, p2, p3, p4, p5, p6, p7, p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &r, p5, p7);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_insert_inside(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }
}

/* INSERT_MODIFIER_SOURCE */
#endif
