/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BSD_SOCKET_READER_SOURCE
#define BSD_SOCKET_READER_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stddef.h> // size_t

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Reads data from bsd socket and stores them in the given byte array.
 *
 * @param p0 the destination data
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source socket
 * @param p4 the socket options
 */
void read_bsd_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* o = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* ss = (int*) p3;

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p2;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read bsd socket.");

                    // Cast int to size_t.
                    //
                    // CAUTION! It IS NECESSARY because on 64 Bit machines,
                    // the "size_t" type has a size of 8 Byte,
                    // whereas the "int" type has the usual size of 4 Byte.
                    // When trying to cast between the two, memory errors
                    // will occur and the valgrind memcheck tool report:
                    // "Invalid read of size 8".
                    //
                    // CAUTION! Initialise temporary size_t variable with final int value
                    // JUST BEFORE handing that over to the glibc function requiring it.
                    //
                    // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
                    // because values are casted to int* internally again.
                    size_t st = (size_t) *s;

                    // Initialise error number.
                    // It is a global variable/function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling
                    // the procedure that might cause an error.
                    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

//?? fwprintf(stdout, L"TEST: read bsd socket buffer *ss: %i \n", *ss);
//?? fwprintf(stdout, L"TEST: read bsd socket buffer st: %i \n", st);
//?? fwprintf(stdout, L"TEST: read bsd socket buffer *s: %i \n", *s);
//?? fwprintf(stdout, L"TEST: read bsd socket buffer p1: %i \n", *((int*) p1));
//?? fwprintf(stdout, L"TEST: read bsd socket buffer p0: %i \n", p0);

                    // Read message.
                    //
                    // Normally, "recv" blocks until there is input available to be read.
                    // However, non-blocking mode may be enabled in cyboi as well.
                    //
                    // CAUTION! If the flags argument (fourth one) is zero, then one can
                    // just as well use the "read" instead of the "recv" function.
                    // However, the "recv" function is used here since sometimes,
                    // data are just to be detected, without removing them.
                    // In this case, the flags argument has the value MSG_PEEK.
                    // Otherwise, for normal reading, it may have a value of zero.
                    int c = recv(*ss, p0, st, *o);

//?? fwprintf(stdout, L"TEST read bsd socket c: %i\n", c);

                    if (c > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST read bsd socket success c: %i\n", c);

                        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully read bsd socket.");

                        // Copy destination count.
                        // CAUTION! Copy value only if >= zero.
                        // Otherwise (with negative value), buffer deallocation will fail.
                        copy_integer(p1, (void*) &c);

                    } else if (c == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST read bsd socket no data c: %i\n", c);

                        // CAUTION! Do NOT log this message, since it would
                        // produce dozens of log entries.
                        // The cyboi endless signal loop queries input/output
                        // channels frequently for new available data.
                        // If there are none, then this is just normal.
                        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. No data could be sensed.");

                        // Copy destination count.
                        // CAUTION! Copy value only if >= zero.
                        // Otherwise (with negative value), buffer deallocation will fail.
                        copy_integer(p1, (void*) &c);

                    } else {

                        // An error occured.

                        if (errno == EBADF) {

                        fwprintf(stdout, L"TEST read bsd socket error EBADF: %i\n", errno);

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The socket argument is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                        fwprintf(stdout, L"TEST read bsd socket error ENOTSOCK: %i\n", errno);

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The descriptor socket is not a socket.");

                        } else if (errno == EWOULDBLOCK) {

                        fwprintf(stdout, L"TEST read bsd socket error EWOULDBLOCK: %i\n", errno);

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The read operation would block even though nonblocking mode has been set on the socket.");

                        } else if (errno == EINTR) {

                        fwprintf(stdout, L"TEST read bsd socket error EINTR: %i\n", errno);

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The operation was interrupted by a signal before any data was received.");

                        } else if (errno == ENOTCONN) {

                        fwprintf(stdout, L"TEST read bsd socket error ENOTCONN: %i\n", errno);

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The socket was never connected.");

                        } else {

                        fwprintf(stdout, L"TEST read bsd socket error UNKNOWN: %i\n", errno);

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. An unknown error occured.");
                        }
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The destination data is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The destination size is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The source socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read bsd socket. The socket options is null.");
    }
}

/* BSD_SOCKET_READER_SOURCE */
#endif
