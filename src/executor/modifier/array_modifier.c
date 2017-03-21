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

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../executor/modifier/empty_modifier.c"
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
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 * @param p6 the destination array count
 * @param p7 the destination array size
 * @param p8 the adjust count flag
 * @param p9 the model flag
 * @param p10 the properties flag
 * @param p11 the operation type
 */
void modify_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify array.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Use destination array count p6 TWICE,
            // as destination index (fifth parametre, INSTEAD of p4)
            // and as destination array count.
            // CAUTION! Set adjust count flag, since destination gets extended by append.
            modify_overwrite(p0, p1, p2, p3, p6, p5, p6, p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) EMPTY_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_empty(p0, p2, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) FILL_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_fill(p0, p1, p2, p3, p4, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_insert(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_overwrite(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_remove(p0, p2, p3, p4, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not modify array. The operation type is unknown.");
    }
}

/* ARRAY_MODIFIER_SOURCE */
#endif
