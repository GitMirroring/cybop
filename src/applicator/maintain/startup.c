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
#include "../../executor/maintainer/starter.c"
#include "../../logger/logger.c"

/**
 * Starts up a service on the given channel.
 *
 * Expected parametres:
 * - channel (required): the channel on which to startup a service, e.g. serial, terminal, display, socket
 *
 * Expected parametres only for channel "serial":
 * - filename (required): the filename
 * - baudrate (optional): the filename
 *
 * Expected parametres only for channel "socket":
 * - namespace (optional): the address family, e.g. local, ipv4, ipv6
 * - style (optional): the communication style, e.g. stream, datagram, raw
 * - protocol (optional): the protocol, e.g. tcp, udp, rdp
 * - blocking (required): the socket status, i.e. whether or not a socket is blocking
 * - filename (optional): the unix domain socket filename
 * - address (required): the host address
 * - port (required): the service identification, e.g. socket port 80
 * - connexions (optional): the number of possible pending client requests
 * - timeout (optional): the timeout in seconds set for each new client
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
    // The serial filename part.
    void* serial_f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial baudrate part.
    void* serial_b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part.
    void* socket_n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part.
    void* socket_st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part.
    void* socket_p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket blocking part.
    void* socket_b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part.
    void* socket_f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part.
    void* socket_a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part.
    void* socket_po = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket connexions part.
    void* socket_co = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket timeout part.
    void* socket_to = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial filename part model item.
    void* serial_fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial baudrate part model item.
    void* serial_bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part model item.
    void* socket_nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part model item.
    void* socket_stm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part model item.
    void* socket_pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket blocking part model item.
    void* socket_bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part model item.
    void* socket_fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part model item.
    void* socket_am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part model item.
    void* socket_pom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket connexions part model item.
    void* socket_com = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket timeout part model item.
    void* socket_tom = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial filename part model item data, count.
    void* serial_fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* serial_fmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial baudrate part model item data.
    void* serial_bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket namespace part model item data, count.
    void* socket_nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket style part model item data, count.
    void* socket_stmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_stmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket protocol part model item data, count.
    void* socket_pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket blocking part model item data.
    void* socket_bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part model item data, count.
    void* socket_fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_fmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket address part model item data, count.
    void* socket_amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* socket_amc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part model item data.
    void* socket_pomd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket connexions part model item data.
    void* socket_comd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket timeout part model item data.
    void* socket_tomd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) CHANNEL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get serial filename part.
    get_part_name((void*) &serial_f, p0, (void*) FILENAME_SERIAL_INTERFACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) FILENAME_SERIAL_INTERFACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get serial baudrate part.
    get_part_name((void*) &serial_b, p0, (void*) BAUDRATE_SERIAL_INTERFACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) BAUDRATE_SERIAL_INTERFACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket namespace part.
    get_part_name((void*) &socket_n, p0, (void*) NAMESPACE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) NAMESPACE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket style part.
    get_part_name((void*) &socket_st, p0, (void*) STYLE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) STYLE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket protocol part.
    get_part_name((void*) &socket_p, p0, (void*) PROTOCOL_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) PROTOCOL_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket blocking part.
    get_part_name((void*) &socket_b, p0, (void*) BLOCKING_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) BLOCKING_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket filename part.
    get_part_name((void*) &socket_f, p0, (void*) FILENAME_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) FILENAME_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket address part.
    get_part_name((void*) &socket_a, p0, (void*) ADDRESS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) ADDRESS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket port part.
    get_part_name((void*) &socket_po, p0, (void*) PORT_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) PORT_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket connexions part.
    get_part_name((void*) &socket_co, p0, (void*) CONNEXIONS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) CONNEXIONS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket timeout part.
    get_part_name((void*) &socket_to, p0, (void*) TIMEOUT_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) TIMEOUT_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get serial filename part model item.
    copy_array_forward((void*) &serial_fm, serial_f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get serial baudrate part model item.
    copy_array_forward((void*) &serial_bm, serial_b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket namespace part model item.
    copy_array_forward((void*) &socket_nm, socket_n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket style part model item.
    copy_array_forward((void*) &socket_stm, socket_st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket protocol part model item.
    copy_array_forward((void*) &socket_pm, socket_p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket blocking part model item.
    copy_array_forward((void*) &socket_bm, socket_b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket filename part model item.
    copy_array_forward((void*) &socket_fm, socket_f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket address part model item.
    copy_array_forward((void*) &socket_am, socket_a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket port part model item.
    copy_array_forward((void*) &socket_pom, socket_po, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket connexions part model item.
    copy_array_forward((void*) &socket_com, socket_co, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket timeout part model item.
    copy_array_forward((void*) &socket_tom, socket_to, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get serial filename part model item data, count.
    copy_array_forward((void*) &serial_fmd, serial_fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &serial_fmc, serial_fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get serial baudrate part model item data.
    copy_array_forward((void*) &serial_bmd, serial_bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket namespace part model item data, count.
    copy_array_forward((void*) &socket_nmd, socket_nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_nmc, socket_nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket style part model item data, count.
    copy_array_forward((void*) &socket_stmd, socket_stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_stmc, socket_stm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket protocol part model item data, count.
    copy_array_forward((void*) &socket_pmd, socket_pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_pmc, socket_pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket blocking part model item data.
    copy_array_forward((void*) &socket_bmd, socket_bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket filename part model item data, count.
    copy_array_forward((void*) &socket_fmd, socket_fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_fmc, socket_fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket address part model item data, count.
    copy_array_forward((void*) &socket_amd, socket_am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &socket_amc, socket_am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket port part model item data, count.
    copy_array_forward((void*) &socket_pomd, socket_pom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket connexions part model item data.
    copy_array_forward((void*) &socket_comd, socket_com, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket timeout part model item data.
    copy_array_forward((void*) &socket_tomd, socket_tom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The interrupt pipe.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The interrupt mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get interrupt pipe.
    copy_array_forward((void*) &p, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_PIPE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get interrupt mutex.
    copy_array_forward((void*) &m, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_MUTEX_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Startup service.
    startup_service(p4, serial_fmd, serial_fmc, serial_bmd, socket_nmd, socket_nmc, socket_stmd, socket_stmc, socket_pmd, socket_pmc, socket_bmd, socket_fmd, socket_fmc, socket_amd, socket_amc, socket_pomd, socket_comd, socket_tomd, (void*) &p, (void*) &m, cmd);
}

/* STARTUP_SOURCE */
#endif
