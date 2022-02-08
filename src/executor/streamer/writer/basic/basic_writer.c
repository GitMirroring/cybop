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

#ifndef BASIC_WRITER_SOURCE
#define BASIC_WRITER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"
--
#include <errno.h> // errno
#include <stddef.h> // size_t
#include <unistd.h> // write

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/locker/locker.c"
#include "../../../../executor/locker/unlocker.c"
#include "../../../../executor/modifier/item_modifier.c"

/**
 * Writes data.
 *
 * CAUTION! Do NOT rename this function to "write",
 * as that name is already used by low-level glibc functionality.
 *
 * @param p0 the destination file descriptor (a file, serial port, terminal, socket)
 * @param p1 the source message data
 * @param p2 the source message count
 * @param p3 the close flag
 */
void write_basic(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* mc = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* f = (int*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write basic.");
                fwprintf(stdout, L"Debug: Write basic. f: %i\n", f);
                fwprintf(stdout, L"Debug: Write basic. *f: %i\n", *((int*) f));

                //
                // Cast message count to correct type.
                //
                // CAUTION! It IS NECESSARY because on 64 Bit machines,
                // the "size_t" type has a size of 8 Byte,
                // whereas the "int" type has the usual size of 4 Byte.
                // When trying to cast between the two, memory errors
                // will occur and the valgrind memcheck tool report:
                // "Invalid read of size 8".
                //
                size_t mct = (size_t) *mc;
                fwprintf(stdout, L"Debug: Write basic. mct: %i\n", mct);

                //
                // Initialise error number.
                //
                // It is a global variable and other functions
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                //
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                //
                // Read data from file descriptor.
                //
                // CAUTION! Using the function "send" is NOT necessary,
                // since its flags argument (fourth one) would be zero,
                // because no special options are needed.
                // Therefore, the function "write" suffices here.
                //
                // CAUTION! The function "write" is BLOCKING by default.
                // So, there is NO reason to set the blocking mode
                // manually using the functions "ioctl" or "setsockopt".
                //
                // CAUTION! The write operation does not necessarily
                // handle all the bytes handed over to it, because
                // its major focus is handling the (network) buffers.
                // In general, it returns when the associated
                // (network) buffers have been filled.
                // It then returns the number of handled bytes.
                //
                // Therefore, this "write" function has to be called
                // in a LOOP, until the complete message has been transmitted.
                //
                ssize_t nb = write(*f, p1, mct);

                // Cast number of bytes actually written to general type.
                int n = (int) nb;

                if (n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write basic. Success.");
                    fwprintf(stdout, L"Debug: Write basic. Success. n: %i\n", n);

                } else if (n == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    //
                    // Socket communication:
                    //
                    // A return value of ZERO means the other end (peer)
                    // CLOSED the socket connexion.
                    //
                    // Therefore, the socket on this side may be closed,
                    // since the other side has closed its connexion.
                    //
                    // CAUTION! Do NOT close socket directly here.
                    // If this is a client socket, then its client entry
                    // resources have to be freed as well,
                    // which is done in the calling function.
                    //

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. Set close flag.");
                    fwprintf(stdout, L"Debug: Could not write basic. Set close flag. n: %i\n", n);

                    // Set close flag.
                    copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. An error occured.");
                    fwprintf(stdout, L"Error: Could not write basic. An error occured. %i\n", r);
                    log_errno((void*) &errno);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. The destination file descriptor is null.");
                fwprintf(stdout, L"Error: Could not write basic. The destination file descriptor is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. The source message data is null.");
            fwprintf(stdout, L"Error: Could not write basic. The source message data is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. The source message count is null.");
        fwprintf(stdout, L"Error: Could not write basic. The source message count is null. p2: %i\n", p2);
    }
}

/* BASIC_WRITER_SOURCE */
#endif
