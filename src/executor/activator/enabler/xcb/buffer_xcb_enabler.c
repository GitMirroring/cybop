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

#ifndef BUFFER_XCB_ENABLER_SOURCE
#define BUFFER_XCB_ENABLER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Writes event to correct client buffer.
 *
 * @param p0 the buffer item
 * @param p1 the event (pointer reference)
 * @param p2 the buffer mutex
 */
void enable_xcb_buffer(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    // CAUTION! Do NOT log messages since there are too many.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable xcb buffer.");
    fwprintf(stdout, L"Debug: Enable xcb buffer. p0: %i\n", p0);

    //
    // Lock mutex.
    //
    // CAUTION! Set this lock BEFORE comparing with the exit flag below
    // since otherwise, a race condition might occur.
    //
    // Example:
    // - the exit flag is not set
    // - the sensing child thread enters the block with r != 0
    // - the main thread receives some shutdown cybol operation
    // - the main thread sets the exit flag only now
    // - the main thread shuts down and deallocates the destination buffer
    // - the sensing child thread decodes characters
    // - the sensing child thread possibly reallocates the (non-existing) destination buffer
    // - this leads to memory errors such as "corrupted double-linked list"
    //
    lock(p2);

    //
    // The exit flag was NOT set in the main thread.
    // Therefore, proceed normally.
    //

    fwprintf(stdout, L"Debug: Enable xcb buffer. Store event in buffer. r: %i\n", r);

    //
    // Store event in buffer.
    //
    // CAUTION! Do NOT use overwrite but rather APPEND, in order to
    // avoid deletion of previous events still existing in buffer.
    //
    modify_item(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Unlock mutex.
    unlock(p2);
}

/* BUFFER_XCB_ENABLER_SOURCE */
#endif
