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
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/setter/internal_memory_setter.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../logger/logger.c"

/**
 * Deallocates the input/output entry of the given service.
 *
 * @param p0 the input/output entry (pointer reference)
 * @param p1 the internal memory data
 * @param p2 the input/output base
 * @param p3 the socket port
 */
void shutdown_io(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** io = (void**) p0;

        //
        // CAUTION! This log message has been commented out
        // due to the large number of potential calls caused
        // by the the number of socket services (65536).
        // See file "shutdown_manager.c".
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown io.");

        if (*io != *NULL_POINTER_STATE_CYBOI_MODEL) {

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
            set_internal_memory_element(p1, (void*) NULL_POINTER_STATE_CYBOI_MODEL, p2, p3);

            // The enable flag.
            void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The mutex.
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The interrupt request.
            void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The sender identification.
            void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get enable flag from input/output entry.
            copy_array_forward((void*) &e, *io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);
            // Get mutex from input/output entry.
            copy_array_forward((void*) &m, *io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_INPUT_OUTPUT_STATE_CYBOI_NAME);
            // Get interrupt request from input/output entry.
            copy_array_forward((void*) &i, *io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_INPUT_OUTPUT_STATE_CYBOI_NAME);
            // Get sender identification from input/output entry.
            copy_array_forward((void*) &s, *io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SENDER_INPUT_OUTPUT_STATE_CYBOI_NAME);

            // Reset enable flag in input/output entry.
            copy_array_forward(*io, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Reset mutex in input/output entry.
            copy_array_forward(*io, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Reset interrupt request in input/output entry.
            copy_array_forward(*io, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTERRUPT_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Reset sender identification in input/output entry.
            copy_array_forward(*io, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SENDER_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // The mutex with casted type.
            mtx_t* mt = (mtx_t*) m;
            // Destroy mutex.
            mtx_destroy(mt);

            //
            // Deallocate enable flag.
            //
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            //
            deallocate_array((void*) &e, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            //
            // Deallocate mutex.
            //
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            //
            deallocate_array((void*) &m, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);
            //
            // Deallocate interrupt request.
            //
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            //
            deallocate_array((void*) &i, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            //
            // Deallocate sender identification.
            //
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            //
            deallocate_array((void*) &s, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            //
            // Deallocate input/output entry.
            //
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            //
            deallocate_array(p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) IO_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

        } else {

            //
            // CAUTION! This log message has been commented out
            // due to the large number of potential calls caused
            // by the the number of socket services (65536).
            // See file "shutdown_manager.c".
            //
            // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown io. The input/output entry value is null, i.e. it does not exist in internal memory.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown io. The input/output entry is null.");
    }
}

/* IO_SHUTTER_SOURCE */
#endif
