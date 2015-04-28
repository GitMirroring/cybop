/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVE_IO_CHECKER_SOURCE
#define RECEIVE_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../controller/checker/client/list_client_checker.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks input output for data.
 *
 * @param p0 the io flag
 * @param p1 the io entry (pointer reference)
 * @param p2 the client list item
 */
void check_io_receive(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io receive.");

    // The client.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Sense data on already open clients.
    check_client_list((void*) &c, p2);

    if (c > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // There ARE data available on one of the clients.
        // The corresponding client number got returned.

fwprintf(stdout, L"TEST: check io receive c: %i \n", c);

        // The io sender.
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get io sender client from io entry.
        get_io_entry_element((void*) &s, p1, (void*) SENDER_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Copy client as sender.
        copy_integer(s, (void*) &c);

        // Set interrupt request into io entry.
        set_io_entry_element(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INTERRUPT_REQUEST_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Set io flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* RECEIVE_IO_CHECKER_SOURCE */
#endif
