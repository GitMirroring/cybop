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

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/handler/element_part_handler.c"
#include "../../controller/handler/initialisation_handler.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/modifier/item_modifier.c"
#include "../../logger/logger.c"

/**
 * Handles the part signal.
 *
 * @param p0 the signal model data (operation)
 * @param p1 the signal model count
 * @param p2 the signal properties data (local stack variables)
 * @param p3 the signal properties count
 * @param p4 the initial value properties data
 * @param p5 the initial value properties count
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

    // The signal properties count old value.
    int pc_old = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The stack memory item count.
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The stack memory item count old value.
    int mc_old = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Copy signal properties count.
    //
    // It is later to be used as count for variable value removal.
    // Within the "handle" function called below, it may happen
    // that the properties and their count get changed.
    // Therefore, the OLD value is saved here.
    //
    copy_integer((void*) &pc_old, p3);
    // Determine stack memory item count.
    copy_array_forward((void*) &mc, p8, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    //
    // Copy stack memory item count.
    //
    // It is later to be used as index for variable value removal.
    // Therefore, the OLD value is saved here.
    //
    copy_integer((void*) &mc_old, mc);

    //
    // Store variable values on stack memory (PUSH).
    //
    // CAUTION! Set the deep copying flag to FALSE here, so that pointer
    // references of the given properties get copied as SHALLOW copy.
    // The deep copying flag is relevant for format "element/part" only.
    // It is important to avoid allocating duplicates of the children
    // of the given properties on stack for at least two reasons:
    //
    // 1 Efficiency would suffer when deep-copying large tree branches
    // 2 Reference counting of rubbish (garbage) collection (gc) might get mixed up
    //
    modify_item(p8, p2, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Assign initial values.
    //
    //?? TODO: Hand over: (void*) &pc_old -- so that not the whole stack
    // but only the relevant variables are searched through.
    //
    //?? TODO: Search in BACKWARD order inside!
    //
    //?? handle_initialisation(p8, p4, p5, p7, p10);

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

        handle_part_element(p0, (void*) &j, p6, p7, p8, p9, p10, p11, p12);

        // Increment loop variable.
        j++;
    }

    //
    // Remove variable values from stack memory (POP).
    //
    // Solution 1: Read properties again
    //
    // CAUTION! The properties might have been changed within
    // the logic executed within the "handle" function above.
    // Therefore, they should NOT be accessed a second time here,
    // in order to remove temporary values from stack memory,
    // since the number and type of properties might have changed,
    // which would otherwise lead to SEVERE MEMORY ERRORS.
    //
    // Solution 2: Add empty marker element to stack
    //
    // - INEFFICIENT since added for each function call
    // - added even for logic not using temporary values on stack
    // - consumes additional time and memory
    //
    // Solution 3: Remember number of values added
    //
    // - seems to be the easiest solution
    // - the exact same number of values that was added to stack
    //   (signal properties count) is removed from it again here
    // - the former (mc_old) stack memory item count is used as index for removal
    //
    // Therefore, solution 3 is applied here.
    //
    // CAUTION! Set the adjust flag to TRUE since otherwise,
    // the destination item will hold a wrong "count" number
    // leading to unpredictable errors in further processing.
    //
    //?? fwprintf(stdout, L"Debug: Handle part. mc_old pre: %i\n", mc_old);
    modify_item(p8, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &pc_old, (void*) &mc_old, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);
    //?? fwprintf(stdout, L"Debug: Handle part. mc_old post: %i\n", mc_old);
}

/* PART_HANDLER_SOURCE */
#endif
