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
 * @version CYBOP 0.26.0 2023-04-04
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

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Writes handler and client identification to the interrupt pipe.
 *
 * @param p0 the destination interrupt pipe write file descriptor
 * @param p1 the source handler (pointer reference)
 * @param p2 the source client identification
 * @param p3 the interrupt mutex
 */
void write_interrupt_pipe(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* id = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** h = (void**) p1;

            // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write interrupt pipe.");
            //?? fwprintf(stdout, L"Debug: Write interrupt pipe. handler p1: %i\n", p1);
            //?? fwprintf(stdout, L"Debug: Write interrupt pipe. handler *p1: %i\n", *((int*) p1));

            // Check handler for existence.
            if (*h != *NULL_POINTER_STATE_CYBOI_MODEL) {

                //
                // A handler exists.
                //
                // The handler is OPTIONAL for some cybol operations and MAY be null.
                // It gets added to the interrupt pipe only if existing.
                //

                // Lock mutex and write handler and client identification to interrupt pipe.
                write_interrupt_pipe_exclusive(p0, p1, p2, p3);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write interrupt pipe. The source handler is null.");
            fwprintf(stdout, L"Error: Could not write interrupt pipe. The source handler is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write interrupt pipe. The source client identification is null.");
        fwprintf(stdout, L"Error: Could not write interrupt pipe. The source client identification is null. p2: %i\n", p2);
    }
}
