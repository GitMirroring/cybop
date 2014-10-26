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
#include "../../../../logger/logger.c"

/**
 * Create socket.
 *
 * @param p0 the socket namespace
 * @param p1 the communication style
 * @param p2 the protocol
 */
void startup_bsd_socket_create(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* p = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* st = (int*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* ns = (int*) p0;

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
                // param 2: protocol
                //
                // CAUTION! Use prefix "PF_" here and NOT "AF_"!
                // The latter is to be used for address family assignment.
                // See further below!
                int s = socket(*ns, *st, *p);

                if (s >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

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

                    // The address data.
                    struct sockaddr* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
                    // The error flag.
                    int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                    // Choose address depending on family.
                    // CAUTION! Distinguishing the address data IS necessary here,
                    // since they have a different structure.
                    startup_bsd_socket_choose((void*) &ad, (void*) &la, (void*) &ia4, (void*) &ia6, (void*) &an);
                    // Bind address to socket.
                    startup_bsd_socket_bind((void*) &e, (void*) &s, (void*) ad, (void*) as);

                    if (e == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        // CAUTION! Datagram sockets do NOT have connections,
                        // which is why the "listen" function is only called
                        // for stream sockets here.
                        if (st == SOCK_STREAM) {

                            startup_bsd_socket_listen((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket. The address binding failed.");
                    }

                } else {

                    if (errno == EPROTONOSUPPORT) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket. The protocol or style is not supported by the namespace specified.");

                    } else if (errno == EMFILE) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket. The process already has too many file descriptors open.");

                    } else if (errno == ENFILE) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket. The system already has too many file descriptors open.");

                    } else if (errno == EACCES) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket. The process does not have the privilege to create a socket of the specified style or protocol.");

                    } else if (errno == ENOBUFS) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket. The system ran out of internal buffer space.");

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket. An unknown error occured while initialising the socket.");
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The socket namespace is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The communication style is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup bsd socket bind. The protocol is null.");
    }
}

/* CREATE_SOCKET_STARTER_SOURCE */
#endif
