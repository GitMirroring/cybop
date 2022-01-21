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

#ifndef INTERRUPT_PIPE_READER_SOURCE
#define INTERRUPT_PIPE_READER_SOURCE

#include <unistd.h> // read

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/locker/locker.c"
#include "../../../../logger/logger.c"

/**
 * Reads message from interrupt pipe.
 *
 * @param p0 the destination server identification (server base + service port)
 * @param p1 the destination client identification (e.g. socket number, window id)
 * @param p2 the source interrupt pipe read file descriptor
 * @param p3 the interrupt mutex (currently unused in this function)
 */
void read_interrupt_pipe(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p2;

        //
        // CAUTION! Do NOT log messages within thread,
        // in order to avoid race conditions and other conflicts.
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read interrupt pipe.");
        fwprintf(stdout, L"Debug: Read interrupt pipe. f: %i\n", f);
        fwprintf(stdout, L"Debug: Read interrupt pipe. *f: %i\n", *f);

        //
        // CAUTION! Using a mutex would do no harm, but is
        // NOT necessary here, for the following reasons:
        //
        // 1 The values are only read but nothing is written.
        //
        // 2 While there may be potentially many threads
        //   writing to this interrupt pipe, there is just ONE
        //   function in file "empty_checker.c" reading it.
        //   Therefore, conflicts are impossible.
        //
        // 3 The order of the values in the pipe is unchanged.
        //   If new values are written to the pipe in one
        //   of the threads, then they are added at the end.
        //   A mutex is used for writing, so that all values
        //   belonging together are placed at once.
        //   Therefore, one can always be sure that the values
        //   being read in a sequence here really do belong together,
        //   to the same interrupt (event).
        //

        //
        // Read from interrupt pipe.
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
        int n1 = read(*f, p0, sizeof(int));
        int n2 = read(*f, p1, sizeof(int));

        fwprintf(stdout, L"Debug: Read interrupt pipe. n1: %i\n", n1);
        fwprintf(stdout, L"Debug: Read interrupt pipe. server p0: %i\n", p0);
        fwprintf(stdout, L"Debug: Read interrupt pipe. server *p0: %i\n", *((int*) p0));
        fwprintf(stdout, L"Debug: Read interrupt pipe. n2: %i\n", n2);
        fwprintf(stdout, L"Debug: Read interrupt pipe. client p1: %i\n", p1);
        fwprintf(stdout, L"Debug: Read interrupt pipe. client *p1: %i\n", *((int*) p1));

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read interrupt pipe. The source interrupt pipe read file descriptor is null.");
        fwprintf(stdout, L"Error: Could not read interrupt pipe. The source interrupt pipe read file descriptor is null. p2: %i\n", p2);
    }
}

/* INTERRUPT_PIPE_READER_SOURCE */
#endif
