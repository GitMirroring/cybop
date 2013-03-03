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

#ifndef STREAM_SOCKET_SENDER_SOURCE
#define STREAM_SOCKET_SENDER_SOURCE

#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cybol/communication_mode_cybol_model.c"
#include "../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../logger/logger.c"

/**
 * Sends data to stream socket in server mode by doing one single transfer.
 *
 * @param p0 the destination communication partner socket
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the number of bytes transferred
 */
void send_stream_socket_server_mode_single_transfer(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* n = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* sc = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // This test is necessary, because the parametre
                // is handed over to a glibc function.

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* d = (int*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send stream socket server mode single transfer.");

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

                    // Send message to destination socket.
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
                    *n = send(*d, p1, *sc, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                    if (*n < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (errno == EBADF) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. The socket argument is not a valid file descriptor.");

                        } else if (errno == EINTR) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. The operation was interrupted by a signal before any data was sent.");

                        } else if (errno == ENOTSOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. The descriptor socket is not a socket.");

                        } else if (errno == EMSGSIZE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. The socket type requires that the message be sent atomically, but the message is too large for this to be possible.");

                        } else if (errno == EWOULDBLOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. Nonblocking mode has been set on the socket, and the write operation would block.");

                            //?? TODO: DELETE the following comment block OR the log message above!

                            // CAUTION! Do NOT log the following error:
                            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send to stream socket. Nonblocking mode has been set on the socket, and the write operation would block.");
                            //
                            // The reason is that the socket is non-blocking,
                            // so that the "accept" procedure returns always,
                            // even if no connection was established,
                            // which would unnecessarily fill up the log file.

                        } else if (errno == ENOBUFS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. There is not enough internal buffer space available.");

                        } else if (errno == ENOTCONN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. You never connected this socket.");

                        } else if (errno == EPIPE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. This socket was connected but the connection is now broken. In this case, send generates a SIGPIPE signal first; if that signal is ignored or blocked, or if its handler returns, then send fails with EPIPE.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. An unknown error occured.");
                        }
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. The socket of this system is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. The source data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. The source count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket server mode single transfer. The number of transferred bytes is null.");
    }
}

/**
 * Sends data to stream socket in server mode.
 *
 * @param p0 the destination communication partner socket
 * @param p1 the source data
 * @param p2 the source count
 */
void send_stream_socket_server_mode(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send stream socket server mode.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The data index to start the transfer at.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The number of bytes transferred.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise data index to start the transfer at.
    copy_pointer((void*) &i, (void*) &p1);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    // CAUTION! The send operation does not necessarily
    // handle all the bytes handed over to it, because
    // its major focus is handling the network buffers.
    // In general, it returns when the associated
    // network buffers have been filled.
    // It then returns the number of handled bytes.
    //
    // The "send" operation therefore has to be
    // CALLED AGAIN AND AGAIN, in a loop, until
    // the complete message has been transmitted!
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        send_stream_socket_server_mode_single_transfer(p0, i, p2, (void*) &n);

        // Increment byte array index.
        calculate_pointer_add((void*) &i, (void*) &n);
        // Decrement byte array count.
        calculate_integer_subtract(p2, (void*) &n);
    }
}

/**
 * Sends data to stream socket in client mode.
 *
 * Connects this system whose socket is given to another system whose address is given.
 *
 * @param p0 the destination communication partner socket
 * @param p1 the receiver socket address (pointer reference)
 * @param p2 the receiver socket address size
 */
void send_stream_socket_client_mode(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        socklen_t* as = (socklen_t*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            struct sockaddr** a = (struct sockaddr**) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* d = (int*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send stream socket client mode.");

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling the procedure
                // that might cause an error.
                errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                // Connect this system whose socket is given
                // to another system whose address is given.
                int r = connect(*d, *a, *as);

                if (r < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    if (errno == EBADF) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The socket is not a valid file descriptor.");

                    } else if (errno == ENOTSOCK) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. File descriptor socket is not a socket.");

                    } else if (errno == EADDRNOTAVAIL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The specified address is not available on the remote machine.");

                    } else if (errno == EAFNOSUPPORT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The namespace of the addr is not supported by this socket.");

                    } else if (errno == EISCONN) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The socket is already connected.");

                    } else if (errno == ETIMEDOUT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The attempt to establish the connection timed out.");

                    } else if (errno == ECONNREFUSED) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The server has actively refused to establish the connection.");

                    } else if (errno == ENETUNREACH) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The network of the given address is not reachable from this host.");

                    } else if (errno == EADDRINUSE) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The given socket address is already in use.");

                    } else if (errno == EINPROGRESS) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The socket is non-blocking and the connection could not be established immediately.");

                    } else if (errno == EALREADY) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The socket is non-blocking and already has a pending connection in progress.");

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. An unknown error occured.");
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The socket of this system is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The socket address is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket client mode. The socket address size is null.");
    }
}

/**
 * Sends data to stream socket.
 *
 * @param p0 the destination communication partner socket
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the receiver socket address of the communication partner (pointer reference)
 * @param p4 the receiver socket address of the communication partner size
 * @param p5 the communication mode data
 * @param p6 the communication mode count
 */
void send_stream_socket(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send stream socket.");

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) SERVER_COMMUNICATION_MODE_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) SERVER_COMMUNICATION_MODE_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Send message to destination socket.
            send_stream_socket_server_mode(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p5, (void*) CLIENT_COMMUNICATION_MODE_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) CLIENT_COMMUNICATION_MODE_CYBOL_MODEL_COUNT);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Connect this system whose socket is given to
            // another system whose address is given.
            send_stream_socket_client_mode(p0, p3, p4);
            // Send message to destination socket.
            send_stream_socket_server_mode(p0, p1, p2);
        }
    }

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send stream socket. The communication mode is unknown.");
    }
}

/* STREAM_SOCKET_SENDER_SOURCE */
#endif
