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

#ifndef IO_STARTER_SOURCE
#define IO_STARTER_SOURCE

#include <threads.h>

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/setter/internal_memory_setter.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../logger/logger.c"
#include "../../variable/symbolic_name/mutex_thread_symbolic_name.c"

/**
 * Retrieves or allocates the input/output entry of the given service.
 *
 * @param p0 the input/output entry (pointer reference)
 * @param p1 the internal memory data
 * @param p2 the input/output base
 * @param p3 the socket port
 */
void startup_io(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** io = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup io.");

        if (*io == *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // The input/output entry (service) does NOT yet exist in internal memory.
            //

            // The mutex.
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

            //
            // Allocate input/output entry.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array(p0, (void*) IO_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
            //
            // Allocate mutex.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &m, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);

            // Create and initialise mutex.
            mtx_init((mtx_t*) m, *PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME);

            // Set mutex in input/output entry.
            copy_array_forward(*io, (void*) &m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Set input/output entry.
            set_internal_memory_element(p1, p0, p2, p3);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup io. The input/output entry (service) is not null, i.e. it does already exist in internal memory.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup io. The input/output entry is null.");
    }
}

/* IO_STARTER_SOURCE */
#endif
