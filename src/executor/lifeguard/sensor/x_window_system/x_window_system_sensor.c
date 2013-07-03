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

#ifndef X_WINDOW_SYSTEM_SENSOR_SOURCE
#define X_WINDOW_SYSTEM_SENSOR_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"

/**
 * Senses x window system messages.
 *
 * @param p0 the display interrupt request
 * @param p1 the checking loop break flag
 * @param p2 the internal memory data
 */
void sense_x_window_system(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense x window system.");

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get connexion.
    copy_array_forward((void*) &c, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Get next event available from the server.
        // If none is available, NULL gets returned.
        //
        // CAUTION! The event gets REMOVED from the queue
        // by the "xcb_poll_for_event" function.
        // It therefore HAS TO BE STORED temporarily
        // in internal memory, in order to be able to
        // process it later on in "executor/receiver/".
        //
        // The ideal solution would be a blocking xcb function
        // running in an own sensing thread in files
        // "x_window_system_sensor.c" and "message_x_window_system_sensor.c".
        //
        // The xcb developers have been asked to add a function like
        // "xcb_test_for_event" that would return on availability
        // of an event WITHOUT ACTUALLY REMOVING the event from the queue.
        // However, the xcb developers did not like the idea for now.
        //
        // See mailing list discussion in xcb project:
        // http://stackoverflow.com/questions/15775281/need-for-xeventsqueueddisplay-queuedafterreading-in-xcb
        // http://lists.freedesktop.org/archives/xcb/2013-April/008219.html
        // http://lists.freedesktop.org/archives/xcb/2013-May/008245.html
        // http://lists.freedesktop.org/archives/xcb/2013-May/008249.html
        // http://xcb.freedesktop.org/
        //
        // Therefore, this workaround here in the main thread is necessary.
        void* e = (void*) xcb_poll_for_event((xcb_connection_t*) c);

        if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Store event in internal memory.
            copy_array_forward(p2, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EVENT_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // CAUTION! Setting a mutex is NOT necessary here,
            // since this is the main thread and no other threads
            // are writing to the interrupt request variable.

            // Set display interrupt request to indicate
            // that a message has been received via display,
            // which may now be processed in the main thread of this system.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set break flag.
            copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system. The connexion is null.");
    }
}

/* X_WINDOW_SYSTEM_SENSOR_SOURCE */
#endif
