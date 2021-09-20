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

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../executor/accessor/getter/internal_memory_getter.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/maintainer/shutter/display/display_shutter.c"
#include "../../executor/maintainer/shutter/serial_port/serial_port_shutter.c"
#include "../../executor/maintainer/shutter/socket/socket_shutter.c"
#include "../../executor/maintainer/shutter/terminal/terminal_shutter.c"
#include "../../executor/maintainer/io_shutter.c"
#include "../../logger/logger.c"

/**
 * Shuts down the given service.
 *
 * CAUTION! Do NOT rename this function to "shutdown",
 * as that name is already used by low-level socket functionality:
 * /usr/include/i386-linux-gnu/sys/socket.h:232:12
 *
 * @param p0 the internal memory data
 * @param p1 the socket port
 * @param p2 the channel
 */
void shutdown_service(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT log messages here, since this function is called 65,536 times
    // for socket channels in a loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    //
    // log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown service.");
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p0, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
            // Shutdown service.
            shutdown_display(io);
            // Shutdown input/output entry.
            shutdown_io((void*) &io, p0, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p0, (void*) SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
            // Shutdown service.
            //?? shutdown_serial_port(io);
            // Shutdown input/output entry.
            shutdown_io((void*) &io, p0, (void*) SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p0, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
            // Shutdown service.
            shutdown_socket(io);
            // Shutdown input/output entry.
            shutdown_io((void*) &io, p0, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
            //
            // Disable channel and exit sensing thread.
            //
            // CAUTION! This has to be done BEFORE deallocating resources
            // in the call of function "shutdown_terminal" further below
            // since otherwise, the terminal properties are reset.
            //
            disable_channel(p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2);
            // Shutdown service.
            shutdown_terminal(io);
            // Shutdown input/output entry.
            shutdown_io((void*) &io, p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown service. The channel is unknown.");
    }
}

/* SHUTTER_SOURCE */
#endif
