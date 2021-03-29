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

/**
 * Shuts down the service running on the given channel.
 *
 * Expected parametres:
 * - channel (required): the channel on which to shutdown a service, e.g. serial, terminal, display, socket
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
    // The socket filename part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket filename part model item data, count.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* fmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket port part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) CHANNEL_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket filename part.
    get_part_name((void*) &f, p0, (void*) FILENAME_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) FILENAME_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get socket port part.
    get_part_name((void*) &p, p0, (void*) PORT_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME, (void*) PORT_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket filename part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get socket port part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get socket filename part model item data, count.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fmc, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get socket port part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Shutdown service.
    shutdown_service(p4, pmd, cmd);
}

/* SHUTDOWN_SOURCE */
#endif
