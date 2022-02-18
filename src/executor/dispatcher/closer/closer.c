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

    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get client entry belonging to given source device.
    find_entry((void*) &ce, internal-memory, channel, server-flag, port, dev-id);

    // Get input output entry from client entry.
    copy_array_forward((void*) &io, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_OUTPUT_BACKLINK_CLIENT_STATE_CYBOI_NAME);

    // Get suitable client list.
    find_mode((void*) &cl, io, server-flag, port);

    // Remove client entry from client list.
    modify_item(p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p5, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);
    //?? TODO: modify_item(cl, (void*) &ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Close client device depending on server flag.
    close_flag(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, ce, p10, p11);

    // Deallocate client entry.
    deallocate_client_entry((void*) &ce, channel);
}

/* CLOSER_SOURCE */
#endif
