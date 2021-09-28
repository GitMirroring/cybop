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

#ifndef MESSAGE_SOCKET_SENSOR_SOURCE
#define MESSAGE_SOCKET_SENSOR_SOURCE

#include <threads.h> // mtx_t, mtx_lock, mtx_unlock
#include <unistd.h> // read

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Senses server socket message.
 *
 * @param p0 the destination buffer item
 * @param p1 the source socket number
 * @param p2 the interrupt pipe write file descriptor
 * @param p3 the input/output entry identification
 * @param p4 the socket mutex (destination buffer item)
 * @param p5 the interrupt mutex
 * @param p6 the local character buffer data
 * @param p7 the local character buffer count
 * @param p8 the exit flag
 */
void sense_socket_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ex = (int*) p8;

        if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* bc = (int*) p7;

            if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    mtx_t* im = (mtx_t*) p5;

                    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        mtx_t* m = (mtx_t*) p4;

                        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                int* ipw = (int*) p2;

                                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    int* s = (int*) p1;

                                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                        //
                                        // CAUTION! Do NOT log messages within thread,
                                        // in order to avoid race conditions and other conflicts.
                                        //
                                        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket message.");

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
                                        fwprintf(stdout, L"Test: Sense socket message. s: %i\n", s);
                                        fwprintf(stdout, L"Test: Sense socket message. *s: %i\n", *((int*) s));
                                        fwprintf(stdout, L"Test: Sense socket message. *bc: %i\n", *bc);
                                        fwprintf(stdout, L"Test: Sense socket message. bct: %i\n", bct);
                                        int n = read(*s, p6, bct);
                                        fwprintf(stdout, L"Test: Sense socket message. n: %i\n", n);
                                        fwprintf(stdout, L"Test: Sense socket message. *p6 as c: %c\n", *((char*) p6));
                                        fwprintf(stdout, L"Test: Sense socket message. p6 as s: %s\n", (char*) p6);

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

                                        compare_integer_equal((void*) &r, ex, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                                        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                                            //
                                            // The exit flag was NOT set in the main thread.
                                            // Therefore, proceed normally.
                                            //

                                            fwprintf(stdout, L"Test: Sense socket message. DO process data. r: %i\n", r);

                                            // Copy local buffer content into destination buffer item.
                                            modify_item(p0, p6, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                                            fwprintf(stdout, L"Test: Sense socket message. *ipw: %i\n", *ipw);

                                            // Lock interrupt mutex.
                                            mtx_lock(im);
                                            //
                                            // Write input/output entry identification to interrupt pipe.
                                            //
                                            // CAUTION! The safe way is to use the functions "snprintf" and "strtol".
                                            // However, if both processes were created using the same compiler version,
                                            // one can take advantage of the fact that anything in C can be
                                            // read or written as an array of char (byte).
                                            //
                                            // Example:
                                            //
                                            // int n = something();
                                            // write(pipe_w, &n, sizeof(n));
                                            // int n;
                                            // read(pipe_r, &n, sizeof(n));
                                            //
                                            // https://stackoverflow.com/questions/5237041/how-to-send-integer-with-pipe-between-two-processes
                                            //
                                            write(*ipw, p3, sizeof(int));
                                            // Unlock interrupt mutex.
                                            mtx_unlock(im);

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

                                            fwprintf(stdout, L"Test: Sense socket message. Do NOT process data. r: %i\n", r);
                                        }

                                        // Unlock socket mutex.
                                        mtx_unlock(m);

                                    } else {

                                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The destination wide character buffer item is null.");
                                        fwprintf(stdout, L"Error: Could not sense socket message. The destination wide character buffer item is null. p0: %i\n", p0);
                                    }

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The source file descriptor is null.");
                                    fwprintf(stdout, L"Error: Could not sense socket message. The source file descriptor is null. p1: %i\n", p1);
                                }

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The interrupt pipe is null.");
                                fwprintf(stdout, L"Error: Could not sense socket message. The interrupt pipe is null. p2: %i\n", p2);
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The input/output entry identification is null.");
                            fwprintf(stdout, L"Error: Could not sense socket message. The input/output entry identification is null. p3: %i\n", p3);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The socket mutex is null.");
                        fwprintf(stdout, L"Error: Could not sense socket message. The socket mutex is null. p4: %i\n", p4);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The interrupt mutex is null.");
                    fwprintf(stdout, L"Error: Could not sense socket message. The interrupt mutex is null. p5: %i\n", p5);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The local buffer data is null.");
                fwprintf(stdout, L"Error: Could not sense socket message. The local buffer data is null. p6: %i\n", p6);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The local buffer count is null.");
            fwprintf(stdout, L"Error: Could not sense socket message. The local buffer count is null. p7: %i\n", p7);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense socket message. The exit flag is null.");
        fwprintf(stdout, L"Error: Could not sense socket message. The exit flag is null. p8: %i\n", p8);
    }
}

/* MESSAGE_SOCKET_SENSOR_SOURCE */
#endif
