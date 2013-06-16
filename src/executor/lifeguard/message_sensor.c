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
 * @version CYBOP 0.14.0 2013-05-31
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

    // It is IMPORTANT that the thread is NOT NULL,
    // since it is handed over as parametre to the
    // "pthread_create" glibc function further below,
    // which possibly does not check for null and
    // exit the whole cyboi process.
    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        pthread_t* t = (pthread_t*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense message.");

        // Compare thread identifications.
        //
        // Returns a non-zero value (true) if t1 and t2
        // are equal and zero if they are unequal (false).
        //
        // CAUTION! The pthread implementation under
        // mingw win32 uses a struct and NOT a scalar value.
        //
        int r = pthread_equal(DEFAULT_THREAD, *t);

        // CAUTION! Create thread ONLY if NOT existent.
        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // The returned value is non-zero, which means
            // that both threads compared above are EQUAL.
            // Since one of the two thread variables was
            // introduced with empty initialisation,
            // this means that the other is empty, too.
            // Therefore, the thread has NOT been created
            // before and CAN be created below now.

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense message. Create thread.");

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
            pthread_create(t, *NULL_POINTER_STATE_CYBOI_MODEL, p2, p0);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense message. The thread is null.");
    }
}

/* MESSAGE_SENSOR_SOURCE */
#endif
