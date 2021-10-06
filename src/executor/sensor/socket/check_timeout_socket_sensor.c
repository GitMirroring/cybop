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

#ifndef CHECK_TIMEOUT_SOCKET_SENSOR_SOURCE
#define CHECK_TIMEOUT_SOCKET_SENSOR_SOURCE

#include <threads.h> // mtx_t, mtx_lock, mtx_unlock
#include <unistd.h> // read

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Checks server socket client timeout.
 *
 * @param p0 the destination sender client socket list item
 * @param p1 the source receiver server socket
 * @param p2 the socket mutex (destination sender client socket list item)
 * @param p3 the exit flag
 */
void sense_socket_timeout_check(void* p0, void* p1, void* p2, void* p3) {

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ex = (int*) p8;

        if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* bc = (int*) p7;

            if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        mtx_t* m = (mtx_t*) p4;

                        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    int* s = (int*) p1;

                                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                        //
                                        // CAUTION! Do NOT log messages within thread,
                                        // in order to avoid race conditions and other conflicts.
                                        //
                                        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket timeout check.");
                                        fwprintf(stdout, L"Debug: Sense socket timeout check. s: %i\n", s);
                                        fwprintf(stdout, L"Debug: Sense socket timeout check. *s: %i\n", *((int*) s));

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
                                        accept_socket(p0, *s);
                                        fwprintf(stdout, L"Debug: Sense socket timeout check. c: %i\n", c);

                                        // The comparison result.
                                        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                                        //
                                        // Lock socket accept mutex.
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

                                        compare_integer_equal((void*) &r, ex, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                                        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                                            //
                                            // The exit flag was NOT set in the main thread.
                                            // Therefore, proceed normally.
                                            //

                                            fwprintf(stdout, L"Test: Sense socket accept. DO process data. r: %i\n", r);

                                            // Copy local buffer content into destination buffer item.
                                            modify_item(p0, p6, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                                            fwprintf(stdout, L"Test: Sense socket accept. *ipw: %i\n", *ipw);

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

                                            fwprintf(stdout, L"Test: Sense socket accept. Do NOT process data. r: %i\n", r);
                                        }

                                        // Unlock socket accept mutex.
                                        mtx_unlock(m);

                                    } else {

                                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket timeout check. The destination wide character buffer item is null.");
                                        fwprintf(stdout, L"Error: Could not sense socket timeout check. The destination wide character buffer item is null. p0: %i\n", p0);
                                    }

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket timeout check. The source file descriptor is null.");
                                    fwprintf(stdout, L"Error: Could not sense socket timeout check. The source file descriptor is null. p1: %i\n", p1);
                                }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket timeout check. The input/output entry identification is null.");
                            fwprintf(stdout, L"Error: Could not sense socket timeout check. The input/output entry identification is null. p3: %i\n", p3);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket timeout check. The socket mutex is null.");
                        fwprintf(stdout, L"Error: Could not sense socket timeout check. The socket mutex is null. p4: %i\n", p4);
                    }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket timeout check. The local buffer data is null.");
                fwprintf(stdout, L"Error: Could not sense socket timeout check. The local buffer data is null. p6: %i\n", p6);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket timeout check. The local buffer count is null.");
            fwprintf(stdout, L"Error: Could not sense socket timeout check. The local buffer count is null. p7: %i\n", p7);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket timeout check. The exit flag is null.");
        fwprintf(stdout, L"Error: Could not sense socket timeout check. The exit flag is null. p8: %i\n", p8);
    }
}

/* CHECK_TIMEOUT_SOCKET_SENSOR_SOURCE */
#endif
