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

#ifndef EVENT_XCB_SENSOR_SOURCE
#define EVENT_XCB_SENSOR_SOURCE

#include <xcb/xcb.h>

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Senses an xcb x window system event.
 *
 * @param p0 the destination buffer item
 * @param p1 the source connexion
 * @param p2 the interrupt pipe write file descriptor
 * @param p3 the input/output entry identification
 * @param p4 the display mutex (destination buffer item)
 * @param p5 the interrupt mutex
 * @param p6 the exit flag
 */
void sense_xcb_event(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ex = (int*) p6;

        if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            mtx_t* im = (mtx_t*) p5;

            if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                mtx_t* m = (mtx_t*) p4;

                if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int* ipw = (int*) p2;

                        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                            xcb_connection_t* c = (xcb_connection_t*) p1;

                            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                //
                                // CAUTION! Do NOT log messages within thread,
                                // in order to avoid race conditions and other conflicts.
                                //
                                // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense xcb event.");

                                //
                                // Get next event available from x window system server.
                                //
                                // CAUTION! This is a blocking call waiting until either
                                // an event arrives or an input/output error occurs.
                                //
                                // CAUTION! Whenever an event is queued in the x server,
                                // it gets dequeued from the queue here and is then returned
                                // as a newly allocated structure. It is cyboi's responsibility
                                // to FREE the returned event structure.
                                //
                                // CAUTION! The event gets REMOVED from the queue by
                                // the "xcb_wait_for_event" function. It therefore
                                // HAS TO BE STORED, in order to be able to process it later on.
                                //
                                fwprintf(stdout, L"Test: Sense xcb event. p1: %i\n", p1);
                                void* e = (void*) xcb_wait_for_event(c);
                                fwprintf(stdout, L"Test: Sense xcb. Event e: %i\n", e);

                                if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

                                    // The comparison result.
                                    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                                    //
                                    // Lock display mutex.
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

                                        fwprintf(stdout, L"Test: Sense xcb message. DO process data. r: %i\n", r);

                                        // Store event in buffer.
                                        modify_item(p0, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                                        fwprintf(stdout, L"Test: Sense xcb event. *ipw: %i\n", *ipw);

                                        // Lock interrupt mutex.
                                        mtx_lock(im);
                                        //
                                        // Write to interrupt pipe.
                                        //
                                        // - input/output entry identification
                                        // - client identification
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
                                        write(*ipw, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, sizeof(int));
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

                                    // Unlock display mutex.
                                    mtx_unlock(m);

                                } else {

                                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb event. The event is null. This indicates an input/output error.");
                                    fwprintf(stdout, L"Error: Could not sense xcb event. The event is null. This indicates an input/output error. e: %i\n", e);
                                }

                            } else {

                                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb event. The destination buffer item is null.");
                                fwprintf(stdout, L"Error: Could not sense xcb event. The destination buffer item is null. p0: %i\n", p0);
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb event. The source connexion is null.");
                            fwprintf(stdout, L"Error: Could not sense xcb event. The source connexion is null. p1: %i\n", p1);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb event. The interrupt pipe is null.");
                        fwprintf(stdout, L"Error: Could not sense xcb event. The interrupt pipe is null. p2: %i\n", p2);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb event. The input/output entry identification is null.");
                    fwprintf(stdout, L"Error: Could not sense xcb event. The input/output entry identification is null. p3: %i\n", p3);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb event. The display mutex is null.");
                fwprintf(stdout, L"Error: Could not sense xcb event. The display mutex is null. p4: %i\n", p4);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb event. The interrupt mutex is null.");
            fwprintf(stdout, L"Error: Could not sense xcb event. The interrupt mutex is null. p5: %i\n", p5);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb event. The exit flag is null.");
        fwprintf(stdout, L"Error: Could not sense xcb event. The exit flag is null. p6: %i\n", p6);
    }
}

/* EVENT_XCB_SENSOR_SOURCE */
#endif
