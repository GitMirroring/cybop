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

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../executor/activator/channel_enabler.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../logger/logger.c"

/**
 * Enables the given channel for message sensing.
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (e.g. socket port)
 * @param p2 the handler part (pointer reference)
 * @param p3 the sender client data (pointer reference, e.g. client socket id, window id, file descriptor)
 * @param p4 the channel
 */
void enable(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable.");

    //?? fwprintf(stdout, L"Test: Enable. channel p4: %i\n", *((int*) p4));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            enable_channel(p0, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2, p3, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            enable_channel(p0, (void*) SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2, p3, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            enable_channel(p0, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2, p3, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Run sensing thread ONLY for unix terminal.
            //
            // CAUTION! A sensing thread for win32 console is NOT necessary,
            // since its input gets sensed in the main thread.
            // Therefore, the function "sense_unix_terminal" and NOT
            // "sense_terminal" is called here.
            //

#if defined(__linux__) || defined(__unix__)
            // Run sensing function in an own child thread.
            enable_channel(p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2, p3, TERMINAL_THREAD_IDENTIFICATION, (void*) &sense_unix_terminal);
#elif defined(__APPLE__) && defined(__MACH__)
            // Run sensing function in an own child thread.
            enable_channel(p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2, p3, TERMINAL_THREAD_IDENTIFICATION, (void*) &sense_unix_terminal);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            // Sense data input within checker loop of main thread.
            enable_channel(p0, (void*) TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, p1, p2, p3, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable. The channel is unknown.");
        fwprintf(stdout, L"Error: Could not enable. The channel is unknown. Channel p4: %i\n", *((int*) p4));
    }
}

/* ENABLER_SOURCE */
#endif
