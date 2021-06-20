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

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/accessor/getter/internal_memory_getter.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks input/output entry data.
 *
 * @param p0 the irq flag
 * @param p1 the handler (pointer reference)
 * @param p2 the internal memory data
 * @param p3 the internal memory index (already initialised with input/output base)
 * @param p4 the input/output entry index
 */
void check_irq_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //
    // CAUTION! Do NOT log messages here, since checking runs in an endless loop.
    // Otherwise, the log file would be filled up with useless entries.
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check irq element.");
    //

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p2, p3, p4);

    //?? fwprintf(stdout, L"Test: Check irq element. io: %i\n", io);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // An input/output entry exists for the service.
        //

        // The enable flag.
        void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The enable flag comparison result.
        int er = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Get enable flag from input/output entry.
        copy_array_forward((void*) &e, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Compare enable flag.
        compare_integer_unequal((void*) &er, e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (er != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The enable flag is set.
            //

            fwprintf(stdout, L"Test: Check irq element. er: %i\n", er);

            // The interrupt request.
            void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The interrupt request comparison result.
            int ir = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // Get interrupt request from input/output entry.
            copy_array_forward((void*) &i, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
            // Compare interrupt request.
            compare_integer_unequal((void*) &ir, i, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (ir != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The interrupt request is set.
                //

                fwprintf(stdout, L"Test: Check irq element. ir: %i\n", ir);

                // Get handler from input/output entry.
                copy_array_forward(p1, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) HANDLER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

                //?? fwprintf(stdout, L"Test: Check irq element. handler p1: %i\n", p1);
                //?? fwprintf(stdout, L"Test: Check irq element. handler *p1: %i\n", *((void**) p1));

                // Set irq flag.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }
        }
    }
}

/* ELEMENT_IRQ_CHECKER_SOURCE */
#endif
