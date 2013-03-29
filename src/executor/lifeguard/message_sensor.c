/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MESSAGE_SENSOR_SOURCE
#define MESSAGE_SENSOR_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Senses a message.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the thread procedure
 */
void sense_message(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense message.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Only create thread, if not existent.
    //
    // CAUTION! Thread variables were initialised with -1 at system startup.
    // They are also reset to -1 when being interrupted.
    // If existent, a thread should therefore be unequal -1.
    //
    // CAUTION! The "pthread_t" type is an integer,
    // which is why both can be compared.
    //
    // CAUTION! This comparison also covers the case
    // in which the thread parametre is null.
    // It is IMPORTANT that the thread is NOT NULL,
    // since it is handed over as parametre to the
    // "pthread_create" glibc function further below,
    // which may not check for null and exit the cyboi process.
    compare_integer_equal((void*) &r, p1, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The thread does not exist, i.e. it was not yet created before.

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense message -- create thread.");

        // Create thread.
        //
        // CAUTION! Do NOT allocate any resources within the thread procedure!
        // The reason is that this main process thread gets forked when executing
        // external programs. A "fork" duplicates ALL resources of the parent process,
        // including ALL resources of any threads running within the parent process.
        // However, since the created child process does not have those threads running,
        // their duplicated resources will never be deallocated, which eats up memory.
        // See source code file: applicator/run/run_execute.c
        //
        // Any dynamically allocated resources needed within the thread have to be:
        // - allocated at service startup
        // - added to the internal memory
        // - handed over to the thread procedure HERE (as internal memory)
        // - deallocated at service shutdown
        //
        // The second parametre determines attributes for the new thread.
        // If it is NULL, then the thread is created with default attributes.
        //
        // The third parametre is the procedure to be called.
        pthread_create((pthread_t*) p1, *NULL_POINTER_STATE_CYBOI_MODEL, p2, p0);
    }
}

/* MESSAGE_SENSOR_SOURCE */
#endif
