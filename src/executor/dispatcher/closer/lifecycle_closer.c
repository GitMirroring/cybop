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
 * @version CYBOP 0.26.0 2023-04-04
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

#include "client.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Executes the client close lifecycle.
 *
 * @param p0 the client identification (e.g. file descriptor, socket number, window id)
 * @param p1 the client entry (pointer reference)
 * @param p2 the channel
 * @param p3 the client list item
 * @param p4 the client list index
 */
void close_lifecycle(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** ce = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close lifecycle.");
        //?? fwprintf(stdout, L"Debug: Close lifecycle. p0: %i\n", p0);
        //?? fwprintf(stdout, L"Debug: Close lifecycle. *p0: %i\n", *((int*) p0));

        //
        // Suspension
        //

        //
        // Suspend data input detection and exit sensing thread.
        //
        // CAUTION! This has to be done BEFORE deallocating resources below.
        //
        suspend_thread(*ce);

        //
        // Removal
        //

        // Remove client entry from client list.
        modify_item(p3, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // Finalisation
        //

        // Finalise device.
        finalise(p0, *ce, p2);

        //
        // Closing
        //

        //
        // Close client device.
        //
        // CAUTION! Contrary to the opening, client socket stubs
        // do NOT need a special treatment here. Their file descriptor
        // gets closed in the same way as for the other channels.
        //
        close_device(p0, *ce, p2);

        //
        // Deallocation
        //

        // Deallocate client entry.
        deallocate_client_entry(p1, p2);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close lifecycle. The client entry is null.");
        fwprintf(stdout, L"Error: Could not close lifecycle. The client entry is null. p1: %i\n", p1);
    }
}
