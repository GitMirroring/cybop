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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_STARTER_SOURCE
#define X_WINDOW_SYSTEM_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/x_window_system_type_size.c"

/**
 * Starts up the x window system.
 *
 * @param p0 the internal memory data
 */
void startup_x_window_system(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup x window system.");

    //
    // CAUTION! The x window system uses a number of synonymous types:
    // Display* == struct _XDisplay*
    // GC == struct _XGC*
    // Window == int
    // Colormap == int
    // Font (ID) == int
    //
    // CYBOI works with the real types, i.e. those on the right-hand side.
    //

    // The display.
    // It is a subsumption of xserver, screens, hardware (input devices etc.).
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get display.
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DISPLAY_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only create display if not existent.
    if (d == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.org would be:
        // char* dn = "earth.cybop.org:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        void* dn = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The screen number item.
        void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The screen.
//??        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The default colourmap id item.
        // For allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The background pixel values item.
        void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The foreground pixel values item.
        void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The top-level root window item.
        // For the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
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
        // The window item.
        void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The value mask item.
        // It defines the attributes for the graphics context.
        // This argument is the bitwise inclusive OR of zero or more
        // of the valid graphic context component mask bits.
        void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The values for the attributes defined in the value mask.
        void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The graphic context.
        // Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // The x window system item data, count.
//??        void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
//??        void* dnd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* snd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* bgd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* fgd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* wd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* vmd = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate x window system items.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        // CAUTION! Use "item" and not just "array" here,
        // since its count and size are needed for deallocation.
        allocate_item((void*) &sn, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &cm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &bg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &fg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &r, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &w, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &vm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
//??        v = malloc(*XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE);

        // Get x window system items data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &snd, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &bgd, bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &fgd, fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &wd, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &vmd, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Initialise x window system internals.
        dn = (void*) "";
        d = (void*) XOpenDisplay((char*) dn);
        *((int*) snd) = DefaultScreen((struct _XDisplay*) d);
//??        s = (void*) XScreenOfDisplay(*((struct _XDisplay*) d), *((int*) sn));
        *((int*) cmd) = XDefaultColormap((struct _XDisplay*) d, *((int*) sn));
        *((unsigned long*) bgd) = XWhitePixel((struct _XDisplay*) d, *((int*) sn));
        *((unsigned long*) fgd) = XBlackPixel((struct _XDisplay*) d, *((int*) sn));
        *((int*) rd) = DefaultRootWindow((struct _XDisplay*) d);
//??        *((int*) rd) = XRootWindowOfScreen(s);
/*??
        fn = (void*) "*-helvetica-*-12-*";
        f = (void*) XLoadQueryFont((struct _XDisplay*) d, (char*) fn);

        if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            fid = ((XFontStruct*) f)->fid;
        }
*/

        sh.x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        sh.y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        sh.width = *NUMBER_800_INTEGER_STATE_CYBOI_MODEL;
        sh.height = *NUMBER_600_INTEGER_STATE_CYBOI_MODEL;
        sh.flags = PPosition | PSize;
        *((int*) wd) = XCreateSimpleWindow(d, *((int*) r), sh.x, sh.y, sh.width, sh.height, *NUMBER_5_INTEGER_STATE_CYBOI_MODEL, *((unsigned long*) fg), *((unsigned long*) bg));
        *((unsigned long*) vmd) = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
//??        *((unsigned long*) vmd) = GCCapStyle | GCJoinStyle;
//??        *((XGCValues*) v) = CapButt | JoinBevel;
        gc = (void*) XCreateGC(d, *((int*) w), *((unsigned long*) vm), (XGCValues*) v);
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

        // Assign x window system internals.
        XSetStandardProperties((struct _XDisplay*) d, *((int*) wd), "Application", "Icon", None, *NULL_POINTER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &sh);
        XAllocColor((struct _XDisplay*) d, *((int*) cmd), &gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cmd), &light_gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cmd), &vlight_gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cmd), &dark_gray);
/*??
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu, *((unsigned long*) bgd));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu, light_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_top, *((unsigned long*) bgd));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_top, vlight_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_bottom, *((unsigned long*) bgd));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_bottom, dark_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_font, light_gray.pixel);
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_font, *((unsigned long*) fgd));
*/
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc, *((unsigned long*) bgd));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc, *((unsigned long*) fgd));
//??        XSetFont((struct _XDisplay*) d, (struct _XGC*) gc, fid);

        // Set x window system items.
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the internal array's count and size are CONSTANT.
        copy_array_forward(p0, (void*) &dn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DISPLAY_NAME_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DISPLAY_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SCREEN_NUMBER_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
//??        copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) COLOUR_MAP_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BACKGROUND_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FOREGROUND_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ROOT_WINDOW_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &gc_menu_border_bottom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BOTTOM_BORDER_MENU_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WINDOW_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_MASK_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUES_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &gc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The x window system is already running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* X_WINDOW_SYSTEM_STARTER_SOURCE */
#endif
