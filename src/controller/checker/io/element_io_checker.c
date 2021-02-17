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

#ifndef ELEMENT_IO_CHECKER_SOURCE
#define ELEMENT_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../controller/checker/io/accept_io_checker.c"
#include "../../../controller/checker/io/receive_io_checker.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../executor/maintainer/get_io_maintainer.c"
#include "../../../logger/logger.c"

/**
 * Checks input output entry data.
 *
 * @param p0 the input/output flag
 * @param p1 the internal memory data
 * @param p2 the input/output base
 * @param p3 the service identification
 * @param p4 the channel
 */
void check_io_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* r = (int*) p0;

        //
        // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
        // Otherwise, it would produce huge log files filled up with useless entries.
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io element.");
        //

        // The input/output entry.
        void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get input/output entry.
        maintain_io_get((void*) &io, p1, p2, p3);

        if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The input/output entry (service) DOES exist in internal memory.

/*??
            fwprintf(stdout, L"TEST: check io element. input/output base p2: %i \n", *((int*) p2));
            fwprintf(stdout, L"TEST: check io element. service identification p3: %i \n", *((int*) p3));
            fwprintf(stdout, L"TEST: check io element io: %i \n", io);
*/

            // The enable flag.
            int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // Get enable flag from input/output entry.
            get_io_entry_element((void*) &e, io, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);

            if (e != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The enable flag is set.

                //?? fwprintf(stdout, L"TEST: check io element e: %i \n", e);

                // The client list item.
                void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
                // The timeout list item.
                void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
                // The default timeout.
                int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                // Get client list item from input/output entry.
                get_io_entry_element((void*) &c, io, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);
                // Get timeout list item from input/output entry.
                get_io_entry_element((void*) &t, io, (void*) TIMEOUT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);
                // Get default timeout from input/output entry.
                get_io_entry_element((void*) &d, io, (void*) TIMEOUT_INPUT_OUTPUT_STATE_CYBOI_NAME);

                // Check for available input/output.
                check_io_receive(p0, c, t, (void*) &d, io, p4);

                //
                // CAUTION! This "if" clause and branching are NECESSARY since otherwise,
                // new client requests are accepted and a new client socket assigned,
                // yet before receiving data via the already existing client socket.
                //
                // Calling "check_io_receive" first and "check_io_accept" only after,
                // that is adapting the order of function calls alone, does NOT suffice.
                // When many client requests are available, then data are received
                // but the following data might lead to accepting a new request anyway.
                //
                // Therefore, "check_io_accept" is only called when no more data are
                // available on the already existing client sockets.
                //
                if (*r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //
                    // There are NO DATA available on input/output.
                    //

                    //
                    // Check for new client requests.
                    //
                    // CAUTION! Actually, only (server) sockets use the "accept" function,
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
                    check_io_accept(c, t, (void*) &d, io, p4);
                }
            }

        } else {

            //
            // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
            // Otherwise, it would produce huge log files filled up with useless entries.
            // The reason is that an input/output entry being null is the standard case,
            // since all 65536 service identification ports are tested,
            // of whom only one or a few are active.
            //
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check io element. The input/output entry is null.");
            //
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check io element. The input/output flag is null.");
    }
}

/* ELEMENT_IO_CHECKER_SOURCE */
#endif
