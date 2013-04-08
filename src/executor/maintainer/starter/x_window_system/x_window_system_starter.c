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

#ifndef X_WINDOW_SYSTEM_STARTER_SOURCE
#define X_WINDOW_SYSTEM_STARTER_SOURCE

#ifdef WIN32
    #include <winsock2.h>
#endif
#include <xcb/xcb.h>

/*??
#include <X11/Xlib.h>
#include <X11/Xutil.h>
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
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

    // The connection.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get connection.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNECTION_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only establish connection if not existent.
    if (c == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup x window system.");

        // The screen.
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The window.
        void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The graphic context.
        // CAUTION! It is possible to use more than one
        // graphical context with a single window,
        // in order to draw in multiple styles
        // (different colors, different line widths etc).
        void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;
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
        // The menu graphic context.
        void* gc_menu = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The menu border top graphic context.
        void* gc_menu_border_top = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The menu border bottom graphic context.
        void* gc_menu_border_bottom = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The menu font graphic context.
        void* gc_menu_font = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The value mask.
        // It defines the attributes for the graphics context.
        // This argument is the bitwise inclusive OR of zero or more
        // of the valid graphic context component mask bits.
        void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The values for the attributes defined in the value mask.
        void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
*/

        // Allocate x window system internals.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_array((void*) &w, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &gc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
/*??
        allocate_array((void*) &cm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &bg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &fg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &vm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
//??        v = malloc(*XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE);
*/

        // Open connection.
        c = (void*) xcb_connect(NULL, NULL);

fwprintf(stdout, L"TEST startup x window system c: %i\n", c);

        // Get first screen.
        const xcb_setup_t* setup = xcb_get_setup((xcb_connection_t*) c);
        xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
        s = (void*) iter.data;

fwprintf(stdout, L"TEST startup x window system s: %i\n", s);

        // Define window background.
        uint32_t mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
//??        uint32_t values[2] = { ((xcb_screen_t*) s)->white_pixel, XCB_EVENT_MASK_EXPOSURE };
        uint32_t values[2];
        values[0] = ((xcb_screen_t*) s)->white_pixel;
        values[1] = XCB_EVENT_MASK_EXPOSURE;

        // Create window.
        xcb_window_t window = xcb_generate_id((xcb_connection_t*) c);
        xcb_create_window((xcb_connection_t*) c, // connection
            XCB_COPY_FROM_PARENT, // depth (same as root)
            window, // window id
            ((xcb_screen_t*) s)->root, // parent window
            0, 0, // x, y
            150, 150, // width, height
            10, // border_width
            XCB_WINDOW_CLASS_INPUT_OUTPUT, // class
            ((xcb_screen_t*) s)->root_visual, // visual
            mask, values); // masks
        // Store window identification in internal memory.
        // CAUTION! The xcb_window_t type is defined as follows:
        // typedef uint32_t xcb_window_t;
        // It may therefore be stored as integer pointer.
        *((int*) w) = window;

fwprintf(stdout, L"TEST startup x window system window: %i\n", window);

        // Create graphic context.
/*??
        xcb_gcontext_t gcontext = xcb_generate_id((xcb_connection_t*) c);
        uint32_t mask = XCB_GC_FOREGROUND;
        uint32_t value[] = { ((xcb_screen_t*) s)->black_pixel };
        xcb_create_gc((xcb_connection_t*) c, gcontext, window, mask, value);
*/
        // Store graphic context identification in internal memory.
        // CAUTION! The xcb_gcontext_t type is defined as follows:
        // typedef uint32_t xcb_gcontext_t;
        // It may therefore be stored as integer pointer.
//??        *((int*) gc) = gcontext;

//?? fwprintf(stdout, L"TEST startup x window system gcontext: %i\n", gcontext);

/*??
        *((int*) cm) = XDefaultColormap((struct _XDisplay*) d, *((int*) sn));
        *((unsigned long*) bg) = XWhitePixel((struct _XDisplay*) d, *((int*) sn));
        *((unsigned long*) fg) = XBlackPixel((struct _XDisplay*) d, *((int*) sn));
/*??
        fn = (void*) "*-helvetica-*-12-*";
        f = (void*) XLoadQueryFont((struct _XDisplay*) d, (char*) fn);

        if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            fid = ((XFontStruct*) f)->fid;
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
        gc_menu = (void*) XCreateGC(d, *((int*) w), *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        gc_menu_border_top = (void*) XCreateGC(d, *((int*) w), *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        gc_menu_border_bottom = (void*) XCreateGC(d, *((int*) w), *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        gc_menu_font = (void*) XCreateGC(d, *((int*) w), *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
*/

/*??
        // Assign x window system internals.
        XSetStandardProperties((struct _XDisplay*) d, *((int*) w), "Application", "Icon", None, *NULL_POINTER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &sh);
        XAllocColor((struct _XDisplay*) d, *((int*) cm), &gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cm), &light_gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cm), &vlight_gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cm), &dark_gray);
/*??
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu, *((unsigned long*) bg));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu, light_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_top, *((unsigned long*) bg));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_top, vlight_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_bottom, *((unsigned long*) bg));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_bottom, dark_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_font, light_gray.pixel);
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_font, *((unsigned long*) fg));
*/
/*??
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc, *((unsigned long*) bg));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc, *((unsigned long*) fg));
//??        XSetFont((struct _XDisplay*) d, (struct _XGC*) gc, fi);
*/

        // Set x window system items.
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the internal array's count and size are CONSTANT.
        copy_array_forward(p0, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CONNECTION_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SCREEN_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WINDOW_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &gc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
/*??
        copy_array_forward(p0, (void*) &cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) COLOUR_MAP_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BACKGROUND_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FOREGROUND_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &gc_menu_border_bottom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BOTTOM_BORDER_MENU_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_MASK_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUES_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
*/

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The x window system is already running.");
    }
}

/* X_WINDOW_SYSTEM_STARTER_SOURCE */
#endif
