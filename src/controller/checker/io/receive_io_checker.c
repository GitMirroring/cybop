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

#ifndef RECEIVE_IO_CHECKER_SOURCE
#define RECEIVE_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../controller/checker/client/list_client_checker.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks input output for data.
 *
 * @param p0 the io flag
 * @param p1 the client list item
 * @param p2 the accepttime list item
 * @param p3 the input/output entry
 * @param p4 the channel
 */
void check_io_receive(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io receive.");

//??     fwprintf(stdout, L"TEST: check io receive. channel *p4: %i \n", *((int*) p4));

    // The sender client.
    int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Sense data on already open clients.
    check_client_list((void*) &c, p1, p2, p3, p4);

    compare_integer_greater((void*) &r, (void*) &c, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // There ARE data available on one of the clients.
        // The corresponding client number got returned.
        //

        //?? fwprintf(stdout, L"TEST: check io receive. client c: %i \n", c);

        //
        // Retrieve various values from input/output entry.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the array's count and size are CONSTANT.
        //
        // CAUTION! Hand over values as pointer REFERENCE.
        //
        // CAUTION! Do NOT hand over input/output entry as pointer reference.
        //

        // The sender client.
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get sender client from input/output entry.
        get_io_entry_element((void*) &s, p3, (void*) SENDER_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Copy client as sender.
        copy_integer(s, (void*) &c);

        // Set interrupt request into input/output entry.
        set_io_entry_element(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INTERRUPT_REQUEST_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Set io flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* RECEIVE_IO_CHECKER_SOURCE */
#endif
