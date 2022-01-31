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

#ifndef IDENTIFICATION_CLIENT_LIST_FINDER_SOURCE
#define IDENTIFICATION_CLIENT_LIST_FINDER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../logger/logger.c"

/**
 * Finds the client entry with the given identification from the client list.
 *
 * @param p0 the comparison result
 * @param p1 the client entry
 * @param p2 the device data (identification e.g. file descriptor of a file, serial port, client socket, window id)
 */
void find_client_list_identification(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find client list identification.");
    fwprintf(stdout, L"Debug: Find client list identification. p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Find client list identification. *p2: %i\n", *((int*) p2));

    // The client identification.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get client identification from client entry.
    copy_array_forward((void*) &id, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);

    compare_integer_equal(p0, id, p2);
}

/* IDENTIFICATION_CLIENT_LIST_FINDER_SOURCE */
#endif
