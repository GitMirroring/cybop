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

#ifndef INITIAL_GUI_SERIALISER_SOURCE
#define INITIAL_GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../executor/copier/array_copier.c"
// CAUTION! Do NOT include the "content_element_part_gui_serialiser.c" module.
// It is true, the "serialise_gui_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
// Therefore, the "gui_serialiser.c" module is included here.
#include "../../../../executor/representer/serialiser/gui/gui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Initialises the gui serialiser.
 *
 * @param p0 the source model data
 * @param p1 the source model count
 * @param p2 the source properties data
 * @param p3 the source properties count
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 * @param p7 the format
 */
void serialise_gui_initial(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui initial.");

    // The internal memory index.
    int i = *DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME;
    // The display input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get display input/output entry from internal memory.
    copy_array_forward((void*) &io, p6, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

//??    fwprintf(stdout, L"TEST Serialise gui initial. io: %i\n", io);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // A display DOES exist in internal memory.

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
        // The win32 device context.
        int dc = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

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
        //?? get_io_entry_element((void*) &w, io, (void*) WINDOW_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Retrieve graphic context from input/output entry.
        //?? get_io_entry_element((void*) &gc, io, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Retrieve font from input/output entry.
        //?? get_io_entry_element((void*) &f, io, (void*) FONT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Retrieve win32 device context from input/output entry.
        //?? get_io_entry_element((void*) &dc, io, (void*) DEVICE_CONTEXT_WIN32_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

        serialise_gui_part_element_content(c, s, (void*) &w, (void*) &gc, (void*) &f, (void*) &dc, p0, p1, p2, p3, p4, p5, p6, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p7);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui initial. There is no input/output x window system entry in the internal memory.");
        fwprintf(stdout, L"Warning: Could not serialise gui initial. There is no input/output x window system entry in the internal memory. io: %i\n", io);
    }
}

/* INITIAL_GUI_SERIALISER_SOURCE */
#endif
