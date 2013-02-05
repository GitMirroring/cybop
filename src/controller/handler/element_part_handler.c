/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_PART_HANDLER_SOURCE
#define ELEMENT_PART_HANDLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../executor/modifier/appender/item_appender.c"
#include "../../logger/logger.c"

//
// Forward declarations.
//

void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

/**
 * Handles the part signal element.
 *
 * @param p0 the signal model data (operation)
 * @param p1 the signal model index
 * @param p2 the signal properties data (parametres) [possibly necessary one day for pre- and post conditions etc.]
 * @param p3 the signal properties count
 * @param p4 the internal memory data
 * @param p5 the knowledge memory part
 * @param p6 the signal memory item
 * @param p7 the direct execution flag
 * @param p8 the shutdown flag
 */
void handle_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle part element.");

    // The signal part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get signal part with given index.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1);
    // Evaluate direct execution flag.
    compare_integer_unequal((void*) &r, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The signal is to be executed DIRECTLY,
        // i.e. by calling the corresponding function,
        // WITHOUT adding it to the signal memory.

        // Handle signal.
        handle(s, p4, p5, p6, p7, p8);

    } else {

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

        // Add signal part to signal memory.
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
        append_item_element(p6, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }
}

/* ELEMENT_PART_HANDLER_SOURCE */
#endif
