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

#ifndef X_WINDOW_SYSTEM_SHUTTER_SOURCE
#define X_WINDOW_SYSTEM_SHUTTER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the x window system.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 */
void shutdown_x_window_system(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown x window system.");

    // The internal memory index.
    int i = *DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME;
    // The display input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get display input/output entry from internal memory.
    copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    fwprintf(stdout, L"TEST shutdown x window system io: %i\n", io);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // A display DOES exist in internal memory.

        //
        // Reset input/output entry in internal memory to null.
        //
        // CAUTION! It is ESSENTIAL to assign NULL here,
        // since cyboi tests for null pointers and otherwise,
        // wild pointers would lead to memory corruption.
        //
        // CAUTION! Do NOT use the "modify_array" (overwrite) function,
        // since it adapts the array count and size.
        // But the internal memory array's count and size are CONSTANT.
        // Therefore, a simple "copy" function is used here.
        //
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

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
        // Retrieve various values from input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Hand over values as pointer REFERENCE.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //

        // Retrieve connexion from input/output entry.
        get_io_entry_element((void*) &c, io, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Retrieve screen from input/output entry.
        get_io_entry_element((void*) &s, io, (void*) SCREEN_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Retrieve window from input/output entry.
        get_io_entry_element((void*) &w, io, (void*) WINDOW_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Retrieve graphic context from input/output entry.
        get_io_entry_element((void*) &gc, io, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Retrieve font from input/output entry.
        get_io_entry_element((void*) &f, io, (void*) FONT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

        //
        // CAUTION! Use descending order as compared to startup,
        // for the following deallocations.
        //

        if (f != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

            //?? TODO: Is there anything to destroy?

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The font is null.");
        }

        if (gc != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

/*??
            // Use xcb type.
            xcb_gcontext_t gct = (xcb_gcontext_t) gc;
            xcb_destroy_??((xcb_connection_t*) c, gct);
*/

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The graphic context is null.");
        }

        if (w != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

            // Use xcb type.
            xcb_window_t wt = w;
            xcb_destroy_window((xcb_connection_t*) c, wt);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The window is null.");
        }

        //
        // CAUTION! Do NOT deallocate the screen manually here.
        // It was retrieved via the connexion and gets
        // deallocated automatically via the connexion below.
        //

        //
        // Close connexion.
        //
        // CAUTION! Do NOT deallocate the connexion manually here.
        // Nothing was allocated for the connexion at startup either.
        // The called function closes the file descriptor and
        // frees ALL memory associated with the connexion.
        //
        xcb_disconnect((xcb_connection_t*) c);

        //
        // Deallocate input/output entry.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &io, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. There is no input/output x window system entry in the internal memory.");
    }
}

/* X_WINDOW_SYSTEM_SHUTTER_SOURCE */
#endif
