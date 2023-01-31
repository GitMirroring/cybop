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

#ifndef LOOP_SOURCE
#define LOOP_SOURCE

#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/flow/loop_flow_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../logger/logger.c"

//
// Forward declarations
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

/**
 * Loops the programme flow endlessly, until the break flag is set.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the signal memory item
 * @param p6 the internal memory data (pointer reference)
 * @param p7 the shutdown flag
 */
void apply_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop.");

    //
    // Declaration
    //

    // The model part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The break part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The break part model item.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The break part model item data.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get model part.
    get_part_name((void*) &m, p0, (void*) MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get break part.
    get_part_name((void*) &b, p0, (void*) BREAK_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) BREAK_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get break part model item.
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get break part model item data.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // The break flag.
    int br = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The direct execution flag.
    //
    // CAUTION! The flag has to be set to true, because otherwise,
    // each loop cycle places a new signal in signal memory so that
    // these would only be processed with a delay.
    // But this is not desirable, since follow-up signals of this
    // loop may rely on its full execution, including all cycles.
    //
    int x = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    if (bmd == *NULL_POINTER_STATE_CYBOI_MODEL) {

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
        copy_integer((void*) &br, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Check if break flag is set to true.
        compare_integer_unequal((void*) &br, bmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (br != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The break flag is TRUE.
            //

            // Leave the loop.
            break;

        } else {

            //
            // The break flag is FALSE (not set).
            //

            // Handle the model as new operation.
            handle(m, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p4, p2, p3, p5, p6, (void*) &x, p7);
        }
    }
}

/* LOOP_SOURCE */
#endif
