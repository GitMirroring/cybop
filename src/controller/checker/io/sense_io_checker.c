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

#ifndef SENSE_IO_CHECKER_SOURCE
#define SENSE_IO_CHECKER_SOURCE

#include "../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../controller/checker/io/socket_io_checker.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/sensor/sensor.c"
#include "../../../logger/logger.c"

/**
 * Senses channels for new data.
 *
 * @param p0 the input/output flag
 * @param p1 the input/output entry
 * @param p2 the channel
 */
void check_io_sense(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io sense.");
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p2, (void*) SOCKET_CYBOI_CHANNEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a socket channel.
        //

        // Sense data on all clients of the server socket.
        check_io_socket(p0, p1, p2);

    } else {

        //
        // This is another channel, e.g. serial, terminal, display.
        //

        //
        // The data available flag.
        //
        // CAUTION! It is actually the data count being returned.
        // Any value greater than zero means that data are available.
        //
        int f = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Sense data available.
        sense((void*) &f, *NULL_POINTER_STATE_CYBOI_MODEL, p1, p2);

        if (f > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // There ARE data available on the client.
            //

            // Set input/output flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }
}

/* SENSE_IO_CHECKER_SOURCE */
#endif
