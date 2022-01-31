/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
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
#include "../../executor/modifier/item_modifier.c"
#include "../../executor/streamer/reader/interrupt_pipe/interrupt_pipe_reader.c"
#include "../../logger/logger.c"

/**
 * Handles the situation that no signal is available in the signal memory
 * and queries interrupt requests instead.
 *
 * @param p0 the internal memory data
 * @param p1 the signal memory item
 * @param p2 the signal memory sleep time
 * @param p3 the interrupt request pipe
 */
void check_empty(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check empty.");
    //?? fwprintf(stdout, L"Debug: Check empty. irq: %i\n", irq);

    // The read interrupt request pipe file descriptor.
    int rd = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The server identification (server base + service port).
    int sid = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The client identification.
    int cid = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The handler (signal part representing the interrupt request handler).
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The handler properties item.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The handler properties item data, count.
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pc= *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client property.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get read interrupt request pipe file descriptor.
    copy_array_forward((void*) &rd, p3, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Debug: Check empty. rd: %i\n", rd);

    // Read from interrupt pipe.
    read_interrupt_pipe((void*) &sid, (void*) &cid, (void*) &rd, *NULL_POINTER_STATE_CYBOI_MODEL);

    if (sid >= *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

        // Get server entry from internal memory.
        copy_array_forward((void*) &se, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &sid);

        if (se != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // A server entry exists for the service.
            //

            // Get client entry from server entry client list by identification.
            find_server_entry((void*) &ce, se, (void*) &cid, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            // Get handler part from client entry.
            copy_array_forward((void*) &h, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLER_GENERAL_CLIENT_STATE_CYBOI_NAME);
            // Get handler properties item from handler part.
            copy_array_forward((void*) &p, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
            // Get handler properties item data, count.
            copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            // Get client identification from handler properties.
            get_part_name((void*) &c, pd, (void*) CLIENT_HANDLER_STATE_CYBOL_NAME, (void*) CLIENT_HANDLER_STATE_CYBOL_NAME_COUNT, pc, knowledge memory part (pointer reference), stack memory item, internal memory data);
            //
            // Copy client identification.
            //
            // CAUTION! This is IMPORTANT, since the cybol application relies
            // on it when sending its response to the requesting client.
            //
            copy_integer(c, (void*) &cid);

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
            modify_item(p1, (void*) &h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check empty. The server entry is null.");
            fwprintf(stdout, L"Error: Could not check empty. The server entry is null. id: %i\n", e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check empty. The server identification is invalid.");
        fwprintf(stdout, L"Error: Could not check empty. The server identification is invalid. id: %i\n", s);
    }
}

/* EMPTY_CHECKER_SOURCE */
#endif
