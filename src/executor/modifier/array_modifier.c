/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_MODIFIER_SOURCE
#define ARRAY_MODIFIER_SOURCE

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../executor/modifier/fill_modifier.c"
#include "../../executor/modifier/insert_modifier.c"
#include "../../executor/modifier/overwrite_modifier.c"
#include "../../executor/modifier/remove_modifier.c"
#include "../../logger/logger.c"

/**
 * Modifies the destination array using the given operation.
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
 * @param p9 the adjust count flag
 * @param p10 the operation type
 */
void modify_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append source to destination.
            //
            // CAUTION! Hand over the destination array count TWICE,
            // as destination index (sixth parametre, INSTEAD of p5)
            // AND as destination array count (eighth parametre)
            //
            // CAUTION! Set adjust count flag to TRUE,
            // since destination gets extended by append.
            modify_overwrite(p0, p1, p2, p3, p4, p7, p6, p7, p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) EMPTY_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Remove all elements from array.
            //
            // CAUTION! Hand over the destination array count TWICE,
            // as count of elements to be removed (third parametre, INSTEAD of p4)
            // AND as destination array count (fifth parametre).
            modify_remove(p0, p2, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) FILL_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_fill(p0, p1, p2, p3, p4, p5, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_insert(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_overwrite(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_remove(p0, p2, p4, p5, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not modify array. The operation type is unknown.");
    }
}

/* ARRAY_MODIFIER_SOURCE */
#endif
