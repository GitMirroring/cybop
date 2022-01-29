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
#include "../../../logger/logger.c"
--
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/sensor/completeness_sensor.c"
#include "../../../executor/sensor/fragment_sensor.c"
#include "../../../executor/streamer/writer/interrupt_pipe/interrupt_pipe_writer.c"

/**
 * Reads a message in certain steps.
 *
 * @param p0 the destination item
 * @param p1 the source client identification (e.g. file descriptor for a file, serial port, terminal, socket)
 * @param p2 the message fragment data
 * @param p3 the message fragment size
 * @param p4 the destination mutex
 * @param p5 the socket close flag
 * @param p6 the interrupt pipe write file descriptor
 * @param p7 the interrupt mutex
 * @param p8 the thread exit flag
 * @param p9 the server identification (server base + service port)
 * @param p10 the language (protocol)
 * @param p11 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p12 the channel
 * @param p13 the asynchronous mode
 */
void read_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read message.");
    fwprintf(stdout, L"Debug: Read message. p12: %i\n", p12);
    fwprintf(stdout, L"Debug: Read message. *p12: %i\n", *((int*) p12));

    // The close flag.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The complete flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Receive next message fragment.
    read_fragment(p0, p1, p2, p3, p4, p10, p11, p12, (void*) &c);

    if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The close flag was set, since the communication
        // partner on the other side has closed its connexion.
        //

        // Cleanup resources.
        //?? deallocate_client_entry(p0, p1, p2, p3, p4, p5, p6, p7, p8);

        //
        // Close socket.
        //
        // CAUTION! The socket may be closed in any case,
        // no matter if this is a client that talked to
        // a server or this is the client stub of a server.
        //
        // There is NO danger of closing the server socket
        // by accident, since that only accepts client requests
        // but does NOT communicate directly.
        //
        close_socket(file-descriptor);

        //
        // Set client stub thread exit flag.
        //
        // This is ONLY relevant if this is a server socket
        // managing its open client connexions in a client list.
        //
        // If this is a client socket that talked to a server,
        // then there is no thread and the exit flag is null,
        // so that it is just ignored here.
        //
        copy_integer(px, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    //
    // CAUTION! The exit flag might have been set inside
    // the function "read_fragment", if the client
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
    // in function "read_completeness" below,
    // so that the complete flag is not set.
    //

    // Check for completeness by evaluating length prefix and end suffix.
    read_completeness((void*) &f, p9, p0, p8, p12);

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

        if (asynchronous-flag == false) {

            //
            // The message was read in SYNCHRONOUS mode,
            // that is from the device DIRECTLY
            // into the cybol destination.
            //

            // Set loop break flag.
            copy_integer(px, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        } else {

            //
            // The message was read in ASYNCHRONOUS mode,
            // that is from the device
            // into a cyboi-internal BUFFER.
            //

            // Inform interrupt pipe of main threaad.
            write_interrupt_pipe(p5, p7, p1, p6);

            //
            // CAUTION! Do NOT set the loop break flag here,
            // since the loop has to CONTINUE to run as long as
            // the sensing thread is active and the exit flag not set.
            //
        }
    }
}

/* MESSAGE_READER_SOURCE */
#endif
