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

#ifndef BRANCH_SOURCE
#define BRANCH_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/accessor/name_getter/array_name_getter.c"
#include "../../executor/copier/array/forward_array_copier.c"
#include "logger.h"

//
// Forward declarations
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

/**
 * Branches the programme flow, depending on the criterion flag.
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
void apply_branch(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply branch.");

    //
    // Declaration
    //

    // The criterion part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The true part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The false part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The criterion part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The criterion part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;

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

    // Get criterion part.
    get_part_name((void*) &c, p0, (void*) CRITERION_BRANCH_FLOW_LOGIC_CYBOL_NAME, (void*) CRITERION_BRANCH_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get true part.
    get_name_array((void*) &t, p0, (void*) TRUE_BRANCH_FLOW_LOGIC_CYBOL_NAME, (void*) TRUE_BRANCH_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Get false part.
    get_name_array((void*) &f, p0, (void*) FALSE_BRANCH_FLOW_LOGIC_CYBOL_NAME, (void*) FALSE_BRANCH_FLOW_LOGIC_CYBOL_NAME_COUNT, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Get criterion part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get criterion part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    //
    // The direct execution flag.
    //
    // CAUTION! The flag has to be set to true, because otherwise,
    // a new signal would be placed in signal memory and only
    // be processed with a delay.
    //
    // But this is not desirable here, since the branch
    // is expected to be executed directly.
    // Further, follow-up signals may rely on its full execution.
    //
    int x = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, cmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The criterion is true. Handle true model.
        handle(t, p4, p2, p3, p5, p6, (void*) &x, p7, *NULL_POINTER_STATE_CYBOI_MODEL);

    } else {

        // The criterion is false. Handle false model.
        handle(f, p4, p2, p3, p5, p6, (void*) &x, p7, *NULL_POINTER_STATE_CYBOI_MODEL);
    }
}

/* BRANCH_SOURCE */
#endif
