/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ELEMENT_IO_CHECKER_SOURCE
#define ELEMENT_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../controller/checker/io/accept_io_checker.c"
#include "../../../controller/checker/io/receive_io_checker.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks input output entry data.
 *
 * @param p0 the io flag
 * @param p1 the internal memory data
 * @param p2 the internal memory index (already initialised with input output base)
 * @param p3 the input/output entry index
 * @param p4 the channel
 */
void check_io_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //
    // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io element.");
    //

    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Calculate internal memory index.
    calculate_integer_add((void*) &i, p2);
    calculate_integer_add((void*) &i, p3);

//??    fwprintf(stdout, L"TEST: check io element i: %i \n", i);

    // Get input/output entry.
    copy_array_forward((void*) &io, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // An input/output entry exists for the service at the calculated internal memory index.

//??        fwprintf(stdout, L"TEST: check io element io: %i \n", io);

        // The enable flag.
        int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Get enable flag from input/output entry.
        get_io_entry_element((void*) &e, io, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);

        if (e != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The enable flag is set.

//??            fwprintf(stdout, L"TEST: check io element e: %i \n", e);

            // The client list item.
            void* l = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get client list item from input/output entry.
            get_io_entry_element((void*) &l, io, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

//??            fwprintf(stdout, L"TEST: check io element l: %i \n", l);

            //
            // Check for new client requests.
            //
            // CAUTION! Actually, only server sockets use the "accept" function,
            // for sensing new client requests.
            // However, in order to apply a unified handling, the function
            // is called here in general, for ALL channels.
            //
            // CAUTION! When using a blocking socket, the programme would wait here.
            // Changing the order of "accept" and "receive" can NOT avoid this.
            // Even comparing with the returned io flag, in order to
            // call "accept" only if no input/output data are available
            // does NOT help, since already in the next loop cycle
            // "accept" will block anyway.
            // In other words, when running cyboi as socket server,
            // it makes sense only together with NON-BLOCKING mode.
            //
            check_io_accept(l, io, p4);

            // Check for available input/output.
            check_io_receive(p0, io, l, p4);
        }
    }
}

/* ELEMENT_IO_CHECKER_SOURCE */
#endif
