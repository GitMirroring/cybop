/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CLIENT_XCB_STARTER_SOURCE
#define CLIENT_XCB_STARTER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up an x window system client (a window).
 *
 * @param p0 the input/output entry
 * @param p1 the window id
 */
void startup_xcb_client(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup xcb client.");

    // The client list item.
    //?? void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The screen.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window.
    int w = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The graphic context.
    int gc = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The font.
    int f = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The delete window cookie.
    void* dwc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get client list item from input/output entry.
    //?? get_io_entry_element((void*) &cl, io, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);
    //
    // Retrieve connexion from input/output entry.
    //
    // CAUTION! Do NOT use "overwrite_array" function here,
    // since it adapts the array count and size.
    // But the array's count and size are CONSTANT.
    //
    // CAUTION! Hand over values as pointer REFERENCE.
    //
    // CAUTION! Do NOT hand over input/output entry as pointer reference.
    //
    get_io_entry_element((void*) &c, p0, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"TEST: Startup xcb client. c: %i\n", c);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A display DOES exist in input/output entry.
        //

        // Get setup.
        const xcb_setup_t* setup = xcb_get_setup((xcb_connection_t*) c);

        //?? fwprintf(stdout, L"TEST: Startup xcb client. setup: %i\n", setup);

        if (setup != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get screen iterator.
            xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);

            //
            // Get first screen.
            //
            // CAUTION! Do NOT allocate the screen manually here.
            // It gets allocated through the connexion above.
            //
            s = (void*) iter.data;

            //?? fwprintf(stdout, L"TEST: Startup xcb client. s: %i\n", s);

            if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // The xcb screen type value.
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
                //
                // The graphic context value mask.
                //
                // CAUTION! It is possible to set several attributes
                // at the same time by OR'ing these values in valuemask.
                //
                // The values that a mask could take are given
                // by the "xcb_gc_t" enumeration:
                //
                // enum xcb_gc_t {
                //     XCB_GC_FUNCTION = 1,
                //     XCB_GC_PLANE_MASK = 2,
                //     XCB_GC_FOREGROUND = 4,
                //     XCB_GC_BACKGROUND = 8,
                //     XCB_GC_LINE_WIDTH = 16,
                //     XCB_GC_LINE_STYLE = 32,
                //     XCB_GC_CAP_STYLE = 64,
                //     XCB_GC_JOIN_STYLE = 128,
                //     XCB_GC_FILL_STYLE = 256,
                //     XCB_GC_FILL_RULE = 512,
                //     XCB_GC_TILE = 1024,
                //     XCB_GC_STIPPLE = 2048,
                //     XCB_GC_TILE_STIPPLE_ORIGIN_X = 4096,
                //     XCB_GC_TILE_STIPPLE_ORIGIN_Y = 8192,
                //     XCB_GC_FONT = 16384,
                //     XCB_GC_SUBWINDOW_MODE = 32768,
                //     XCB_GC_GRAPHICS_EXPOSURES = 65536,
                //     XCB_GC_CLIP_ORIGIN_X = 131072,
                //     XCB_GC_CLIP_ORIGIN_Y = 262144,
                //     XCB_GC_CLIP_MASK = 524288,
                //     XCB_GC_DASH_OFFSET = 1048576,
                //     XCB_GC_DASH_LIST = 2097152,
                //     XCB_GC_ARC_MODE = 4194304
                // }
                //
                // CAUTION! Be careful when setting the values,
                // as they HAVE TO FOLLOW the order of the enumeration.
                //
                //?? uint32_t gcm = XCB_GC_BACKGROUND | XCB_GC_FOREGROUND; //?? | XCB_GC_FONT;
                uint32_t gcm = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;

                // The window values.
                uint32_t wv[2];
                // The graphic context values.
                uint32_t gcv[2];

                //
                // CAUTION! Initialise values BEFORE using
                // them in function calls further below.
                // Otherwise, drawing errors will occur.
                //

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
                // ??TODO: Is the following claim REALLY needed?
                // CAUTION! Be careful when setting the values,
                // as they HAVE TO FOLLOW the order of the enumeration.
                //
                wv[1] =
                    // Nothing.
                    // It actually makes no sense to activate this constant.
                    // However, it does no harm either and is added here to be complete.
                    XCB_EVENT_MASK_NO_EVENT
                    // Keyboard press and release (while focus is on window).
                    | XCB_EVENT_MASK_KEY_PRESS
                    | XCB_EVENT_MASK_KEY_RELEASE
                    // Mouse button press and release.
                    | XCB_EVENT_MASK_BUTTON_PRESS
                    | XCB_EVENT_MASK_BUTTON_RELEASE
                    // Mouse pointer enter and leave.
                    | XCB_EVENT_MASK_ENTER_WINDOW
                    | XCB_EVENT_MASK_LEAVE_WINDOW
                    // Mouse movement.
                    | XCB_EVENT_MASK_POINTER_MOTION // motion with no mouse button held
                    | XCB_EVENT_MASK_POINTER_MOTION_HINT
                    | XCB_EVENT_MASK_BUTTON_1_MOTION // motion while only 1st mouse button is held
                    | XCB_EVENT_MASK_BUTTON_2_MOTION // and so on ...
                    | XCB_EVENT_MASK_BUTTON_3_MOTION
                    | XCB_EVENT_MASK_BUTTON_4_MOTION
                    | XCB_EVENT_MASK_BUTTON_5_MOTION
                    | XCB_EVENT_MASK_BUTTON_MOTION // motion with one or more of the mouse buttons held
                    // Keymap.
                    | XCB_EVENT_MASK_KEYMAP_STATE
                    // Expose.
                    // - a window that covered part of the current window has moved away, exposing part (or all) of the current window
                    // - the current window was raised above other windows
                    // - the current window was mapped for the first time
                    // - the current window was de-iconified (to 'iconify' a window is to minimize it or send it to the tray such that it is not shown at all)
                    | XCB_EVENT_MASK_EXPOSURE
                    // Window.
                    | XCB_EVENT_MASK_VISIBILITY_CHANGE
                    | XCB_EVENT_MASK_STRUCTURE_NOTIFY
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
                    | XCB_EVENT_MASK_SUBSTRUCTURE_NOTIFY
                    | XCB_EVENT_MASK_SUBSTRUCTURE_REDIRECT
                    | XCB_EVENT_MASK_FOCUS_CHANGE
                    | XCB_EVENT_MASK_PROPERTY_CHANGE
                    | XCB_EVENT_MASK_COLOR_MAP_CHANGE
                    | XCB_EVENT_MASK_OWNER_GRAB_BUTTON;

                //
                // Initialise graphic context values.
                //
                // CAUTION! The index has to be in the
                // SAME ORDER as given in the mask above.
                //
                gcv[0] = (*st).black_pixel;
                gcv[1] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
/*??
                gcv[0] = (*st).white_pixel;
                gcv[1] = (*st).black_pixel;
                //?? gcv[2] = font;
*/

                // Allocate xid for window, graphic context, font.
                w = (int) xcb_generate_id((xcb_connection_t*) c);
                gc = (int) xcb_generate_id((xcb_connection_t*) c);
                f = (int) xcb_generate_id((xcb_connection_t*) c);

                // Create window.
                xcb_create_window((xcb_connection_t*) c, // connexion
                    XCB_COPY_FROM_PARENT, // depth (same as root)
                    (xcb_window_t) w, // window id
                    (*st).root, // parent window
                    0, 0, // x, y
                    150, 150, // width, height
                    10, // border_width
                    XCB_WINDOW_CLASS_INPUT_OUTPUT, // class
                    (*st).root_visual, // visual
                    wm, wv); // mask and values

                //
                // Create graphic context.
                //
                // CAUTION! It is possible to use more than one
                // graphical context with a single window,
                // in order to draw in multiple styles
                // (different colors, different line widths etc).
                //
                // However, just ONE graphic context suffices here,
                // since its styles get updated as needed
                // with each new send / serialise gui function call.
                //
                // CAUTION! The last parametre has to be a pointer,
                // and it already IS one, since it is an array.
                //
                xcb_create_gc((xcb_connection_t*) c, (xcb_gcontext_t) gc, (xcb_drawable_t) w, gcm, gcv);

                //
                // Create delete window cookie.
                //

                // Send notification when window is destroyed.
                xcb_intern_atom_cookie_t protocols_cookie = xcb_intern_atom((xcb_connection_t*) c, (uint8_t) *NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (uint16_t) strlen("WM_PROTOCOLS"), "WM_PROTOCOLS");
                // CAUTION! The last argument is a pointer reference of type void**
                xcb_intern_atom_reply_t* protocols_reply = xcb_intern_atom_reply((xcb_connection_t*) c, protocols_cookie, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);
                xcb_intern_atom_cookie_t delete_cookie = xcb_intern_atom((xcb_connection_t*) c, (uint8_t) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (uint16_t) strlen("WM_DELETE_WINDOW"), "WM_DELETE_WINDOW");
                // CAUTION! The last argument is a pointer reference of type void**
                xcb_intern_atom_reply_t* delete_reply = xcb_intern_atom_reply((xcb_connection_t*) c, delete_cookie, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);

                dwc = (void*) delete_reply;

                //
                // Assign delete window cookie.
                //
                // CAUTION! Do NOT replace the fifth parametre (integer value 4)
                // with either XCB_ATOM_INTEGER or (*protocols_reply).atom,
                // since it will not function then.
                //
                xcb_change_property((xcb_connection_t*) c, XCB_PROP_MODE_REPLACE, (xcb_window_t) w, (*protocols_reply).atom, 4, 32, 1, &((*delete_reply).atom));

                // Free internal protocols cookie structure.
                free(protocols_reply);

                //?? fwprintf(stdout, L"TEST: Startup xcb client. delete_reply: %i\n", delete_reply);
                //?? fwprintf(stdout, L"TEST: Startup xcb client. (*delete_reply).atom: %i\n", (*delete_reply).atom);

                //
                // CAUTION! Do NOT free the delete cookie structure here.
                // It is still needed for processing window close events.
                // It gets freed at system shutdown.
                //

                // Add window to client list item.
                //?? modify_item(cl, (void*) &w, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                // Copy window as id to corresponding parametre.
                copy_integer(p1, (void*) &w);

                //
                // Store various values in input/output entry.
                //
                // CAUTION! Do NOT use "overwrite_array" function here,
                // since it adapts the array count and size.
                // But the array's count and size are CONSTANT.
                //
                // CAUTION! Do NOT hand over input/output entry as pointer reference.
                //
                // CAUTION! Hand over values as pointer REFERENCE.
                //

/*??
                fwprintf(stdout, L"TEST: Startup xcb client. dwc: %i\n", dwc);
                xcb_intern_atom_reply_t* test = (xcb_intern_atom_reply_t*) dwc;
                fwprintf(stdout, L"TEST: Startup xcb client. test: %i\n", test);
                fwprintf(stdout, L"TEST: Startup xcb client. (*test).atom: %i\n", (*test).atom);
*/

                //?? TODO: REMOVE, since the window is now stored in the client list
                // Store window in input/output entry.
                //?? set_io_entry_element(p0, (void*) &w, (void*) WINDOW_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
                // Store graphic context in input/output entry.
                //?? set_io_entry_element(p0, (void*) &gc, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
                // Store font in input/output entry.
                //?? set_io_entry_element(p0, (void*) &f, (void*) FONT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
                // Store delete window cookie in input/output entry.
                //?? set_io_entry_element(p0, (void*) &dwc, (void*) DELETE_WINDOW_COOKIE_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup xcb client. The screen is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup xcb client. The setup is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup xcb client. The connexion is null.");
    }
}

/* CLIENT_XCB_STARTER_SOURCE */
#endif
