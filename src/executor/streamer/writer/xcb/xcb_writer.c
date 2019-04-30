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

#ifndef XCB_WRITER_SOURCE
#define XCB_WRITER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
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

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write xcb.");

    // The internal memory index.
    int i = *DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME;
    // The display input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get display input/output entry from internal memory.
    copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

//??    fwprintf(stdout, L"TEST Write xcb io: %i\n", io);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // A display DOES exist in internal memory.

        // The connexion.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The window.
        int w = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

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
        // Retrieve window from input/output entry.
        get_io_entry_element((void*) &w, io, (void*) WINDOW_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // CAUTION! This test is necessary to avoid a "Segmentation fault"!
        if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // CAUTION! This test is necessary to avoid a "Segmentation fault"!
            if (w != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

//??                fwprintf(stdout, L"TEST Write xcb: %i\n", w);

                // Use xcb connexion type.
                xcb_connection_t* connexion = (xcb_connection_t*) c;
                // Use xcb window type.
                xcb_window_t window = w;

                // Map window on the screen, in order to make it visible.
                xcb_map_window(connexion, window);

                // Make sure all pending requests to the x server are sent.
                // This is similar to "fflush" used for standard terminal output.
                xcb_flush(connexion);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write xcb. The window is null.");

                fwprintf(stdout, L"Error: Could not write xcb. The window is null. w: %i\n", w);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write xcb. The connexion is null.");

            fwprintf(stdout, L"Error: Could not write xcb. The connexion is null. c: %i\n", c);
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write xcb. There is no input/output x window system entry in the internal memory.");

        fwprintf(stdout, L"Error: Could not write xcb. There is no input/output x window system entry in the internal memory. io: %i\n", io);
    }
}

/* XCB_WRITER_SOURCE */
#endif
