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

#ifndef SERVER_ENTRY_FINDER_SOURCE
#define SERVER_ENTRY_FINDER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/finder/client_list_finder.c"
#include "../../../logger/logger.c"

/**
 * Finds the client entry with the given identification within
 * the server entry's client list.
 *
 * @param p0 the destination client entry (pointer reference)
 * @param p1 the source server entry
 * @param p2 the device data (identification e.g. file descriptor of a file, serial port, client socket, window id OR name e.g. a file system path pointing to some device)
 * @param p3 the device count
 * @param p4 the name flag (if true, then search by name, otherwise by identification)
 */
void find_server_entry(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find server entry.");
    fwprintf(stdout, L"Debug: Find server entry. p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Find server entry. *p2: %i\n", *((int*) p2));

    // The client list item.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get client list item from server entry.
    copy_array_forward((void*) &cl, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_LIST_SERVER_STATE_CYBOI_NAME);

    // Get client entry from client list.
    find_client_list(p0, cl, p2, p3, p4);
}

/* SERVER_ENTRY_FINDER_SOURCE */
#endif
