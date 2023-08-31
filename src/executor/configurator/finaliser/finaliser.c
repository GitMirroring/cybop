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

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "client.h"
#include "constant.h"
#include "logger.h"

/**
 * Finalises the device belonging to the given channel.
 *
 * @param p0 the file descriptor
 * @param p1 the client entry
 * @param p2 the channel
 */
void finalise(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Finalise.");
    //?? fwprintf(stdout, L"Debug: Finalise. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Finalise. *p2: %i\n", *((int*) p2));

    //
    // CAUTION! The terminal and serial port could be treated ALMOST identically.
    // However, there are TWO reasons for treating them DIFFERENTLY here:
    //
    // 1 The original terminal mode has to be stored at DIFFERENT indices in client entry.
    //
    // 2 The windows operating system uses DIFFERENT values and functions in win32 api, e.g.:
    // - DCB structure: serial port setting
    // - GetCommState function: access serial port setting
    // - DWORD integer: console mode flags
    // - GetConsoleMode function: access console mode
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            finalise_serial_port(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            finalise_terminal(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not finalise. The channel is unknown. This is unproblematic, since most devices do not need an finalisation.");
        // fwprintf(stdout, L"Warning: Could not finalise. The channel is unknown. This is unproblematic, since most devices do not need an finalisation. p2: %i\n", p2);
        // fwprintf(stdout, L"Warning: Could not finalise. The channel is unknown. This is unproblematic, since most devices do not need an finalisation. *p2: %i\n", *((int*) p2));
    }
}
