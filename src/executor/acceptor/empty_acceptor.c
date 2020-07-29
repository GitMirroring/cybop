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

#ifndef EMPTY_ACCEPTOR_SOURCE
#define EMPTY_ACCEPTOR_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Adds a default client identification if the client list is empty.
 *
 * This may happen for channels: display, serial, terminal.
 *
 * If no client was assigned, then ZERO is copied as DEFAULT IDENTIFICATION here.
 * Otherwise, the checking mechanism in cyboi directory "controller/checker/"
 * would not work, since the corresponding loop expects at least one client.
 *
 * @param p0 the sender client (e.g. display connection, file descriptor, client socket)
 * @param p1 the client list item
 */
void accept_empty(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept empty.");

//??     fwprintf(stdout, L"TEST: Accept empty. sender client user *p0: %i \n", *((int*) p0));

    // The client list item count.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Get client list item count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    compare_integer_less_or_equal((void*) &r, c, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The client list is empty.

        // Copy sender client user identification to destination.
        copy_integer(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    } else {

        // A sender client user already exists in the client list.

        //
        // CAUTION! Do NOT log messages here, since this is normal behaviour.
        // Otherwise, it would produce huge log files filled up with useless entries.
        // Since cyboi is non-blocking using busy waiting, frequent calls to this function are done.
        // But only the first one actually creates a new sender client.
        //
    }
}

/* EMPTY_ACCEPTOR_SOURCE */
#endif
