/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef XCB_DESERIALISER_SOURCE
#define XCB_DESERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cybol/xcb/event_xcb_cybol_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the given xcb event.
 *
 * @param p0 the event name item
 * @param p1 the window identification item [window, event] (xcb_window_t) for many events
 * @param p2 the exposed rectangle coordinate x of the left-upper corner relative to the window's origin item (uint16_t) for expose event
 * @param p3 the exposed rectangle coordinate y of the left-upper corner relative to the window's origin item (uint16_t) for expose event
 * @param p4 the exposed rectangle width item (uint16_t) for expose event
 * @param p5 the exposed rectangle height item (uint16_t) for expose event
 * @param p6 the mouse coordinate x [event_x] (int16_t) relative to the event window's origin item for mouse and keyboard events
 * @param p7 the mouse coordinate y [event_y] (int16_t) relative to the event window's origin item for mouse and keyboard events
 * @param p8 the button [detail] item (xcb_button_t) for mouse events
 * @param p9 the keycode [detail] (xcb_keycode_t) of the physical key on the keyboard item for keyboard events
 * @param p10 the mask [state] (uint16_t) of the pointer buttons and modifier keys item for mouse and keyboard events
 * @param p11 the mouse button identification [mode] item (uint8_t) for mouse events
 * @param p12 the input/output entry
 * @param p13 the event
 */
void deserialise_xcb(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    //
    // The following code sections are NOT indented,
    // in order to better keep overview,
    // since more may have to be added in future.
    //

    if (p13 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_generic_event_t* e = (xcb_generic_event_t*) p13;

    if (p11 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* mode = (int*) p11;

    if (p10 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* mask = (int*) p10;

    if (p9 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* k = (int*) p9;

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* b = (int*) p8;

    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* y = (int*) p7;

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* x = (int*) p6;

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* eh = (int*) p5;

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ew = (int*) p4;

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ey = (int*) p3;

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ex = (int*) p2;

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* w = (int*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xcb.");

        // Get response type.
        uint8_t t = e->response_type;

//??        fwprintf(stdout, L"TEST deserialise xcb t: %i\n", t);

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

//??        fwprintf(stdout, L"TEST deserialise xcb converted t: %i\n", t);

        if (t == XCB_BUTTON_PRESS) {

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_BUTTON_PRESS t: %i\n", t);

            modify_item(p0, (void*) BUTTON_PRESS_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) BUTTON_PRESS_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            xcb_button_press_event_t* ev = (xcb_button_press_event_t*) e;

            // Get window identification.
            int w = (int) ev->event;
            // Get mouse coordinates.
            int x = (int) ev->event_x;
            int y = (int) ev->event_y;
            // Get mouse button or keycode.
            int b = (int) ev->detail;
            // Get button mask.
            int mask = (int) ev->state;

            // Set window identification.
            modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse coordinates.
            modify_item(p6, (void*) &x, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            modify_item(p7, (void*) &y, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse button or keycode.
            modify_item(p8, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set button mask.
            modify_item(p10, (void*) &mask, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        } else if (t == XCB_BUTTON_RELEASE) {

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_BUTTON_RELEASE t: %i\n", t);

            modify_item(p0, (void*) BUTTON_RELEASE_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) BUTTON_RELEASE_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            xcb_button_release_event_t* ev = (xcb_button_release_event_t*) e;

            // Get window identification.
            int w = (int) ev->event;
            // Get mouse coordinates.
            int x = (int) ev->event_x;
            int y = (int) ev->event_y;
            // Get mouse button or keycode.
            int b = (int) ev->detail;
            // Get button mask.
            int mask = (int) ev->state;

            // Set window identification.
            modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse coordinates.
            modify_item(p6, (void*) &x, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            modify_item(p7, (void*) &y, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse button or keycode.
            modify_item(p8, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set button mask.
            modify_item(p10, (void*) &mask, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_BUTTON_RELEASE x: %i\n", x);
//??            fwprintf(stdout, L"TEST deserialise xcb XCB_BUTTON_RELEASE y: %i\n", y);

        } else if (t == XCB_CIRCULATE_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_CIRCULATE_NOTIFY t: %i\n", t);

        } else if (t == XCB_CIRCULATE_REQUEST) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_CIRCULATE_REQUEST t: %i\n", t);

        } else if (t == XCB_CLIENT_MESSAGE) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE t: %i\n", t);

            xcb_client_message_event_t* ev = (xcb_client_message_event_t*) e;

            // Get window.
            uint32_t w = (uint32_t) (*ev).window;
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 0 w: %i\n", w);
            // Get type.
            uint32_t ty = (uint32_t) ev->type;
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 1 ty: %i\n", ty);
            // Get data.
            xcb_client_message_data_t d = ev->data;
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 2 d: %i\n", d);

            // Set window.
            modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 3 p1: %i\n", p1);

            // The delete window cookie.
            void* dwc = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Retrieve delete window cookie from input/output entry.
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 4 dwc: %i\n", dwc);
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 4 p12: %i\n", p12);
            get_io_entry_element((void*) &dwc, p12, (void*) DELETE_WINDOW_COOKIE_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 5 dwc: %i\n", dwc);

            // The delete window cookie structure.
            xcb_intern_atom_reply_t* dwcs = (xcb_intern_atom_reply_t*) dwc;
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 6 dwcs: %i\n", dwcs);

            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 7 d.data32[0]: %i\n", d.data32[0]);
//??            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 8 (*dwcs).atom: %i\n", (*dwcs).atom);
            // Find out if window is to be closed.
//??            if (d.data32[0] == (*dwcs).atom) {

                // Assign close window event.
                modify_item(p0, (void*) CLOSE_WINDOW_CLIENT_MESSAGE_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) CLOSE_WINDOW_CLIENT_MESSAGE_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 9 p0: %i\n", p0);
//??            }
            fwprintf(stdout, L"TEST deserialise xcb XCB_CLIENT_MESSAGE 10 t: %i\n", t);

        } else if (t == XCB_COLORMAP_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_COLORMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_CONFIGURE_NOTIFY) {

            //
            // This is called very often ...
            //

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_CONFIGURE_NOTIFY t: %i\n", t);

/*??
            modify_item(p0, (void*) CONFIGURE_NOTIFY_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) CONFIGURE_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            xcb_configure_notify_event_t* ev = (xcb_configure_notify_event_t*) e;

            //
            // Get original window size.
            //
            // CAUTION! The keyword "static" is IMPORTANT!
            // Using it, the variables are declared and initialised only the FIRST TIME
            // this code is executed, in order to store the original window size.
            // Later, original and new window size may be compared.
            //
            static uint16_t ow = ev->width;
            static uint16_t oh = ev->height;

            // Get current window size.
            uint16_t ew = ev->width;
            uint16_t eh = ev->height;

            // Resize window.
            if (((ew > 0) && (ow != ew)) || ((eh > 0) && (oh != eh)) ) {

                // Assign new width and height.
                ow = ew;
                oh = eh;
            }
*/

        } else if (t == XCB_CONFIGURE_REQUEST) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_CONFIGURE_REQUEST t: %i\n", t);

        } else if (t == XCB_CREATE_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_CREATE_NOTIFY t: %i\n", t);

        } else if (t == XCB_DESTROY_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_DESTROY_NOTIFY t: %i\n", t);

        } else if (t == XCB_ENTER_NOTIFY) {

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_ENTER_NOTIFY t: %i\n", t);

            modify_item(p0, (void*) ENTER_NOTIFY_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ENTER_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            xcb_enter_notify_event_t* ev = (xcb_enter_notify_event_t*) e;

            //?? an_event.xcrossing

            // Get window identification.
            int w = (int) ev->event;
            // Get mouse coordinates.
            int x = (int) ev->event_x;
            int y = (int) ev->event_y;
            // Get mouse button or keycode.
            int b = (int) ev->detail;
            // Get button mask.
            int mask = (int) ev->state;
            // Get mouse button identification.
            int mode = (int) ev->mode;

            // Set window identification.
            modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse coordinates.
            modify_item(p6, (void*) &x, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            modify_item(p7, (void*) &y, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse button or keycode.
            modify_item(p8, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set button mask.
            modify_item(p10, (void*) &mask, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse button identification.
            modify_item(p11, (void*) &mode, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        } else if (t == XCB_EXPOSE) {

            //
            // Expose events are sensed when a window needs
            // to be repainted, e.g. when being displayed after
            // having been covered by another window before.
            //

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_EXPOSE t: %i\n", t);

            modify_item(p0, (void*) EXPOSE_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) EXPOSE_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            xcb_expose_event_t* ev = (xcb_expose_event_t*) e;

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_EXPOSE ev->count: %i\n", ev->count);

            //
            // Consider only the last in a row of multiple expose events,
            // in order to avoid flickering of the display.
            //
            if (ev->count == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Get window identification.
                int w = (int) ev->window;
                // Get expose area position.
                int ex = (int) ev->x;
                int ey = (int) ev->y;
                // Get expose area size.
                int ew = (int) ev->width;
                int eh = (int) ev->height;

                // Set window identification.
                modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
                // Set expose area position.
                modify_item(p2, (void*) &ex, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
                modify_item(p3, (void*) &ey, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
                // Set expose area size.
                modify_item(p4, (void*) &ew, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
                modify_item(p5, (void*) &eh, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            }

        } else if (t == XCB_FOCUS_IN) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_FOCUS_IN t: %i\n", t);

        } else if (t == XCB_FOCUS_OUT) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_FOCUS_OUT t: %i\n", t);

        } else if (t == XCB_GE_GENERIC) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_GE_GENERIC t: %i\n", t);

        } else if (t == XCB_GRAPHICS_EXPOSURE) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_GRAPHICS_EXPOSURE t: %i\n", t);

        } else if (t == XCB_GRAVITY_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_GRAVITY_NOTIFY t: %i\n", t);

        } else if (t == XCB_KEY_PRESS) {

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_KEY_PRESS t: %i\n", t);

            modify_item(p0, (void*) KEY_PRESS_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) KEY_PRESS_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            // Key press events relate to keyboard keys.
            xcb_key_press_event_t* ev = (xcb_key_press_event_t*) e;

            // Get window identification.
            int w = (int) ev->event;
            // Get mouse coordinates.
            int x = (int) ev->event_x;
            int y = (int) ev->event_y;
            // Get keycode.
            int k = (int) ev->detail;
            // Get button mask.
            int mask = (int) ev->state;

            // Set window identification.
            modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse coordinates.
            modify_item(p6, (void*) &x, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            modify_item(p7, (void*) &y, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set keycode.
            modify_item(p9, (void*) &k, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set button mask.
            modify_item(p10, (void*) &mask, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        } else if (t == XCB_KEY_RELEASE) {

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_KEY_RELEASE t: %i\n", t);

            modify_item(p0, (void*) KEY_RELEASE_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) KEY_RELEASE_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            xcb_key_release_event_t* ev = (xcb_key_release_event_t*) e;

            // Get window identification.
            int w = (int) ev->event;
            // Get mouse coordinates.
            int x = (int) ev->event_x;
            int y = (int) ev->event_y;
            // Get keycode.
            int k = (int) ev->detail;
            // Get button mask.
            int mask = (int) ev->state;

            // Set window identification.
            modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse coordinates.
            modify_item(p6, (void*) &x, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            modify_item(p7, (void*) &y, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set keycode.
            modify_item(p9, (void*) &k, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set button mask.
            modify_item(p10, (void*) &mask, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        } else if (t == XCB_KEYMAP_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_KEYMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_LEAVE_NOTIFY) {

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_LEAVE_NOTIFY t: %i\n", t);

            modify_item(p0, (void*) LEAVE_NOTIFY_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) LEAVE_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            xcb_leave_notify_event_t* ev = (xcb_leave_notify_event_t*) e;

            // Get window identification.
            int w = (int) ev->event;
            // Get mouse coordinates.
            int x = (int) ev->event_x;
            int y = (int) ev->event_y;
            // Get mouse button or keycode.
            int b = (int) ev->detail;
            // Get button mask.
            int mask = (int) ev->state;
            // Get mouse button identification.
            int mode = (int) ev->mode;

            // Set window identification.
            modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse coordinates.
            modify_item(p6, (void*) &x, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            modify_item(p7, (void*) &y, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse button or keycode.
            modify_item(p8, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set button mask.
            modify_item(p10, (void*) &mask, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse button identification.
            modify_item(p11, (void*) &mode, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        } else if (t == XCB_MAP_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_MAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_MAP_REQUEST) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_MAP_REQUEST t: %i\n", t);

        } else if (t == XCB_MAPPING_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_MAPPING_NOTIFY t: %i\n", t);

        } else if (t == XCB_MOTION_NOTIFY) {

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_MOTION_NOTIFY t: %i\n", t);

            modify_item(p0, (void*) MOTION_NOTIFY_EVENT_XCB_CYBOL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MOTION_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            xcb_motion_notify_event_t* ev = (xcb_motion_notify_event_t*) e;

            // Get window identification.
            int w = (int) ev->event;
            // Get mouse coordinates.
            int x = (int) ev->event_x;
            int y = (int) ev->event_y;
            // Get mouse button or keycode.
            int b = (int) ev->detail;
            // Get button mask.
            int mask = (int) ev->state;

            // Set window identification.
            modify_item(p1, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse coordinates.
            modify_item(p6, (void*) &x, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            modify_item(p7, (void*) &y, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set mouse button or keycode.
            modify_item(p8, (void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
            // Set button mask.
            modify_item(p10, (void*) &mask, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        } else if (t == XCB_NO_EXPOSURE) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_NO_EXPOSURE t: %i\n", t);

        } else if (t == XCB_PROPERTY_NOTIFY) {

            //
            // This is called very often ...
            //

//??            fwprintf(stdout, L"TEST deserialise xcb XCB_PROPERTY_NOTIFY t: %i\n", t);

        } else if (t == XCB_REPARENT_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_REPARENT_NOTIFY t: %i\n", t);

        } else if (t == XCB_RESIZE_REQUEST) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_RESIZE_REQUEST t: %i\n", t);

        } else if (t == XCB_SELECTION_CLEAR) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_SELECTION_CLEAR t: %i\n", t);

        } else if (t == XCB_SELECTION_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_SELECTION_NOTIFY t: %i\n", t);

        } else if (t == XCB_SELECTION_REQUEST) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_SELECTION_REQUEST t: %i\n", t);

        } else if (t == XCB_UNMAP_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_UNMAP_NOTIFY t: %i\n", t);

        } else if (t == XCB_VISIBILITY_NOTIFY) {

            fwprintf(stdout, L"TEST deserialise xcb XCB_VISIBILITY_NOTIFY t: %i\n", t);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The window identification is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The window identification is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The exposed rectangle coordinate x is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The exposed rectangle coordinate x is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The exposed rectangle coordinate y is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The exposed rectangle coordinate y is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The exposed rectangle width is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The exposed rectangle width is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The exposed rectangle height is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The exposed rectangle height is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The mouse coordinate x is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The mouse coordinate x is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The mouse coordinate y is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The mouse coordinate y is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The button is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The button is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The keycode is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The keycode is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The mask is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The mask is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The mouse button identification (mode) is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The mouse button identification (mode) is null.\n");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The event is null.");
        fwprintf(stdout, L"Error: Could not deserialise xcb. The event is null.\n");
    }
}

/* XCB_DESERIALISER_SOURCE */
#endif
