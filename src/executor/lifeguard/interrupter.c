/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPTER_SOURCE
#define INTERRUPTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Interrupts the service running at the given channel.
 *
 * @param p0 the internal memory data
 * @param p1 the channel
 */
void interrupt(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Interrupt.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The internal memory index.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The enable flag.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CYBOI_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The order of function calls is IMPORTANT!

            // Reset enable flag.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) ENABLE_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            copy_integer(e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Interrupt sensing thread.
            interrupt_thread((void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT);

            // Reset handler.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) HANDLER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The order of function calls is IMPORTANT!

            // Reset enable flag.
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_integer(e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Interrupt sensing thread.
//??            interrupt_thread((void*) DISPLAY_THREAD, (void*) DISPLAY_EXIT);

            // Reset handler.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SERIAL_PORT_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The order of function calls is IMPORTANT!

            // Reset enable flag.
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_integer(e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Interrupt sensing thread.
            interrupt_thread((void*) SERIAL_PORT_THREAD, (void*) SERIAL_PORT_EXIT);

            // Reset handler.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The order of function calls is IMPORTANT!

            // Reset enable flag.
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_integer(e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Interrupt sensing thread.
            interrupt_thread((void*) TERMINAL_THREAD, (void*) TERMINAL_EXIT);

            // Reset handler.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) WWW_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The order of function calls is IMPORTANT!

            // Reset enable flag.
            copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) ENABLE_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            copy_integer(e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Interrupt sensing thread.
            interrupt_thread((void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT);

            // Reset handler.
            // CAUTION! Assign NULL to the internal memory.
            // It is ESSENTIAL, since cyboi tests for null pointers.
            // Otherwise, wild pointers would lead to memory corruption.
            copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) HANDLER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not interrupt. The channel is unknown.");
    }
}

/* INTERRUPTER_SOURCE */
#endif
