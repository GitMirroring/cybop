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

#ifndef ALLOCATE_IO_MAINTAINER_SOURCE
#define ALLOCATE_IO_MAINTAINER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/setter/io_entry_setter.c"
#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../logger/logger.c"

/**
 * Allocates the input/output entry with client list and timeout list.
 *
 * @param p0 the input/output entry (pointer reference)
 */
void maintain_io_allocate(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** io = (void**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Maintain io allocate.");

        //
        // The client list item.
        //
        // CAUTION! A client list IS needed here,
        // since the data sensing mechanism relies on it,
        // in order to apply a unified handling.
        //
        // This is so even though some services
        // such as display, serial port, terminal
        // need only ONE client,
        // as opposed to a socket with many possible clients.
        //
        void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The corresponding timeout list item.
        void* tl = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Allocate input/output entry.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);

        //
        // Allocate client list item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &cl, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        //
        // Allocate timeout list item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &tl, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // Store client list item in input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //
        // CAUTION! Hand over value as pointer REFERENCE.
        //
        set_io_entry_element(*io, (void*) &cl, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);
        //
        // Store timeout list item in input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //
        // CAUTION! Hand over value as pointer REFERENCE.
        //
        set_io_entry_element(*io, (void*) &tl, (void*) TIMEOUT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not maintain io allocate. The input/output entry is null.");
    }
}

/* ALLOCATE_IO_MAINTAINER_SOURCE */
#endif
