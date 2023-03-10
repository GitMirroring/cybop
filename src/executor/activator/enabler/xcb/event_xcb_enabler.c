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

#ifndef EVENT_XCB_ENABLER_SOURCE
#define EVENT_XCB_ENABLER_SOURCE

#include <xcb/xcb.h> // xcb_connection_t, xcb_wait_for_event

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../logger/logger.c"

/**
 * Gets next event from x window system via xcb.
 *
 * @param p0 the destination event (pointer reference)
 * @param p1 the source connexion
 */
void enable_xcb_event(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_connection_t* c = (xcb_connection_t*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** e = (void**) p0;

            // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable xcb event.");
            //?? fwprintf(stdout, L"Debug: Enable xcb event. c: %i\n", c);

            //
            // Get next event available from x window system server.
            //
            // CAUTION! This is a blocking call waiting until either
            // an event arrives or an input/output error occurs.
            //
            // CAUTION! Whenever an event is queued in the x server,
            // it gets dequeued from the queue here and is then returned
            // as a newly allocated structure. It is cyboi's responsibility
            // to FREE the returned event structure later.
            //
            // CAUTION! The event gets REMOVED from the queue by
            // the "xcb_wait_for_event" function. It therefore
            // HAS TO BE STORED, in order to be able to process it later on.
            //
            *e = (void*) xcb_wait_for_event(c);
            //?? fwprintf(stdout, L"Debug: Enable xcb event. received event *e: %i\n", *e);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb event. The destination event is null.");
            fwprintf(stdout, L"Error: Could not enable xcb event. The destination event is null. p0: %i\n", p0);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb event. The source connexion is null.");
        fwprintf(stdout, L"Error: Could not enable xcb event. The source connexion is null. p1: %i\n", p1);
    }
}

/* EVENT_XCB_ENABLER_SOURCE */
#endif
