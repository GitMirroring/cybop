/*
 * Copyright (C) 1999-2026. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version $RCSfile: cyboi_system_sending_communicator.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
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
#include "knowledge.h"
#include "logger.h"

/**
 * Reads a signal into the destination.
 *
 * @param p0 the destination signal item
 * @param p1 the source signal memory data
 * @param p2 the source signal memory count
 * @param p3 the eof-or-close flag
 */
void read_signal(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read signal.");
    //?? fwprintf(stdout, L"Debug: Read signal. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Read signal. *p2: %i\n\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater((void*) &r, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

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

        //
        // Append source signal memory part (signal or event) at
        // position index ZERO to destination signal item.
        //
        // CAUTION! The signal memory item's count is checked inside.
        // If it is smaller or equal to the given zero index,
        // then the signal part is NOT changed and remains NULL.
        //
        // CAUTION! Use simple POINTER_STATE_CYBOI_TYPE and NOT PART_ELEMENT_STATE_CYBOI_TYPE here.
        // The signal memory just holds references to knowledge memory parts (signals),
        // but only the knowledge memory may care about rubbish (garbage) collection (gc).
        //
        // CAUTION! Do NOT use overwrite but rather APPEND here, in order to
        // avoid deletion of already existing signals in the destination.
        //
        // Example:
        //
        // Assume there are two signals in the signal memory.
        // The second references a logic part that is to be destroyed by the first.
        // If reference counting from rubbish (garbage) collection were used,
        // then the logic part serving as second signal could not be deallocated
        // as long as it is still referenced from the signal memory item.
        //
        // But probably, there is a reason the first signal wants to destroy the
        // second and consequently, the second should not be executed anymore.
        // After destruction, the second signal just points to null, which is IGNORED.
        // Hence, rubbish (garbage) collection (gc) would only disturb here
        // and should be left to the knowledge memory.
        //
        modify_item(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Set eof-or-close flag.
        copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read signal. The signal memory is empty.");
        //?? fwprintf(stdout, L"Warning: Could not read signal. The signal memory is empty. p2: %i\n\n", p2);
        //?? fwprintf(stdout, L"Warning: Could not read signal. The signal memory is empty. *p2: %i\n\n", *((int*) p2));
    }
}
