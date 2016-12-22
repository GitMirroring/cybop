/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef UNIX_TERMINAL_SHUTTER_SOURCE
#define UNIX_TERMINAL_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../../executor/maintainer/shutter/unix_terminal/attributes_unix_terminal_shutter.c"
#include "../../../../executor/maintainer/shutter/unix_terminal/close_unix_terminal_shutter.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the unix terminal.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the input file descriptor item data
 * @param p1 the output file descriptor item data
 * @param p2 the internal memory data
 */
void shutdown_unix_terminal(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* o = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* i = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown unix terminal.");

            //
            // Restore original terminal attributes.
            //
            // Although tcgetattr and tcsetattr specify the terminal device with a file descriptor,
            // the attributes are those of the terminal device itself and not of the file descriptor.
            // This means that the effects of changing terminal attributes are persistent;
            // if another process opens the terminal file later on, it will see the changed attributes
            // even though it doesn't have anything to do with the open file descriptor originally
            // specified in changing the attributes.
            //
            // Similarly, if a single process has multiple or duplicated file descriptors
            // for the same terminal device, changing the terminal attributes affects
            // input and output to all of these file descriptors.
            // This means, for example, that one can't open one file descriptor or stream
            // to read from a terminal in the normal line-buffered, echoed mode;
            // and simultaneously have another file descriptor for the same terminal
            // that one uses to read from it in single-character, non-echoed mode.
            // Instead, one has to explicitly switch the terminal back and forth between the two modes.
            //
            // Therefore, it does not matter whether the input- OR
            // output file descriptor is specified here. EITHER may be used.
            // The attribute changes affect the whole terminal,
            // that is input AND output.
            //
            if (*i >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                shutdown_unix_terminal_attributes(p0, p2);

            } else if (*o >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                shutdown_unix_terminal_attributes(p1, p2);

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. The file descriptor is zero or negative.");
            }

            //
            // CAUTION! The input- and output file descriptors are NOT closed here,
            // since they reference the "stdin" and "stdout" streams of the system,
            // which MUST NOT be closed.
            //
            // However, if they have to be closed one day for some reason,
            // then do NOT put these function calls in the if-else branch
            // of the attributes above!
            // Whilst the attributes have to be reset just ONCE for the terminal,
            // no matter which of the file descriptors are given,
            // the file descriptors themselves have to be closed each, one by one.
            //
            // shutdown_unix_terminal_close(p0);
            // shutdown_unix_terminal_close(p1);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. The input item data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix terminal. The output item data is null.");
    }
}

/* UNIX_TERMINAL_SHUTTER_SOURCE */
#endif
