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

#ifndef MESSAGE_CLIENT_SOCKET_READER_SOURCE
#define MESSAGE_CLIENT_SOCKET_READER_SOURCE

#include <unistd.h> // read

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Reads message data as client from server socket.
 *
 * @param p0 the destination item to store message data in
 * @param p1 the source server socket to read from
 * @param p2 the local character buffer data
 * @param p3 the local character buffer count
 * @param p4 the break flag
 */
void read_socket_client_message(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* ex = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* bc = (int*) p3;

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* s = (int*) p1;

                    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read socket client message.");
                        fwprintf(stdout, L"Debug: Read socket client message. s: %i\n", s);
                        fwprintf(stdout, L"Debug: Read socket client message. *s: %i\n", *((int*) s));

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
                        fwprintf(stdout, L"Debug: Read socket client message. *bc: %i\n", *bc);
                        fwprintf(stdout, L"Debug: Read socket client message. bct: %i\n", bct);
                        fwprintf(stdout, L"Waiting for input on server socket: %i\n", *s);
                        int n = read(*s, p2, bct);
                        fwprintf(stdout, L"Debug: Read socket client message. n: %i\n", n);
                        //?? fwprintf(stdout, L"Debug: Read socket client message. *p2 as c: %c\n", *((char*) p2));
                        //?? fwprintf(stdout, L"Debug: Read socket client message. p2 as s: %s\n", (char*) p2);

                        // Copy local buffer content into destination buffer item.
                        modify_item(p0, p2, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                        //?? TODO: Detect message size prefix or end of message suffix.
                        //?? TEMPORARY SOLUTION TO BREAK LOOP -- replace later with prefix/suffix detection
                        if (n < *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL) {
                            // Set break flag.
                            copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read socket client message. The destination item is null.");
                        fwprintf(stdout, L"Error: Could not read socket client message. The destination item is null. p0: %i\n", p0);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read socket client message. The source server socket is null.");
                    fwprintf(stdout, L"Error: Could not read socket client message. The source server socket is null. p1: %i\n", p1);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read socket client message. The local buffer data is null.");
                fwprintf(stdout, L"Error: Could not read socket client message. The local buffer data is null. p2: %i\n", p2);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read socket client message. The local buffer count is null.");
            fwprintf(stdout, L"Error: Could not read socket client message. The local buffer count is null. p3: %i\n", p3);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read socket client message. The break flag is null.");
        fwprintf(stdout, L"Error: Could not read socket client message. The break flag is null. p4: %i\n", p4);
    }
}

/* MESSAGE_CLIENT_SOCKET_READER_SOURCE */
#endif
