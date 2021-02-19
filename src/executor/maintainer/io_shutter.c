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

#ifndef IO_SHUTTER_SOURCE
#define IO_SHUTTER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/maintainer/deallocate_io_maintainer.c"
#include "../../executor/maintainer/details_shutter.c"
#include "../../executor/maintainer/get_io_maintainer.c"
#include "../../executor/maintainer/set_io_maintainer.c"
#include "../../logger/logger.c"

/**
 * Shuts down the given service.
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (e.g. socket port)
 * @param p2 the socket client socket
 * @param p3 the socket mode data
 * @param p4 the socket mode count
 * @param p5 the channel
 * @param p6 the input/output base
 */
void shutdown_io(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! This log message has been commented out
    // due to the large number of potential calls caused
    // by the the number of socket services (65536).
    // See file "shutdown_manager.c".
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown io.");

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    maintain_io_get((void*) &io, p0, p6, p1);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The input/output entry (service) DOES exist in internal memory.
        //

        //
        // Reset input/output entry.
        //
        // CAUTION! It is ESSENTIAL to assign NULL here,
        // since cyboi tests for null pointers and otherwise,
        // wild pointers would lead to memory corruption.
        //
        // CAUTION! Do NOT use the "modify_array" (overwrite) function,
        // since it adapts the array count and size.
        // But the internal memory array's count and size are CONSTANT.
        //
        // CAUTION! Hand over null as pointer reference NULL_POINTER_STATE_CYBOI_MODEL
        // and NOT as dereferenced pointer *NULL_POINTER_STATE_CYBOI_MODEL.
        //
        maintain_io_set(p0, NULL_POINTER_STATE_CYBOI_MODEL, p6, p1);

        // Shutdown service details.
        shutdown_details(io, p2, p3, p4, p5);

        // Deallocate input/output entry.
        maintain_io_deallocate((void*) &io);

    } else {

        //
        // CAUTION! This log message has been commented out
        // due to the large number of potential calls caused
        // by the the number of socket services (65536).
        // See file "shutdown_manager.c".
        //
        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown io. The input/output entry (service) is null, i.e. it does not exist in internal memory.");
    }
}

/* IO_SHUTTER_SOURCE */
#endif
