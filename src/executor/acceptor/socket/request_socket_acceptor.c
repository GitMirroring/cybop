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

#ifndef REQUEST_SOCKET_ACCEPTOR_SOURCE
#define REQUEST_SOCKET_ACCEPTOR_SOURCE

#include <threads.h> // mtx_t, mtx_lock, mtx_unlock

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/acceptor/socket/client_socket_acceptor.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Accepts a new client request via socket.
 *
 * @param p0 the destination client list item
 * @param p1 the source server socket
 * @param p2 the client list mutex
 * @param p3 the exit flag
 */
int accept_socket_request(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept socket request.");

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ex = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            mtx_t* m = (mtx_t*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    //
                    // CAUTION! Do NOT log messages within thread,
                    // in order to avoid race conditions and other conflicts.
                    //
                    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept socket request.");

                    // The client socket.
                    int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

                    // Accept client request on server socket.
                    fwprintf(stdout, L"Debug: Accept socket request. *s: %i\n", *s);
                    fwprintf(stdout, L"Debug: Accept socket request. pre c: %i\n", c);
                    accept_socket_client((void*) &c, *s);
                    fwprintf(stdout, L"Debug: Accept socket request. post c: %i\n", c);

                    // The comparison result.
                    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                    //
                    // Lock client list mutex.
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

                        fwprintf(stdout, L"Debug: Accept socket request. DO process data. r: %i\n", r);

                        // Add client socket to client list item.
                        modify_item(p0, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                        fwprintf(stdout, L"Debug: Accept socket request. append success c: %i\n", c);

                        //
                        // Startup child socket thread.
                        //
                        //?? TODO: Call startup_socket_client and WITHIN IT:
                        // - allocate message buffer
                        // - create new child thread
                        //

                        //
                        // Create thread for new client socket.
                        //
                        // CAUTION! A new child thread can be created by ANY thread,
                        // not only the main programme thread, at any time.
                        //
                        //?? TODO ...

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
                        // Reallocation may happen above, when adding a number to the client list item.
                        //

                        fwprintf(stdout, L"Debug: Accept socket request. Do NOT process data. r: %i\n", r);
                    }

                    // Unlock client list mutex.
                    mtx_unlock(m);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept socket request. The destination client list item is null.");
                    fwprintf(stdout, L"Error: Could not accept socket request. The destination client list item is null. p0: %i\n", p0);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept socket request. The source server socket is null.");
                fwprintf(stdout, L"Error: Could not accept socket request. The source server socket is null. p1: %i\n", p1);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept socket request. The client list mutex is null.");
            fwprintf(stdout, L"Error: Could not accept socket request. The client list mutex is null. p2: %i\n", p2);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept socket request. The exit flag is null.");
        fwprintf(stdout, L"Error: Could not accept socket request. The exit flag is null. p3: %i\n", p3);
    }
}

/* REQUEST_SOCKET_ACCEPTOR_SOURCE */
#endif
