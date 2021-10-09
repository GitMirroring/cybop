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

#ifndef SOCKET_READER_SOURCE
#define SOCKET_READER_SOURCE

#include <threads.h> // mtx_lock, mtx_unlock

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Reads data via socket.
 *
 * @param p0 the destination item
 * @param p1 the client entry
 */
void read_socket(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read socket.");

    // The buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"Debug: Read socket. 0 bc: %i\n", bc);
    // Get buffer item from client entry.
    copy_array_forward((void*) &b, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BUFFER_MESSAGE_CLIENT_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Read socket. 1 bc: %i\n", bc);
    // Get mutex from client entry.
    copy_array_forward((void*) &m, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_MESSAGE_CLIENT_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Read socket. 2 bc: %i\n", bc);
    //
    // Get buffer item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Read socket. 3 bc: %i\n", bc);
    copy_array_forward((void*) &bc, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"Debug: Read socket. bc: %i\n", bc);
    fwprintf(stdout, L"Debug: Read socket. *bc: %i\n", *((int*) bc));

    // Lock mutex.
    mtx_lock(m);
    // Read data from buffer.
    modify_item(p0, bd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, bc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Unlock mutex.
    mtx_unlock(m);
}

/* SOCKET_READER_SOURCE */
#endif
