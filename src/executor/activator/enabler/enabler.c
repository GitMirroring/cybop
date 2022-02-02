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

#ifndef ENABLER_SOURCE
#define ENABLER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/accessor/getter/channel_internal_memory_getter.c"
#include "../../../executor/activator/enabler/entry_enabler.c"
#include "../../../executor/activator/enabler/thread_enabler.c"
#include "../../../logger/logger.c"

/**
 * Enables the service on the given channel.
 *
 * @param p0 the internal memory
 * @param p1 the channel (pointer reference)
 * @param p2 the port (pointer reference)
 * @param p3 the sender client identification (pointer reference)
 * @param p4 the handler (pointer reference)
 */
void enable(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** p = (void**) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** c = (void**) p1;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable.");
            fwprintf(stdout, L"Information: Enable. p1: %i\n", p1);
            fwprintf(stdout, L"Information: Enable. *p1: %i\n", *((void**) p1));
            fwprintf(stdout, L"Information: Enable. **p1: %i\n", *((int*) *((void**) p1)));

            // The server entry.
            void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get server entry from internal memory.
            get_internal_memory_channel((void*) &e, p0, *c, *p);

            // Assign parametres to server entry.
            enable_entry(e, p1, p2, p3, p4);

            // Invoke enable function within a new thread.
            enable_thread(e);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable. The channel is null.");
            fwprintf(stdout, L"Error: Could not enable. The channel is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable. The port is null.");
        fwprintf(stdout, L"Error: Could not enable. The port is null. p2: %i\n", p2);
    }
}

/* ENABLER_SOURCE */
#endif
