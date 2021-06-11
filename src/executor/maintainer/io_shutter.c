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

#ifndef IO_SHUTTER_SOURCE
#define IO_SHUTTER_SOURCE

#include <threads.h>

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/internal_memory_getter.c"
#include "../../executor/accessor/setter/internal_memory_setter.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/maintainer/details_shutter.c"
#include "../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../logger/logger.c"

/**
 * Shuts down the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the socket port
 * @param p2 the channel
 * @param p3 the input/output base
 */
void shutdown_io(void* p0, void* p1, void* p2, void* p3) {

    //
    // CAUTION! This log message has been commented out
    // due to the large number of potential calls caused
    // by the the number of socket services (65536).
    // See file "shutdown_manager.c".
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown io.");

    // The service identification (id).
    int id = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Copy socket port to be used as service identification (id).
    //
    // CAUTION! The value gets copied ONLY if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //
    // In other words, the identification is ZERO BY DEFAULT.
    // Only for the socket channel, it gets replaced by the PORT number.
    //
    copy_integer((void*) &id, p1);

    //?? fwprintf(stdout, L"Test: Shutdown io. io base *p3: %i\n", *((int*) p3));
    //?? fwprintf(stdout, L"Test: Shutdown io. service id: %i\n", id);

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p0, p3, (void*) &id);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The input/output entry (service) DOES exist in internal memory.
        //

        //
        // Reset input/output entry.
        //
        // CAUTION! It is ESSENTIAL to assign NULL here,
        // since cyboi tests for null pointers and otherwise,
        // wild pointers would lead to memory corruption.
        //
        // CAUTION! Do NOT use the "modify_array" (overwrite) function,
        // since it adapts the array count and size.
        // But the internal memory array's count and size are CONSTANT.
        //
        // CAUTION! Hand over null as pointer reference NULL_POINTER_STATE_CYBOI_MODEL
        // and NOT as dereferenced pointer *NULL_POINTER_STATE_CYBOI_MODEL.
        //
        set_internal_memory_element(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, p3, (void*) &id);

        // Shutdown service details.
        shutdown_details(io, p2);

        // The mutex.
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get mutex from input/output entry.
        get_io_entry_element((void*) &m, io, (void*) MUTEX_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Reset mutex in input/output entry.
        set_io_entry_element(io, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) MUTEX_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Destroy mutex.
        mtx_destroy((mtx_t*) m);

        //
        // Deallocate mutex.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &m, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);
        //
        // Deallocate input/output entry.
        //
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        //
        deallocate_array((void*) &io, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);

    } else {

        //
        // CAUTION! This log message has been commented out
        // due to the large number of potential calls caused
        // by the the number of socket services (65536).
        // See file "shutdown_manager.c".
        //
        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown io. The input/output entry (service) is null, i.e. it does not exist in internal memory.");
    }
}

/* IO_SHUTTER_SOURCE */
#endif
