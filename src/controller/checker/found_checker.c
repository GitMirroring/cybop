/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FOUND_CHECKER_SOURCE
#define FOUND_CHECKER_SOURCE

#include <pthread.h>

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/handler.c"
#include "../../executor/modifier/remover/item_remover.c"
#include "../../logger/logger.c"

/**
 * Handles a found signal.
 *
 * @param p0 the signal part
 * @param p1 the internal memory data
 * @param p2 the knowledge memory part
 * @param p3 the signal memory item
 * @param p4 the signal memory interrupt
 * @param p5 the signal memory mutex
 * @param p6 the shutdown flag
 */
void check_found(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check found.");

    // The direct execution flag.
    int x = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

//?? fwprintf(stdout, L"TEST check found p0: %i\n", p0);

    // Lock signal memory mutex.
//??    pthread_mutex_lock(p5);

    // Remove signal from signal memory.
    // CAUTION! Use POINTER_STATE_CYBOI_TYPE and NOT PART_ELEMENT_STATE_CYBOI_TYPE here,
    // since the latter causes the rubbish (garbage) collection to decrement the references count
    // of the removed part, so that it (wrongly) might get deallocated while still being used.
    remove_item(p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    // Reset interrupt request.
    //
    // Whenever a signal is added to the signal memory,
    // then the signal memory flag is set as well.
    // It gets reset when detecting the signal memory interrupt.
    //
    // CAUTION! However, when other signals happen to be processed right now,
    // then the signal that was just added is processed as well.
    // In this case, an interrupt detection does not take place.
    // But the signal memory interrupt HAS TO BE RESET ANYWAY,
    // since otherwise, the system's signal processing might get mixed up.
//??    copy_integer(p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Unlock signal memory mutex.
//??    pthread_mutex_unlock(p5);

    // Handle signal.
    handle(p0, p1, p2, p3, p4, p5, (void*) &x, p6);
}

/* FOUND_CHECKER_SOURCE */
#endif
