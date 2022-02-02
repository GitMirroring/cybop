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

#ifndef OPEN_SOURCE
#define OPEN_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/dispatching/open_dispatching_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/dispatcher/opener/opener.c"
#include "../../logger/logger.c"

/**
 * Opens up a client on the given channel.
 *
 * Parametres:
 * - channel (required): the channel on which to open a client, e.g. file, serial_port, socket, display
 * - device (required):
 *      = filename for channel "file" or "serialport" or "terminal" or "pipeline"
 *      = filename for channel "socket" with namespace "local" (unix domain socket)
 *      = host address for channel "socket" with namespace "ipv4" or "ipv6"
 * - port (optional): the port for channel "socket" with namespace "ipv4" or "ipv6"
 * - namespace (optional): the address family, e.g. ipv4 or ipv6
 * - style (optional): the communication style, e.g. stream or datagram
 * - protocol (optional): the protocol, e.g. tcp or udp
 * - identification (required): the file descriptor or client socket number or window id returned from cyboi (except for channel "server_socket", where accept returns a ready client id)
 * - stub (optional): the flag indicating if the client socket is a stub (server-side placeholder for a standalone client)
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_open(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply open.");

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The device part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The namespace part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The style part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The protocol part.
    void* pr = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The stub flag part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The device part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The namespace part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The style part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The protocol part model item.
    void* prm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part model item.
    void* idm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The stub flag part model item.
    void* stm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The device part model item data, count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The namespace part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The style part model item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The protocol part model item data, count.
    void* prmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* prmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part model item data.
    void* idmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The stub flag part model item data.
    void* stmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) CHANNEL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get device part.
    get_part_name((void*) &d, p0, (void*) DEVICE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) DEVICE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get port part.
    get_part_name((void*) &p, p0, (void*) PORT_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) PORT_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get namespace part.
    get_part_name((void*) &n, p0, (void*) NAMESPACE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) NAMESPACE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get style part.
    get_part_name((void*) &s, p0, (void*) STYLE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) STYLE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get protocol part.
    get_part_name((void*) &pr, p0, (void*) PROTOCOL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) PROTOCOL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get identification part.
    get_part_name((void*) &id, p0, (void*) IDENTIFICATION_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) IDENTIFICATION_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get stub flag part.
    get_part_name((void*) &st, p0, (void*) STUB_OPEN_DISPATCHING_LOGIC_CYBOL_NAME, (void*) STUB_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get device part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get port part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get namespace part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get style part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get protocol part model item.
    copy_array_forward((void*) &prm, pr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get identification part model item.
    copy_array_forward((void*) &idm, id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get stub flag part model item.
    copy_array_forward((void*) &stm, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get device part model item data, count.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get port part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get namespace part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get style part model item data, count.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get protocol part model item data, count.
    copy_array_forward((void*) &prmd, prm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &prmc, prm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get identification part model item data.
    copy_array_forward((void*) &idmd, idm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get stub flag part model item data.
    copy_array_forward((void*) &stmd, stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Open up client.
    open_client(idmd, p4, cmd, pmd, dmd, dmc/*??, nmd, nmc, smd, smc, prmd, prmc*/, stmd);
}

/* OPEN_SOURCE */
#endif
