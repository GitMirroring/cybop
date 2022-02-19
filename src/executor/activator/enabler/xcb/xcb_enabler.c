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

#ifndef XCB_ENABLER_SOURCE
#define XCB_ENABLER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/activator/enabler/xcb/buffer_xcb_enabler.c"
#include "../../../../executor/activator/enabler/xcb/client_xcb_enabler.c"
#include "../../../../executor/activator/enabler/xcb/event_xcb_enabler.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/finder/server_entry_finder.c"
#include "../../../../logger/logger.c"

/**
 * Enables x window system event delivery via xcb.
 *
 * @param p0 the sender client window identification
 * @param p1 the server entry
 */
void enable_xcb(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable xcb.");
    fwprintf(stdout, L"Debug: Enable xcb. window id p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Enable xcb. window id *p0: %i\n", *((int*) p0));

    // The x window system connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The event.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client window identification.
    int w = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The clients list.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item, mutex.
    void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get x window system connexion from server entry.
    copy_array_forward((void*) &c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);

    // Get next event from x window system via xcb connexion.
    enable_xcb_event((void*) &e, c);

    if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Get client window identification from event.
        enable_xcb_client((void*) &w, e);

        if (w >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Get server clients list from server entry.
            copy_array_forward((void*) &cl, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_CLIENTS_SERVER_STATE_CYBOI_NAME);

            // Get client entry from server clients list by device identification.
            find_list((void*) &ce, cl, (void*) &w, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);

            // Get input buffer item, mutex from client entry.
            copy_array_forward((void*) &bi, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);
            copy_array_forward((void*) &bm, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME);

            //
            // Write event to correct client buffer.
            //
            // CAUTION! Hand over event as pointer REFERENCE.
            //
            enable_xcb_buffer(bi, (void*) &e, bm);

            // Copy window identification to sender client identification.
            copy_integer(p0, (void*) &w);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb. The window identification is invalid.");
            fwprintf(stdout, L"Error: Could not enable xcb. The window identification is invalid. w: %i\n", w);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable xcb. The event is null. This indicates an input/output error.");
        fwprintf(stdout, L"Error: Could not enable xcb. The event is null. This indicates an input/output error. e: %i\n", e);
    }
}

/* XCB_ENABLER_SOURCE */
#endif
