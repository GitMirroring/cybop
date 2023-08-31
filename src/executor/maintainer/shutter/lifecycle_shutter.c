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
 * @version CYBOP 0.27.0 2023-08-31
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

#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "server.h"

/**
 * Executes the service shutdown lifecycle.
 *
 * @param p0 the internal memory data
 * @param p1 the port (service identification)
 * @param p2 the channel
 * @param p3 the server entry (pointer reference)
 * @param p4 the server list item
 * @param p5 the server list index
 */
void shutdown_lifecycle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** se = (void**) p3;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown lifecycle.");
        //?? fwprintf(stdout, L"Information: Shutdown lifecycle. p1: %i\n", p1);
        //?? fwprintf(stdout, L"Information: Shutdown lifecycle. *p1: %i\n", *((int*) p1));

        //
        // Disabling
        //

        //
        // Disable service by exiting enable (accept) thread.
        //
        // CAUTION! This has to be done BEFORE deallocating resources below.
        //
        // Display:
        //
        // The enable thread writes received events into the client input buffer.
        // These EVENTS got allocated inside the x window system and
        // have to be DEALLOCATED (freed) yet.
        //
        // Therefore, the enable thread has to be exited FIRST and only
        // then the main thread can loop the request input buffer and
        // deallocate ALL events before deallocating the buffer itself.
        //
        // Socket:
        //
        // The clients having already been accepted by the server socket
        // are stored in the request buffer. They have to be CLOSED yet.
        //
        // Terminal:
        //
        // The main thread resets the terminal properties on shutdown, so that
        // default echoing and canonical input (with <enter> key) are reactivated.
        // But then, the call of function "ioctl" might not work promptly,
        // if the terminal is waiting for the <enter> key.
        //
        // Therefore, the sensing thread has to be exited FIRST
        // as long as ioctl fake input can be received prompt.
        //
        disable(p0, p1, p2);

        //
        // Removal
        //

        //
        // CAUTION! Locking a mutex is NOT necessary here,
        // since only the main thread accesses the server list.
        //

        // Remove server entry from server list item.
        modify_item(p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p5, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // Shuttingdown
        //

        // The client list item.
        void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get client list item from server entry.
        copy_array_forward((void*) &cl, *se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_CLIENTS_SERVER_STATE_CYBOI_NAME);

        // Shutdown clients.
        shutdown_list(cl, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME, p2, p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Shutdown service.
        shutdown_service(*se, p2);

        //
        // Deallocation
        //

        // Deallocate server entry.
        deallocate_server_entry(p3);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown lifecycle. The server entry is null.");
        fwprintf(stdout, L"Error: Could not shutdown lifecycle. The server entry is null. p3: %i\n", p3);
    }
}
