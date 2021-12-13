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

#ifndef SERVER_SOCKET_READER_SOURCE
#define SERVER_SOCKET_READER_SOURCE

#include <threads.h> // mtx_t, mtx_lock, mtx_unlock

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/internal_memory_getter.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Reads as server from client socket.
 *
 * @param p0 the destination item
 * @param p1 the source client socket number
 * @param p2 the internal memory data
 * @param p3 the socket port
 */
void read_socket_server(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read socket server.");
    fwprintf(stdout, L"Debug: Read socket server. p1: %i\n", p1);

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list item.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list item data.
    void* cld = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The buffer item data, count, size.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bs = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p2, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, p3);
    fwprintf(stdout, L"Debug: Read. io: %i\n", io);
    // Get client list item from input/output entry.
    copy_array_forward((void*) &cl, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CLIENT_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Read. cl: %i\n", cl);
    // Get client list item data.
    copy_array_forward((void*) &cld, cl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Read. cld: %i\n", cld);
    // Get client entry using client socket number as source client list index.
    copy_array_forward((void*) &e, cld, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1);
    fwprintf(stdout, L"Debug: Read. e: %i\n", e);
    // Get buffer item from client entry.
    copy_array_forward((void*) &b, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BUFFER_MESSAGE_CLIENT_STATE_CYBOI_NAME);
    // Get mutex from client entry.
    copy_array_forward((void*) &m, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_MESSAGE_CLIENT_STATE_CYBOI_NAME);

    fwprintf(stdout, L"Debug: Read. client socket e: %i\n", e);
    fwprintf(stdout, L"Debug: Read. client socket *e: %i\n", *((int*) e));

    // The mutex with correct type.
    mtx_t* mt = (mtx_t*) m;

    //
    // Lock mutex.
    //
    // CAUTION! Set this lock BEFORE retrieving the item data and count below
    // since otherwise, a race condition might occur, e.g. when the sensing thread
    // appends data to the buffer, a new data array with bigger size might get allocated.
    // In order to get the correct data array here, the lock has to be set before.
    //
    mtx_lock(mt);

    //
    // Get buffer item data, count, size.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bc, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bs, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    // The complete flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Check for length prefix and end suffix.
    //?? sense_socket_check_completeness((void*) &f, p9, p0, p8);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The message is complete, that is all data
        // belonging to it have been received.
        //

        // Read data from buffer.
        modify_item(p0, bd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, bc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // Remove data from buffer.
        //
        // CAUTION! This is important since otherwise,
        // the same data would be processed again and again.
        //
        // CAUTION! Do NOT EMPTY the buffer here since new data
        // might be added continuously within the sensing thread.
        //
        modify_array((void*) &bd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, bc, bs, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);
    }

    // Unlock mutex.
    mtx_unlock(mt);
}

/* SERVER_SOCKET_READER_SOURCE */
#endif
