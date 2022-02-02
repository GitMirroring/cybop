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

#ifndef OPENER_SOURCE
#define OPENER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/accessor/getter/internal_memory_getter_channel.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/dispatcher/opener/entry_opener.c"
#include "../../../executor/dispatcher/opener/flag_opener.c"
#include "../../../executor/finder/server_entry_finder.c"
#include "../../../executor/memoriser/allocator/client_entry_allocator.c"
#include "../../../executor/memoriser/allocator/server_entry_allocator.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Opens a new client belonging to the given channel.
 *
 * CAUTION! Do NOT rename this function to "open",
 * as that name is already used by low-level file descriptor functionality:
 * /usr/include/fcntl.h:168
 * extern int open (const char *__file, int __oflag, ...) __nonnull ((1));
 *
 * @param p0 the client identification (e.g. file descriptor, socket number)
 * @param p1 the internal memory
 * @param p2 the channel
 * @param p3 the port
 * @param p4 the device name data
 * @param p5 the device name count
 * @param p6 the stub flag
 */
void open_client(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open client.");
    fwprintf(stdout, L"Debug: Open client. channel p2: %i\n", p2);

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from internal memory.
    get_internal_memory_channel((void*) &se, p1, p2, p3);

    if (se == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A server entry does NOT exist yet.
        //

        // Allocate server entry.
        allocate_server_entry((void*) &se);
    }

    // Get client list from server entry.
    copy_array_forward((void*) &cl, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_LIST_SERVER_STATE_CYBOI_NAME);

    // Get client entry from server entry client list by given device identification.
    find_server_entry((void*) &ce, se, p0, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (ce == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Open device depending on stub flag.
        open_flag(p0, p4, p5, p2, p6);

        // Allocate client entry.
        allocate_client_entry((void*) &ce, p2);

        // Initialise client entry.
        open_entry(ce, p0, p4, p5, (void*) &se);

        // Add client entry to client list of server entry.
        modify_item(cl, (void*) &ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open client. A client entry already exists for the given device.");
        fwprintf(stdout, L"Error: Could not open client. A client entry already exists for the given device. se: %i\n", se);
    }
}

/* OPENER_SOURCE */
#endif
