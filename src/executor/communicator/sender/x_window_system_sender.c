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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SENDER_SOURCE
#define X_WINDOW_SYSTEM_SENDER_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <pthread.h>

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cybol/graphical_user_interface_cybol_name.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../logger/logger.c"

/**
 * Sends the window onto the x window system display.
 *
 * @param p0 the destination display (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the internal memory
 * @param p4 the source count
 */
void send_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        struct _XDisplay** d = (struct _XDisplay**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send to x window system display.");

        // The window.
        int** w = (int**) NULL_POINTER_STATE_CYBOI_MODEL;

        // Get x window system internals.
        get((void*) &w, p3, (void*) WINDOW_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        // CAUTION! This test is necessary to avoid a "Segmentation fault"!
        if (*d != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // CAUTION! This test is necessary to avoid a "Segmentation fault"!
            if (*w != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Request input events (signals) to be put into event queue.
                XSelectInput(*d, **w, ExposureMask
                    | KeyPressMask | KeyReleaseMask
                    | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | ButtonMotionMask
                    | Button1MotionMask | Button2MotionMask | Button3MotionMask | Button4MotionMask | Button5MotionMask
                    | EnterWindowMask | LeaveWindowMask);

                // Show the window (make it visible).
                XMapWindow(*d, **w);

                // Flush all pending requests to the X server.
                XFlush(*d);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send to x window system display. The destination display is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send to x window system display. The destination display is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send to x window system display. The destination display argument is null.");
    }
}

/**
 * Sends an x window system message.
 *
 * @param p0 the internal memory
 * @param p1 the source gui compound model
 * @param p2 the source gui compound model count
 * @param p3 the knowledge memory
 * @param p4 the knowledge memory count
 */
void apply_send_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply send x window system.");

    // The x window system mutex.
    pthread_mutex_t** xmt = (pthread_mutex_t**) NULL_POINTER_STATE_CYBOI_MODEL;

    // Get x window system mutex.
    get((void*) &xmt, p0, (void*) MUTEX_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

    pthread_mutex_lock(*xmt);

//??    fwprintf(stdout, L"TEST send x 0: %i\n", p0);

    // Encode compound model into x window system window.
    serialise_x_window_system(p0, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p1, p2, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p3, p4);

    // The display, which is a subsumption of
    // xserver, screens, hardware (input devices etc.).
    void** d = NULL_POINTER_STATE_CYBOI_MODEL;

    // Get display.
    get_array_elements((void*) &d, p0, (void*) DISPLAY_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) POINTER_STATE_CYBOI_TYPE);

//??    fwprintf(stdout, L"TEST send x 1: %i\n", p0);

    // Show window on display.
    send_x_window_system(d, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p0, *NULL_POINTER_STATE_CYBOI_MODEL);

//??    fwprintf(stdout, L"TEST send x 2: %i\n", p0);

    pthread_mutex_unlock(*xmt);

    // TODO?? Destroy here ALL other things that were created in serialise_x_window_system!!
}

/* X_WINDOW_SYSTEM_SENDER_SOURCE */
#endif
