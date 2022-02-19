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

#ifndef REQUEST_ENABLER_SOURCE
#define REQUEST_ENABLER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../executor/activator/enabler/client_enabler.c"
#include "../../../executor/streamer/writer/interrupt_pipe/interrupt_pipe_writer.c"
#include "../../../logger/logger.c"

/**
 * Send request client identification to interrupt pipe.
 *
 * @param p0 the sender client identification (e.g. socket number, window id)
 * @param p1 the server entry
 * @param p2 the channel
 * @param p3 the destination interrupt pipe write file descriptor
 * @param p4 the destination interrupt handlers item
 * @param p5 the source handler (pointer reference)
 * @param p6 the interrupt mutex
 */
void enable_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable request.");
    fwprintf(stdout, L"Debug: Enable request. p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Enable request. *p2: %i\n", *((int*) p2));

    // Receive next request.
    enable_client(p0, p1, p2);

    // Inform interrupt pipe of main threaad.
    write_interrupt_pipe(p3, p4, p5, p6);

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
}

/* REQUEST_ENABLER_SOURCE */
#endif
