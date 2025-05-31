/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <xcb/xcb.h> // xcb_connection_t etc.
#include <stdio.h> // stdout
#include <stdlib.h> // free
#include <string.h> // strlen
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Opens up a client window on the x window system display.
 *
 * @param p0 the window identification
 * @param p1 the client entry
 */
void open_xcb(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open xcb.");
    //?? fwprintf(stdout, L"Debug: Open xcb. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Open xcb. *p0: %i\n", *((int*) p0));

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The screen.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window.
    int w = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The delete window cookie.
    void* dwc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from client entry.
    copy_array_forward((void*) &se, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME);

    // Get connexion from server entry.
    copy_array_forward((void*) &c, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);
    // Get screen from server entry.
    copy_array_forward((void*) &s, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SCREEN_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A display DOES exist in server entry.
        //

        // Cast connexion to correct type.
        xcb_connection_t* ct = (xcb_connection_t*) c;

        if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Cast screen to correct type.
            xcb_screen_t* st = (xcb_screen_t*) s;

            //
            // The client window value mask.
            //
            // CAUTION! It is possible to set several attributes
            // at the same time by OR'ing these values in valuemask.
            //
            // The values that a mask could take are given
            // by the "xcb_cw_t" enumeration:
            //
            // typedef enum {
            //     XCB_CW_BACK_PIXMAP       = 1L << 0, // 0
            //     XCB_CW_BACK_PIXEL        = 1L << 1, // 1
            //     XCB_CW_BORDER_PIXMAP     = 1L << 2, // 2
            //     XCB_CW_BORDER_PIXEL      = 1L << 3, // 4
            //     XCB_CW_BIT_GRAVITY       = 1L << 4, // 8
            //     XCB_CW_WIN_GRAVITY       = 1L << 5, // 16
            //     XCB_CW_BACKING_STORE     = 1L << 6, // 32
            //     XCB_CW_BACKING_PLANES    = 1L << 7, // 64
            //     XCB_CW_BACKING_PIXEL     = 1L << 8, // 128
            //     XCB_CW_OVERRIDE_REDIRECT = 1L << 9, // 256
            //     XCB_CW_SAVE_UNDER        = 1L << 10, // 512
            //     XCB_CW_EVENT_MASK        = 1L << 11, // 1024
            //     XCB_CW_DONT_PROPAGATE    = 1L << 12, // 2048
            //     XCB_CW_COLORMAP          = 1L << 13, // 4096
            //     XCB_CW_CURSOR            = 1L << 14 // 8192
            // } xcb_cw_t;
            //
            // CAUTION! Be careful when setting the values,
            // as they HAVE TO FOLLOW the order of the enumeration.
            //
            uint32_t wm = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
            // The window values.
            uint32_t wv[2];

            //
            // Initialise window background.
            //
            // CAUTION! The index has to be in the
            // SAME ORDER as given in the mask above.
            //
            wv[0] = (*st).white_pixel;
            //
            // Register for all possible event types.
            //
            // CAUTION! The index has to be in the
            // SAME ORDER as given in the mask above.
            //
            // The event value mask.
            //
            // CAUTION! It is possible to set several attributes
            // at the same time by OR'ing these values in valuemask.
            //
            // The values that a mask could take are given
            // by the "xcb_event_mask_t" enumeration:
            //
            // enum xcb_event_mask_t {
            //     XCB_EVENT_MASK_NO_EVENT = 0,
            //     XCB_EVENT_MASK_KEY_PRESS = 1,
            //     XCB_EVENT_MASK_KEY_RELEASE = 2,
            //     XCB_EVENT_MASK_BUTTON_PRESS = 4,
            //     XCB_EVENT_MASK_BUTTON_RELEASE = 8,
            //     XCB_EVENT_MASK_ENTER_WINDOW = 16,
            //     XCB_EVENT_MASK_LEAVE_WINDOW = 32,
            //     XCB_EVENT_MASK_POINTER_MOTION = 64,
            //     XCB_EVENT_MASK_POINTER_MOTION_HINT = 128,
            //     XCB_EVENT_MASK_BUTTON_1_MOTION = 256,
            //     XCB_EVENT_MASK_BUTTON_2_MOTION = 512,
            //     XCB_EVENT_MASK_BUTTON_3_MOTION = 1024,
            //     XCB_EVENT_MASK_BUTTON_4_MOTION = 2048,
            //     XCB_EVENT_MASK_BUTTON_5_MOTION = 4096,
            //     XCB_EVENT_MASK_BUTTON_MOTION = 8192,
            //     XCB_EVENT_MASK_KEYMAP_STATE = 16384,
            //     XCB_EVENT_MASK_EXPOSURE = 32768,
            //     XCB_EVENT_MASK_VISIBILITY_CHANGE = 65536,
            //     XCB_EVENT_MASK_STRUCTURE_NOTIFY = 131072,
            //     XCB_EVENT_MASK_RESIZE_REDIRECT = 262144,
            //     XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY = 524288,
            //     XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT = 1048576,
            //     XCB_EVENT_MASK_FOCUS_CHANGE = 2097152,
            //     XCB_EVENT_MASK_PROPERTY_CHANGE = 4194304,
            //     XCB_EVENT_MASK_COLOR_MAP_CHANGE = 8388608,
            //     XCB_EVENT_MASK_OWNER_GRAB_BUTTON = 16777216
            // }
            //
            // CAUTION! Be careful when setting the values,
            // as they HAVE TO FOLLOW the order of the enumeration.
            //
            wv[1] =
                // Nothing.
                // It actually makes no sense to activate this constant.
                // However, it does no harm either and is added here to be complete.
                //?? XCB_EVENT_MASK_NO_EVENT
                // Keyboard press and release (while focus is on window).
                //?? |
                XCB_EVENT_MASK_KEY_PRESS
                | XCB_EVENT_MASK_KEY_RELEASE
                // Mouse button press and release.
                | XCB_EVENT_MASK_BUTTON_PRESS
                | XCB_EVENT_MASK_BUTTON_RELEASE
                // Mouse pointer enter and leave.
                //?? | XCB_EVENT_MASK_ENTER_WINDOW
                //?? | XCB_EVENT_MASK_LEAVE_WINDOW
                // Mouse movement.
                //?? | XCB_EVENT_MASK_POINTER_MOTION // motion with no mouse button held
                //?? | XCB_EVENT_MASK_POINTER_MOTION_HINT
                //?? | XCB_EVENT_MASK_BUTTON_1_MOTION // motion while only 1st mouse button is held
                //?? | XCB_EVENT_MASK_BUTTON_2_MOTION // and so on ...
                //?? | XCB_EVENT_MASK_BUTTON_3_MOTION
                //?? | XCB_EVENT_MASK_BUTTON_4_MOTION
                //?? | XCB_EVENT_MASK_BUTTON_5_MOTION
                //?? | XCB_EVENT_MASK_BUTTON_MOTION // motion with one or more of the mouse buttons held
                // Keymap.
                //?? | XCB_EVENT_MASK_KEYMAP_STATE
                // Expose.
                // - a window that covered part of the current window has moved away, exposing part (or all) of the current window
                // - the current window was raised above other windows
                // - the current window was mapped for the first time
                // - the current window was de-iconified (to 'iconify' a window is to minimize it or send it to the tray such that it is not shown at all)
                | XCB_EVENT_MASK_EXPOSURE
                // Window.
                //?? | XCB_EVENT_MASK_VISIBILITY_CHANGE
                //?? | XCB_EVENT_MASK_STRUCTURE_NOTIFY
                //?? TODO:
                //?? Activating the resize event causes
                //?? the window NOT to be displayed correctly
                //?? (only part of it is shown).
                //?? Therefore, it is commented out here.
                //?? Resizing may be done alternatively via
                //?? the mask XCB_EVENT_MASK_STRUCTURE_NOTIFY
                //?? and catching the event XCB_CLIENT_MESSAGE.
                //??
                //?? | XCB_EVENT_MASK_RESIZE_REDIRECT
                //?? | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
                //?? | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT
                //?? | XCB_EVENT_MASK_FOCUS_CHANGE
                //?? | XCB_EVENT_MASK_PROPERTY_CHANGE
                //?? | XCB_EVENT_MASK_COLOR_MAP_CHANGE
                //?? | XCB_EVENT_MASK_OWNER_GRAB_BUTTON
                ;

            // Allocate xid for window.
            w = (int) xcb_generate_id(ct);
            // Cast window id to correct type.
            xcb_window_t wt = (xcb_window_t) w;

            //?? fwprintf(stdout, L"Debug: Open xcb. w: %i\n", w);

            // Create window.
            xcb_create_window(ct, // connexion
                XCB_COPY_FROM_PARENT, // depth (same as root)
                wt, // window id
                (*st).root, // parent window
                0, 0, // x, y
                150, 150, // width, height
                10, // border_width
                XCB_WINDOW_CLASS_INPUT_OUTPUT, // class
                (*st).root_visual, // visual
                wm, wv); // mask and values

            //
            // Create delete window cookie.
            //

            // Send notification when window is destroyed.
            xcb_intern_atom_cookie_t protocols_cookie = xcb_intern_atom(ct, (uint8_t) *NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (uint16_t) strlen("WM_PROTOCOLS"), "WM_PROTOCOLS");
            // CAUTION! The last argument is a pointer reference of type void**
            xcb_intern_atom_reply_t* protocols_reply = xcb_intern_atom_reply(ct, protocols_cookie, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);
            xcb_intern_atom_cookie_t delete_cookie = xcb_intern_atom(ct, (uint8_t) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (uint16_t) strlen("WM_DELETE_WINDOW"), "WM_DELETE_WINDOW");
            // CAUTION! The last argument is a pointer reference of type void**
            xcb_intern_atom_reply_t* delete_reply = xcb_intern_atom_reply(ct, delete_cookie, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);

            dwc = (void*) delete_reply;

            //
            // Assign delete window cookie.
            //
            // CAUTION! Do NOT replace the fifth parametre (integer value 4)
            // with either XCB_ATOM_INTEGER or (*protocols_reply).atom,
            // since it will not function then.
            //
            xcb_change_property(ct, XCB_PROP_MODE_REPLACE, wt, (*protocols_reply).atom, 4, 32, 1, &((*delete_reply).atom));

            // Free internal protocols cookie structure.
            free(protocols_reply);

            //?? fwprintf(stdout, L"Debug: Open xcb. delete_reply: %i\n", delete_reply);
            //?? fwprintf(stdout, L"Debug: Open xcb. (*delete_reply).atom: %i\n", (*delete_reply).atom);

            //
            // CAUTION! Do NOT free the delete cookie structure here.
            // It is still needed for processing window close events.
            // It gets freed at system shutdown.
            //

            // Copy window identification to corresponding parametre.
            copy_integer(p0, (void*) &w);

            //?? fwprintf(stdout, L"Debug: Open xcb. copied window id p0: %i\n", p0);
            //?? fwprintf(stdout, L"Debug: Open xcb. copied window id *p0: %i\n", *((int*) p0));

            // Set delete window cookie into server entry.
            //?? copy_array_forward(p1, (void*) &dwc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DELETE_WINDOW_COOKIE_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open xcb. The screen is null.");
            fwprintf(stdout, L"Error: Could not open xcb. The screen is null. s: %i\n", s);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open xcb. The connexion is null.");
        fwprintf(stdout, L"Error: Could not open xcb. The connexion is null. c: %i\n", c);
    }
}
