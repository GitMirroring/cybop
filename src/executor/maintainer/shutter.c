/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SHUTTER_SOURCE
#define SHUTTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/maintainer/shutter/display/display_shutter.c"
#include "../../executor/maintainer/shutter/serial_port/serial_port_shutter.c"
#include "../../executor/maintainer/shutter/socket/socket_shutter.c"
#include "../../executor/maintainer/shutter/terminal/terminal_shutter.c"
#include "../../executor/maintainer/starter/deallocate_io_maintainer.c"
#include "../../executor/maintainer/starter/get_io_maintainer.c"
#include "../../executor/maintainer/starter/set_io_maintainer.c"
#include "../../logger/logger.c"

/**
 * Shuts down the given service.
 *
 * CAUTION! Do NOT rename this function to "shutdown",
 * as that name is already used by low-level socket functionality:
 * /usr/include/i386-linux-gnu/sys/socket.h:232:12
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (e.g. socket port)
 * @param p2 the socket client socket
 * @param p3 the socket mode data
 * @param p4 the socket mode count
 * @param p5 the socket network service data
 * @param p6 the socket network service count
 * @param p7 the channel
 */
void shutdown_service(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Reset input/output entry in internal memory to null.
            //
            // CAUTION! It is ESSENTIAL to assign NULL here,
            // since cyboi tests for null pointers and otherwise,
            // wild pointers would lead to memory corruption.
            //
            // CAUTION! Do NOT use the "modify_array" (overwrite) function,
            // since it adapts the array count and size.
            // But the internal memory array's count and size are CONSTANT.
            // Therefore, a simple "copy" function is used here.
            //

            shutdown_display(io);
            shutdown_io((void*) &io, p0, DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Reset input/output entry in internal memory to null.
            //
            // CAUTION! It is ESSENTIAL to assign NULL here,
            // since cyboi tests for null pointers and otherwise,
            // wild pointers would lead to memory corruption.
            //
            // CAUTION! Do NOT use the "modify_array" (overwrite) function,
            // since it adapts the array count and size.
            // But the internal memory array's count and size are CONSTANT.
            // Therefore, a simple "copy" function is used here.
            //

            shutdown_serial_port(p0);
            shutdown_io((void*) &io, p0, SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Reset input/output entry in internal memory to null.
            //
            // CAUTION! It is ESSENTIAL to assign NULL here,
            // since cyboi tests for null pointers and otherwise,
            // wild pointers would lead to memory corruption.
            //
            // CAUTION! Do NOT use the "modify_array" (overwrite) function,
            // since it adapts the array count and size.
            // But the internal memory array's count and size are CONSTANT.
            // Therefore, a simple "copy" function is used here.
            //

            shutdown_socket(p0, p1, p2, p3, p4, p5, p6);
            shutdown_io((void*) &io, p0, SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            maintain_io_get((void*) &io, p0, TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);

            if (*io != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // The input/output entry, i.e. service, DOES exist in internal memory.

                //
                // Reset input/output entry in internal memory to null.
                //
                // CAUTION! It is ESSENTIAL to assign NULL here,
                // since cyboi tests for null pointers and otherwise,
                // wild pointers would lead to memory corruption.
                //
                // CAUTION! Do NOT use the "modify_array" (overwrite) function,
                // since it adapts the array count and size.
                // But the internal memory array's count and size are CONSTANT.
                //
                maintain_io_set(p0, NULL_POINTER_STATE_CYBOI_MODEL, TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
                shutdown_terminal(io);
                maintain_io_deallocate((void*) &io, p0, TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1);
            }
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown. The channel is unknown.");
    }
}

/* SHUTTER_SOURCE */
#endif
