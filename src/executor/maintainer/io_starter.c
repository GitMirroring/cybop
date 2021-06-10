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

#ifndef IO_STARTER_SOURCE
#define IO_STARTER_SOURCE

#include <threads.h>

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/maintainer/details_starter.c"
#include "../../executor/maintainer/get_io_maintainer.c"
#include "../../executor/maintainer/set_io_maintainer.c"
#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../logger/logger.c"
#include "../../variable/symbolic_name/mutex_thread_symbolic_name.c"

/**
 * Retrieves the input/output entry of the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the serial filename data
 * @param p2 the serial filename count
 * @param p3 the serial baudrate
 * @param p4 the socket family data (namespace)
 * @param p5 the socket family count
 * @param p6 the socket style data (communication type)
 * @param p7 the socket style count
 * @param p8 the socket protocol data
 * @param p9 the socket protocol count
 * @param p10 the blocking flag
 * @param p11 the socket filename data
 * @param p12 the socket filename count
 * @param p13 the socket host address data
 * @param p14 the socket host address count
 * @param p15 the socket port
 * @param p16 the socket connexions (number of possible pending client requests)
 * @param p17 the socket timeout
 * @param p18 the channel
 * @param p19 the input/output base
 */
void startup_io(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup io.");

    // The service identification (id).
    int id = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Copy socket port to be used as service identification (id).
    //
    // CAUTION! The value gets copied ONLY if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //
    // In other words, the identification is ZERO BY DEFAULT.
    // Only for the socket channel, it gets replaced by the PORT number.
    //
    copy_integer((void*) &id, p15);

    fwprintf(stdout, L"Test: Startup io. io base *p19: %i\n", *((int*) p19));
    fwprintf(stdout, L"Test: Startup io. service id: %i\n", id);

    // Get input/output entry.
    maintain_io_get((void*) &io, p0, p19, (void*) &id);

    if (io == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The input/output entry (service) does NOT yet exist in internal memory.
        //

        // The mutex.
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Allocate input/output entry.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &io, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);
        //
        // Allocate mutex.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &m, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);

        // Create and initialise mutex.
        mtx_init((mtx_t*) m, *PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME);

        // Set mutex in input/output entry.
        set_io_entry_element(io, (void*) &m, (void*) MUTEX_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Startup service details.
        startup_details(io, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18);

        // Set input/output entry.
        maintain_io_set(p0, (void*) &io, p19, (void*) &id);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup io. The input/output entry (service) is not null, i.e. it does already exist in internal memory.");
    }
}

/* IO_STARTER_SOURCE */
#endif
