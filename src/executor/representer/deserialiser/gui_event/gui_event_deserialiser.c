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

#ifndef GUI_EVENT_DESERIALISER_SOURCE
#define GUI_EVENT_DESERIALISER_SOURCE

#include <stdlib.h> // free

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/internal_memory_getter.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/representer/deserialiser/gui_event/properties_gui_event_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the gui event.
 *
 * @param p0 the destination properties item
 * @param p1 the knowledge memory part (pointer reference)
 * @param p2 the stack memory item
 * @param p3 the internal memory data
 */
void deserialise_gui_event(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui event.");

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Get input/output entry from internal memory.
    //
    // CAUTION! The last argument is the service identification.
    // If it is null, then zero is assumed and the input/output base is used inside.
    //
    get_internal_memory_element((void*) &io, p3, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The input/output entry (service) DOES exist in internal memory.
        //

        // The event.
        void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Retrieve event from input/output entry.
        //
        // CAUTION! The file "wait_checker.c" polls for events in the main thread
        // and stores a found event in the input/output entry of the internal memory,
        // before it can be processed here.
        //
        // CAUTION! Do NOT use the "modify_array" (overwrite) function,
        // since it adapts the array count and size.
        // But the io array's count and size are CONSTANT.
        //
        // CAUTION! Hand over value as pointer REFERENCE.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //
        copy_array_forward((void*) &e, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

        //?? fwprintf(stdout, L"Test: Deserialise gui event. event e: %i\n", e);

        if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The destination properties item data, count.
            void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get destination properties item data, count.
            copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Process event.
            deserialise_gui_event_properties(d, c, p1, p2, p3, io, e);

            //
            // Reset event in input/output entry.
            //
            // CAUTION! This IS NECESSARY since otherwise,
            // the same old event would be processed again and again.
            //
            // CAUTION! Do NOT use the "modify_array" (overwrite) function,
            // since it adapts the array count and size.
            // But the io array's count and size are CONSTANT.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            // CAUTION! Hand over null as pointer reference NULL_POINTER_STATE_CYBOI_MODEL
            // and NOT as dereferenced pointer *NULL_POINTER_STATE_CYBOI_MODEL.
            //
            copy_array_forward(io, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            //
            // Deallocate event.
            //
            // CAUTION! Free memory only if event is NOT null.
            //
            // CAUTION! It HAS TO BE destroyed manually here, since for:
            // - linux: it gets created automatically inside the xcb library
            // - win32: it gets created manually as message using the type MSG
            //
            // However, in BOTH CASES they are just pointers and hence
            // NOT platform-specific and therefore may get freed here.
            //
            free(e);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise gui event. The event is null.");
            fwprintf(stdout, L"Error: Could not deserialise gui event. The event is null. e: %i\n", e);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise gui event. The input/output entry (service) is null, i.e. it does not exist in internal memory.");
        fwprintf(stdout, L"Error: Could not deserialise gui event. The input/output entry (service) is null, i.e. it does not exist in internal memory. io: %i\n", io);
    }
}

/* GUI_EVENT_DESERIALISER_SOURCE */
#endif
