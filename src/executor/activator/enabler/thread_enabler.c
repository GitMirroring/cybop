/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef THREAD_ENABLER_SOURCE
#define THREAD_ENABLER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/activator/enabler/function_enabler.c"
#include "../../../executor/threader/spinner.c"
#include "../../../logger/logger.c"

/**
 * Prepares the enable thread.
 *
 * @param p0 the server entry
 */
void enable_thread(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable thread.");
    //?? fwprintf(stdout, L"Debug: Enable thread. channel p0: %i\n", p0);

    // The thread identification.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The thread function.
    void* f = (void*) &enable_function;

    // Get thread identification from server entry.
    copy_array_forward((void*) &t, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_INPUT_SERVER_STATE_CYBOI_NAME);

    // Invoke enable function WITHIN a new thread.
    spin(t, f, p0);
}

/* THREAD_ENABLER_SOURCE */
#endif
