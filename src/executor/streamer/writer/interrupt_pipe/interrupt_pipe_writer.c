/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INTERRUPT_PIPE_WRITER_SOURCE
#define INTERRUPT_PIPE_WRITER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/pointer/unequal_pointer_comparator.c"
#include "../../../../executor/streamer/writer/interrupt_pipe/exclusive_interrupt_pipe_writer.c"
#include "../../../../logger/logger.c"

/**
 * Tests if the handler exists and writes it to the interrupt pipe.
 *
 * @param p0 the destination interrupt pipe write file descriptor
 * @param p1 the source handler (pointer reference)
 * @param p2 the interrupt mutex
 */
void write_interrupt_pipe(void* p0, void* p1, void* p2) {

    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write interrupt pipe.");
    fwprintf(stdout, L"Debug: Write interrupt pipe. handler p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Write interrupt pipe. handler *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Check handler for existence.
    compare_pointer_unequal((void*) &r, p1, NULL_POINTER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A handler exists.
        //
        // The handler is OPTIONAL and may be null.
        // It gets added to the interrupt pipe only if existing.
        //

        // Lock mutex and write handler to interrupt pipe.
        write_interrupt_pipe_exclusive(p0, p1, p2);
    }
}

/* INTERRUPT_PIPE_WRITER_SOURCE */
#endif
