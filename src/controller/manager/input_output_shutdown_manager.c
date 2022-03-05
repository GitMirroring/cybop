/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INPUT_OUTPUT_SHUTDOWN_MANAGER_SOURCE
#define INPUT_OUTPUT_SHUTDOWN_MANAGER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/maintainer/shutter/list_shutter.c"
#include "../../logger/logger.c"

/**
 * Shuts down all clients and services of the given input output entry.
 *
 * @param p0 the input output entry
 * @param p1 the channel
 * @param p2 the internal memory data
 */
void manage_shutdown_input_output(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manage shutdown input output.");
    fwprintf(stdout, L"Debug: Manage shutdown input output. p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Manage shutdown input output. *p1: %i\n", *((int*) p1));

    // The client list item.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server list item.
    void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get client list item from input output entry.
    copy_array_forward((void*) &cl, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CLIENTS_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get server list item from input output entry.
    copy_array_forward((void*) &sl, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVERS_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Shutdown clients.
    shutdown_list(cl, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME, p1, p2);
    // Shutdown servers.
    shutdown_list(sl, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME, p1, p2);
}

/* INPUT_OUTPUT_SHUTDOWN_MANAGER_SOURCE */
#endif
