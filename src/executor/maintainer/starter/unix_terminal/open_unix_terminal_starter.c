/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPEN_UNIX_TERMINAL_STARTER_SOURCE
#define OPEN_UNIX_TERMINAL_STARTER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/unix_terminal/get_attributes_unix_terminal_starter.c"
#include "../../../../logger/logger.c"

/**
 * Opens the unix terminal.
 *
 * @param p0 the input file descriptor item data
 * @param p1 the output file descriptor item data
 * @param p2 the internal memory data
 */
void startup_unix_terminal_open(void* p0, void* p1, void* p2) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* o = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* i = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix terminal open.");

            // The input- and output file stream.
            FILE* is = stdin;
            FILE* os = stdout;

            // Get input- and output file descriptor item data
            // as integer from input- and output file stream.
            *i = fileno(is);
            *o = fileno(os);

            //
            // Get and set attributes of terminal.
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

                startup_unix_terminal_attributes_get(p0, p2);

            } else if (*o >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                startup_unix_terminal_attributes_get(p1, p2);

            } else {

                // The normal return value from "open" is a
                // non-negative integer file descriptor.
                // In the case of an error, a value of
                // minus one is returned instead.

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal open. The input- or output file descriptor is invalid.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal open. The input item data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal open. The output item data is null.");
    }
}

/* OPEN_UNIX_TERMINAL_STARTER_SOURCE */
#endif
