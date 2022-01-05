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

#ifndef MESSAGE_SOCKET_SENSOR_SOURCE
#define MESSAGE_SOCKET_SENSOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/sensor/socket/completeness_check_socket_sensor.c"
#include "../../../executor/sensor/socket/fragment_socket_sensor.c"
#include "../../../executor/sensor/socket/interrupt_set_socket_sensor.c"
#include "../../../logger/logger.c"

/**
 * Senses socket message.
 *
 * @param p0 the destination buffer item
 * @param p1 the source identification (client socket number)
 * @param p2 the client socket mutex (destination buffer item)
 * @param p3 the interrupt pipe write file descriptor
 * @param p4 the interrupt mutex
 * @param p5 the local character buffer data
 * @param p6 the local character buffer count
 * @param p7 the input/output identification (input/output base + socket port)
 * @param p8 the language (protocol)
 * @param p9 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p10 the exit flag
 */
void sense_socket_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket message.");
    fwprintf(stdout, L"Debug: Sense socket message. p10: %i\n", p10);
    fwprintf(stdout, L"Debug: Sense socket message. *p10: %i\n", *((int*) p10));

    // The complete flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Receive next message fragment.
    sense_socket_fragment(p0, p1, p2, p5, p6, p10);

    //
    // CAUTION! The exit flag might have been set inside
    // the function "sense_socket_fragment", if the client
    // closed the connexion. The destination buffer item
    // remained empty, since no data got copied.
    //
    // In this case, further processing is NOT necessary.
    // It might even lead to errors if the interrupt pipe
    // of the main thread gets informed below.
    //
    // However, the exit flag is not tested here via "if-else"
    // (it could be done, but is not necessary),
    // since an empty destination buffer item is just ignored
    // in function "sense_socket_check_completeness" below,
    // so that the complete flag is not set.
    //

    // Check for length prefix and end suffix.
    sense_socket_check_completeness((void*) &f, p9, p0, p8);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The message is complete, that is all data
        // belonging to it have been received.
        //

        //
        // CAUTION! The complete flag does NOT have to be reset here,
        // since it is a local variable on stack and gets freed
        // automatically when this function is left now.
        //
        // f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        //

        // Reset message length.
        copy_integer(p9, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

        // Inform interrupt pipe if message is complete.
        sense_socket_set_interrupt(p3, p4, p7, p1);
    }
}

/* MESSAGE_SOCKET_SENSOR_SOURCE */
#endif
