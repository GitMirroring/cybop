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

#ifndef CREATE_BSD_SOCKET_STARTER_SOURCE
#define CREATE_BSD_SOCKET_STARTER_SOURCE

#include <netinet/tcp.h> // SOL_TCP, TCP_NODELAY
#include <sys/socket.h> // setsockopt
#include <errno.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/maintainer/starter/bsd_socket/get_status_bsd_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Create socket.
 *
 * @param p0 the socket
 * @param p1 the protocol family (socket namespace)
 * @param p2 the communication style
 * @param p3 the protocol
 * @param p4 the blocking flag
 */
void startup_bsd_socket_create(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* pr = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* st = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* pf = (int*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* s = (int*) p0;

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket create.");

                    //
                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the
                    // function that might cause an error.
                    //
                    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    //?? fwprintf(stdout, L"TEST: startup bsd socket create *pf: %i \n", *pf);
                    //?? fwprintf(stdout, L"TEST: startup bsd socket create *st: %i \n", *st);
                    //?? fwprintf(stdout, L"TEST: startup bsd socket create *pr: %i \n", *pr);

                    //
                    // Initialise server socket.
                    //
                    // param 0: protocol family (namespace)
                    // param 1: communication style
                    // param 2: protocol (zero is usually right)
                    //
                    // CAUTION! Use prefix "PF_" here and NOT "AF_"!
                    // The latter is to be used for address family assignment.
                    // See further below!
                    //
                    *s = socket(*pf, *st, *pr);

                    // The socket options.
                    int od = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                    int os = sizeof(od);

                    //
                    // Disable nagle algorithm delay.
                    //
                    // SOL_TCP:
                    // - constant handed over to indicate tcp-level options
                    //
                    // TCP_NODELAY:
                    // - specifies whether or not to use the nagle algorithm (delay)
                    //   for deciding when to send data
                    // - only supported by stream sockets (tcp)
                    // - should be used for applications using the request/response paradigm
                    // - a non-zero value sets the option forcing tcp to always
                    //   send data immediately (disabled nagle algorithm)
                    //
                    // https://stackoverflow.com/questions/1525050/non-blocking-socket
                    // https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_72/apis/ssocko.htm
                    //
                    setsockopt(*s, SOL_TCP, TCP_NODELAY, &od, os);

                    //
                    // Set socket reusable after execution.
                    //
                    // SOL_SOCKET:
                    // - constant handed over to indicate socket-level options
                    //
                    // SO_REUSEADDR:
                    // - avoid error message "address already in use"
                    // - should always be set for a tcp server before it calls "bind"
                    //
                    setsockopt(*s, SOL_SOCKET, SO_REUSEADDR, &od, os);

                    //
                    // The SO_KEEPALIVE option may be used for sending
                    // "heartbeats" through a persistent connection.
                    //
                    // It has two end purposes:
                    // - back-end application: detect an absent client,
                    //   so as to drop a connection and release the associated resources
                    // - client: prevent connection resources stored within intermediate nodes
                    //   (such as a nat router) being released, so as to keep the connection alive
                    //
                    // https://holmeshe.me/network-essentials-setsockopt-SO_KEEPALIVE/
                    //
                    // Neither of these two is needed in cyboi,
                    // which is why the SO_KEEPALIVE option is NOT set here.
                    //

                    if (*s >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket create success.");
                        //?? fwprintf(stdout, L"TEST: Startup bsd socket create success. *s: %i \n", *s);

                        // Make socket nonblocking.
                        startup_bsd_socket_status_get(p0, p4);

                    } else {

                        //
                        // An error occured.
                        //

                        fwprintf(stdout, L"TEST: startup bsd socket create error errno: %i \n", errno);

                        if (errno == EPROTONOSUPPORT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The protocol or style is not supported by the namespace specified.");
                            fwprintf(stdout, L"TEST: startup bsd socket create error EPROTONOSUPPORT: %i \n", errno);

                        } else if (errno == EMFILE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The process already has too many file descriptors open.");
                            fwprintf(stdout, L"TEST: startup bsd socket create error EMFILE: %i \n", errno);

                        } else if (errno == ENFILE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The system already has too many file descriptors open.");
                            fwprintf(stdout, L"TEST: startup bsd socket create error ENFILE: %i \n", errno);

                        } else if (errno == EACCES) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The process does not have the privilege to create a socket of the specified style or protocol.");
                            fwprintf(stdout, L"TEST: startup bsd socket create error EACCES: %i \n", errno);

                        } else if (errno == ENOBUFS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The system ran out of internal buffer space.");
                            fwprintf(stdout, L"TEST: startup bsd socket create error ENOBUFS: %i \n", errno);

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. An unknown error occured while initialising the socket.");
                            fwprintf(stdout, L"TEST: startup bsd socket create error UNKNOWN: %i \n", errno);
                        }
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The socket is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The protocol family is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The communication style is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The protocol is null.");
    }
}

/* CREATE_BSD_SOCKET_STARTER_SOURCE */
#endif
