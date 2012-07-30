/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTERRUPT_CHECKER_SOURCE
#define INTERRUPT_CHECKER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Checks input channels for interrupt requests.
 *
 * Example input channels:
 * - signal memory
 * - terminal
 * - x window system
 * - socket
 *
 * The "handler" is an operation encapsulated as part, which is
 * to be forwarded as signal to be processed normally in the system.
 *
 * @param p0 the interrupt (pointer reference)
 * @param p1 the mutex (pointer reference)
 * @param p2 the handler (pointer reference)
 * @param p3 the internal memory data
 */
void check_interrupt(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** irq = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check for interrupt requests.");

        // The internal memory index.
        int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // CAUTION! The boolean logic expressions below ARE NECESSARY for comparison, because:
        // - first case: irq is null which means that NO OTHER irq has been checked before
        // - second case: irq is not null which means some other irq has been retrieved from
        //   internal memory and checked before, BUT its value is false anyway (irq not set)
        //
        // In both cases, this interrupt is retrieved and checked.
        // Otherwise, if an irq was retrieved AND its value is not false (irq is set),
        // this and further interrupts are NOT checked.

/*??
        if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detected signal memory interrupt.");

            // Get signal memory interrupt request, mutex, handler.
            copy_array_forward(p0, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p1, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

            // CAUTION! A handler is NOT set in the case of a signal memory interrupt.

//?? fwprintf(stdout, L"TEST detected signal memory irq: %i\n", *((int*) *irq));
        }
*/

        if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detected terminal interrupt.");

            // Get terminal interrupt request, mutex, handler.
            copy_array_forward(p0, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p1, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p2, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLER_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

//?? fwprintf(stdout, L"TEST detected terminal irq: %i\n", *((int*) *irq));
        }

        if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detected x window system interrupt.");

            // Get x window system interrupt request, mutex, handler.
            copy_array_forward(p0, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p1, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p2, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLER_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);

//?? fwprintf(stdout, L"TEST detected x window system irq: %i\n", *((int*) *irq));
        }

        if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detected www service interrupt.");

            // Get www service interrupt request.
            copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) INTERRUPT_REQUEST_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p0, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get www service mutex.
            copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) MUTEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p1, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get www service handler.
            copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) HANDLER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p2, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

//?? fwprintf(stdout, L"TEST detected www service irq: %i\n", *((int*) *irq));
        }

        if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detected cyboi service interrupt.");

            // Get cyboi service interrupt request.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) INTERRUPT_REQUEST_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p0, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get cyboi service mutex.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) MUTEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p1, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
            // Get cyboi service handler.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) HANDLER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p2, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

//?? fwprintf(stdout, L"TEST detected cyboi service irq: %i\n", *((int*) *irq));
        }

        if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check for interrupt requests. No interrupt request is set.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check for interrupt requests. The interrupt request is null.");
    }
}

/* INTERRUPT_CHECKER_SOURCE */
#endif
