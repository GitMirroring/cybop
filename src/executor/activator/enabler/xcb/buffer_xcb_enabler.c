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

#ifndef BUFFER_XCB_ENABLER_SOURCE
#define BUFFER_XCB_ENABLER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/porter/locker.c"
#include "../../../../executor/porter/unlocker.c"
#include "../../../../logger/logger.c"

/**
 * Writes window event to correct client buffer.
 *
 * @param p0 the destination buffer item
 * @param p1 the source event (pointer reference)
 * @param p2 the buffer mutex
 */
void enable_xcb_buffer(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT log messages, since there are too many.
    //
    //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable xcb buffer.");
    //?? fwprintf(stdout, L"Debug: Enable xcb buffer. source event p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Enable xcb buffer. source event *p1: %i\n", *((void**) p1));

    // Lock mutex.
    lock(p2);

    //
    // Store event in buffer.
    //
    // CAUTION! Do NOT use overwrite but rather APPEND, in order to
    // avoid deletion of previous events still existing in buffer.
    //
    modify_item(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Unlock mutex.
    unlock(p2);
}

/* BUFFER_XCB_ENABLER_SOURCE */
#endif
