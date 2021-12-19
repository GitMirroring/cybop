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

#ifndef FRAGMENT_SOCKET_SENSOR_SOURCE
#define FRAGMENT_SOCKET_SENSOR_SOURCE

#include <stddef.h> // size_t
#include <threads.h> // mtx_t, mtx_lock, mtx_unlock
#include <unistd.h> // read

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Senses a socket message fragment.
 *
 * @param p0 the destination buffer item
 * @param p1 the source identification (client socket number)
 * @param p2 the client socket mutex (destination buffer item)
 * @param p3 the local character buffer data
 * @param p4 the local character buffer count
 * @param p5 the exit flag
 */
void sense_socket_fragment(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* bc = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                mtx_t* m = (mtx_t*) p2;

                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* s = (int*) p1;

                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        //
                        // CAUTION! Do NOT log messages within thread,
                        // in order to avoid race conditions and other conflicts.
                        //
                        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket fragment.");
                        fwprintf(stdout, L"Debug: Sense socket fragment. s: %i\n", s);
                        fwprintf(stdout, L"Debug: Sense socket fragment. *s: %i\n", *((int*) s));

                        // Cast buffer size to correct type.
                        size_t bct = (size_t) *bc;

                        //
                        // Read data from socket.
                        //
                        // CAUTION! Using the function "recv" is NOT necessary,
                        // since its flags argument (fourth one) would be zero,
                        // because no special options are needed.
                        // Therefore, the function "read" suffices here.
                        //
                        // The function "read" is BLOCKING by default.
                        // So, there is NO reason to set the blocking mode
                        // manually using the functions "ioctl" or "setsockopt".
                        //
                        // Do NOT set the option MSG_WAITALL, which requests
                        // the operation to block until all data have been received.
                        // It is impossible to predict the size of the incoming data,
                        // so that it is not clear how big the buffer array shall be.
                        // Therefore, call "read" in a loop until no more data are available.
                        //
                        fwprintf(stdout, L"Debug: Sense socket message. *bc: %i\n", *bc);
                        fwprintf(stdout, L"Debug: Sense socket message. bct: %i\n", bct);
                        fwprintf(stdout, L"Debug: Sense socket message. Waiting for input/output on client socket: %i\n", *s);
                        int n = read(*s, p3, bct);
                        fwprintf(stdout, L"Debug: Sense socket message. n: %i\n", n);
                        fwprintf(stdout, L"Debug: Sense socket message. *p5 as c: %c\n", *((char*) p5));
                        fwprintf(stdout, L"Debug: Sense socket message. p5 as s: %s\n", (char*) p5);

                        // The comparison result.
                        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                        //
                        // Lock socket mutex.
                        //
                        // CAUTION! Set this lock BEFORE comparing with the exit flag below
                        // since otherwise, a race condition might occur.
                        //
                        // Example:
                        // - the exit flag is not set
                        // - the sensing child thread enters the block with r != 0
                        // - the main thread receives some shutdown cybol operation
                        // - the main thread sets the exit flag only now
                        // - the main thread shuts down and deallocates the destination buffer
                        // - the sensing child thread decodes characters
                        // - the sensing child thread possibly reallocates the (non-existing) destination buffer
                        // - this leads to memory errors such as "corrupted double-linked list"
                        //
                        mtx_lock(m);

                        //
                        // A return value of ZERO means the other end (peer, client)
                        // CLOSED the socket connexion. It never means there was no data.
                        // - blocking mode: "read" will block
                        // - non-blocking mode: it will return -1 if there is no data
                        //   with errno set to EAGAIN or EWOULDBLOCK, depending on the platform
                        //
                        // https://stackoverflow.com/questions/12773509/read-is-not-blocking-in-socket-programming
                        //
                        if (n == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                            //
                            // Close the client socket on this server side,
                            // since the client side has closed its connexion.
                            //
                            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                        }

                        compare_integer_equal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            //
                            // The exit flag was NOT set in the main thread.
                            // Therefore, proceed normally.
                            //

                            fwprintf(stdout, L"Debug: Sense socket message. DO process data. r: %i\n", r);

                            // Copy local buffer content into destination buffer item.
                            modify_item(p0, p3, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                        } else {

                            //
                            // The exit flag WAS SET in the main thread.
                            // Therefore, do NOT process data here any longer.
                            //
                            // The reason is that data processing might require
                            // reallocation of some destination arrays, which may
                            // not exist anymore if the main thread deallocated them,
                            // leading to the error "realloc(): invalid pointer".
                            //
                            // Reallocation may happen above, in call of function "modify_item".
                            //

                            fwprintf(stdout, L"Debug: Sense socket message. Do NOT process data, since the exit flag is set. r: %i\n", r);
                        }

                        // Unlock socket mutex.
                        mtx_unlock(m);

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket fragment. The destination buffer item is null.");
                        fwprintf(stdout, L"Error: Could not sense socket fragment. The destination buffer item is null. p0: %i\n", p0);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket fragment. The source identification is null.");
                    fwprintf(stdout, L"Error: Could not sense socket fragment. The source identification is null. p1: %i\n", p1);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket fragment. The client socket mutex is null.");
                fwprintf(stdout, L"Error: Could not sense socket fragment. The client socket mutex is null. p2: %i\n", p2);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket fragment. The local character buffer data is null.");
            fwprintf(stdout, L"Error: Could not sense socket fragment. The local character buffer data is null. p3: %i\n", p3);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket fragment. The local character buffer count is null.");
        fwprintf(stdout, L"Error: Could not sense socket fragment. The local character buffer count is null. p4: %i\n", p4);
    }
}

/* FRAGMENT_SOCKET_SENSOR_SOURCE */
#endif
