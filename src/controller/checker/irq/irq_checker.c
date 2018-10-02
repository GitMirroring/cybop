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

#ifndef IRQ_CHECKER_SOURCE
#define IRQ_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../controller/checker/irq/all_irq_checker.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks input channels for interrupt requests.
 *
 * Example input channels:
 * - display
 * - serial port
 * - socket
 * - terminal
 *
 * The "handler" is an operation encapsulated as part, which is
 * to be forwarded as signal to be processed normally in the system.
 *
 * @param p0 the interrupt request
 * @param p1 the handler (pointer reference)
 * @param p2 the internal memory data
 * @param p3 the OLD interrupt request (pointer reference)
 * @param p4 the OLD mutex (pointer reference)
 */
void check_irq(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check irq.");

    fwprintf(stdout, L"TEST check irq p0: %i\n", p0);
    fwprintf(stdout, L"TEST check irq *p0: %i\n", *((int*) p0));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??        check_irq_all((void*) &r, p0, p1, p2, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??        check_irq_all((void*) &r, p0, p1, p2, (void*) SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??        check_irq_all((void*) &r, p0, p1, p2, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_65536_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_irq_all((void*) &r, p0, p1, p2, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

/*??
    //?? TODO: The following comparisons are OLD and to be deleted in the future.
    //
    // CAUTION! This comparison IS NECESSARY since otherwise, a possibly
    // already existing handler found above would get overwritten below.
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** irq = (void**) p3;

            //
            // CAUTION! The boolean logic expressions below ARE NECESSARY for comparison, because:
            // - first case: irq is null which means that NO OTHER irq has been checked before
            // - second case: irq is not null which means some other irq has been retrieved from
            //   internal memory and checked before, BUT its value is false anyway (irq not set)
            //
            // In both cases, this interrupt is retrieved and checked.
            // Otherwise, if an irq was retrieved AND its value is not false (irq is set),
            // this and further interrupts are NOT checked.
            //

/*??
            if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detected display interrupt.");

                // Get interrupt request, handler, mutex.
                copy_array_forward(p3, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
                copy_array_forward(p1, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLER_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
                copy_array_forward(p4, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

//??    fwprintf(stdout, L"TEST check irq display irq: %i\n", *((int*) *irq));
            }
*/

/*??
            if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detected serial interrupt.");

                // Get interrupt request, handler, mutex.
                copy_array_forward(p3, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
                copy_array_forward(p1, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLER_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
                copy_array_forward(p4, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

//??    fwprintf(stdout, L"TEST check irq serial irq: %i\n", *((int*) *irq));
            }

            //?? Socket already removed due to NEW solution above.

            if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detected terminal interrupt.");

                // Get interrupt request, handler, mutex.
                copy_array_forward(p3, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
                copy_array_forward(p1, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLER_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
                copy_array_forward(p4, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

//??    fwprintf(stdout, L"TEST check irq terminal irq: %i\n", *((int*) *irq));
            }

            if ((*irq == *NULL_POINTER_STATE_CYBOI_MODEL) || ((*irq != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) *irq) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check interrupt. No interrupt request was detected.");
                fwprintf(stdout, L"Warning: Could not check interrupt. No interrupt request was detected.\n");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check interrupt. The interrupt request is null.");
        }
    }
*/
}

/* IRQ_CHECKER_SOURCE */
#endif
