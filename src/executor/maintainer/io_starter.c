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

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/maintainer/allocate_io_maintainer.c"
#include "../../executor/maintainer/details_starter.c"
#include "../../executor/maintainer/get_io_maintainer.c"
#include "../../executor/maintainer/set_io_maintainer.c"
#include "../../logger/logger.c"

/**
 * Retrieves the input/output entry of the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (e.g. filename, socket port)
 * @param p2 the serial filename data
 * @param p3 the serial filename count
 * @param p4 the serial baudrate
 * @param p5 the socket family data (namespace)
 * @param p6 the socket family count
 * @param p7 the socket style data (communication type)
 * @param p8 the socket style count
 * @param p9 the socket protocol data
 * @param p10 the socket protocol count
 * @param p11 the blocking flag
 * @param p12 the socket filename data
 * @param p13 the socket filename count
 * @param p14 the socket host address data
 * @param p15 the socket host address count
 * @param p16 the socket connexions (number of possible pending client requests)
 * @param p17 the socket timeout
 * @param p18 the socket client socket
 * @param p19 the socket mode data
 * @param p20 the socket mode count
 * @param p21 the display client (window identification)
 * @param p22 the channel
 * @param p23 the input/output base
 */
void startup_io(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup io.");

    fwprintf(stdout, L"Test: Startup io. io_base *p23: %i\n", *((int*) p23));
    fwprintf(stdout, L"Test: Startup io. service_id *p1: %i\n", *((int*) p1));

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    maintain_io_get((void*) &io, p0, p23, p1);

    if (io == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The input/output entry (service) does NOT yet exist in internal memory.
        //

        // Allocate input/output entry.
        maintain_io_allocate((void*) &io);

        // Startup service details.
        startup_details(io, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22);

        // Set input/output entry.
        maintain_io_set(p0, (void*) &io, p23, p1);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup io. The input/output entry (service) is not null, i.e. it does already exist in internal memory.");

        //?? TEST ONLY! Delete later.
        startup_details(io, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22);
    }
}

/* IO_STARTER_SOURCE */
#endif
