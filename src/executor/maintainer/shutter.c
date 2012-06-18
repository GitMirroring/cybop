/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHUTTER_SOURCE
#define SHUTTER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
//?? #include "../../executor/maintainer/shutter/opengl_shutter.c"
//?? #include "../../executor/maintainer/shutter/socket_shutter.c"
#include "../../executor/maintainer/shutter/terminal_shutter.c"
//?? #include "../../executor/maintainer/shutter/x_window_system_shutter.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Shuts down the given service.
 *
 * CAUTION! Do NOT rename this function to "shutdown",
 * as that name is already used by low-level socket functionality
 * (/usr/include/i386-linux-gnu/sys/socket.h:232:12).
 *
 * @param p0 the internal memory data
 * @param p1 the channel
 */
void shutdown_service(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            shutdown_terminal(p0, (void*) TERMINAL_THREAD, (void*) TERMINAL_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) X_WINDOW_SYSTEM_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            shutdown_x_window_system(p0, (void*) X_WINDOW_SYSTEM_THREAD, (void*) X_WINDOW_SYSTEM_EXIT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) WWW_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            shutdown_socket(p0, (void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CYBOI_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            shutdown_socket(p0, (void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown. The channel is unknown.");
    }
}

/* SHUTTER_SOURCE */
#endif
