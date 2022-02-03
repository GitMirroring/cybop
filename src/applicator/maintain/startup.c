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

#ifndef STARTUP_SOURCE
#define STARTUP_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/maintenance/startup_maintenance_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/maintainer/starter/starter.c"
#include "../../logger/logger.c"

/**
 * Starts up a service on the given channel.
 *
 * Parametres:
 * - channel (required): the channel on which to startup a service, e.g. display, socket
 * - port (optional): the service identification, e.g. socket port 80
 * - namespace (optional): the address family, e.g. local, ipv4, ipv6
 * - style (optional): the communication style, e.g. stream, datagram, raw
 * - protocol (optional): the protocol, e.g. tcp, udp, rdp
 * - filename (optional): the unix domain socket filename
 * - address (optional): the host address, e.g. localhost or 127.0.0.1
 * - connexions (optional): the number of possible pending client requests, e.g. 10
 * - timeout (optional): the timeout in seconds set for each new client, e.g. 300
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_startup(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply startup.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part.
    void* pr = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket connexions part.
    void* co = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket timeout part.
    void* to = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part model item.
    void* stm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part model item.
    void* prm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket connexions part model item.
    void* com = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket timeout part model item.
    void* tom = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part model item data, count.
    void* stmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* stmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part model item data, count.
    void* prmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* prmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part model item data, count.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* fmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part model item data, count.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* amc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket connexions part model item data.
    void* comd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket timeout part model item data.
    void* tomd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) CHANNEL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket port part.
    get_part_name((void*) &p, p0, (void*) PORT_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) PORT_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket namespace part.
    get_part_name((void*) &n, p0, (void*) NAMESPACE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) NAMESPACE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket style part.
    get_part_name((void*) &st, p0, (void*) STYLE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) STYLE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket protocol part.
    get_part_name((void*) &pr, p0, (void*) PROTOCOL_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) PROTOCOL_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket filename part.
    get_part_name((void*) &f, p0, (void*) FILENAME_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) FILENAME_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket address part.
    get_part_name((void*) &a, p0, (void*) ADDRESS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) ADDRESS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket connexions part.
    get_part_name((void*) &co, p0, (void*) CONNEXIONS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) CONNEXIONS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket timeout part.
    get_part_name((void*) &to, p0, (void*) TIMEOUT_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) TIMEOUT_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket port part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket namespace part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket style part model item.
    copy_array_forward((void*) &stm, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket protocol part model item.
    copy_array_forward((void*) &prm, pr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket filename part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket address part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket connexions part model item.
    copy_array_forward((void*) &com, co, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket timeout part model item.
    copy_array_forward((void*) &tom, to, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket port part model item data, count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket namespace part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket style part model item data, count.
    copy_array_forward((void*) &stmd, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &stmc, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket protocol part model item data, count.
    copy_array_forward((void*) &prmd, prm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &prmc, prm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket filename part model item data, count.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fmc, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket address part model item data, count.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &amc, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket connexions part model item data.
    copy_array_forward((void*) &comd, com, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket timeout part model item data.
    copy_array_forward((void*) &tomd, tom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Startup service.
    startup_server(p4, cmd, pmd, nmd, nmc, stmd, stmc, prmd, prmc, fmd, fmc, amd, amc, comd, tomd);
}

/* STARTUP_SOURCE */
#endif
