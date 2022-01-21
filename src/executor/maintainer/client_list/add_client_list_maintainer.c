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

#ifndef ADD_CLIENT_LIST_MAINTAINER_SOURCE
#define ADD_CLIENT_LIST_MAINTAINER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/maintainer/client_list/find_client_list_maintainer.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Stores the client entry in the client list.
 *
 * @param p0 the destination client entry list item
 * @param p1 the destination client identification list item
 * @param p2 the source client entry (pointer reference)
 * @param p3 the source client identification (e.g. client socket, window id)
 */
void maintain_client_list_add(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Maintain client list add.");
    fwprintf(stdout, L"Debug: Maintain client list add. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Maintain client list add. *p3: %i\n", *((int*) p3));

    // The index.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Search client identification in client identification list item.
    maintain_client_list_find((void*) &i, p1, p3);

    if (i == *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

        //
        // A client entry with the given client identification
        // does NOT exist yet in the client identification list.
        //

        // Add source client entry to destination client entry list item.
        modify_item(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Add source client identification to destination client identification list item.
        modify_item(p1, p3, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not maintain client list add. A client entry with the given source client identification already exists.");
        fwprintf(stdout, L"Error: Could not maintain client list add. A client entry with the given source client identification already exists. p3: %i\n", p3);
        fwprintf(stdout, L"Error: Could not maintain client list add. A client entry with the given source client identification already exists. *p3: %i\n", *((int*) p3));
    }
}

/* ADD_CLIENT_LIST_MAINTAINER_SOURCE */
#endif
