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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WINDOW_X_WINDOW_SYSTEM_SENDER_SOURCE
#define WINDOW_X_WINDOW_SYSTEM_SENDER_SOURCE

/*??
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <pthread.h>
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/graphical_user_interface_cybol_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../logger/logger.c"

/**
 * Sends the window to the x window system display.
 *
 * @param p0 the internal memory data
 */
void send_x_window_system_window(void* p0) {

    // The mutex.
//??    void* mt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The connection.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get mutex.
//??    copy_array_forward((void*) &mt, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get connection.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNECTION_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get window.
    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WINDOW_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST send x window system window c: %i\n", c);
fwprintf(stdout, L"TEST send x window system window w: %i\n", w);

    // CAUTION! This test is necessary to avoid a "Segmentation fault"!
    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! This test is necessary to avoid a "Segmentation fault"!
        if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send x window system window.");

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

//?? TEST BEGIN

            // The screen.
            void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

            copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SCREEN_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);

            /* geometric objects */
            xcb_point_t          points[] = {
                {10, 10},
                {10, 20},
                {20, 10},
                {20, 20}};

            xcb_point_t          polyline[] = {
                {50, 10},
                { 5, 20},     /* rest of points are relative */
                {25,-20},
                {10, 10}};

            xcb_segment_t        segments[] = {
                {100, 10, 140, 30},
                {110, 25, 130, 60}};

            xcb_rectangle_t      rectangles[] = {
                { 10, 50, 40, 20},
                { 80, 50, 10, 40}};

            xcb_arc_t            arcs[] = {
                {10, 100, 60, 40, 0, 90 << 6},
                {90, 100, 55, 40, 0, 270 << 6}};

            xcb_gcontext_t foreground = xcb_generate_id((xcb_connection_t*) c);
            uint32_t mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
            uint32_t values[2] = { ((xcb_screen_t*) s)->black_pixel, 0 };
            xcb_create_gc((xcb_connection_t*) c, foreground, window, mask, values);

            /* draw primitives */
            xcb_generic_event_t *event;

            while (event = xcb_wait_for_event((xcb_connection_t*) c)) {

                switch (event->response_type & ~0x80) {

                    case XCB_EXPOSE:

                        /* We draw the points */
                        xcb_poly_point ((xcb_connection_t*) c, XCB_COORD_MODE_ORIGIN, window, foreground, 4, points);

                        /* We draw the polygonal line */
                        xcb_poly_line ((xcb_connection_t*) c, XCB_COORD_MODE_PREVIOUS, window, foreground, 4, polyline);

                        /* We draw the segements */
                        xcb_poly_segment ((xcb_connection_t*) c, window, foreground, 2, segments);

                        /* draw the rectangles */
                        xcb_poly_rectangle ((xcb_connection_t*) c, window, foreground, 2, rectangles);

                        /* draw the arcs */
                        xcb_poly_arc ((xcb_connection_t*) c, window, foreground, 2, arcs);

                        /* flush the request */
                        xcb_flush ((xcb_connection_t*) c);

                        break;

                    default:

                        /* Unknown event type, ignore it */
                        break;
                }

                free (event);
            }
//?? TEST END

            // Unlock x window system mutex.
//??            pthread_mutex_unlock((pthread_mutex_t*) mt);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send x window system window. The window is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send x window system window. The connection is null.");
    }
}

/* WINDOW_X_WINDOW_SYSTEM_SENDER_SOURCE */
#endif
