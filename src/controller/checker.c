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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHECKER_SOURCE
#define CHECKER_SOURCE

#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../controller/checker/signal_checker.c"
#include "../executor/modifier/copier/array_copier.c"
#include "../logger/logger.c"

/**
 * Checks the signal memory for signals.
 *
 * @param p0 the internal memory data
 */
void check(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n\n");
    log_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) CHECK_FOR_SIGNALS_MESSAGE_LOG_CYBOI_MODEL, (void*) CHECK_FOR_SIGNALS_MESSAGE_LOG_CYBOI_MODEL_COUNT);

    // CAUTION! The parametres were not handed over as function arguments,
    // since it is more flexible to just hand over the internal memory as argument.
    //
    // It is very likely that new services (besides terminal, x window system, socket etc.)
    // will be added in the future. So it is easier not to have to change the function arguments,
    // but instead just retrieve them from the internal memory below.
    //
    // CAUTION! ALL parametres are retrieved from the internal memory HERE,
    // in other words just once at system startup, since doing so within
    // the loop further below would eat up precious cpu time.

    // The knowledge memory part.
    void* k = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory item, interrupt, mutex, sleep time.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* irq = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mt = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get knowledge memory part.
    copy_array_forward((void*) &k, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get signal memory item, interrupt, mutex, sleep time.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &irq, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mt, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &st, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SLEEP_TIME_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // The shutdown flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Run endless loop checking signal memory for signals.
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Leave loop if shutdown flag was set.
            break;
        }

        check_signal(p0, k, s, irq, mt, st, (void*) &f);
    }
}

/* CHECKER_SOURCE */
#endif
