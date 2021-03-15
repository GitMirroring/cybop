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
#include "../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the x window system.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the input/output entry
 */
void shutdown_x_window_system(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown x window system.");

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
    // The delete window cookie.
    void* dwc = *NULL_POINTER_STATE_CYBOI_MODEL;

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
    get_io_entry_element((void*) &c, p0, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Retrieve screen from input/output entry.
    get_io_entry_element((void*) &s, p0, (void*) SCREEN_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Retrieve window from input/output entry.
    get_io_entry_element((void*) &w, p0, (void*) WINDOW_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Retrieve graphic context from input/output entry.
    get_io_entry_element((void*) &gc, p0, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Retrieve font from input/output entry.
    get_io_entry_element((void*) &f, p0, (void*) FONT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Retrieve delete window cookie from input/output entry.
    get_io_entry_element((void*) &dwc, p0, (void*) DELETE_WINDOW_COOKIE_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST shutdown x window system c: %i\n", c);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A display DOES exist in input/output entry.
        //

        //
        // CAUTION! Use descending order as compared to startup,
        // for the following deallocations.
        //

        if (dwc != *NULL_POINTER_STATE_CYBOI_MODEL) {

/*??
            fwprintf(stdout, L"TEST shutdown x window system before dwc: %i\n", dwc);
            // Free delete window cookie atom reply that was created at startup.
            free(dwc);
            fwprintf(stdout, L"TEST shutdown x window system after dwc: %i\n", dwc);
*/

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The delete window cookie is null.");
        }

        if (f != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

            //?? TODO: Is there anything to destroy?

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The font is null.");
        }

        if (gc != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

            // Use xcb type.
            xcb_gcontext_t gct = (xcb_gcontext_t) gc;
            // Free graphic context.
            xcb_free_gc((xcb_connection_t*) c, gct);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The graphic context is null.");
        }

        if (w != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

            // Use xcb type.
            xcb_window_t wt = w;
            // Destroy window.
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
        // Reset various values in input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //
        // CAUTION! Hand over values as pointer REFERENCE.
        //

        // Reset connexion in input/output entry.
        set_io_entry_element(p0, NULL_POINTER_STATE_CYBOI_MODEL, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Reset screen in input/output entry.
        set_io_entry_element(p0, NULL_POINTER_STATE_CYBOI_MODEL, (void*) SCREEN_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Reset window in input/output entry.
        set_io_entry_element(p0, NULL_POINTER_STATE_CYBOI_MODEL, (void*) WINDOW_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Reset graphic context in input/output entry.
        set_io_entry_element(p0, NULL_POINTER_STATE_CYBOI_MODEL, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Reset font in input/output entry.
        set_io_entry_element(p0, NULL_POINTER_STATE_CYBOI_MODEL, (void*) FONT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Reset delete window cookie in input/output entry.
        set_io_entry_element(p0, NULL_POINTER_STATE_CYBOI_MODEL, (void*) DELETE_WINDOW_COOKIE_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown x window system. The display is null.");
    }
}

/* X_WINDOW_SYSTEM_SHUTTER_SOURCE */
#endif
