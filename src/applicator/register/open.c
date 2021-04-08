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
#include "../../constant/name/cybol/logic/registration/open_registration_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/registrar/opener.c"
#include "../../logger/logger.c"

/**
 * Opens up the client on the given channel.
 *
 * Expected parametres:
 * - channel (required): the channel on which to open a client, e.g. socket or display
 * - id (required): the identification
 *
 * Expected parametres only for channel "socket":
 * - namespace (optional): the address family, e.g. ip6
 * - style (optional): the communication style, e.g. stream
 * - protocol (optional): the protocol, e.g. tcp
 * - filename (optional): the unix domain socket filename
 * - address (optional): the host address
 * - port (optional): the port
 * - blocking (required): the status, i.e. whether or not a socket is blocking
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
    // The id part.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part.
    void* socket_n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part.
    void* socket_st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part.
    void* socket_p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part.
    void* socket_f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part.
    void* socket_a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part.
    void* socket_po = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket blocking part.
    void* socket_b = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The id part model item.
    void* idm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part model item.
    void* socket_nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part model item.
    void* socket_stm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part model item.
    void* socket_pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part model item.
    void* socket_fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part model item.
    void* socket_am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part model item.
    void* socket_pom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket blocking part model item.
    void* socket_bm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The id part model item data.
    void* idmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part model item data, count.
    void* socket_nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part model item data, count.
    void* socket_stmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_stmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part model item data, count.
    void* socket_pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part model item data, count.
    void* socket_fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_fmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part model item data, count.
    void* socket_amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_amc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part model item data.
    void* socket_pomd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket blocking part model item data.
    void* socket_bmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) CHANNEL_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get id part.
    get_part_name((void*) &id, p0, (void*) IDENTIFICATION_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) IDENTIFICATION_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket namespace part.
    get_part_name((void*) &socket_n, p0, (void*) NAMESPACE_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) NAMESPACE_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket style part.
    get_part_name((void*) &socket_st, p0, (void*) STYLE_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) STYLE_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket protocol part.
    get_part_name((void*) &socket_p, p0, (void*) PROTOCOL_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) PROTOCOL_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket filename part.
    get_part_name((void*) &socket_f, p0, (void*) FILENAME_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) FILENAME_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket address part.
    get_part_name((void*) &socket_a, p0, (void*) ADDRESS_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) ADDRESS_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket port part.
    get_part_name((void*) &socket_po, p0, (void*) PORT_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) PORT_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket blocking part.
    get_part_name((void*) &socket_b, p0, (void*) BLOCKING_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME, (void*) BLOCKING_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get id part model item.
    copy_array_forward((void*) &idm, id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket namespace part model item.
    copy_array_forward((void*) &socket_nm, socket_n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket style part model item.
    copy_array_forward((void*) &socket_stm, socket_st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket protocol part model item.
    copy_array_forward((void*) &socket_pm, socket_p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket filename part model item.
    copy_array_forward((void*) &socket_fm, socket_f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket address part model item.
    copy_array_forward((void*) &socket_am, socket_a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket port part model item.
    copy_array_forward((void*) &socket_pom, socket_po, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket blocking part model item.
    copy_array_forward((void*) &socket_bm, socket_b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get id part model item data.
    copy_array_forward((void*) &idmd, idm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket namespace part model item data, count.
    copy_array_forward((void*) &socket_nmd, socket_nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_nmc, socket_nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket style part model item data, count.
    copy_array_forward((void*) &socket_stmd, socket_stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_stmc, socket_stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket protocol part model item data, count.
    copy_array_forward((void*) &socket_pmd, socket_pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_pmc, socket_pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket filename part model item data, count.
    copy_array_forward((void*) &socket_fmd, socket_fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_fmc, socket_fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket address part model item data, count.
    copy_array_forward((void*) &socket_amd, socket_am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_amc, socket_am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket port part model item data.
    copy_array_forward((void*) &socket_pomd, socket_pom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket blocking part model item data.
    copy_array_forward((void*) &socket_bmd, socket_bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Open up client.
    open_client(idmd, socket_nmd, socket_nmc, socket_stmd, socket_stmc, socket_pmd, socket_pmc, socket_fmd, socket_fmc, socket_amd, socket_amc, socket_pomd, socket_bmd, p4, cmd);
}

/* OPEN_SOURCE */
#endif
