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

#ifndef CLIENT_XCB_ENABLER_SOURCE
#define CLIENT_XCB_ENABLER_SOURCE

#include <xcb/xcb.h> // xcb_generic_event_t etc.

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Gets client window identification from event.
 *
 * @param p0 the destination client window identification
 * @param p1 the source event
 */
void enable_xcb_client(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable xcb client.");
    //?? fwprintf(stdout, L"Debug: Enable xcb client. p1: %i\n", p1);

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_generic_event_t* e = (xcb_generic_event_t*) p1;

        // Get event response type.
        uint8_t t = (*e).response_type;

        //?? fwprintf(stdout, L"Debug: Enable xcb client. response type t: %i\n", t);

        //
        // Reset highest-level bit to zero.
        //
        // The hexadecimal value 0x80 is decimal 128.
        // The bit operator ~ negates that value to zero.
        // Using the bit operation AND resets the highest-level bit to zero.
        //
        //?? TODO: Why is this needed?
        //?? All examples found in the web used it, but without explanation.
        //?? It was copied from an example in the xcb tutorial.
        //
        t = t & (~0x80);

        //?? fwprintf(stdout, L"Debug: Enable xcb client. converted response type t: %i\n", t);

        if (t == XCB_BUTTON_PRESS) {

            xcb_button_press_event_t* ev = (xcb_button_press_event_t*) e;

            // Get window identification.
            int w = (int) (*ev).event;
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_BUTTON_PRESS w: %i\n", w);

            copy_integer(p0, (void*) &w);

        } else if (t == XCB_BUTTON_RELEASE) {

            xcb_button_release_event_t* ev = (xcb_button_release_event_t*) e;

            // Get window identification.
            int w = (int) (*ev).event;
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_BUTTON_RELEASE w: %i\n", w);

            copy_integer(p0, (void*) &w);

        } else if (t == XCB_CIRCULATE_NOTIFY) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_CIRCULATE_NOTIFY t: %i\n", t);

        } else if (t == XCB_CIRCULATE_REQUEST) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_CIRCULATE_REQUEST t: %i\n", t);

        } else if (t == XCB_CLIENT_MESSAGE) {

            xcb_client_message_event_t* ev = (xcb_client_message_event_t*) e;

            // Get window.
            uint32_t w = (uint32_t) (*ev).window;
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_CLIENT_MESSAGE w: %i\n", w);

            copy_integer(p0, (void*) &w);

        } else if (t == XCB_COLORMAP_NOTIFY) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_COLORMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_CONFIGURE_NOTIFY) {

            //
            // This is called very often ...
            //

            //?? xcb_configure_notify_event_t* ev = (xcb_configure_notify_event_t*) e;

            //?? There was no field to determine the window identification.
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_CONFIGURE_NOTIFY -1: %i\n", -1);

        } else if (t == XCB_CONFIGURE_REQUEST) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_CONFIGURE_REQUEST t: %i\n", t);

        } else if (t == XCB_CREATE_NOTIFY) {

            //?? fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_CREATE_NOTIFY t: %i\n", t);

        } else if (t == XCB_DESTROY_NOTIFY) {

            //?? fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_DESTROY_NOTIFY t: %i\n", t);

        } else if (t == XCB_ENTER_NOTIFY) {

            xcb_enter_notify_event_t* ev = (xcb_enter_notify_event_t*) e;

            // Get window identification.
            int w = (int) (*ev).event;
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_ENTER_NOTIFY w: %i\n", w);

            copy_integer(p0, (void*) &w);

        } else if (t == XCB_EXPOSE) {

            xcb_expose_event_t* ev = (xcb_expose_event_t*) e;

            //
            // Consider only the last in a row of multiple expose events,
            // in order to avoid flickering of the display.
            //
            if ((*ev).count == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Get window identification.
                int w = (int) (*ev).window;
                //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_EXPOSE w: %i\n", w);

                copy_integer(p0, (void*) &w);
            }

        } else if (t == XCB_FOCUS_IN) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_FOCUS_IN t: %i\n", t);

        } else if (t == XCB_FOCUS_OUT) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_FOCUS_OUT t: %i\n", t);

        } else if (t == XCB_GE_GENERIC) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_GE_GENERIC t: %i\n", t);

        } else if (t == XCB_GRAPHICS_EXPOSURE) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_GRAPHICS_EXPOSURE t: %i\n", t);

        } else if (t == XCB_GRAVITY_NOTIFY) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_GRAVITY_NOTIFY t: %i\n", t);

        } else if (t == XCB_KEY_PRESS) {

            xcb_key_press_event_t* ev = (xcb_key_press_event_t*) e;

            // Get window identification.
            int w = (int) (*ev).event;
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_KEY_PRESS w: %i\n", w);

            copy_integer(p0, (void*) &w);

        } else if (t == XCB_KEY_RELEASE) {

            xcb_key_release_event_t* ev = (xcb_key_release_event_t*) e;

            // Get window identification.
            int w = (int) (*ev).event;
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_KEY_RELEASE w: %i\n", w);

            copy_integer(p0, (void*) &w);

        } else if (t == XCB_KEYMAP_NOTIFY) {

            //?? fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_KEYMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_LEAVE_NOTIFY) {

            xcb_leave_notify_event_t* ev = (xcb_leave_notify_event_t*) e;

            // Get window identification.
            int w = (int) (*ev).event;
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_LEAVE_NOTIFY w: %i\n", w);

            copy_integer(p0, (void*) &w);

        } else if (t == XCB_MAP_NOTIFY) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_MAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_MAP_REQUEST) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_MAP_REQUEST t: %i\n", t);

        } else if (t == XCB_MAPPING_NOTIFY) {

            //?? fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_MAPPING_NOTIFY t: %i\n", t);

        } else if (t == XCB_MOTION_NOTIFY) {

            xcb_motion_notify_event_t* ev = (xcb_motion_notify_event_t*) e;

            // Get window identification.
            int w = (int) (*ev).event;
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_MOTION_NOTIFY w: %i\n", w);

            copy_integer(p0, (void*) &w);

        } else if (t == XCB_NO_EXPOSURE) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_NO_EXPOSURE t: %i\n", t);

        } else if (t == XCB_PROPERTY_NOTIFY) {

            //
            // This is called very often ...
            //

            //?? fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_PROPERTY_NOTIFY t: %i\n", t);
            //?? fwprintf(stdout, L"Debug: Enable xcb client. XCB_PROPERTY_NOTIFY -1: %i\n", -1);

        } else if (t == XCB_REPARENT_NOTIFY) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_REPARENT_NOTIFY t: %i\n", t);

        } else if (t == XCB_RESIZE_REQUEST) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_RESIZE_REQUEST t: %i\n", t);

        } else if (t == XCB_SELECTION_CLEAR) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_SELECTION_CLEAR t: %i\n", t);

        } else if (t == XCB_SELECTION_NOTIFY) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_SELECTION_NOTIFY t: %i\n", t);

        } else if (t == XCB_SELECTION_REQUEST) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_SELECTION_REQUEST t: %i\n", t);

        } else if (t == XCB_UNMAP_NOTIFY) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_UNMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_VISIBILITY_NOTIFY) {

            fwprintf(stdout, L"Debug: Enable xcb client. TODO ?? XCB_VISIBILITY_NOTIFY t: %i\n", t);

        } else {

            //
            // CAUTION! There seem to be too many unknown event response types.
            // Therefore, this log message is commented out.
            //

            //?? log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb client. The event response type is unknown.");
            //?? fwprintf(stdout, L"Warning: Could not enable xcb client. The event response type is unknown. t: %i\n", t);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb client. The event is null.");
        fwprintf(stdout, L"Error: Could not enable xcb client. The event is null.\n");
    }
}

/* CLIENT_XCB_ENABLER_SOURCE */
#endif
