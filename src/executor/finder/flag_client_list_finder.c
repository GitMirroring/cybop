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

#ifndef FLAG_CLIENT_LIST_FINDER_SOURCE
#define FLAG_CLIENT_LIST_FINDER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/finder/identification_client_list_finder.c"
#include "../../../executor/finder/name_client_list_finder.c"
#include "../../../logger/logger.c"

/**
 * Finds the client entry either by identification or by name,
 * depending on the given flag.
 *
 * @param p0 the comparison result
 * @param p1 the client entry
 * @param p2 the device data (identification e.g. file descriptor of a file, serial port, client socket, window id OR name e.g. a file system path pointing to some device)
 * @param p3 the device count
 * @param p4 the name flag (if true, then search by name, otherwise by identification)
 */
void find_client_list_flag(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find client list flag.");
    fwprintf(stdout, L"Debug: Find client list flag. p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Find client list flag. *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        find_client_list_identification(p0, p1, p2);

    } else {

        find_client_list_name(p0, p1, p2, p3);
    }
}

/* FLAG_CLIENT_LIST_FINDER_SOURCE */
#endif
