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

#ifndef GENERAL_STARTER_SOURCE
#define GENERAL_STARTER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/accessor/getter/internal_memory_getter.c"
#include "../../executor/accessor/setter/internal_memory_setter.c"
#include "../../executor/comparator/pointer/equal_pointer_comparator.c"
#include "../../executor/maintainer/io_starter.c"
#include "../../executor/maintainer/specific_starter.c"
#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../logger/logger.c"

/**
 * Starts up general things of the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the interrupt pipe (pointer reference)
 * @param p2 the interrupt mutex (pointer reference)
 * @param p3 the serial filename data
 * @param p4 the serial filename count
 * @param p5 the serial baudrate
 * @param p6 the socket family data (namespace)
 * @param p7 the socket family count
 * @param p8 the socket style data (communication type)
 * @param p9 the socket style count
 * @param p10 the socket protocol data
 * @param p11 the socket protocol count
 * @param p12 the socket filename data
 * @param p13 the socket filename count
 * @param p14 the socket host address data
 * @param p15 the socket host address count
 * @param p16 the socket port (service identification)
 * @param p17 the socket connexions (number of possible pending client requests)
 * @param p18 the socket timeout
 * @param p19 the channel
 * @param p20 the input/output base
 * @param p21 the thread function (pointer reference)
 * @param p22 the channel (pointer reference)
 */
void startup_general(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup general.");
    fwprintf(stdout, L"Debug: Startup general. p19: %i\n", p19);

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p0, p20, p16);

    if (io == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The input/output entry (service) does NOT yet exist in internal memory.
        //

        // The identification.
        int id = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Initialise identification.
        //
        // - add input/output base
        // - add service identification (port)
        //
        // CAUTION! If the service identification is NULL, then it is NOT copied here.
        // This is tested inside the "calculate_integer_add" function.
        // In this case, the input/output base added before remains AS IS,
        // which is the same as a service identification of ZERO.
        //
        // In other words, the service identification is ZERO BY DEFAULT.
        // Only for the socket channel, it gets replaced by the PORT number.
        //
        calculate_integer_add((void*) &id, p20);
        calculate_integer_add((void*) &id, p16);
        //
        // Allocate input/output entry.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &io, (void*) IO_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
        // Set input/output entry.
        set_internal_memory_element(p0, (void*) &io, p20, p16);
        // Startup input/output entry.
        startup_io(io, p1, p2, (void*) &id, p21, (void*) &io, p18, p22);
        // Execute channel-specific startup functions.
        startup_specific(io, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup general. The input/output entry (service) is not null, i.e. it does already exist in internal memory.");
        fwprintf(stdout, L"Warning: Could not startup general. The input/output entry (service) is not null, i.e. it does already exist in internal memory.\n");
    }
}

/* GENERAL_STARTER_SOURCE */
#endif
