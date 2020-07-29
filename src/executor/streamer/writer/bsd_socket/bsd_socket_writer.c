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

#ifndef BSD_SOCKET_WRITER_SOURCE
#define BSD_SOCKET_WRITER_SOURCE

#include <sys/socket.h> // send
#include <errno.h> // errno
#include <stddef.h> // size_t

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Writes buffer data via bsd socket.
 *
 * @param p0 the destination socket
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the number of bytes transferred
 */
void write_bsd_socket(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* n = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* sc = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                //
                // This test is necessary, because the parametre
                // is handed over to a glibc function.
                //
                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* d = (int*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write bsd socket.");

                    //
                    // Initialise error number.
                    // It is a global variable/function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling
                    // the procedure that might cause an error.
                    //
                    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    //
                    // The source count as size_t.
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
                    //
                    size_t st = (size_t) *sc;

                    //
                    // Write message to destination socket.
                    //
                    // If the flags argument (fourth one) is zero, then one can
                    // just as well use the "write" instead of the "send" procedure.
                    // If the socket is nonblocking, then "send" can return after
                    // sending just PART OF the data.
                    // Note, however, that a successful return value merely indicates
                    // that the message has been SENT without error, NOT necessarily
                    // that it has been received without error!
                    //
                    // The function returns the number of bytes transmitted
                    // or -1 on failure.
                    //
                    *n = send(*d, p1, st, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                    if (*n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully written bsd socket.");
                        //?? fwprintf(stdout, L"TEST: write bsd socket success *n: %i \n", *n);

                    } else if (*n == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. No data could be sent.");
                        fwprintf(stdout, L"TEST: write bsd socket no data sent *n: %i \n", *n);

                    } else {

                        //
                        // An error occured.
                        //

                        if (errno == EBADF) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. The socket argument is not a valid file descriptor.");
                            fwprintf(stdout, L"TEST: write bsd socket error EBADF: %i \n", errno);

                        } else if (errno == EINTR) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. The operation was interrupted by a signal before any data was sent.");
                            fwprintf(stdout, L"TEST: write bsd socket error EINTR: %i \n", errno);

                        } else if (errno == ENOTSOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. The descriptor socket is not a socket.");
                            fwprintf(stdout, L"TEST: write bsd socket error ENOTSOCK: %i \n", errno);

                        } else if (errno == EMSGSIZE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");
                            fwprintf(stdout, L"TEST: write bsd socket error EMSGSIZE: %i \n", errno);

                        } else if (errno == EWOULDBLOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                            fwprintf(stdout, L"TEST: write bsd socket error EWOULDBLOCK: %i \n", errno);

                        } else if (errno == ENOBUFS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. There is not enough internal buffer space available.");
                            fwprintf(stdout, L"TEST: write bsd socket error ENOBUFS: %i \n", errno);

                        } else if (errno == ENOTCONN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. You never connected this socket.");
                            fwprintf(stdout, L"TEST: write bsd socket error ENOTCONN: %i \n", errno);

                        } else if (errno == EPIPE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. This socket was connected but the connection is now broken. In this case, write generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then write fails with EPIPE.");
                            fwprintf(stdout, L"TEST: write bsd socket error EPIPE: %i \n", errno);

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. An unknown error occured.");
                            fwprintf(stdout, L"TEST: write bsd socket error UNKNOWN: %i \n", errno);
                        }
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. The destination socket is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. The source data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. The source count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write bsd socket. The number of transferred bytes is null.");
    }
}

/* BSD_SOCKET_WRITER_SOURCE */
#endif
