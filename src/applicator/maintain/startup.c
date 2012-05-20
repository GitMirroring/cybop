/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STARTUP_SOURCE
#define STARTUP_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/maintenance/startup_maintenance_operation_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/maintainer/starter.c"
#include "../../executor/modifier/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Starts up a service on the given channel.
 *
 * Expected parametres:
 * - channel (required): the channel on which to startup a service (terminal, tcp_socket, unix_socket, x_window_system, ...)
 * - namespace (optional, only if service is www, cyboi or similar): the namespace of the socket
 * - style (optional, only if service is www or similar): the namespace of the socket
 * - address (optional, only if service is www or similar): the address of hosts communicating with this system via socket
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the internal memory data
 */
void apply_startup(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply startup.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The communication style part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The host address part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_knowledge((void*) &c, p0, (void*) CHANNEL_STARTUP_MAINTENANCE_OPERATION_CYBOL_NAME, (void*) CHANNEL_STARTUP_MAINTENANCE_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get socket namespace.
    get_part_knowledge((void*) &n, p0, (void*) NAMESPACE_STARTUP_MAINTENANCE_OPERATION_CYBOL_NAME, (void*) NAMESPACE_STARTUP_MAINTENANCE_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get communication style.
    get_part_knowledge((void*) &st, p0, (void*) STYLE_STARTUP_MAINTENANCE_OPERATION_CYBOL_NAME, (void*) STYLE_STARTUP_MAINTENANCE_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get host address.
    get_part_knowledge((void*) &a, p0, (void*) ADDRESS_STARTUP_MAINTENANCE_OPERATION_CYBOL_NAME, (void*) ADDRESS_STARTUP_MAINTENANCE_OPERATION_CYBOL_NAME_COUNT, p1, p2);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    startup_service(p3, cmd);
}

/* STARTUP_SOURCE */
#endif
