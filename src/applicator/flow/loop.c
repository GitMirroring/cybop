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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LOOP_SOURCE
#define LOOP_SOURCE

//
// Library interface
//

#include "constant.h"
#include "executor.h"
#include "logger.h"

//
// Forward declarations
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

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
    //?? fwprintf(stdout, L"Information: Apply loop. p7: %i\n", p7);

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

    //
    // CAUTION! There is a DIFFERENCE in how a part containing a cybol path as model is retrieved:
    //
    // 1 Leave cybol path as is
    //
    // - used in function "copy_array_forward" identifying a tree node by index
    // - used in function "get_name_array" identifying a tree node by name
    // - treats cybol path as pure string
    // - returns the properties of this cybol path part itself
    //
    // 2 Resolve cybol path
    //
    // - used in functions "get_part_name", "get_part_knowledge", "deserialise_knowledge" identifying a tree node by path
    // - resolves the cybol path diving deep into the tree hierarchy
    // - returns the properties of the tree node that the cybol path points to
    //
    // Therefore, different functions are used depending on the purpose:
    //
    // - copy_array_forward: get part as compound element to be handed over to "handle", done in "handle_element" and "read_signal"
    // - get_name_array: get part as model to be handed over to "handle", done in sequence/loop/branch
    // - get_part_name: retrieve the properties belonging to a cybol operation, done in most applicator functions
    //

    // Get model part.
    get_name_array((void*) &m, p0, (void*) MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
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

            //?? fwprintf(stdout, L"Debug: Apply loop. before handle br: %i\n", br);

            // Handle the model as new operation.
            handle(m, p4, p2, p3, p5, p6, (void*) &x, p7, bmd);

            //?? fwprintf(stdout, L"Debug: Apply loop. after handle br: %i\n", br);
        }
    }
}

/* LOOP_SOURCE */
#endif
