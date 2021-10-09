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
#include "../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/acceptor/socket/client_socket_acceptor.c"
#include "../../../executor/activator/client_channel_enabler.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/maintainer/client_starter.c"
#include "../../../executor/modifier/item_modifier.c"
//?? #include "../../../executor/sensor/serial_port/serial_port_sensor.c"
#include "../../../executor/sensor/socket/socket_sensor.c"
//?? #include "../../../executor/sensor/unix_terminal/unix_terminal_sensor.c"
//?? #include "../../../executor/sensor/xcb/xcb_sensor.c"
#include "../../../logger/logger.c"

/**
 * Accepts a new client request via socket.
 *
 * @param p0 the destination client list item
 * @param p1 the source server socket
 * @param p2 the client list mutex
 * @param p3 the interrupt pipe (pointer reference)
 * @param p4 the interrupt mutex (pointer reference)
 * @param p5 the input/output identification (pointer reference, input/output base + socket port)
 * @param p6 the exit flag
 */
int accept_socket_request(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept socket request.");

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ex = (int*) p6;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            mtx_t* m = (mtx_t*) p2;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                //
                // CAUTION! Do NOT log messages within thread,
                // in order to avoid race conditions and other conflicts.
                //
                // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Accept socket request.");

                // The client socket.
                int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
                // The comparison result.
                int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                // Accept client request on server socket.
                fwprintf(stdout, L"Debug: Accept socket request. p1: %i\n", p1);
                fwprintf(stdout, L"Debug: Accept socket request. *p1: %i\n", *((int*) p1));
                fwprintf(stdout, L"Debug: Accept socket request. pre c: %i\n", c);
                fwprintf(stdout, L"Waiting for requesting clients on server socket: %i\n", *((int*) p1));
                accept_socket_client((void*) &c, p1);
                fwprintf(stdout, L"Debug: Accept socket request. post c: %i\n", c);

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

                    // The client entry.
                    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
                    // The thread function.
                    void* f = (void*) &sense_socket;
                    // The identification.
                    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

                    //
                    // Allocate client entry.
                    //
                    // CAUTION! Due to memory allocation handling, the size MUST NOT
                    // be negative or zero, but have at least a value of ONE.
                    //
                    allocate_array((void*) &e, (void*) CLIENT_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

                    fwprintf(stdout, L"Debug: Accept socket request. startup client e: %i\n", e);
                    // Startup client entry.
                    startup_client(e, p3, p4, p5, (void*) &c, (void*) &f, (void*) &e);

                    // Get identification from client entry.
                    copy_array_forward((void*) &id, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_CLIENT_STATE_CYBOI_NAME);
                    // Copy client socket to become the client identification.
                    copy_integer(id, (void*) &c);

                    //
                    // Set client entry into client list of input/output entry.
                    //
                    // CAUTION! Hand over the CLIENT SOCKET as DESTINATION INDEX.
                    // The client socket numbers are unique, so that they may be
                    // used as destination item array index, which is very efficient.
                    //
                    // The unefficient alternative would be to loop through all
                    // client entries and compare their identification with the
                    // client socket, in order to get the correct client entry.
                    // This is needed in read functions that have to access
                    // the client entry's buffer.
                    //
                    // CAUTION! Do NOT adjust count of the destination array
                    // when writing the client entry, since there may be
                    // other client entries further behind.
                    // However, the destination array count does not really matter,
                    // since the client list is used like a random access file.
                    //
                    fwprintf(stdout, L"Debug: Accept socket request. write client entry into client list c: %i\n", c);
                    modify_item(p0, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &c, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

                    //
                    // Create thread for new client socket.
                    //
                    // CAUTION! A new child thread can be created by ANY thread,
                    // not only the main programme thread, at any time.
                    //
                    enable_channel_client(e);

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

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept socket request. The client list mutex is null.");
            fwprintf(stdout, L"Error: Could not accept socket request. The client list mutex is null. p2: %i\n", p2);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not accept socket request. The exit flag is null.");
        fwprintf(stdout, L"Error: Could not accept socket request. The exit flag is null. p6: %i\n", p6);
    }
}

/* REQUEST_SOCKET_ACCEPTOR_SOURCE */
#endif
