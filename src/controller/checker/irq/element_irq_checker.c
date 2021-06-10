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

#ifndef ELEMENT_IRQ_CHECKER_SOURCE
#define ELEMENT_IRQ_CHECKER_SOURCE

#include <threads.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks input/output entry data.
 *
 * @param p0 the comparison result
 * @param p1 the interrupt request
 * @param p2 the handler (pointer reference)
 * @param p3 the internal memory data
 * @param p4 the internal memory index (already initialised with input/output base)
 * @param p5 the input/output entry index
 * @param p6 the break flag
 */
void check_irq_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! Do NOT log messages here, since checking runs in an endless loop.
    // Otherwise, the log file would be filled up with useless entries.
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check irq element.");
    //

    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Calculate internal memory index.
    calculate_integer_add((void*) &i, p4);
    calculate_integer_add((void*) &i, p5);

    //?? fwprintf(stdout, L"Test: Check irq element. index i: %i\n", i);

    // Get input/output entry.
    copy_array_forward((void*) &io, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // An input/output entry exists for the service
        // at the calculated internal memory index.
        //

        //?? fwprintf(stdout, L"TEST Check irq element. io_entry: %i\n", io);

        //
        // Retrieve various values from input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Hand over values as pointer REFERENCE.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //

        // The enable flag.
        int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Get enable flag from input/output entry.
        get_io_entry_element((void*) &e, io, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);

        if (e != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The enable flag is set.
            //

            //?? fwprintf(stdout, L"Test: Check irq element. enable_flag e: %i\n", e);

            // The interrupt request.
            int irq = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // Get interrupt request from input/output entry.
            get_io_entry_element((void*) &irq, io, (void*) INTERRUPT_REQUEST_INPUT_OUTPUT_STATE_CYBOI_NAME);

            if (irq != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The interrupt request is set.
                //

                //?? fwprintf(stdout, L"Test: Check irq element. irq: %i\n", irq);

                // The mutex.
                void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

                // Get mutex from input/output entry.
                get_io_entry_element((void*) &m, io, (void*) MUTEX_INPUT_OUTPUT_STATE_CYBOI_NAME);

                if (m != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    //
                    // Block current thread until the mutex is locked.
                    //
                    // CAUTION! This guarantees exclusive access to
                    // input/output resources as well as the interrupt flag,
                    // which are shared between input sensing (child) threads
                    // and this main (parent) thread.
                    //
                    // CAUTION! Not all input/output channels use sensing threads.
                    // Sometimes, the main thread is the only one accessing resources.
                    // However, in order to have a uniform implementation,
                    // a mutex exists for all channels and it does no harm
                    // to lock it here even if only the main thread accesses it.
                    //
                    mtx_lock((mtx_t*) m);

                    // Reset interrupt request in input/output entry.
                    set_io_entry_element(io, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INTERRUPT_REQUEST_INPUT_OUTPUT_STATE_CYBOI_NAME);

                    // Unlock mutex.
                    mtx_unlock((mtx_t*) m);

                    // Get handler from input/output entry.
                    get_io_entry_element(p2, io, (void*) HANDLER_INPUT_OUTPUT_STATE_CYBOI_NAME);

                    //?? fwprintf(stdout, L"Test: Check irq element. handler *p2: %i\n", *((void**) p2));

                    // Set comparison result.
                    copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    // Set interrupt request.
                    copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    // Set break flag.
                    copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check irq element. The mutex is null.");
                    fwprintf(stdout, L"Error: Could not check irq element. The mutex is null. m: %i\n", m);
                }
            }
        }
    }
}

/* ELEMENT_IRQ_CHECKER_SOURCE */
#endif
