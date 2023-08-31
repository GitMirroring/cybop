/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <errno.h> // errno
#include <stdio.h> // stdout
#include <termios.h> // struct termios, tcsetattr
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Sets the unix terminal mode into the device pointed to by the file descriptor.
 *
 * @param p0 the destination file descriptor
 * @param p1 the source terminal mode
 */
void set_unix_terminal_mode(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        struct termios* m = (struct termios*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* f = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set unix terminal mode.");

            //
            // Initialise error number.
            //
            // It is a global variable and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling
            // the function that might cause an error.
            //
            errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            //
            // Set terminal mode.
            //
            // The second argument specifies how to deal with
            // input and output already queued.
            // It can be one of the following values:
            // TCSANOW - Make the change immediately.
            // TCSADRAIN - Make the change after waiting until all queued output has been written.
            //             You SHOULD usually USE this option when changing parameters that affect output.
            // TCSAFLUSH - This is like TCSADRAIN, but also discards any queued input.
            // TCSASOFT - This is a flag bit that you can add to any of the above alternatives.
            //            Its meaning is to inhibit alteration of the state of the terminal hardware.
            //            It is a BSD extension; it is only supported on BSD systems and the GNU system.
            //            Using TCSASOFT is exactly the same as setting the CIGNORE bit in the c_cflag member of the structure termios-p points to.
            //
            int r = tcsetattr(*f, TCSANOW, m);

            if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set unix terminal mode. An error occured.");
                fwprintf(stdout, L"Error: Could not set unix terminal mode. An error occured. r: %i\n", r);
                log_error((void*) &errno);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set unix terminal mode. The destination file descriptor is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set unix terminal mode. The source terminal mode is null.");
    }
}
