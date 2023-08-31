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
#include <unistd.h> // read
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "logger.h"
#include "variable.h"

/**
 * Reads message from interrupt pipe.
 *
 * @param p0 the destination handler (pointer reference)
 * @param p1 the destination client identification
 * @param p2 the source interrupt pipe read file descriptor
 */
void read_interrupt_pipe(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read interrupt pipe.");
                //?? fwprintf(stdout, L"Debug: Read interrupt pipe. f: %i\n", f);
                //?? fwprintf(stdout, L"Debug: Read interrupt pipe. *f: %i\n", *f);

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
                // CAUTION! Do NOT lock a MUTEX for reading the pipe.
                //
                // It is not necessary here, for the following reasons:
                //
                // 1 The values are only READ but nothing is written.
                //
                // 2 While there may be potentially many threads
                //   WRITING to this interrupt pipe, there is just ONE
                //   function in the main signal (event) loop reading it.
                //   Therefore, conflicts are impossible.
                //
                // 3 The ORDER of the values in the pipe is UNCHANGED.
                //   If new values are written to the pipe in one
                //   of the threads, then they are added at the end.
                //   A MUTEX is used for WRITING, so that all values
                //   belonging together are placed at once.
                //   Therefore, one can always be sure that the values
                //   being read in a sequence here really do belong together,
                //   to the same interrupt.
                //
                // CAUTION! If a mutex was set here, then the "read" function
                // would block FOREVER, without any input thread having
                // the chance to write to it, due to the LOCK.
                //

                //
                // Read from interrupt pipe.
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
                int np = read(*f, p0, sp);
                int ni = read(*f, p1, si);

                //?? fwprintf(stdout, L"Debug: Read interrupt pipe. np: %i\n", np);
                //?? fwprintf(stdout, L"Debug: Read interrupt pipe. ni: %i\n", ni);

                //?? fwprintf(stdout, L"Debug: Read interrupt pipe. handler p0: %i\n", p0);
                //?? fwprintf(stdout, L"Debug: Read interrupt pipe. handler *p0: %i\n", *((int*) p0));

                //?? fwprintf(stdout, L"Debug: Read interrupt pipe. handler p1: %i\n", p1);
                //?? fwprintf(stdout, L"Debug: Read interrupt pipe. handler *p1: %i\n", *((int*) p1));

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read interrupt pipe. The destination handler is null.");
                fwprintf(stdout, L"Error: Could not read interrupt pipe. The destination handler is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read interrupt pipe. The destination client identification is null.");
            fwprintf(stdout, L"Error: Could not read interrupt pipe. The destination client identification is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read interrupt pipe. The source interrupt pipe read file descriptor is null.");
        fwprintf(stdout, L"Error: Could not read interrupt pipe. The source interrupt pipe read file descriptor is null. p2: %i\n", p2);
    }
}
