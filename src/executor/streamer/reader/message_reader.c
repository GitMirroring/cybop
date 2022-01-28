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

#ifndef MESSAGE_READER_SOURCE
#define MESSAGE_READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/sensor/completeness_sensor.c"
#include "../../../executor/sensor/fragment_sensor.c"
#include "../../../executor/streamer/writer/interrupt_pipe/interrupt_pipe_writer.c"
#include "../../../logger/logger.c"

/**
 * Senses a message.
 *
 * @param p0 the destination item
 * @param p1 the source client identification (e.g. socket number, window id)
 * @param p2 the input memory data
 * @param p3 the input memory size
 * @param p4 the destination item mutex
 * @param p5 the interrupt pipe write file descriptor
 * @param p6 the interrupt mutex
 * @param p7 the server identification (server base + service port)
 * @param p8 the language (protocol)
 * @param p9 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p10 the exit flag
 * @param p11 the client mode (true if reading as client from server socket; false otherwise)
 * @param p12 the channel
 */
void sense_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense message.");
    fwprintf(stdout, L"Debug: Sense message. p12: %i\n", p12);
    fwprintf(stdout, L"Debug: Sense message. *p12: %i\n", *((int*) p12));

    // The complete flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Receive next message fragment.
    sense_fragment(p0, p1, p2, p3, p4, p10, p11, p12);

    //
    // CAUTION! The exit flag might have been set inside
    // the function "sense_fragment", if the client
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
    // in function "sense_completeness" below,
    // so that the complete flag is not set.
    //

    // Check for completeness by evaluating length prefix and end suffix.
    sense_completeness((void*) &f, p9, p0, p8, p12);

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

        // Reset message length.
        copy_integer(p9, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

        //?? TODO: set_break_flag_for_loop
        copy_integer(TODO);

        if (asynchronous-flag == true) {

            // Inform interrupt pipe that a message was sensed in complete.
            write_interrupt_pipe(p5, p7, p1, p6);
        }
    }
}

/* MESSAGE_READER_SOURCE */
#endif
