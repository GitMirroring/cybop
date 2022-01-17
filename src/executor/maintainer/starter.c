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

#ifndef STARTER_SOURCE
#define STARTER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/maintainer/channel_starter.c"
#include "../../executor/maintainer/general_starter.c"
#include "../../logger/logger.c"

/**
 * Starts up the given service.
 *
 * CAUTION! Do NOT rename this function to "startup",
 * since it should be consistent with "shutdown_service",
 * which cannot be renamed to "shutdown",
 * as that name is already used by low-level socket functionality:
 * /usr/include/i386-linux-gnu/sys/socket.h:232:12
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
 * @param p20 the channel (pointer reference)
 */
void startup_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup service.");
    fwprintf(stdout, L"Information: Startup service. p19: %i\n", p19);

    // The input/output base.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The thread function.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Determine channel-specific values.
    startup_channel((void*) &b, (void*) &f, p19);
    // Execute general startup functions.
    startup_general(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, (void*) &b, (void*) &f, p20);
}

/* STARTER_SOURCE */
#endif
