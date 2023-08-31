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

#include <stddef.h> // size_t
#include <stdio.h> // stdout
#include <unistd.h> // write
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"
#include "system.h"
#include "variable.h"

/**
 * Locks the mutex and writes the handler to the interrupt pipe.
 *
 * @param p0 the destination interrupt pipe write file descriptor
 * @param p1 the source handler (pointer reference)
 * @param p2 the source client identification
 * @param p3 the interrupt mutex
 */
void write_interrupt_pipe_exclusive(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write interrupt pipe exclusive.");
        //?? fwprintf(stdout, L"Debug: Write interrupt pipe exclusive. mutex p3: %i\n", p3);
        //?? fwprintf(stdout, L"Debug: Write interrupt pipe exclusive. mutex *p3: %i\n", *((int*) p3));

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
        size_t sp = (size_t) *POINTER_TYPE_SIZE;
        size_t si = (size_t) *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE;

        //
        // Lock mutex.
        //
        // CAUTION! A mutex HAS TO BE set here, since MANY threads
        // may want to write to the interrupt pipe concurrently.
        //
        lock(p3);

        //
        // Write to interrupt pipe.
        //
        // CAUTION! Do NOT write the client identification as
        // pointer value, also NOT as null pointer, for TWO reasons:
        //
        // 1 The actual VALUE that the pointer points to might get
        // CHANGED by other threads before having processed the value
        // in the main thread (race condition).
        //
        // 2 The reading side of the pipe expects an INTEGER value,
        // which has a SIZE of 4 Byte, while type pointer has a size
        // of 8 Byte on 64 bit platforms.
        //
        // CAUTION! The safe way is to use the functions "snprintf" and "strtol".
        // However, if both processes were created using the same compiler version,
        // one can take advantage of the fact that ANYTHING in C can be
        // read or written as an array of CHAR (byte).
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
        write(*f, p1, sp);
        write(*f, p2, si);

        // Unlock mutex.
        unlock(p3);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write interrupt pipe exclusive. The destination interrupt pipe write file descriptor is null.");
        fwprintf(stdout, L"Error: Could not write interrupt pipe exclusive. The destination interrupt pipe write file descriptor is null. p0: %i\n", p0);
    }
}
