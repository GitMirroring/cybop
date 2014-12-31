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

#ifndef BSD_SOCKET_SENSOR_SOURCE
#define BSD_SOCKET_SENSOR_SOURCE

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>

#include "../../../../constant/channel/cybol_channel.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/array_getter.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter/signal_memory_getter.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/memoriser/allocator.c"
#include "../../../../executor/runner/sleeper.c"

/**
 * Senses socket message.
 *
 * @param p0 the interrupt
 * @param p1 the mutex
 * @param p2 the sleep time
 * @param p3 the communication partner-connected socket
 * @param p4 the communication partner-connected socket address
 * @param p5 the communication partner-connected socket address size
 * @param p6 the original socket of this system
 */
void sense_socket_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* os = (int*) p6;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* ps = (int*) p3;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                pthread_mutex_t* mt = (pthread_mutex_t*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* irq = (int*) p0;

                    // CAUTION! DO NOT log this function call!
                    // This function is executed within a thread, but the
                    // logging is not guaranteed to be thread-safe and might
                    // cause unpredictable programme behaviour.
                    // Also, this function runs in an endless loop and would produce huge log files.

                    fwprintf(stdout, L"TEST: sense (stream) socket server socket: %i \n", *os);

                    // Initialise error number.
                    //
                    // It is a global variable/function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling
                    // the procedure that might cause an error.
                    //
                    // CAUTION! Do NOT reset the GLOBAL "errno" variable here!
                    // All what is said above is true, but is this a THREAD
                    // and other threads might access the "errno" variable
                    // at the same time, which would lead to false programme behaviour.
                    // errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // Accept client socket request and store client socket.
                    //
                    // Accepting a connection does NOT make the original socket
                    // part of the connection. Instead, it creates a new socket
                    // which becomes connected. The normal return value of
                    // "accept" is the file descriptor for the new socket.
                    //
                    // After "accept", the original socket remains open and
                    // unconnected, and continues listening until it gets closed.
                    // One can accept further connections with the original
                    // socket by calling "accept" again -- best done in a loop!
                    //
                    // The address "pa" returns information about the name of the
                    // communication partner socket that initiated the connection.
                    //
                    // CAUTION! The "select" procedure was NOT used to make this socket non-blocking,
                    // because it has some overhead in that other sockets need to be considered
                    // and their file descriptors handed over as parametre.
                    //
                    *ps = accept(*os, (struct sockaddr*) p4, (socklen_t*) p5);

                    if (*ps >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        fwprintf(stdout, L"TEST: sense (stream) socket client partner socket ps: %i \n", *ps);

                        // CAUTION! Do NOT close client socket here!
                        // It is stored in the internal memory and only closed
                        // in the "send_socket" operation, when replying to the client.
                        // close(*ps);

                        // Lock socket mutex.
                        pthread_mutex_lock(mt);

                        // Set socket interrupt request to indicate
                        // that a message has been received via socket,
                        // which may now be processed in the main thread of this system.
                        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                        // Unlock socket mutex.
                        pthread_mutex_unlock(mt);

                        fwprintf(stdout, L"TEST: sense wait st: %i \n", *((int*) p2));

                        // Access irq as atomic variable.
                        // CAUTION! Therefore better don't use the following line:
                        // while (*irq != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                        while (*irq) {

                            // Sleep as long as the socket interrupt is not handled and reset yet.
                            // This is to give the central processing unit (cpu) some
                            // time to breathe, that is to be idle or to process other signals.
                            sleep_nano(p2);
                        }

                    } else {

                        // An error occured.

                        if (errno == EBADF) {

                            // CAUTION! DO NOT log this function call!
                            // This function is executed within a thread, but the
                            // logging is not guaranteed to be thread-safe and might
                            // cause unpredictable programme behaviour.
                            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The socket argument is not a valid file descriptor.");

                        } else if (errno == ENOTSOCK) {

                            // CAUTION! DO NOT log this function call!
                            // This function is executed within a thread, but the
                            // logging is not guaranteed to be thread-safe and might
                            // cause unpredictable programme behaviour.
                            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The descriptor socket argument is not a socket.");

                        } else if (errno == EOPNOTSUPP) {

                            // CAUTION! DO NOT log this function call!
                            // This function is executed within a thread, but the
                            // logging is not guaranteed to be thread-safe and might
                            // cause unpredictable programme behaviour.
                            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The descriptor socket does not support this operation.");

                        } else if (errno == EWOULDBLOCK) {

                            // CAUTION! DO NOT log this function call!
                            // This function is executed within a thread, but the
                            // logging is not guaranteed to be thread-safe and might
                            // cause unpredictable programme behaviour.
                            //
                            // CAUTION! Do NOT log the following error!
                            // The reason is that the socket is non-blocking,
                            // so that the "accept" procedure returns always,
                            // even if no connection was established,
                            // which would unnecessarily fill up the log file.
                            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The socket has nonblocking mode set, and there are no pending connections immediately available.");

                        } else {

                            // CAUTION! DO NOT log this function call!
                            // This function is executed within a thread, but the
                            // logging is not guaranteed to be thread-safe and might
                            // cause unpredictable programme behaviour.
                            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. An unknown error occured while accepting a socket connection.");
                        }
                    }

                } else {

                    // CAUTION! DO NOT log this function call!
                    // This function is executed within a thread, but the
                    // logging is not guaranteed to be thread-safe and might
                    // cause unpredictable programme behaviour.
                    // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The interrupt is null.");
                }

            } else {

                // CAUTION! DO NOT log this function call!
                // This function is executed within a thread, but the
                // logging is not guaranteed to be thread-safe and might
                // cause unpredictable programme behaviour.
                // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The mutex is null.");
            }

        } else {

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The communication partner-connected socket is null.");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The original socket of this system is null.");
    }
}

/* BSD_SOCKET_SENSOR_SOURCE */
#endif
