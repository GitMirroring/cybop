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

#ifndef ALLOCATE_MODE_UNIX_TERMINAL_STARTER_SOURCE
#define ALLOCATE_MODE_UNIX_TERMINAL_STARTER_SOURCE

#include <stdlib.h> // malloc

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../variable/type_size/terminal_type_size.c"
#include "../../../../logger/logger.c"

/**
 * Allocates the terminal mode.
 *
 * @param p0 the terminal mode (pointer reference)
 */
void startup_unix_terminal_mode_allocate(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** m = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix terminal mode allocate.");

        //
        // Allocate terminal mode.
        //
        // The structure of type "struct termios" stores the
        // ENTIRE collection of attributes of a terminal / serial port.
        // It is used with the functions "tcgetattr" and
        // "tcsetattr" to get and set the attributes.
        //
        // CAUTION! When setting serial port modes, one should call "tcgetattr" first
        // to get the current modes of the particular serial port device,
        // modify only those modes that you are really interested in,
        // and store the result with tcsetattr.
        //
        // It's a bad idea to simply initialize a "struct termios" structure
        // to a chosen set of attributes and pass it directly to "tcsetattr".
        // The programme may be run years from now, on systems that support
        // members not documented here. The way to avoid setting these members
        // to unreasonable values is to avoid changing them.
        //
        // What's more, different serial port devices may require
        // different mode settings in order to function properly.
        // So you should avoid blindly copying attributes
        // from one serial port device to another.
        //
        // When a member contains a collection of independent flags,
        // as the c_iflag, c_oflag and c_cflag members do,
        // even setting the entire member is a bad idea,
        // because particular operating systems have their own flags.
        // Instead, one should start with the current value of the member
        // and alter only those flags whose values matter in the programme,
        // leaving any other flags unchanged.
        //

        *m = malloc(*TERMIOS_TERMINAL_TYPE_SIZE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix terminal mode allocate. The terminal mode is null.");
    }
}

/* ALLOCATE_MODE_UNIX_TERMINAL_STARTER_SOURCE */
#endif
