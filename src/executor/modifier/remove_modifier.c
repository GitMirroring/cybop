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

#ifndef REMOVE_MODIFIER_SOURCE
#define REMOVE_MODIFIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../executor/comparator/basic/integer/smaller_integer_comparator.c"
#include "../../executor/modifier/inside_remove_modifier.c"
#include "../../logger/logger.c"

/**
 * Removes the given number of elements from the array,
 * starting from the given index.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the type
 * @param p2 the count
 * @param p3 the destination index
 * @param p4 the destination array count
 * @param p5 the destination array size
 * @param p6 the adjust count flag
 */
void modify_remove(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify remove.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller((void*) &r, p4, p5);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            modify_remove_inside(p0, p1, p2, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not modify remove. The array is empty.");
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

/*??
        fwprintf(stdout, L"ERROR: Could not modify remove. The destination index is outside the array boundaries.\n");
        fwprintf(stdout, L"ERROR: Could not modify remove. The destination array count p4: %i\n", p4);
        fwprintf(stdout, L"ERROR: Could not modify remove. The destination array count *p4: %i\n", *((int*) p4));
        fwprintf(stdout, L"ERROR: Could not modify remove. The destination array size p5: %i\n", p5);
        fwprintf(stdout, L"ERROR: Could not modify remove. The destination array size *p5: %i\n", *((int*) p5));
*/

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not modify remove. The destination index is outside the array boundaries.");
    }
}

/* REMOVE_MODIFIER_SOURCE */
#endif
