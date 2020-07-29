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

#ifndef DEALLOCATE_IO_MAINTAINER_SOURCE
#define DEALLOCATE_IO_MAINTAINER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/io_entry_getter.c"
#include "../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../logger/logger.c"

/**
 * Deallocates the input/output entry and client list.
 *
 * @param p0 the input/output entry (pointer reference)
 */
void maintain_io_deallocate(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** io = (void**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Maintain io deallocate.");

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

        //
        // Retrieve client list item from input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Hand over value as pointer REFERENCE.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //
        get_io_entry_element((void*) &cl, *io, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

        //
        // Deallocate client list item.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_item((void*) &cl, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        //
        // Deallocate input/output entry.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not maintain io deallocate. The input/output entry is null.");
    }
}

/* DEALLOCATE_IO_MAINTAINER_SOURCE */
#endif
