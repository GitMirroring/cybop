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

#ifndef REQUEST_ENABLER_SOURCE
#define REQUEST_ENABLER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "server.h"
#include "system.h"

/**
 * Send request client identification to interrupt pipe.
 *
 * @param p0 the destination request input buffer item
 * @param p1 the destination request input buffer mutex
 * @param p2 the server entry
 * @param p3 the channel
 * @param p4 the interrupt pipe write file descriptor
 * @param p5 the handler (pointer reference)
 * @param p6 the interrupt mutex
 */
void enable_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable request.");
    //?? fwprintf(stdout, L"Debug: Enable request. p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Enable request. *p3: %i\n", *((int*) p3));

    // The sender client identification (socket number).
    int id = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Receive next request.
    enable_client((void*) &id, p2, p3);

    if (id >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // Lock mutex.
        lock(p1);

        //
        // Append sender client identification to request input buffer.
        //
        // CAUTION! Do NOT use overwrite but rather APPEND, in order to
        // avoid deletion of previous client requests still existing in buffer.
        //
        modify_item(p0, (void*) &id, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Unlock mutex.
        unlock(p1);

        // Inform interrupt pipe of main threaad.
        write_interrupt_pipe(p4, p5, (void*) &id, p6);

        //
        // CAUTION! The client entry does NOT have to be opened (and allocated) here.
        //
        // Display:
        //
        // The cybol operation "dispatch/open" has to be called MANUALLY for each
        // window, and the corresponding client entry gets allocated within it.
        // The cybol operation "activate/enable" just distributes events
        // to the input buffer of the targeted window.
        // If the event loop of the main threaad does not find a handler
        // in the interrupt pipe, then NOTHING gets executed.
        // Thus, a callback handler does NOT necessarily have to be
        // given as property of the cybol operation "activate/enable".
        //
        // Socket:
        //
        // A callback handler HAS TO BE given as property of the cybol
        // operation "activate/enable". It calls the cybol operation
        // "dispatch/open", so that a client entry gets allocated.
        //

    } else {

        //
        // CAUTION! This warning message is relevant only for SOCKET channel.
        // The display channel does NOT return the destination sender
        // client identification ON PURPOSE.
        //
        // The window clients have to get created MANUALLY in
        // the corresponding cybol application, so that returning
        // a window identification does NOT make sense here.
        //
        // Furthermore, this calling function "enable_request" stores the
        // returned client identifications in a request input buffer item,
        // and also informs the interrupt pipe via handler,
        // which is NOT wanted and would only cause errors,
        // since the window clients have already got created MANUALLY.
        //

        //?? log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable request. The sender client identification is invalid. Only relevant for socket channel. NO problem for display channel, since the window was opened and id assigned MANUALLY in cybol.");
        //?? fwprintf(stdout, L"Warning: Could not enable request. The sender client identification is invalid. Only relevant for socket channel. NO problem for display channel, since the window was opened and id assigned MANUALLY in cybol. id: %i\n", id);
    }
}

/* REQUEST_ENABLER_SOURCE */
#endif
