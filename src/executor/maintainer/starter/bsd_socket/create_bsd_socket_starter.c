/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOCKET_STARTER_SOURCE
#define CREATE_SOCKET_STARTER_SOURCE

#include <sys/socket.h>
#include <errno.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/maintainer/starter/bsd_socket/bind_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/listen_bsd_socket_starter.c"
#include "../../../../executor/maintainer/starter/bsd_socket/socket_address_bsd_socket_starter.c"
#include "../../../../logger/logger.c"

/**
 * Create socket.
 *
 * @param p0 the socket
 * @param p1 the protocol family (socket namespace)
 * @param p2 the communication style
 * @param p3 the protocol
 * @param p4 the filename data
 * @param p5 the filename count
 * @param p6 the host address data
 * @param p7 the host address count
 * @param p8 the port
 * @param p9 the address family (address namespace)
 */
void startup_bsd_socket_create(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* pr = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* st = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* pf = (int*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* s = (int*) p0;

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup bsd socket create.");

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling the procedure
                    // that might cause an error.
                    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // Initialise server socket.
                    //
                    // param 0: namespace
                    // param 1: style
                    // param 2: protocol (zero is usually right)
                    //
                    // CAUTION! Use prefix "PF_" here and NOT "AF_"!
                    // The latter is to be used for address family assignment.
                    // See further below!
                    *s = socket(*pf, *st, *p);

                    if (*s >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // Set non-blocking mode for the socket file descriptor.
                        //
                        // If the O_NONBLOCK flag (a bit) is set, read requests on the socket
                        // (file) can return immediately with a failure status if there is no
                        // input immediately available, instead of blocking. Likewise, write
                        // requests can also return immediately with a failure status if the
                        // output can't be written immediately.
                        //
                        // CAUTION! The "select" procedure was NOT used to make this socket
                        // non-blocking, because it has some overhead in that other sockets
                        // need to be considered and their file descriptors handed over as
                        // parametre.
                        // A simple "sleep" procedure is considered to be a more simple and
                        // clean solution here.

    /*??
                        // Get file status flags.
                        int fl = fcntl(*s, F_GETFL, NUMBER_0_INTEGER);

                        if (fl != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

                            // Set non-blocking flag (bit).
                            fl |= O_NONBLOCK;

                            // Store modified flag word in the file descriptor.
                            fcntl(*s, F_SETFL, fl);

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket / set non-blocking mode. The socket file descriptor flags could not be read.");
                        }
    */

                        // The socket address data, size.
                        void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
                        int as = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                        // The error flag.
                        int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                        // Initialise socket address depending on family.
                        // CAUTION! Hand over address data as pointer reference,
                        // since it gets allocated inside the function and
                        // has to be preserved as return value.
                        startup_bsd_socket_socket_address((void*) &ad, (void*) &as, p4, p5, p6, p7, p8, p9);
                        // Bind address to socket.
                        startup_bsd_socket_bind((void*) &e, p0, ad, (void*) &as);

                        if (e == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            // CAUTION! Datagram sockets do NOT have connections,
                            // which is why the "listen" function is ONLY called
                            // for stream sockets here.
                            if (*st == SOCK_STREAM) {

                                // The second argument specifies the length of the queue for pending connections.
                                // For now, just ONE client may connect (possibly to be adapted later).
                                startup_bsd_socket_listen(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The address binding failed.");
                        }

                    } else {

                        if (errno == EPROTONOSUPPORT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The protocol or style is not supported by the namespace specified.");

                        } else if (errno == EMFILE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The process already has too many file descriptors open.");

                        } else if (errno == ENFILE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The system already has too many file descriptors open.");

                        } else if (errno == EACCES) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The process does not have the privilege to create a socket of the specified style or protocol.");

                        } else if (errno == ENOBUFS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. The system ran out of internal buffer space.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket create. An unknown error occured while initialising the socket.");
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

/* CREATE_SOCKET_STARTER_SOURCE */
#endif
