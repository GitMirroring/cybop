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

#include <errno.h> // errno
#include <stddef.h> // size_t
#include <unistd.h> // write

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/porter/locker.c"
#include "../../../../executor/porter/unlocker.c"
#include "../../../../logger/logger.c"

/**
 * Writes data.
 *
 * CAUTION! Do NOT rename this function to "write",
 * as that name is already used by low-level glibc functionality.
 *
 * @param p0 the destination file descriptor (a file, serial port, terminal, socket)
 * @param p1 the source buffer data (pointer reference)
 * @param p2 the source buffer count
 * @param p3 the source buffer size
 * @param p4 the source buffer type
 * @param p5 the source buffer mutex
 * @param p6 the loop break flag
 */
void write_basic(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* c = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** d = (void**) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* f = (int*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write basic.");
                fwprintf(stdout, L"Debug: Write basic. f: %i\n", f);
                fwprintf(stdout, L"Debug: Write basic. *f: %i\n", *((int*) f));

                //
                // Cast buffer count to correct type.
                //
                // CAUTION! It IS NECESSARY because on 64 Bit machines,
                // the "size_t" type has a size of 8 Byte,
                // whereas the "int" type has the usual size of 4 Byte.
                // When trying to cast between the two, memory errors
                // will occur and the valgrind memcheck tool report:
                // "Invalid read of size 8".
                //
                size_t ct = (size_t) *c;
                fwprintf(stdout, L"Debug: Write basic. ct: %i\n", ct);

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
                // Write data to device given by the file descriptor.
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
                // in a LOOP, until all data have been transmitted.
                //
                ssize_t nb = write(*f, *d, ct);

                // Cast number of bytes actually written to general type.
                int n = (int) nb;

                if (n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write basic. Success.");
                    fwprintf(stdout, L"Debug: Write basic. Success. n: %i\n", n);

                    // The comparison result.
                    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                    compare_integer_greater_or_equal((void*) &r, (void*) &n, p2);

                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        //
                        // ALL data have been transmitted.
                        //

                        fwprintf(stdout, L"Debug: Write basic. All data have been transmitted. r: %i\n", r);

                        // Set loop break flag.
                        copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                    } else {

                        //
                        // Only SOME data have been transmitted.
                        //

                        fwprintf(stdout, L"Debug: Write basic. Only SOME data have been transmitted. r: %i\n", r);

                        //
                        // Lock mutex.
                        //
                        // CAUTION! New data may be written into the source buffer in
                        // the main thread, in case this writer is called asynchronously
                        // in a thread. But the already written data are removed from
                        // the source buffer below. Therefore, exclusive access has
                        // to be guaranteed here using a mutex.
                        //
                        lock(p5);

                        //
                        // Remove written data from source buffer.
                        //
                        // CAUTION! This is IMPORTANT, so that in the next loop cycle,
                        // only the REMAINING data are transmitted.
                        //
                        // CAUTION! Calling the function "modify_item" would work here,
                        // but "modify_array" is used instead since the buffer item's
                        // data and count have been handed over as parametre above.
                        //
                        // CAUTION! Do NOT hand over the buffer count but rather
                        // the number of bytes ACTUALLY WRITTEN for specifying
                        // the number of elements to be removed.
                        //
                        // CAUTION! Set the adjust count flag to TRUE since otherwise,
                        // the buffer item will hold a wrong "count" number
                        // leading to unpredictable errors in further processing.
                        //
                        // CAUTION! Hand over destination array as pointer REFERENCE!
                        //
                        modify_array(p1, *NULL_POINTER_STATE_CYBOI_MODEL, p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p2, p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

                        // Unlock mutex.
                        unlock(p5);
                    }

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

                    // Set loop break flag.
                    copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. An error occured.");
                    fwprintf(stdout, L"Error: Could not write basic. An error occured. %i\n", r);
                    log_errno((void*) &errno);

                    // Set loop break flag.
                    copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. The destination file descriptor is null.");
                fwprintf(stdout, L"Error: Could not write basic. The destination file descriptor is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. The source buffer data is null.");
            fwprintf(stdout, L"Error: Could not write basic. The source buffer data is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write basic. The source buffer count is null.");
        fwprintf(stdout, L"Error: Could not write basic. The source buffer count is null. p2: %i\n", p2);
    }
}

/* BASIC_WRITER_SOURCE */
#endif
