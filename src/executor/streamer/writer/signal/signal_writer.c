/*
 * Copyright (C) 1999-2020. Christian Heller.
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

#ifndef SIGNAL_WRITER_SOURCE
#define SIGNAL_WRITER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Writes a message as signal to the cyboi system (this system itself).
 *
 * @param p0 the source part (pointer reference)
 * @param p1 the client entry
 */
void write_signal(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write signal.");
    fwprintf(stdout, L"Debug: Write signal. p0: %i\n", p0);

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The internal memory.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory part.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory part model item.
    void* smm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from client entry.
    copy_array_forward((void*) &se, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME);
    // Get internal memory from server entry.
    copy_array_forward((void*) &im, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERNAL_MEMORY_BACKLINK_SERVER_STATE_CYBOI_NAME);
    // Get signal memory part from internal memory.
    copy_array_forward((void*) &sm, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get signal memory part model item.
    copy_array_forward((void*) &smm, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    //
    // Add signal part to signal memory.
    //
    // CAUTION! Do NOT add to the signal memory PART,
    // but to the signal memory part model ITEM instead,
    // which was determined above.
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
    modify_item(smm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}

/* SIGNAL_WRITER_SOURCE */
#endif
