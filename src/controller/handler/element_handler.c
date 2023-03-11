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

#ifndef ELEMENT_HANDLER_SOURCE
#define ELEMENT_HANDLER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../executor/copier/array/forward_array_copier.c"
#include "../../executor/streamer/writer/signal/signal_writer.c"
#include "logger.h"

//
// Forward declarations
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

/**
 * Handles the part signal element.
 *
 * @param p0 the signal model data (operation)
 * @param p1 the signal model index
 * @param p2 the internal memory data
 * @param p3 the knowledge memory part (pointer reference)
 * @param p4 the stack memory item
 * @param p5 the signal memory item
 * @param p6 the internal memory data (pointer reference)
 * @param p7 the direct execution flag
 * @param p8 the shutdown flag
 */
void handle_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle element.");

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

    // The signal part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get signal part with given index.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1);
    // Evaluate direct execution flag.
    compare_integer_unequal((void*) &r, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The signal is to be executed DIRECTLY,
        // i.e. by calling the corresponding function.
        //

        handle(s, p2, p3, p4, p5, p6, p7, p8, *NULL_POINTER_STATE_CYBOI_MODEL);

    } else {

        //
        // The signal is to be executed INDIRECTLY,
        // i.e. by adding it to the signal memory,
        // where it later gets checked and handled.
        // This may be useful for REAL TIME SYSTEMS,
        // where a fast system response time is guaranteed.
        //
        // Example:
        // When a big algorithm takes very long to be processed,
        // then it is better to let its parts be executed
        // as separate signals. That way, other signals
        // waiting in the signal memory have the chance
        // to be processed in between, in order to fulfil
        // the response time requirement.
        //

        write_signal(p2, (void*) &s);
    }
}

/* ELEMENT_HANDLER_SOURCE */
#endif
