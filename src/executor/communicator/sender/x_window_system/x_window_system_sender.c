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

#ifndef X_WINDOW_SYSTEM_SENDER_SOURCE
#define X_WINDOW_SYSTEM_SENDER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../logger/logger.c"

/**
 * Updates the x window system window.
 *
 * @param p0 the internal memory data
 */
void send_x_window_system(void* p0) {

    // The mutex.
//??    void* mt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get mutex.
//??    copy_array_forward((void*) &mt, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get connexion.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get window.
    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

//?? fwprintf(stdout, L"TEST send x window system window c: %i\n", c);
//?? fwprintf(stdout, L"TEST send x window system window w: %i\n", w);

    // CAUTION! This test is necessary to avoid a "Segmentation fault"!
    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! This test is necessary to avoid a "Segmentation fault"!
        if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send x window system.");

            // Lock x window system mutex.
//??            pthread_mutex_lock((pthread_mutex_t*) mt);

/*??
            // Request input events (signals) to be put into event queue.
            XSelectInput((struct _XDisplay*) d, *((int*) w), ExposureMask
                | KeyPressMask | KeyReleaseMask
                | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | ButtonMotionMask
                | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask
                | EnterWindowMask | LeaveWindowMask);
*/

            // Use xcb type.
            xcb_window_t window = *((int*) w);

            // Map window on the screen, in order to make it visible.
            xcb_map_window((xcb_connection_t*) c, window);

            // Make sure all pending requests to the x server are sent.
            // This is similar to "fflush" used for standard terminal output.
            xcb_flush((xcb_connection_t*) c);

            //?? TEST: Hold client until <ctrl>+<c> is pressed,
            //?? so that the window does not disappear too fast.
//??            pause();

            // Unlock x window system mutex.
//??            pthread_mutex_unlock((pthread_mutex_t*) mt);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send x window system. The window is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send x window system. The connexion is null.");
    }
}

/* X_WINDOW_SYSTEM_SENDER_SOURCE */
#endif
