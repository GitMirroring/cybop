/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DATAGRAM_SOCKET_SENDER_SOURCE
#define DATAGRAM_SOCKET_SENDER_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../logger/logger.c"
#include "../../../executor/comparator/all/array_all_comparator.c"

/**
 * Sends a byte array stream to the datagram socket.
 *
 * @param p0 the destination receiver socket address (pointer reference)
 * @param p1 the destination receiver socket address size
 * @param p2 the destination socket of this system
 * @param p3 the source data
 * @param p4 the source count
 */
void send_datagram_socket(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p2;

                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    socklen_t* as = (socklen_t*) p1;

                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        struct sockaddr** a = (struct sockaddr**) p0;

                        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send datagram socket.");

                        // Initialise error number.
                        // It is a global variable/ function and other operations
                        // may have set some value that is not wanted here.
                        //
                        // CAUTION! Initialise the error number BEFORE calling the procedure
                        // that might cause an error.
                        copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                        //
                        // CAUTION! Locking does NOT seem to be necessary here.
                        //
                        // One might think that a deadlock may occur if this system
                        // sends a message to itself. However, this could ONLY occur if
                        // the socket of this system got LOCKED when a message is sent
                        // AND ALSO when a message is received. Once the lock got set by
                        // the "send" procedure, the "receive" procedure would wait
                        // endlessly for an unlock, since the "send" in turn would wait
                        // for the "receive" procedure to finish.
                        //
                        // But all this is not a problem and cannot happen, since the
                        // "receive" operation creates a new socket with the address
                        // data of the communication partner, whenever data are received.
                        // Therefore, sender- and receiver socket cannot happen to be identical.
                        // As a consequence, socket locking using a mutex is NOT necessary here!
                        //

                        // Send to socket and return result.
                        int r = sendto(*s, p3, *sc, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *a, *as);

                        if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                            if (errno == EBADF) {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The socket argument is not a valid file descriptor.");

                            } else if (errno == EINTR) {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The operation was interrupted by a signal before any data was sent.");

                            } else if (errno == ENOTSOCK) {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The descriptor socket is not a socket.");

                            } else if (errno == EMSGSIZE) {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");

                            } else if (errno == EWOULDBLOCK) {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. Nonblocking mode has been set on the socket, and the write operation would block.");

                                //?? TODO: DELETE the following comment block OR the log message above!

                                // CAUTION! Do NOT log the following error:
                                // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                                //
                                // The reason is that the socket is non-blocking,
                                // so that the "accept" procedure returns always,
                                // even if no connection was established,
                                // which would unnecessarily fill up the log file.

                            } else if (errno == ENOBUFS) {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. There is not enough internal buffer space available.");

                            } else if (errno == ENOTCONN) {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. You never connected this socket.");

                            } else if (errno == EPIPE) {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. This socket was connected but the connection is now broken. In this case, send generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then send fails with EPIPE.");

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. An unknown error occured.");
                            }
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The receiver socket address is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The receiver socket address size is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The socket of this system is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The source data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send datagram socket. The source count is null.");
    }
}

/* DATAGRAM_SOCKET_SENDER_SOURCE */
#endif
