/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

//
// Forward declaration
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

/**
 * Loops the programme flow from the given start to the given end in the given steps.
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
void apply_loop_for(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop for.");

    //
    // Declaration
    //

    // The start part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The end part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The step part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The start part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The end part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The step part model item.
    void* stm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The start part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The end part model item data.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The step part model item data.
    void* stmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

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

    // Get start part.
    get_part_name((void*) &s, p0, (void*) START_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) START_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get end part.
    get_part_name((void*) &e, p0, (void*) END_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) END_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get step part.
    get_part_name((void*) &st, p0, (void*) STEP_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) STEP_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get index part.
    get_part_name((void*) &i, p0, (void*) INDEX_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) INDEX_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get model part.
    get_name_array((void*) &m, p0, (void*) MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Get start part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get end part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get step part model item.
    copy_array_forward((void*) &stm, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get start part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get end part model item data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get step part model item data.
    copy_array_forward((void*) &stmd, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get index part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The downward comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The step operator.
    int o = *GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT;
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

    if (smd == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop for. The start model data is null.");
        fwprintf(stdout, L"Warning: Could not apply loop for. The start model data is null. smd: %i\n", smd);

        //
        // CAUTION! If the parametre is NULL, then the break flag
        // will NEVER be set to true, because the loop variable comparison
        // does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    if (emd == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop for. The end model data is null.");
        fwprintf(stdout, L"Warning: Could not apply loop for. The end model data is null. emd: %i\n", emd);

        //
        // CAUTION! If the parametre is NULL, then the break flag
        // will NEVER be set to true, because the loop variable comparison
        // does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    if (stmd == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop for. The step model data is null.");
        fwprintf(stdout, L"Warning: Could not apply loop for. The step model data is null. stmd: %i\n", stmd);

        //
        // CAUTION! If the parametre is NULL, then the break flag
        // will NEVER be set to true, because the loop variable comparison
        // does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    if (imd == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop for. The index model data is null.");
        fwprintf(stdout, L"Warning: Could not apply loop for. The index model data is null. imd: %i\n", imd);

        //
        // CAUTION! If the parametre is NULL, then the break flag
        // will NEVER be set to true, because the loop variable comparison
        // does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    // Compare for negative step width.
    compare_integer_less((void*) &r, stmd, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The loop is running downward with negative step width.
        //

        // Use less-or-equal comparison operator instead of greater-or-equal.
        copy_integer((void*) &o, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);
    }

    // Initialise index with start model.
    copy_integer(imd, smd);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer((void*) &b, imd, emd, (void*) &o);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The break flag is TRUE.
            //

            // Leave the loop.
            break;

        } else {

            //
            // The break flag is FALSE.
            //

            //?? fwprintf(stdout, L"Debug: Apply loop for. before handle b: %i\n", b);

            // Handle the model as new operation.
            handle(m, p4, p2, p3, p5, p6, (void*) &x, p7, *NULL_POINTER_STATE_CYBOI_MODEL);

            //?? fwprintf(stdout, L"Debug: Apply loop for. after handle b: %i\n", b);
        }

        // Increment index.
        calculate_integer_add(imd, stmd);
    }
}
