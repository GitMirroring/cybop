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
 * Opens a client either as standalone device or from request buffer, depending on the given server flag.
 *
 * @param p0 the client identification (e.g. file descriptor, socket number, window id)
 * @param p1 the client entry
 */
void open_stub(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open stub.");
    //?? fwprintf(stdout, L"Debug: Open stub. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Open stub. *p0: %i\n", *((int*) p0));

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client request input buffer item.
    void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client request input buffer mutex.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from client entry.
    copy_array_forward((void*) &se, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME);
    // Get client request input buffer item from server entry.
    copy_array_forward((void*) &bi, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME);
    // Get client request input buffer mutex from server entry.
    copy_array_forward((void*) &bm, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME);

    // Lock mutex.
    lock(bm);

    // Get client socket number from client request input buffer item at index ZERO.
    get_item(p0, bi, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"Debug: Open stub. get p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Open stub. get *p0: %i\n", *((int*) p0));

    // Remove client socket number from client request input buffer item at index ZERO.
    modify_item(bi, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

    // Unlock mutex.
    unlock(bm);
}
