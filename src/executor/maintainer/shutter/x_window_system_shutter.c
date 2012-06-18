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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SHUTTER_SOURCE
#define X_WINDOW_SYSTEM_SHUTTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../executor/lifeguard/interrupter/thread_interrupter.c"

/**
 * Shuts down the x window system.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_x_window_system(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown x window system.");

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
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only destroy display if existent.
    if (d != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Interrupt x window system service thread.
        interrupt_thread(p1, p2);

        // The display name.
        // An example identifying the second screen of the first
        // display of host computer earth.cybop.org would be:
        // char* dn = "earth.cybop.org:0.1"
        //?? TODO: This has to be built dynamically, later on!
        //?? For now, it is just an empty string.
        void* dn = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The screen number.
        void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The screen.
//??        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The default colourmap id for allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The background pixel values.
        void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The foreground pixel values.
        void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The top-level root window for the given display and screen.
        // This is sometimes called the root window of the window manager.
        // Remember, CYBOI itself IS the window manager.
        void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The menu border bottom graphic context.
        void* gc_menu_border_bottom = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The window.
        void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The value mask for the graphics context.
        // It defines the attributes for the graphics context.
        // This argument is the bitwise inclusive OR of zero or more
        // of the valid graphic context component mask bits.
        void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The values for the attributes defined in the value mask.
        void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The graphic context. Each graphic element needs one.
        // It can be used with any destination drawable (window or pixmap)
        // having the same root and depth as the specified drawable.
        // Use with other drawables results in a BadMatch error.
        void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get x window system internals.
        copy_array_forward((void*) &dn, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_DISPLAY_NAME_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sn, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_SCREEN_NUMBER_INTERNAL_MEMORY_STATE_CYBOI_NAME);
//??        copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_SCREEN_INTERNAL);
        copy_array_forward((void*) &cm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_COLOUR_MAP_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &bg, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_BACKGROUND_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &fg, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_FOREGROUND_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &r, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_ROOT_WINDOW_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &gc_menu_border_bottom, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_MENU_BORDER_BOTTOM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_WINDOW_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &vm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUE_MASK_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &v, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_VALUES_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &gc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) X_WINDOW_SYSTEM_GRAPHIC_CONTEXT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

/*??
        XFreeGC((struct _XDisplay*) d, (struct _XGC*) gc_menu_font);
        XFreeGC((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_bottom);
        XFreeGC((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_top);
        XFreeGC((struct _XDisplay*) d, (struct _XGC*) gc_menu);
*/

        // Free x window system internals.
//??        XFreeGC((struct _XDisplay*) d, (struct _XGC*) gc);

//??        XDestroyWindow((struct _XDisplay*) d, *((int*) w));

//??        XCloseDisplay((struct _XDisplay*) d);

        // Destroy x window system internals.
        // CAUTION! Use descending order!
        // Example: The values (v) are destroyed BEFORE the value mask (vm)
        // attributes, since v might still reference vm internally.
//??        free(v);
        deallocate((void*) &vm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        deallocate((void*) &w, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate((void*) &r, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate((void*) &fg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        deallocate((void*) &bg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        deallocate((void*) &cm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate((void*) &sn, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. There is no x window system running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* X_WINDOW_SYSTEM_SHUTTER_SOURCE */
#endif
