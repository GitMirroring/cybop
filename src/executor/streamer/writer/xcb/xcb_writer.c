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

#ifndef XCB_WRITER_SOURCE
#define XCB_WRITER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../logger/logger.c"

/**
 * Updates the xcb window.
 *
 * @param p0 the internal memory data
 */
void write_xcb(void* p0) {

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get connexion.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get window.
    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // CAUTION! This test is necessary to avoid a "Segmentation fault"!
    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! This test is necessary to avoid a "Segmentation fault"!
        if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write xcb.");

            // Use xcb type.
            xcb_window_t window = *((int*) w);

            // Map window on the screen, in order to make it visible.
            xcb_map_window((xcb_connection_t*) c, window);

            // Make sure all pending requests to the x server are sent.
            // This is similar to "fflush" used for standard terminal output.
            xcb_flush((xcb_connection_t*) c);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write xcb. The window is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write xcb. The connexion is null.");
    }
}

/* XCB_WRITER_SOURCE */
#endif
