/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <xcb/xcb.h>
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Closes down the window with the given identification.
 *
 * @param p0 the window identification
 * @param p1 the client entry
 */
void close_xcb(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* w = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close xcb.");
        //?? fwprintf(stdout, L"Debug: Close xcb. w: %i\n", w);
        //?? fwprintf(stdout, L"Debug: Close xcb. *w: %i\n", *w);

        // The server entry.
        void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The connexion.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The delete window cookie.
        void* dwc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get server entry from client entry.
        copy_array_forward((void*) &se, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME);

        // Get connexion from server entry.
        copy_array_forward((void*) &c, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);
        // Get delete window cookie from server entry.
        //?? copy_array_forward((void*) &dwc, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DELETE_WINDOW_COOKIE_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);

        if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // A display DOES exist in server entry.
            //

            // Cast connexion to correct type.
            xcb_connection_t* ct = (xcb_connection_t*) c;
            // Cast window id to correct type.
            xcb_window_t wt = *w;

/*??
            if (dwc != *NULL_POINTER_STATE_CYBOI_MODEL) {

                fwprintf(stdout, L"Debug: Close xcb. pre dwc: %i\n", dwc);
                // Free delete window cookie atom reply that was created at startup.
                free(dwc);
                fwprintf(stdout, L"Debug: Close xcb. post dwc: %i\n", dwc);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close xcb. The delete window cookie is null.");
                fwprintf(stdout, L"Debug: Could not close xcb. The delete window cookie is null. dwc: %i\n", dwc);
            }
*/

            // Destroy window.
            xcb_destroy_window(ct, wt);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close xcb. The display is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not close xcb. The window identification is null.");
    }
}
