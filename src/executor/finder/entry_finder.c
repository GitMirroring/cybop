/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ENTRY_FINDER_SOURCE
#define ENTRY_FINDER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/copier/array/forward_array_copier.c"
#include "../../executor/finder/list_finder.c"
#include "../../executor/finder/mode_finder.c"
#include "../../logger/logger.c"
#include "../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Gets client entry belonging to given source device.
 *
 * @param p0 the client entry (pointer reference)
 * @param p1 the internal memory
 * @param p2 the channel
 * @param p3 the server flag
 * @param p4 the port
 * @param p5 the device identification (e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 */
void find_entry(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find entry.");
    // fwprintf(stdout, L"Debug: Find entry. p0: %i\n", p0);

    // The internal memory name.
    int n = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clients list.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get internal memory name by channel.
    map_channel_to_internal_memory((void*) &n, p2);

    if (n != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

        // Get channel input output entry from internal memory.
        copy_array_forward((void*) &io, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &n);

        // Get client list from suitable entry.
        find_mode((void*) &cl, io, p3, p4);

        // Get client entry from server clients list by device identification.
        find_list(p0, cl, p5, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);

    } else {

        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not find entry. The internal memory name is invalid. This is unproblematic, since some channels like e.g. signal are not stored in internal memory.");
        // fwprintf(stdout, L"Warning: Could not find entry. The internal memory name is invalid. This is unproblematic, since some channels like e.g. signal are not stored in internal memory. p0: %i\n", p0);
    }
}

/* ENTRY_FINDER_SOURCE */
#endif
