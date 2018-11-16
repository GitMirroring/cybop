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

#ifndef DISPLAY_READER_SOURCE
#define DISPLAY_READER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../executor/maintainer/get_io_maintainer.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Reads display input event into destination.
 *
 * @param p0 the destination item
 * @param p1 the internal memory data
 * @param p2 the input/output base
 * @param p3 the service identification
 */
void read_display(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read display.");

    fwprintf(stdout, L"TEST: Read display. p2: %i \n", p2);
    fwprintf(stdout, L"TEST: Read display. *p2: %i \n", *((int*) p2));

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    maintain_io_get((void*) &io, p1, p2, p3);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The input/output entry (service) DOES exist in internal memory.

        // The event.
        void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Retrieve event from input/output entry.
        //
        // CAUTION! The file "wait_checker.c" polls for
        // events in the main thread and stores a found event
        // in internal memory, before it can be processed here.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Hand over value as pointer REFERENCE.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //
        get_io_entry_element((void*) &e, io, (void*) EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

        fwprintf(stdout, L"TEST: Read display. event e: %i \n", e);

        // Append event to destination item.
        modify_item(p0, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // Reset event in input/output entry.
        //
        // CAUTION! This IS NECESSARY since otherwise,
        // the same old event would be processed again and again.
        //
        // CAUTION! Do NOT use the "modify_array" (overwrite) function,
        // since it adapts the array count and size.
        // But the internal memory array's count and size are CONSTANT.
        //
        // CAUTION! Hand over null as pointer reference NULL_POINTER_STATE_CYBOI_MODEL
        // and NOT as dereferenced pointer *NULL_POINTER_STATE_CYBOI_MODEL.
        //
        set_io_entry_element(io, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read display. The input/output entry (service) is null, i.e. it does not exist in internal memory.");

        fwprintf(stdout, L"Error: Could not read display. The input/output entry (service) is null, i.e. it does not exist in internal memory. io: %i \n", io);
    }
}

/* DISPLAY_READER_SOURCE */
#endif
