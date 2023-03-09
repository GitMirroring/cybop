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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef XCB_SHUTTER_SOURCE
#define XCB_SHUTTER_SOURCE

#include <xcb/xcb.h> // xcb_disconnect, xcb_connection_t, xcb_gcontext_t etc.

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the x window system connexion.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the server entry
 */
void shutdown_xcb(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown xcb.");
    //?? fwprintf(stdout, L"Debug: Shutdown xcb. p0: %i\n", p0);

    //
    // Declaration
    //

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The graphic context.
    void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get connexion from server entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);
    // Get graphic context from server entry.
    copy_array_forward((void*) &gc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A display DOES exist in server entry.
        //

        // Cast connexion to correct type.
        xcb_connection_t* ct = (xcb_connection_t*) c;

        //
        // Finalisation
        //
        // CAUTION! Resetting the values is not necessary,
        // since the server entry gets deallocated anyway.
        //

        //
        // Deallocation
        //
        // CAUTION! Use descending order as compared to startup.
        //

        if (gc != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Shutdown xcb. inside gc: %i\n", gc);

            //
            // Cast graphic context to integer.
            //
            // CAUTION! The graphic context is defined as:
            // typedef uint32_t xcb_gcontext_t;
            //
            // CAUTION! Dereference value ONLY VIA uint32_t
            // and do NOT dereference xcb_gcontext_t value directly
            // as shown in the following example, since it is
            // leading to a memory segmentation fault:
            //
            // xcb_gcontext_t* gct = (xcb_gcontext_t*) gc;
            // ... *gct ...
            //
            uint32_t* gci = (uint32_t*) gc;
            //?? fwprintf(stdout, L"Debug: Shutdown xcb. gci: %i\n", gci);
            //?? fwprintf(stdout, L"Debug: Shutdown xcb. *gci: %i\n", *gci);
            // Cast graphic context to correct type.
            xcb_gcontext_t gct = (xcb_gcontext_t) *gci;
            //?? fwprintf(stdout, L"Debug: Shutdown xcb. free gct: %i\n", gct);
            // Free graphic context.
            xcb_free_gc(ct, gct);
            //?? fwprintf(stdout, L"Debug: Shutdown xcb. post free gct: %i\n", gct);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown xcb. The graphic context is null.");
            fwprintf(stdout, L"Warning: Could not shutdown xcb. The graphic context is null. gc: %i\n", gc);
        }

        //
        // Deallocate graphic context.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &gc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

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
        xcb_disconnect(ct);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown xcb. The connexion is null.");
        fwprintf(stdout, L"Warning: Could not shutdown xcb. The connexion is null. c: %i\n", c);
    }
}

/* XCB_SHUTTER_SOURCE */
#endif
