/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EVENT_X_WINDOW_SYSTEM_RECEIVER_SOURCE
#define EVENT_X_WINDOW_SYSTEM_RECEIVER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/state/gui/event_gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/keyboard/keyboard_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/mouse/mouse_state_cybol_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Receives an x window system event.
 *
 * @param p0 the event (pointer reference)
 * @param p1 the connexion
 * @param p2 the mutex
 * @param p3 the loop break flag
 */
void receive_x_window_system_event(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        pthread_mutex_t* mt = (pthread_mutex_t*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            xcb_connection_t* c = (xcb_connection_t*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** e = (void**) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive x window system event.");

                pthread_mutex_lock(mt);

                // Get next event.
                //
                // A special thread with "sense" function was used to
                // detect events. But this is the main thread.
                // The event detected before shall be received here.
                //
                // There are two ways to receive events:
                // - blocking: xcb_wait_for_event
                // - non-blocking: xcb_poll_for_event
                //
                // The "xcb_wait_for_event" function blocks until an event
                // is queued in the x server, then dequeues it from the
                // queue, then returns it as a newly allocated structure.
                //
                // The "xcb_poll_for_event" function dequeues and returns
                // an event immediately. It returns NULL if no event is
                // available at the time of the call. If an error occurs,
                // the parameter error will be filled with the error status.
                //
                // Decision:
                //
                // Since this is the main thread, it MUST NOT block.
                // Therefore, the non-blocking "xcb_poll_for_event"
                // function is used here.
                //
                // CAUTION! Whenever an event is queued in the x server,
                // it gets dequeued from the queue here and is then
                // returned as a newly allocated structure.
                // It is cyboi's responsibility to FREE the
                // returned event structure.
                *e = (void*) xcb_poll_for_event(c);

                pthread_mutex_unlock(mt);

                if (*e == *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // No messages are available.

                    // Set loop break flag.
                    copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The event is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The connexion is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive x window system event. The mutex is null.");
    }
}

/* EVENT_X_WINDOW_SYSTEM_RECEIVER_SOURCE */
#endif
