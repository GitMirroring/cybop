/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <errno.h> // errno
#include <stddef.h> // size_t
#include <stdio.h> // stdout
#include <unistd.h> // read
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "system.h"

/**
 * Reads data.
 *
 * CAUTION! Do NOT rename this function to "read",
 * as that name is already used by low-level glibc functionality.
 *
 * @param p0 the destination item
 * @param p1 the source file descriptor (a file, serial port, terminal, socket)
 * @param p2 the message fragment data
 * @param p3 the message fragment size
 * @param p4 the destination mutex
 * @param p5 the eof-or-close flag
 */
void read_basic(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ms = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* f = (int*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read basic.");
                    //?? fwprintf(stdout, L"Debug: Read basic. s: %i\n", f);
                    //?? fwprintf(stdout, L"Debug: Read basic. *s: %i\n", *((int*) f));

                    //
                    // Cast fragment size to correct type.
                    //
                    // CAUTION! It IS NECESSARY because on 64 Bit machines,
                    // the "size_t" type has a size of 8 Byte, whereas
                    // the "int" type has the usual size of 4 Byte.
                    // When trying to dereference a pointer that uses the other type,
                    // memory errors will occur and the valgrind memcheck tool report:
                    // "Invalid read of size 8".
                    //
                    size_t mst = (size_t) *ms;

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
                    // CAUTION! Using the function "recv" is NOT necessary,
                    // since its flags argument (fourth one) would be zero,
                    // because no special options are needed.
                    // Therefore, the function "read" suffices here.
                    //
                    // CAUTION! The function "read" is BLOCKING by default.
                    // So, there is NO reason to set the blocking mode
                    // manually using the functions "ioctl" or "setsockopt".
                    //
                    // CAUTION! Do NOT set the option MSG_WAITALL, which requests
                    // the operation to block until all data have been received.
                    // It is impossible to predict the size of the incoming data,
                    // so that it is not clear how big the buffer array shall be.
                    // Therefore, call "read" in a loop until no more data are available.
                    //
                    //?? fwprintf(stdout, L"Debug: Read basic. Waiting for input. *f: %i\n", *f);
                    ssize_t nb = read(*f, p2, mst);

                    // Cast number of bytes actually read to general type.
                    int n = (int) nb;

                    //?? fwprintf(stdout, L"Debug: Read basic. n: %i\n", n);

                    if (n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read basic. Copy fragment data into destination item.");
                        // fwprintf(stdout, L"Debug: Read basic. Copy fragment data into destination item. p2: %s\n", (char*) p2);

                        // The comparison result.
                        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                        // Lock mutex.
                        lock(p4);

                        // fwprintf(stdout, L"Debug: Read basic. Modify destination item. r: %i\n", r);

                        //
                        // Copy fragment data into destination item.
                        //
                        // CAUTION! Do NOT use overwrite since data are read stepwise
                        // as fragments and therefore have to be APPENDED to the
                        // already existing data in the destination.
                        //
                        // Example:
                        // This can happen if reading data from terminal in the
                        // child thread is faster than their processing in the main thread.
                        //
                        modify_item(p0, p2, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                        // Unlock mutex.
                        unlock(p4);

                    } else if (n == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        //
                        // File communication:
                        //
                        // A return value of zero indicates end-of-file (EOF),
                        // except if the fragment size is also zero.
                        // This is NOT considered an error.
                        //
                        // Socket communication:
                        //
                        // A return value of ZERO means the other end (peer)
                        // CLOSED the socket connexion. It never means there was no data.
                        // Therefore, the socket on this side may be closed,
                        // since the other side has closed its connexion.
                        //
                        // CAUTION! Do NOT close socket directly here.
                        // If this is a client socket, then its client entry
                        // resources have to be freed as well,
                        // which is done in the calling function.
                        // Therefore, only set the eof-or-close flag below.
                        //

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The return value is zero, which means EOF for file or connexion closed for socket. Setting eof-or-close flag now.");
                        //?? fwprintf(stdout, L"Warning: Could not read basic. The return value is zero, which means EOF for file or connexion closed for socket. Setting eof-or-close flag now. n: %i\n", n);

                        // Set eof-or-close flag.
                        copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. An error occured. Did you open the device? Setting eof-or-close flag now.");
                        fwprintf(stdout, L"Error: Could not read basic. An error occured. n: %i\n", n);
                        fwprintf(stdout, L"Hint: Did you open the device? Setting eof-or-close flag now.\n");
                        log_error((void*) &errno);

                        //
                        // Set eof-or-close flag.
                        //
                        // CAUTION! If this flag was not set here, then cyboi
                        // would run into an ENDLESS LOOP if in server mode.
                        //
                        copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The destination item is null.");
                    fwprintf(stdout, L"Error: Could not read basic. The destination item is null. p0: %i\n", p0);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The source file descriptor is null.");
                fwprintf(stdout, L"Error: Could not read basic. The source file descriptor is null. p1: %i\n", p1);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The fragment data is null.");
            fwprintf(stdout, L"Error: Could not read basic. The fragment data is null. p2: %i\n", p2);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read basic. The input memory size is null.");
        fwprintf(stdout, L"Error: Could not read basic. The input memory size is null. p3: %i\n", p3);
    }
}
