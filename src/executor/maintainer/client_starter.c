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

#ifndef CLIENT_STARTER_SOURCE
#define CLIENT_STARTER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/maintainer/entry_client_starter.c"
#include "../../executor/maintainer/store_client_starter.c"
#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../executor/sensor/sensor.c"
#include "../../executor/threader/spinner.c"
#include "../../logger/logger.c"

/**
 * Starts up the client.
 *
 * @param p0 the destination client list item
 * @param p1 the client identification (socket)
 * @param p2 the interrupt pipe (pointer reference)
 * @param p3 the interrupt mutex (pointer reference)
 * @param p4 the input/output identification (pointer reference, input/output base + socket port)
 * @param p5 the language (pointer reference, protocol)
 * @param p6 the channel (pointer reference)
 */
void startup_client(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup client.");
    fwprintf(stdout, L"Debug: Startup client. p0: %i\n", p0);

    // The client entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The thread identification.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sense function.
    void* f = (void*) &sense;

    //
    // Allocate client entry.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &e, (void*) CLIENT_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

    // Startup client entry.
    startup_client_entry(e, p2, p3, p4, p5, p6, p1);

    // Store client entry at index of client socket in client list.
    startup_client_store(p0, (void*) &e, p1);

    // Get thread identification from client entry.
    copy_array_forward((void*) &t, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_THREAD_CLIENT_STATE_CYBOI_NAME);

    //
    // Create thread and invoke sensing function.
    //
    // CAUTION! A new child thread can be created by ANY thread,
    // not only the main programme thread, at any time.
    //
    spin(t, f, e);
}

/* CLIENT_STARTER_SOURCE */
#endif
