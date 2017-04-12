/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SHUTTER_SOURCE
#define X_WINDOW_SYSTEM_SHUTTER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../logger/logger.c"

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

/*??
    // The internal memory index.
    int i = *DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME;
    // The socket io entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get socket io entry.
    copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST shutdown x window system io: %i\n", io);

        // Only deallocate socket resources if a socket exists.

        // Interrupt socket service thread.
        interrupt_thread(p1, p2);

        // Get connexion from io entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        get_io_entry_element((void*) &s, (void*) &io, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Close server socket.
        shutdown_socket_close((void*) &s);

        // Deallocate io entry.
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        deallocate_array((void*) &io, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);

        // Reset values.
        //
        // CAUTION! Assign NULL to the internal memory.
        // It is ESSENTIAL, since cyboi tests for null pointers.
        // Otherwise, wild pointers would lead to memory corruption.
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
*/

//?? TODO: -------------------------------

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get connexion.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only destroy connexion if existent.
    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Interrupt x window system service thread.
        interrupt_thread(p1, p2);

        // The screen.
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The window.
        void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The graphic context.
        void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The font.
        void* f = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get x window system internals.
        copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SCREEN_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &gc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        copy_array_forward((void*) &f, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FONT_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

        //
        // CAUTION! Use descending order as compared to startup,
        // for the following deallocations.
        //

        // Destroy font.
        if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            deallocate_array((void*) &f, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The font is null.");
        }

        // Destroy graphic context.
        if (gc != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Use xcb type.
/*??
            xcb_gcontext_t gct = *((int*) gc);
            xcb_destroy_??((xcb_connection_t*) c, gct);
*/

            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            deallocate_array((void*) &gc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The graphic context is null.");
        }

        // Destroy window.
        if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Use xcb type.
            xcb_window_t wt = *((int*) w);
            xcb_destroy_window((xcb_connection_t*) c, wt);

            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            deallocate_array((void*) &w, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The window is null.");
        }

        // CAUTION! Do NOT deallocate the screen manually here.
        // It was retrieved via the connexion and
        // gets deallocated via the connexion below.

        // Close connexion.
        // CAUTION! Do NOT deallocate the connexion manually here.
        // Nothing was allocated for the connexion at startup either.
        // The called function closes the file descriptor
        // and frees ALL memory associated with the connexion.
        xcb_disconnect((xcb_connection_t*) c);

        // Reset x window system internals.
        //
        // CAUTION! Assign NULL to the internal memory.
        // It is ESSENTIAL, since cyboi tests for null pointers.
        // Otherwise, wild pointers would lead to memory corruption.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the internal array's count and size are CONSTANT.
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CONNEXION_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SCREEN_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FONT_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. There is no x window system running.");
    }
}

/* X_WINDOW_SYSTEM_SHUTTER_SOURCE */
#endif
