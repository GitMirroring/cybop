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

#ifndef INTERRUPT_SOURCE
#define INTERRUPT_SOURCE

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Interrupts a service.
 *
 * Expected parametres:
 * - service (required): the service to be interrupted (terminal, www, x_window_system etc.)
 *
 * @param p0 the parametres array (signal/ operation part properties with pointers referencing parts)
 * @param p1 the parametres array count
 */
void apply_interrupt(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply interrupt.");

    // The service part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service part model.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service part model data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get service part.
    get_part_knowledge((void*) &s, p0, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME, (void*) SERVICE_LIFECYCLE_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get service part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get service part model data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, (void*) *smd, (void*) TERMINAL_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            interrupt_thread((void*) TERMINAL_THREAD, (void*) TERMINAL_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, (void*) *smd, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            interrupt_thread((void*) X_WINDOW_SYSTEM_THREAD, (void*) X_WINDOW_SYSTEM_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, (void*) *smd, (void*) WWW_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            interrupt_thread((void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, (void*) *smd, (void*) CYBOI_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            interrupt_thread((void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply interrupt. The service is unknown.");
    }
}

/* INTERRUPT_SOURCE */
#endif
