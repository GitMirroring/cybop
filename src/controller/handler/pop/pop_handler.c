/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef POP_HANDLER_SOURCE
#define POP_HANDLER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../controller/handler/pop/part_pop_handler.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Pops (removes) parts from stack memory.
 *
 * @param p0 the stack memory item
 * @param p1 the parts count
 */
void handle_pop(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle pop.");

    //
    // Declaration
    //

    // The stack memory item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The stop index.
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Initialisation
    //

    // Get stack memory item data, count.
    copy_array_forward((void*) &smd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Initialise loop variable with stack memory count.
    copy_integer((void*) &j, smc);
    // Subtract one from loop variable, since this is an INDEX.
    calculate_integer_subtract((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Initialise stop index with loop variable.
    copy_integer((void*) &s, (void*) &j);
    // Subtract parts count from stop index.
    calculate_integer_subtract((void*) &s, p1);

    //
    // Iteration
    //

    if (p1 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    //
    // CAUTION! This loop is running BACKWARDS for more efficiency.
    // It is much faster to remove an element from the end of an array,
    // since when removing from somewhere in between, all following
    // elements have to be moved one position forward.
    //

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &b, (void*) &j, (void*) &s);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Pop (remove) part from stack memory.
        handle_pop_part(p0, smd, (void*) &j);

        // Decrement loop variable.
        j--;
    }
}

/* POP_HANDLER_SOURCE */
#endif
