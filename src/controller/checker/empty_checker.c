/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef EMPTY_CHECKER_SOURCE
#define EMPTY_CHECKER_SOURCE

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/checker/irq/irq_checker.c"
#include "../../controller/checker/wait_checker.c"
#include "../../executor/modifier/item_modifier.c"
#include "../../logger/logger.c"

/**
 * Handles the situation that no signal is available in the signal memory
 * and queries interrupts instead.
 *
 * @param p0 the internal memory data
 * @param p1 the signal memory item
 * @param p2 the signal memory sleep time
 */
void check_empty(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check empty.");

    // The interrupt.
    int irq = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The signal part representing the interrupt request handler.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    //?? fwprintf(stdout, L"TEST check empty irq: %i\n", irq);

    //
    // The signal memory is empty, so that the cyboi system
    // may check for new interrupt requests now.
    //
    // CAUTION! This code section also covers the situation
    // when a new signal has been placed in signal memory
    // just after it was checked to be empty.
    // In such a case, the signal memory flag was set
    // so that the new signal may be recognised here
    // and does not get forgotten.
    //

    // Check channels for interrupt requests.
    check_irq((void*) &irq, (void*) &s, p0);

    if (irq != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"TEST check empty found irq: %i\n", irq);
        //?? fwprintf(stdout, L"TEST check empty found s: %i\n", s);

        //
        // Add part model (signal) to signal memory.
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
        modify_item(p1, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // CAUTION! An interrupt request was detected and the corresponding data received.
        // It is therefore VERY likely that new signals have been generated while handling the data.
        // The cyboi system is therefore NOT sent to sleep, so that possibly existing
        // signals may be handled in the next iteration of the signal checker loop.
        //

    } else {

        //
        // No interrupt request was detected.
        //

        check_wait(p0, p2);
    }
}

/* EMPTY_CHECKER_SOURCE */
#endif
