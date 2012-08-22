/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WINDOW_X_WINDOW_SYSTEM_SENDER_SOURCE
#define WINDOW_X_WINDOW_SYSTEM_SENDER_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <pthread.h>

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/graphical_user_interface_cybol_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../logger/logger.c"

/**
 * Sends the window to the x window system display.
 *
 * @param p0 the internal memory
 */
void send_x_window_system_window(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send x window system window.");

    //
    // CAUTION! The x window system uses a number of synonymous types:
    // Display* == struct _XDisplay*
    // GC == struct _XGC*
    // Window == int
    // Colormap == int
    // Font (ID) == int
    //
    // CYBOI works with the real types, i.e. those on the right-hand side.
    //

    // The mutex.
    void* mt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The display.
    // It is a subsumption of xserver, screens, hardware (input devices etc.).
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get mutex.
    copy_array_forward((void*) &mt, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get display.
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DISPLAY_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get window.
    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WINDOW_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // CAUTION! This test is necessary to avoid a "Segmentation fault"!
    if (d != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! This test is necessary to avoid a "Segmentation fault"!
        if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Lock x window system mutex.
            pthread_mutex_lock((pthread_mutex_t*) mt);

            // Request input events (signals) to be put into event queue.
            XSelectInput((struct _XDisplay*) d, *((int*) w), ExposureMask
                | KeyPressMask | KeyReleaseMask
                | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | ButtonMotionMask
                | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask
                | EnterWindowMask | LeaveWindowMask);

            // Show the window (make it visible).
            XMapWindow((struct _XDisplay*) d, *((int*) w));

            // Flush all pending requests to the X server.
            XFlush((struct _XDisplay*) d);

            // Unlock x window system mutex.
            pthread_mutex_unlock((pthread_mutex_t*) mt);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send x window system window. The window is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send x window system window. The display is null.");
    }
}

/* WINDOW_X_WINDOW_SYSTEM_SENDER_SOURCE */
#endif
