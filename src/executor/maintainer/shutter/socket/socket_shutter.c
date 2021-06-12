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

#ifndef SOCKET_SHUTTER_SOURCE
#define SOCKET_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/maintainer/shutter/socket/server/list_server_socket_shutter.c"
#include "../../../../executor/maintainer/shutter/socket/close_socket_shutter.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the socket service.
 *
 * CAUTION! This is done in the reverse order the service was started up.
 *
 * @param p0 the input/output entry
 */
void shutdown_socket(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket.");

    // The socket.
    int s = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The client list item.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The accepttime list item.
    void* al = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieve various values from input/output entry.
    //
    // CAUTION! Do NOT use "overwrite_array" function here,
    // since it adapts the array count and size.
    // But the array's count and size are CONSTANT.
    //
    // CAUTION! Hand over value as pointer REFERENCE.
    //
    // CAUTION! Do NOT hand over input/output entry as pointer reference.
    //

    // Get socket from input/output entry.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get client list item from input/output entry.
    copy_array_forward((void*) &cl, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CLIENT_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get accepttime list item from input/output entry.
    copy_array_forward((void*) &al, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ACCEPTTIME_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // The timeout is just an integer number that does not have to get deallocated.

    // Shutdown client list.
    shutdown_socket_server_list(cl, al);

    // Deallocate client list item.
    deallocate_item((void*) &cl, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Deallocate accepttime list item.
    deallocate_item((void*) &al, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    // Close server socket.
    shutdown_socket_close((void*) &s);
}

/* SOCKET_SHUTTER_SOURCE */
#endif
