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
 * Iterates through all of the elements in the given collection.
 * The single elements may be accessed by index from within the model (function) being executed.
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
void apply_loop_each(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop each.");

    //
    // Declaration
    //

    // The collection part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The collection part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The collection part model item count.
    void* cmc = *NULL_POINTER_STATE_CYBOI_MODEL;
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

    // Get collection part.
    get_part_name((void*) &c, p0, (void*) COLLECTION_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) COLLECTION_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get index part.
    get_part_name((void*) &i, p0, (void*) INDEX_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) INDEX_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get model part.
    get_name_array((void*) &m, p0, (void*) MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME, (void*) MODEL_LOOP_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Get collection part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get collection part model item count.
    copy_array_forward((void*) &cmc, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get index part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
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

    if (cmc == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop each. The collection model count is null.");
        fwprintf(stdout, L"Warning: Could not apply loop each. The collection model count is null. cmc: %i\n", cmc);

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

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply loop each. The index model data is null.");
        fwprintf(stdout, L"Warning: Could not apply loop each. The index model data is null. imd: %i\n", imd);

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

    //?? fwprintf(stdout, L"Debug: Apply loop each. cmc: %i\n", cmc);
    //?? fwprintf(stdout, L"Debug: Apply loop each. *cmc: %i\n", *((int*) cmc));

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, imd, cmc);

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

            //?? fwprintf(stdout, L"Debug: Apply loop each. before handle imd: %i\n", imd);
            //?? fwprintf(stdout, L"Debug: Apply loop each. before handle *imd: %i\n", ((int*) imd));

            // Handle the model as new operation.
            handle(m, p4, p2, p3, p5, p6, (void*) &x, p7, *NULL_POINTER_STATE_CYBOI_MODEL);

            //?? fwprintf(stdout, L"Debug: Apply loop each. after handle imd: %i\n", imd);
            //?? fwprintf(stdout, L"Debug: Apply loop each. after handle *imd: %i\n", ((int*) imd));
        }

        // Increment index.
        calculate_integer_add(imd, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}
