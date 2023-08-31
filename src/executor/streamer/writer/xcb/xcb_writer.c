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
 * @version CYBOP 0.27.0 2023-08-31
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
 * Updates the xcb window.
 *
 * @param p0 the destination window id
 * @param p1 the client entry
 */
void write_xcb(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* w = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write xcb.");
        //?? fwprintf(stdout, L"Debug: Write xcb. window id p0: %i\n", p0);
        //?? fwprintf(stdout, L"Debug: Write xcb. window id *p0: %i\n", *((int*) p0));
        //?? fwprintf(stdout, L"Debug: Write xcb. client entry p1: %i\n", p1);

        // The server entry.
        void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The connexion.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get server entry from client entry.
        copy_array_forward((void*) &se, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME);
        // Get connexion from server entry.
        copy_array_forward((void*) &c, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);

        // CAUTION! This test is necessary to avoid a "Segmentation fault"!
        if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // A display DOES exist in server entry.
            //

            // Cast connexion to correct type.
            xcb_connection_t* ct = (xcb_connection_t*) c;

            // CAUTION! This test is necessary to avoid a "Segmentation fault"!
            if (*w >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Cast window id to correct type.
                xcb_window_t wt = (xcb_window_t) *w;

                // Map window on the screen, in order to make it visible.
                xcb_map_window(ct, wt);

                //
                // Make sure all pending requests to the x server are sent.
                // This is similar to "fflush" used for standard terminal output.
                //
                xcb_flush(ct);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write xcb. The destination window id is negative.");
                fwprintf(stdout, L"Error: Could not write xcb. The destination window id is negative. *w: %i\n", *w);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write xcb. The connexion is null.");
            fwprintf(stdout, L"Error: Could not write xcb. The connexion is null. c: %i\n", c);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write xcb. The destination window id is null.");
        fwprintf(stdout, L"Error: Could not write xcb. The destination window id is null. p0: %i\n", p0);
    }
}
