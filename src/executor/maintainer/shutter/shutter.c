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

#ifndef SHUTTER_SOURCE
#define SHUTTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/maintainer/specific_shutter.c"
#include "../../../executor/maintainer/general_shutter.c"
#include "../../../logger/logger.c"

/**
 * Shuts down the given service.
 *
 * CAUTION! Do NOT rename this function to "shutdown",
 * as that name is already used by low-level socket functionality:
 * /usr/include/i386-linux-gnu/sys/socket.h:232:12
 *
 * @param p0 the internal memory data
 * @param p1 the socket port (service identification)
 * @param p2 the channel
 */
void shutdown_service(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT log messages here, since this function is called 65,536 times
    // for socket channels in a loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    //
    // log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown service.");
    //?? fwprintf(stdout, L"Information: Shutdown service. p2: %i\n", p2);

    // The input/output base.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Determine channel-specific values.
    shutdown_specific((void*) &b, p2);
    // Execute general shutdown functions.
    shutdown_general(p0, p1, p2, (void*) &b);
}

/* SHUTTER_SOURCE */
#endif
