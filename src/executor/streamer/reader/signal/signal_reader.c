/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: cyboi_system_sending_communicator.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_READER_SOURCE
#define SIGNAL_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../logger/logger.c"

/**
 * Reads a signal into the destination.
 *
 * @param p0 the destination signal item
 * @param p1 the source signal memory item
 * @param p2 the source signal memory index
 */
void read_signal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read signal.");

    // The signal part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get signal part from position index zero.
    //
    // CAUTION! The signal memory item's count is checked inside
    // this function. If it is smaller or equal to the given index
    // (here: zero), then the signal value s is NOT changed,
    // i.e. it remains NULL if initialised so before.
    //
    get_item_metadata((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2, (void*) DATA_ITEM_STATE_CYBOI_NAME);

//?? fwprintf(stdout, L"TEST read signal s: %i\n\n", s);

    // Add signal part to destination item.
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
    modify_item(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}

/* SIGNAL_READER_SOURCE */
#endif
