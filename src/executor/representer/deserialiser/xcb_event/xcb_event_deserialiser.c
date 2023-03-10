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

#ifndef XCB_EVENT_DESERIALISER_SOURCE
#define XCB_EVENT_DESERIALISER_SOURCE

#include <xcb/xcb.h> // xcb_generic_event_t, XCB_BUTTON_PRESS etc.
#include <stdint.h> // uint8_t

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/representer/deserialiser/xcb_event/button_press_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/button_release_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/client_message_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/configure_notify_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/enter_notify_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/expose_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/key_press_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/key_release_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/leave_notify_xcb_event_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xcb_event/motion_notify_xcb_event_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the given xcb event.
 *
 * @param p0 the destination properties item
 * @param p1 the source event
 */
void deserialise_xcb_event(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_generic_event_t* e = (xcb_generic_event_t*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xcb event.");
        //?? fwprintf(stdout, L"Debug: Deserialise xcb event. source event e: %i\n", e);

        // Get response type.
        uint8_t t = (*e).response_type;

        //?? fwprintf(stdout, L"Debug: Deserialise xcb event. response type t: %i\n", t);

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

        //?? fwprintf(stdout, L"Debug: Deserialise xcb event. converted response type t: %i\n", t);

        if (t == XCB_BUTTON_PRESS) {

            deserialise_xcb_event_button_press(p0, p1);

        } else if (t == XCB_BUTTON_RELEASE) {

            //?? fwprintf(stdout, L"Debug: Deserialise xcb event. detected XCB_KEY_RELEASE (should be 3) t: %i\n", t);
            deserialise_xcb_event_button_release(p0, p1);

        } else if (t == XCB_CIRCULATE_NOTIFY) {

            //?? deserialise_xcb_event_circulate_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_CIRCULATE_NOTIFY t: %i\n", t);

        } else if (t == XCB_CIRCULATE_REQUEST) {

            //?? deserialise_xcb_event_circulate_request(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_CIRCULATE_REQUEST t: %i\n", t);

        } else if (t == XCB_CLIENT_MESSAGE) {

            deserialise_xcb_event_client_message(p0, p1);

        } else if (t == XCB_COLORMAP_NOTIFY) {

            //?? deserialise_xcb_event_colormap_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_COLORMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_CONFIGURE_NOTIFY) {

            deserialise_xcb_event_configure_notify(p0, p1);

        } else if (t == XCB_CONFIGURE_REQUEST) {

            //?? deserialise_xcb_event_configure_request(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_CONFIGURE_REQUEST t: %i\n", t);

        } else if (t == XCB_CREATE_NOTIFY) {

            //?? deserialise_xcb_event_create_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_CREATE_NOTIFY t: %i\n", t);

        } else if (t == XCB_DESTROY_NOTIFY) {

            //?? deserialise_xcb_event_destroy_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_DESTROY_NOTIFY t: %i\n", t);

        } else if (t == XCB_ENTER_NOTIFY) {

            deserialise_xcb_event_enter_notify(p0, p1);

        } else if (t == XCB_EXPOSE) {

            deserialise_xcb_event_expose(p0, p1);

        } else if (t == XCB_FOCUS_IN) {

            //?? deserialise_xcb_event_focus_in(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_FOCUS_IN t: %i\n", t);

        } else if (t == XCB_FOCUS_OUT) {

            //?? deserialise_xcb_event_focus_out(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_FOCUS_OUT t: %i\n", t);

        } else if (t == XCB_GE_GENERIC) {

            //?? deserialise_xcb_event_ge_generic(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_GE_GENERIC t: %i\n", t);

        } else if (t == XCB_GRAPHICS_EXPOSURE) {

            //?? deserialise_xcb_event_graphics_exposure(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_GRAPHICS_EXPOSURE t: %i\n", t);

        } else if (t == XCB_GRAVITY_NOTIFY) {

            //?? deserialise_xcb_event_gravity_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_GRAVITY_NOTIFY t: %i\n", t);

        } else if (t == XCB_KEY_PRESS) {

            deserialise_xcb_event_key_press(p0, p1);

        } else if (t == XCB_KEY_RELEASE) {

            deserialise_xcb_event_key_release(p0, p1);

        } else if (t == XCB_KEYMAP_NOTIFY) {

            //?? deserialise_xcb_event_keymap_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_KEYMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_LEAVE_NOTIFY) {

            deserialise_xcb_event_leave_notify(p0, p1);

        } else if (t == XCB_MAP_NOTIFY) {

            //?? deserialise_xcb_event_map_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_MAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_MAP_REQUEST) {

            //?? deserialise_xcb_event_map_request(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_MAP_REQUEST t: %i\n", t);

        } else if (t == XCB_MAPPING_NOTIFY) {

            //?? deserialise_xcb_event_mapping_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_MAPPING_NOTIFY t: %i\n", t);

        } else if (t == XCB_MOTION_NOTIFY) {

            deserialise_xcb_event_motion_notify(p0, p1);

        } else if (t == XCB_NO_EXPOSURE) {

            //?? deserialise_xcb_event_no_exposure(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_NO_EXPOSURE t: %i\n", t);

        } else if (t == XCB_PROPERTY_NOTIFY) {

            //?? deserialise_xcb_event_property_notify(p0, p1);

            //
            // This is called very often ...
            //
            //?? fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_PROPERTY_NOTIFY t: %i\n", t);

        } else if (t == XCB_REPARENT_NOTIFY) {

            //?? deserialise_xcb_event_reparent_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_REPARENT_NOTIFY t: %i\n", t);

        } else if (t == XCB_RESIZE_REQUEST) {

            //?? deserialise_xcb_event_resize_request(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_RESIZE_REQUEST t: %i\n", t);

        } else if (t == XCB_SELECTION_CLEAR) {

            //?? deserialise_xcb_event_selection_clear(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_SELECTION_CLEAR t: %i\n", t);

        } else if (t == XCB_SELECTION_NOTIFY) {

            //?? deserialise_xcb_event_selection_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_SELECTION_NOTIFY t: %i\n", t);

        } else if (t == XCB_SELECTION_REQUEST) {

            //?? deserialise_xcb_event_selection_request(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_SELECTION_REQUEST t: %i\n", t);

        } else if (t == XCB_UNMAP_NOTIFY) {

            //?? deserialise_xcb_event_unmap_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_UNMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_VISIBILITY_NOTIFY) {

            //?? deserialise_xcb_event_visibility_notify(p0, p1);
            fwprintf(stdout, L"Debug: Deserialise xcb event. XCB_VISIBILITY_NOTIFY t: %i\n", t);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb event. The source event is unknown.");
            fwprintf(stdout, L"Warning: Could not deserialise xcb event. The source event is unknown. t: %i\n", t);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb event. The source event is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb event. The source event is null. event p1: %i\n", p1);
    }
}

/* XCB_EVENT_DESERIALISER_SOURCE */
#endif
