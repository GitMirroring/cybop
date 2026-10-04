/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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
#include "constant.h"
#include "logger.h"
#include "server.h"

/**
 * Enables client requests or events via endless loop.
 *
 * @param p0 the destination request input buffer item
 * @param p1 the destination request input buffer mutex
 * @param p2 the server entry
 * @param p3 the channel
 * @param p4 the interrupt pipe write file descriptor
 * @param p5 the handler (pointer reference)
 * @param p6 the interrupt mutex
 * @param p7 the enable thread exit flag
 */
void enable_loop(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable loop.");
    //?? fwprintf(stdout, L"Debug: Enable loop. enable thread exit flag p7: %i\n", p7);
    //?? fwprintf(stdout, L"Debug: Enable loop. enable thread exit flag *p7: %i\n", *((int*) p7));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The exit flag was set in the main thread.
            // Therefore, leave this endless loop now.
            // This child thread gets exited when this
            // and its calling functions return.
            //

            break;
        }

        enable_request(p0, p1, p2, p3, p4, p5, p6);
    }
}
