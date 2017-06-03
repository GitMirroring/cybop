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

#ifndef BUBBLE_SORTER_SOURCE
#define BUBBLE_SORTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/basic/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/sorter/bubble/bubble_bubble_sorter.c"
#include "../../../logger/logger.c"

/*
 * Sorts the given data array using the bubble algorithm.
 *
 * @param p0 the array data
 * @param p1 the type
 * @param p2 the array count
 */
void sort_bubble(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble.");

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The swapped flag.
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The bubble loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Reset swapped flag.
        s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // Reset bubble loop count.
        c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Calculate bubble loop count.
        //
        // CAUTION! This is an optimisation.
        // Reduce the data array count by the current index!
        // This causes the loop to sort only that part of
        // the array that has not been sorted yet.
        //
        copy_integer((void*) &c, p2);
        calculate_integer_subtract((void*) &c, (void*) &j);

        // Bubble up the greater value.
        sort_bubble_bubble(p0, p1, (void*) &s, (void*) &c);

        // CAUTION! This is an optimisation.
        // Break loop if nothing is left to be sorted.
        // If the swapped flag remained unchanged,
        // then nothing was changed inside the array.
        if (s == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Increment loop variable.
        j++;
    }
}

/* BUBBLE_SORTER_SOURCE */
#endif
