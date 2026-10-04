/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "system.h"

/**
 * Sets the thread exit flag and sends an awaken message.
 *
 * @param p0 the client entry
 */
void suspend_thread(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Suspend thread.");
    //?? fwprintf(stdout, L"Debug: Suspend thread. p0: %i\n", p0);

    // The sense thread identification.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sense thread exit flag.
    void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get sense thread identification from server entry.
    copy_array_forward((void*) &t, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME);
    // Get sense thread exit flag from server entry.
    copy_array_forward((void*) &ex, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) EXIT_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME);

    // Set sense thread exit flag.
    copy_integer(ex, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // Awaken thread so that it can detect the exit flag set above.
    //
    // CAUTION! Mind the order. The exit flag has to be set FIRST
    // since otherwise, the fake input might be processed and be LOST,
    // if the exit flag were not found to be set before.
    //
    //?? awaken(io, p0, sense-flag-set[to-distinguish-from-sense-thread]);

    // Wait for thread to exit.
    cut(t);
}
