/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ACCEPT_IO_CHECKER_SOURCE
#define ACCEPT_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../controller/checker/io/element_io_checker.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../executor/lifeguard/sensor/socket/accept_socket_sensor.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Checks input output for new client requests.
 *
 * @param p0 the client list item
 * @param p1 the io entry (pointer reference)
 */
void check_io_accept(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io accept.");

    // The receiver server.
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The sender client.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get receiver server from io entry.
    get_io_entry_element((void*) &s, p1, (void*) SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

//?? fwprintf(stdout, L"TEST: check io accept s: %i \n", s);

    // Sense new client requests (accept) on server socket.
    sense_socket_accept((void*) &c, (void*) &s);

    if (c > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // A client request has been detected on the server.

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io accept success.");

        // Add client to list item.
        modify_item(p0, (void*) &c, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    }
}

/* ACCEPT_IO_CHECKER_SOURCE */
#endif
