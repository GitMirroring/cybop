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

#ifndef OPENER_SOURCE
#define OPENER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/dispatcher/opener/entry_opener.c"
#include "../../../executor/dispatcher/opener/flag_opener.c"
#include "../../../executor/dispatcher/opener/identification_opener.c"
#include "../../../executor/finder/mode_finder.c"
#include "../../../executor/memoriser/allocator/client_entry_allocator.c"
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
 * @param p0 the client identification (e.g. file descriptor, socket number, window id)
 * @param p1 the port
 * @param p2 the host address data (network communication) OR filename data (device, file, local unix domain socket)
 * @param p3 the host address count (network communication) OR filename count (device, file, local unix domain socket)
 * @param p4 the file open mode data
 * @param p5 the file open mode count
 * @param p6 the family data (namespace)
 * @param p7 the family count
 * @param p8 the style data (communication type)
 * @param p9 the style count
 * @param p10 the protocol data
 * @param p11 the protocol count
 * @param p12 the channel
 * @param p13 the server flag
 * @param p14 the internal memory
 * @param p15 the internal memory (pointer reference)
 */
void open_client(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open client.");
    //?? fwprintf(stdout, L"Information: Open client. channel p12: %i\n", p12);
    //?? fwprintf(stdout, L"Information: Open client. channel *p12: %i\n", *((int*) p12));

    //?? fwprintf(stdout, L"Information: Open client. port *p1: %i\n", *((int*) p1));
    //?? fwprintf(stdout, L"Information: Open client. server flag *p13: %i\n", *((int*) p13));

    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate client entry.
    allocate_client_entry((void*) &ce, p12);

    //
    // Initialise client entry.
    //
    // CAUTION! It has to get initialised BEFORE opening
    // the client below, since its values are used there.
    //
    open_entry(ce, p14, p12, p13, p1, p15);

    // Open client device depending on server flag.
    open_flag(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, ce, p12, p13);

    // Assign identification to client entry.
    open_identification(ce, p0, p2, p3);

    // Get input output entry from client entry.
    copy_array_forward((void*) &io, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_OUTPUT_BACKLINK_CLIENT_STATE_CYBOI_NAME);

    // Get suitable client list item.
    find_mode((void*) &cl, io, p13, p1);

    // Append client entry to client list.
    modify_item(cl, (void*) &ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}

/* OPENER_SOURCE */
#endif
