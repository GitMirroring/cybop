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

#ifndef FOUND_CHECKER_SOURCE
#define FOUND_CHECKER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../controller/handler/handler.c"
#include "../../executor/modifier/item_modifier.c"
#include "logger.h"

/**
 * Handles a found signal.
 *
 * @param p0 the signal part
 * @param p1 the internal memory data
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the signal memory item
 * @param p5 the signal memory index where the signal was found
 * @param p6 the internal memory data (pointer reference)
 * @param p7 the shutdown flag
 */
void check_found(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check found.");
    //?? fwprintf(stdout, L"Debug: Check found. signal p0: %i\n", p0);

    // The direct execution flag.
    int x = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Remove signal from signal memory.
    //
    // CAUTION! Use simple POINTER_STATE_CYBOI_TYPE and NOT PART_ELEMENT_STATE_CYBOI_TYPE here.
    // The signal memory just holds references to knowledge memory parts (signals),
    // but only the knowledge memory may care about rubbish (garbage) collection.
    //
    // Example:
    // Assume there are two signals in the signal memory.
    // The second references a logic part that is to be destroyed by the first.
    // If reference counting from rubbish (garbage) collection were used,
    // then the logic part serving as second signal could not be deallocated
    // as long as it is still referenced from the signal memory item.
    //
    // But probably, there is a reason the first signal wants to destroy the
    // second and consequently, the second should not be executed anymore.
    // After destruction, the second signal just points to null, which is ignored.
    // Hence, rubbish (garbage) collection would only disturb here
    // and should be left to the knowledge memory.
    //
    // CAUTION! Set the adjust count flag to TRUE since otherwise,
    // the destination item will hold a wrong "count" number
    // leading to unpredictable errors in further processing.
    //
    modify_item(p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p5, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

    // Handle signal.
    handle(p0, p1, p2, p3, p4, p6, (void*) &x, p7, *NULL_POINTER_STATE_CYBOI_MODEL);
}

/* FOUND_CHECKER_SOURCE */
#endif
