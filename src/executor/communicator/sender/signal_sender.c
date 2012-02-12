/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: cyboi_system_sending_communicator.c,v $ $Revision: 1.6 $ $Date: 2009-01-31 16:06:29 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_SENDER_SOURCE
#define SIGNAL_SENDER_SOURCE

#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../logger/logger.c"

/**
 * Sends a message as signal to the cyboi system (this system itself).
 *
 * @param p0 the internal memory array
 * @param p1 the source part
 */
void send_signal(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send signal.");

    // The signal memory item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory mutex.
    pthread_mutex_t* mt = (pthread_mutex_t*) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory interrupt request flag.
    sig_atomic_t* irq = (sig_atomic_t*) *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get signal memory item.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get signal memory mutex.
    copy_array_forward((void*) &mt, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_MUTEX_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get signal memory interrupt request flag.
    copy_array_forward((void*) &irq, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_INTERRUPT_REQUEST_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Lock signal memory mutex.
    pthread_mutex_lock(mt);

    // Add signal part to signal memory.
    append_item_element(s, (void*) &p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Set interrupt request flag, in order to notify the signal checker
    // that a new signal has been placed in the signal memory.
    copy_integer(irq, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // Unlock signal memory mutex.
    pthread_mutex_unlock(mt);
}

/* SIGNAL_SENDER_SOURCE */
#endif
