/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SHUTDOWN_SOURCE
#define SHUTDOWN_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/maintenance/shutdown_maintenance_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/maintainer/shutter.c"
#include "../../logger/logger.c"
#include "../../variable/service_interrupt.c"
#include "../../variable/thread_identification.c"

/**
 * Shuts down the service running on the given channel.
 *
 * Expected parametres:
 * - channel (required): the channel on which to shutdown a service (terminal, www, x-window-system, ...)
 * - id (optional): the service identification if having multiple terminals/displays/sockets etc., e.g. socket port 80; either port or service may be specified; port has higher priority; if missing, zero will be used (first io entry)
 * - service (optional): the network service, e.g. http; either port or service may be specified; port has higher priority; useful only if channel is "socket"
 * - mode (optional): the communication mode (needed only if channel is "socket")
 * - socket (optional): the client socket (needed only if mode is "client")
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_shutdown(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply shutdown.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service id part.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The network service part.
    void* ns = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The communication mode part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client socket part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service id part model item.
    void* idm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The network service part model item.
    void* nsm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The communication mode part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client socket part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The service id part model item data.
    void* idmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The network service part model item data, count.
    void* nsmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nsmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The communication mode part model item data, count.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client socket part model item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) CHANNEL_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get service id part.
    get_part_name((void*) &id, p0, (void*) IDENTIFICATION_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) IDENTIFICATION_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get network service part.
    get_part_name((void*) &ns, p0, (void*) SERVICE_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) SERVICE_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get communication mode part.
    get_part_name((void*) &m, p0, (void*) MODE_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) MODE_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get client socket part.
    get_part_name((void*) &s, p0, (void*) SOCKET_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) SOCKET_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get service id part model item.
    copy_array_forward((void*) &idm, id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get network service part model item.
    copy_array_forward((void*) &nsm, ns, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get communication mode part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get client socket part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get service id part model item data.
    copy_array_forward((void*) &idmd, idm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get network service part model item data, count.
    copy_array_forward((void*) &nsmd, nsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nsmc, nsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get communication mode part model item data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get client socket part model item data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    shutdown_service(p4, idmd, smd, mmd, mmc, nsmd, nsmc, cmd);
}

/* SHUTDOWN_SOURCE */
#endif
