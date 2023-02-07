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

#ifndef PART_HANDLER_SOURCE
#define PART_HANDLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/handler/pop/pop_handler.c"
#include "../../controller/handler/push/push_handler.c"
#include "../../controller/handler/element_handler.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Handles the part signal.
 *
 * @param p0 the signal model data (operation)
 * @param p1 the signal model count
 * @param p2 the signal properties representing local variable data
 * @param p3 the signal properties representing local variable count
 * @param p4 the cybol-path properties representing runtime argument data
 * @param p5 the cybol-path properties representing runtime argument count
 * @param p6 the internal memory data
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the signal memory item
 * @param p10 the internal memory data (pointer reference)
 * @param p11 the direct execution flag
 * @param p12 the shutdown flag
 */
void handle_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle part.");
    fwprintf(stdout, L"Debug: Handle part. p12: %i\n", p12);

    //
    // Declaration
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Pushing
    //

    // Push (add) local variable parts onto stack memory.
    handle_push(p8, p2, p3, p7, p9);

    // Push (add) runtime argument parts onto stack memory.
    //?? handle_push(p8, p4, p5, p7, p9);

    //
    // Execution
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
    // CAUTION! If the signal is to be executed INDIRECTLY,
    // i.e. by adding it to the signal memory,
    // where it later gets checked and handled,
    // then do NOT store any properties in stack memory!
    //
    // There is no guarantee as to when the signal gets
    // actually processed from the signal memory (queue).
    // External interrupts such as from a socket communication
    // or mouse events might occur and be processed first.
    // In this case, the order of stack memory entries
    // would get MIXED UP.
    // Therefore, the stack memory may ONLY be used with
    // DIRECT handling of signals as done in the "if" branch above.
    //

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p1);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        handle_element(p0, (void*) &j, p6, p7, p8, p9, p10, p11, p12);

        // Increment loop variable.
        j++;
    }

    //
    // Popping
    //

    //
    // CAUTION! Use REVERSE order as compared to push,
    // which means pop runtime argument parts at FIRST
    // and local variable parts only after.
    //

    // Pop (remove) runtime argument parts from stack memory.
    //?? handle_pop(p8, p4, p5, p7, p9);

    // Pop (remove) local variable parts from stack memory.
    handle_pop(p8, p3);
}

/* PART_HANDLER_SOURCE */
#endif
