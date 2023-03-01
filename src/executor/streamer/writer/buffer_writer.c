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

#ifndef BUFFER_WRITER_SOURCE
#define BUFFER_WRITER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../executor/porter/locker.c"
#include "../../../executor/porter/unlocker.c"
#include "../../../logger/logger.c"

/**
 * Copies data into the buffer.
 *
 * This is done always, in synchronous and asynchronous mode,
 * so that the actual writing can happen in many steps,
 * until the buffer is empty and all data written to the device.
 *
 * @param p0 the destination output buffer item
 * @param p1 the source message data
 * @param p2 the source message count
 * @param p3 the data type
 * @param p4 the output buffer mutex
 */
void write_buffer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write buffer.");
    //?? fwprintf(stdout, L"Debug: Write buffer. data type p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Write buffer. data type *p3: %i\n", *((int*) p3));

    // Lock mutex.
    lock(p4);

    //
    // Append buffer data to destination message item.
    //
    // CAUTION! Do NOT overwrite, but append the data,
    // since another thread might still be sending buffer data
    // that MUST NOT be deleted by overwriting them.
    // Therefore, let this main thread just APPEND new data.
    //
    modify_item(p0, p1, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Unlock mutex.
    unlock(p4);
}

/* BUFFER_WRITER_SOURCE */
#endif
