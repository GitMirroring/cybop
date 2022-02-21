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

#ifndef CLOSER_SOURCE
#define CLOSER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Closes the client with the given identification on the given channel.
 *
 * CAUTION! Do NOT rename this function to "close",
 * as that name is already used by low-level functionality:
 * /usr/include/unistd.h:353:12
 * extern int close (int __fd);
 *
 * @param p0 the client identification (e.g. file descriptor, socket number)
 * @param p1 the internal memory
 * @param p2 the channel
 * @param p3 the port
 */
void close_client(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close client.");
    fwprintf(stdout, L"Debug: Close client. p0: %i\n", p0);

    //
    // Declaration
    //

    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry index.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get client entry belonging to given source device.
    find_entry((void*) &ce, internal-memory, channel, server-flag, port, dev-id);

    //
    // Suspension
    //

    //
    // Suspend input detection and exit sensing thread.
    //
    // CAUTION! This has to be done BEFORE deallocating resources below.
    //
    //?? TODO

    //
    // Removal
    //

    // Get input output entry from client entry.
    copy_array_forward((void*) &io, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_OUTPUT_BACKLINK_CLIENT_STATE_CYBOI_NAME);
    // Get suitable client list item.
    find_mode((void*) &cl, io, server-flag, port);
    // Get client entry index within server list by client device identification.
    find_list_index((void*) &i, cl, p0, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);
    // Remove client entry from client list.
    modify_item(cl, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Finalisation
    //

    // Finalise device.
    finalise(p0-client-id, ce, channel);

    //
    // Closing
    //

    //
    // Close client device.
    //
    // CAUTION! Contrary to the opening, client socket stubs
    // do NOT need a special treatment here. Their file descriptor
    // gets closed in the same way as for the other channels.
    //
    close_device(p0, ce, p2);

    //
    // Deallocation
    //

    // Deallocate client entry.
    deallocate_client_entry((void*) &ce, channel);
}

/* CLOSER_SOURCE */
#endif
