/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SOCKET_IO_CHECKER_SOURCE
#define SOCKET_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../controller/checker/io/accept_io_checker.c"
#include "../../../controller/checker/io/receive_io_checker.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Senses socket channel for new data.
 *
 * @param p0 the input/output flag
 * @param p1 the input/output entry
 * @param p2 the channel
 */
void check_io_socket(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io socket.");
    //

    // The client list item.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The accepttime list item.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get client list item from input/output entry.
    copy_array_forward((void*) &c, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CLIENT_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get accepttime list item from input/output entry.
    copy_array_forward((void*) &a, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ACCEPTTIME_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Check for available input/output.
    check_io_receive((void*) &r, c, a, p1, p2);

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
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

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
        check_io_accept(c, a, p1, p2);

    } else {

        // Set input/output flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* SOCKET_IO_CHECKER_SOURCE */
#endif
