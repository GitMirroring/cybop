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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BUBBLE_BUBBLE_SORTER_SOURCE
#define BUBBLE_BUBBLE_SORTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/sorter/bubble/swap_bubble_sorter.c"
#include "../../../logger/logger.c"

/*
 * Bubbles up the greater value, i.e. it gets moved to the right.
 *
 * @param p0 the data (pointer reference only if type is part or pointer)
 * @param p1 the type
 * @param p2 the swapped flag
 * @param p3 the left value (pointer reference only if type is part or pointer)
 * @param p4 the right value (pointer reference only if type is part or pointer)
 * @param p5 the loop count
 * @param p6 the criterion data (pointer reference)
 * @param p7 the criterion count
 * @param p8 the criterion type
 * @param p9 the knowledge memory part (pointer reference)
 * @param p10 the stack memory item
 * @param p11 the internal memory data
 * @param p12 the descending flag
 */
void sort_bubble_bubble(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble bubble.");

    // The loop variable as left index.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The right index.
    int j1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (p5 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p5);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Calculate successor index.
        //
        // CAUTION! The data array boundaries are NOT crossed and all is FINE here.
        // The reason is that p0 is the original pointer to the first data element
        // and the loop count p5 got already reduced by 1 (one) before calling this function.
        j1 = j + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        sort_bubble_swap(p0, p1, p2, p3, p4, (void*) &j, (void*) &j1, p6, p7, p8, p9, p10, p11, p12);

        // Increment loop variable.
        j++;
    }
}

/* BUBBLE_BUBBLE_SORTER_SOURCE */
#endif
