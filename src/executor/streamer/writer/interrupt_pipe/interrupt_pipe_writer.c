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

#ifndef INTERRUPT_PIPE_WRITER_SOURCE
#define INTERRUPT_PIPE_WRITER_SOURCE

#include <unistd.h> // write

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/locker/locker.c"
#include "../../../../logger/logger.c"

/**
 * Writes message to interrupt pipe.
 *
 * @param p0 the destination interrupt pipe write file descriptor
 * @param p1 the source server identification (server base + service port)
 * @param p2 the source client identification (e.g. socket number, window id)
 * @param p3 the interrupt mutex
 */
void write_interrupt_pipe(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        //
        // CAUTION! Do NOT log messages within thread,
        // in order to avoid race conditions and other conflicts.
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write interrupt pipe.");
        fwprintf(stdout, L"Debug: Write interrupt pipe. f: %i\n", f);
        fwprintf(stdout, L"Debug: Write interrupt pipe. *f: %i\n", *f);

        // Lock mutex.
        lock(p3);

        //
        // Write to interrupt pipe.
        //
        // - server identification (server base + service port)
        // - client identification
        //
        // CAUTION! The safe way is to use the functions "snprintf" and "strtol".
        // However, if both processes were created using the same compiler version,
        // one can take advantage of the fact that anything in C can be
        // read or written as an array of char (byte).
        //
        // Example:
        //
        // int n = something();
        // write(pipe_w, &n, sizeof(n));
        // int n;
        // read(pipe_r, &n, sizeof(n));
        //
        // https://stackoverflow.com/questions/5237041/how-to-send-integer-with-pipe-between-two-processes
        //
        write(*f, p1, sizeof(int));
        write(*f, p2, sizeof(int));

        // Unlock mutex.
        unlock(p3);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write interrupt pipe. The destination interrupt pipe write file descriptor is null.");
        fwprintf(stdout, L"Error: Could not write interrupt pipe. The destination interrupt pipe write file descriptor is null. p0: %i\n", p0);
    }
}

/* INTERRUPT_PIPE_WRITER_SOURCE */
#endif
