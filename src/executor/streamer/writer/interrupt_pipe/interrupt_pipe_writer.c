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

#include <stddef.h> // size_t
#include <unistd.h> // write

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../executor/porter/locker.c"
#include "../../../../executor/porter/unlocker.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/pointer_type_size.c"

/**
 * Writes message to interrupt pipe.
 *
 * @param p0 the destination interrupt pipe write file descriptor
 * @param p1 the source handler (pointer reference)
 * @param p2 the interrupt mutex
 */
void write_interrupt_pipe(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write interrupt pipe.");
        fwprintf(stdout, L"Debug: Write interrupt pipe. handler p1: %i\n", p1);
        fwprintf(stdout, L"Debug: Write interrupt pipe. handler *p1: %i\n", *((int*) p1));

        //
        // Cast size to correct type.
        //
        // CAUTION! It IS NECESSARY because on 64 Bit machines,
        // the "size_t" type has a size of 8 Byte, whereas
        // the "int" type has the usual size of 4 Byte.
        // When trying to dereference a pointer that uses the other type,
        // memory errors will occur and the valgrind memcheck tool report:
        // "Invalid read of size 8".
        //
        size_t s = (size_t) *POINTER_TYPE_SIZE;

        //
        // Lock mutex.
        //
        // CAUTION! A mutex HAS TO BE set here, since MANY threads
        // may want to write to the interrupt pipe concurrently.
        //
        lock(p2);

        //
        // Write to interrupt pipe.
        //
        // It does not matter what is written to inform the main thread.
        // Therefore, the simple integer value of 1 (true) is put into the pipe.
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
        //?? write(*f, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, s);
        write(*f, p1, s);

        // Unlock mutex.
        unlock(p2);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write interrupt pipe. The destination interrupt pipe write file descriptor is null.");
        fwprintf(stdout, L"Error: Could not write interrupt pipe. The destination interrupt pipe write file descriptor is null. p0: %i\n", p0);
    }
}

/* INTERRUPT_PIPE_WRITER_SOURCE */
#endif
