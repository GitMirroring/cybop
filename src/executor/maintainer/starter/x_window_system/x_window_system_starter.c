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

#ifndef X_WINDOW_SYSTEM_STARTER_SOURCE
#define X_WINDOW_SYSTEM_STARTER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../logger/logger.c"

//
// The X.Org Foundation formed by X.Org and freedesktop.org
// has an oversight role in X Window System development.
// XFree86 is still being developed at a very slow pace,
// but the X.Org Foundation currently sets the standard.
//
// http://www.x.org/wiki/Documentation:
// For low-level X development, the X C Bindings (XCB)
// provide a clean low-level protocol binding:
// http://xcb.freedesktop.org/tutorial/
//
// Its older cousin Xlib (or libX11), is NOT recommended
// for new development, but is still very widely used.
// Xt is a similarly DEPRECATED library for building toolkits.
//

/**
 * Starts up the x window system.
 *
 * @param p0 the internal memory data
 */
void startup_x_window_system(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup x window system.");

    // The internal memory index.
    int i = *DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME;
    // The display input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get display input/output entry from internal memory.
    copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    if (io == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // A display does NOT yet exist in internal memory.

        //
        // CAUTION! The following variables are declared RIGHT HERE
        // and not only further down since otherwise,
        // they would not be known to the compiler when
        // being stored in input/output entry at the end.
        //

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

        //
        // Allocate and open connexion.
        //
        // CAUTION! Do NOT allocate the connexion manually here.
        // The xcb_connection_t is a structure containing
        // all data needed to communicate with an x server.
        //
        c = (void*) xcb_connect(NULL, NULL);

//??        fwprintf(stdout, L"TEST startup x window system c: %i\n", c);

        if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get setup.
            const xcb_setup_t* setup = xcb_get_setup((xcb_connection_t*) c);

//??            fwprintf(stdout, L"TEST startup x window system setup: %i\n", setup);

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

//??                fwprintf(stdout, L"TEST startup x window system s: %i\n", s);

                if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // The xcb screen type value.
                    xcb_screen_t* st = (xcb_screen_t*) s;

                    //
                    // The window value mask.
                    //
                    // CAUTION! It is possible to set several attributes
                    // at the same time by OR'ing these values in valuemask.
                    //
                    // The values that a mask could take are given
                    // by the "xcb_cw_t" enumeration:
                    //
                    // typedef enum {
                    //     XCB_CW_BACK_PIXMAP       = 1L<<0,
                    //     XCB_CW_BACK_PIXEL        = 1L<<1,
                    //     XCB_CW_BORDER_PIXMAP     = 1L<<2,
                    //     XCB_CW_BORDER_PIXEL      = 1L<<3,
                    //     XCB_CW_BIT_GRAVITY       = 1L<<4,
                    //     XCB_CW_WIN_GRAVITY       = 1L<<5,
                    //     XCB_CW_BACKING_STORE     = 1L<<6,
                    //     XCB_CW_BACKING_PLANES    = 1L<<7,
                    //     XCB_CW_BACKING_PIXEL     = 1L<<8,
                    //     XCB_CW_OVERRIDE_REDIRECT = 1L<<9,
                    //     XCB_CW_SAVE_UNDER        = 1L<<10,
                    //     XCB_CW_EVENT_MASK        = 1L<<11,
                    //     XCB_CW_DONT_PROPAGATE    = 1L<<12,
                    //     XCB_CW_COLORMAP          = 1L<<13,
                    //     XCB_CW_CURSOR            = 1L<<14
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
//??                        uint32_t gcm = XCB_GC_BACKGROUND | XCB_GC_FOREGROUND; //?? | XCB_GC_FONT;
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
                    wv[1] =
                        // Expose.
                        // - a window that covered part of the current window has moved away, exposing part (or all) of the current window
                        // - the current window was raised above other windows
                        // - the current window was mapped for the first time
                        // - the current window was de-iconified (to 'iconify' a window is to minimize it or send it to the tray such that it is not shown at all)
                        XCB_EVENT_MASK_EXPOSURE
                        // Mouse button press and release.
                        | XCB_EVENT_MASK_BUTTON_PRESS
                        | XCB_EVENT_MASK_BUTTON_RELEASE
                        // Mouse movement.
                        | XCB_EVENT_MASK_POINTER_MOTION // motion with no mouse button held
                        | XCB_EVENT_MASK_BUTTON_MOTION // motion with one or more of the mouse buttons held
                        | XCB_EVENT_MASK_BUTTON_1_MOTION // motion while only 1st mouse button is held
                        | XCB_EVENT_MASK_BUTTON_2_MOTION // and so on ...
                        | XCB_EVENT_MASK_BUTTON_3_MOTION
                        | XCB_EVENT_MASK_BUTTON_4_MOTION
                        | XCB_EVENT_MASK_BUTTON_5_MOTION
                        // Mouse pointer enter and leave.
                        | XCB_EVENT_MASK_ENTER_WINDOW
                        | XCB_EVENT_MASK_LEAVE_WINDOW
                        // Keyboard press and release (while focus is on window).
                        | XCB_EVENT_MASK_KEY_PRESS
                        | XCB_EVENT_MASK_KEY_RELEASE;

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
//??                    gcv[2] = font;
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

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The screen is null.");
                }

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The setup is null.");
            }

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The connexion is null.");
        }

        //
        // Allocate input/output entry.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &io, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);

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

        // Store connexion in input/output entry.
        set_io_entry_element(io, (void*) &c, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Store screen in input/output entry.
        set_io_entry_element(io, (void*) &s, (void*) SCREEN_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Store window in input/output entry.
        set_io_entry_element(io, (void*) &w, (void*) WINDOW_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Store graphic context in input/output entry.
        set_io_entry_element(io, (void*) &gc, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Store font in input/output entry.
        set_io_entry_element(io, (void*) &f, (void*) FONT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

        //
        // Store input/output entry in internal memory.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the internal array's count and size are CONSTANT.
        //
        // CAUTION! Hand over input/output entry as pointer REFERENCE.
        //
        copy_array_forward(p0, (void*) &io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The x window system already exists in internal memory.");
    }
}

/* X_WINDOW_SYSTEM_STARTER_SOURCE */
#endif
