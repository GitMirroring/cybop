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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_STARTER_SOURCE
#define X_WINDOW_SYSTEM_STARTER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/x_window_system_type_size.c"

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

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get connexion.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only establish connexion if not existent.
    if (c == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup x window system.");

/*??
        // The default colourmap id.
        // For allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The background pixel values.
        void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The foreground pixel values.
        void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The font name.
        void* fn = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The font.
        void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The font id.
//??        int fid = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The size hint.
        XSizeHints sh;
        // The colours.
        XColor gray;
        XColor light_gray;
        XColor vlight_gray;
        XColor dark_gray;
*/

        // Allocate x window system internals.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
/*??
        allocate_array((void*) &cm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &bg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &fg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &vm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
//??        v = malloc(*XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE);
*/

fwprintf(stdout, L"TEST startup x window system c: %i\n", c);

        // Allocate and open connexion.
        // CAUTION! Do NOT allocate the connexion manually here.
        // The xcb_connection_t is a structure containing
        // all data needed to communicate with an x server.
        c = (void*) xcb_connect(NULL, NULL);

        if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get setup.
            const xcb_setup_t* setup = xcb_get_setup((xcb_connection_t*) c);

            if (setup != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Get screen iterator.
                xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);

                // Get first screen.
                // CAUTION! Do NOT allocate the screen manually here.
                // It gets allocated through the connexion above.
                void* s = (void*) iter.data;

                if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST startup x window system s: %i\n", s);

                    // The window.
                    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
                    // The graphic context.
                    void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;

                    // Allocate window.
                    allocate_array((void*) &w, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
                    // Allocate graphic context.
                    allocate_array((void*) &gc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

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
                    // CAUTION! They have to be in the
                    // SAME ORDER as given in the mask above.
                    uint32_t wv[2];
                    // The graphic context values.
                    // CAUTION! They have to be in the
                    // SAME ORDER as given in the mask above.
                    uint32_t gcv[2];

                    // CAUTION! Initialise values BEFORE using
                    // them in function calls further below.
                    // Otherwise, drawing errors will occur.

                    // Initialise window background.
                    wv[0] = (*((xcb_screen_t*) s)).white_pixel;
                    // Register for all possible event types.
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

                    // Initialise graphic context values.
                    gcv[0] = (*((xcb_screen_t*) s)).black_pixel;
                    gcv[1] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
/*??
                    gcv[0] = (*((xcb_screen_t*) s)).white_pixel;
                    gcv[1] = (*((xcb_screen_t*) s)).black_pixel;
//??                    gcv[2] = font;
*/

                    // Allocate xid for window.
                    *((int*) w) = (int) xcb_generate_id((xcb_connection_t*) c);
                    // Allocate xid for graphic context.
                    *((int*) gc) = (int) xcb_generate_id((xcb_connection_t*) c);

                    // Create window.
                    xcb_create_window((xcb_connection_t*) c, // connexion
                        XCB_COPY_FROM_PARENT, // depth (same as root)
                        (xcb_window_t) *((int*) w), // window id
                        (*((xcb_screen_t*) s)).root, // parent window
                        0, 0, // x, y
                        150, 150, // width, height
                        10, // border_width
                        XCB_WINDOW_CLASS_INPUT_OUTPUT, // class
                        (*((xcb_screen_t*) s)).root_visual, // visual
                        wm, wv); // mask and values

                    // Create graphic context.
                    //
                    // CAUTION! It is possible to use more than one
                    // graphical context with a single window,
                    // in order to draw in multiple styles
                    // (different colors, different line widths etc).
                    //
                    // However, just ONE graphic context suffices here,
                    // since its styles gets updated as needed
                    // with each new send / serialise gui function call.
                    //
                    // CAUTION! The last parametre has to be a pointer,
                    // and it already IS one, since it is an array.
                    xcb_create_gc((xcb_connection_t*) c, (xcb_gcontext_t) *((int*) gc), (xcb_drawable_t) *((int*) w), gcm, gcv);

            /*??
                    *((int*) cm) = XDefaultColormap((struct _XDisplay*) d, *((int*) sn));
                    *((unsigned long*) bg) = XWhitePixel((struct _XDisplay*) d, *((int*) sn));
                    *((unsigned long*) fg) = XBlackPixel((struct _XDisplay*) d, *((int*) sn));
            /*??
                    fn = (void*) "*-helvetica-*-12-*";
                    f = (void*) XLoadQueryFont((struct _XDisplay*) d, (char*) fn);

                    if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        fid = (*((XFontStruct*) f)).fid;
                    }
            */

            /*??
                    sh.x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    sh.y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    sh.width = *NUMBER_800_INTEGER_STATE_CYBOI_MODEL;
                    sh.height = *NUMBER_600_INTEGER_STATE_CYBOI_MODEL;
                    sh.flags = PPosition | PSize;
                    *((int*) w) = XCreateSimpleWindow(d, *((int*) r), sh.x, sh.y, sh.width, sh.height, *NUMBER_5_INTEGER_STATE_CYBOI_MODEL, *((unsigned long*) fg), *((unsigned long*) bg));
                    *((unsigned long*) vm) = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            //??        *((unsigned long*) vm) = GCCapStyle | GCJoinStyle;
            //??        *((XGCValues*) v) = CapButt | JoinBevel;

                    gray.red = 49125;
                    gray.green = 49125;
                    gray.blue = 49125;
                    light_gray.red = 56000;
                    light_gray.green = 58000;
                    light_gray.blue = 60000;
                    vlight_gray.red = 60000;
                    vlight_gray.green = 61000;
                    vlight_gray.blue = 62000;
                    dark_gray.red = 32768;
                    dark_gray.green = 32768;
                    dark_gray.blue = 32768;

/*??
                    // Assign x window system internals.
                    XSetStandardProperties((struct _XDisplay*) d, *((int*) w), "Application", "Icon", None, *NULL_POINTER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &sh);
                    XAllocColor((struct _XDisplay*) d, *((int*) cm), &gray);
                    XAllocColor((struct _XDisplay*) d, *((int*) cm), &light_gray);
                    XAllocColor((struct _XDisplay*) d, *((int*) cm), &vlight_gray);
                    XAllocColor((struct _XDisplay*) d, *((int*) cm), &dark_gray);
            //??        XSetFont((struct _XDisplay*) d, (struct _XGC*) gc, fi);
*/

                    // Store x window system items in internal memory.
                    // CAUTION! Do NOT use "overwrite_array" function here,
                    // since it adapts the array count and size.
                    // But the internal array's count and size are CONSTANT.
                    copy_array_forward(p0, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CONNEXION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SCREEN_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    // CAUTION! The xcb_window_t type is defined as follows:
                    // typedef uint32_t xcb_window_t;
                    copy_array_forward(p0, (void*) &w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    // CAUTION! The xcb_gcontext_t type is defined as follows:
                    // typedef uint32_t xcb_gcontext_t;
                    copy_array_forward(p0, (void*) &gc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
//??                        copy_array_forward(p0, (void*) &cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) COLOUR_MAP_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The screen is null.");
                }

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The setup is null.");
            }

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The connexion is null.");
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The x window system is already running.");
    }
}

/* X_WINDOW_SYSTEM_STARTER_SOURCE */
#endif
