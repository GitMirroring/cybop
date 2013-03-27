/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_SERIAL_PORT_SENDER_SOURCE
#define STREAM_SERIAL_PORT_SENDER_SOURCE

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/sender/serial_port/elements_stream_serial_port_sender.c"
#include "../../../../logger/logger.c"

/**
 * Sends the source to the serial port output.
 *
 * @param p0 the destination file descriptor data
 * @param p1 the source data
 * @param p2 the source count
 */
void send_serial_port_stream(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send serial port stream.");

        // The break flag.
        int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The data index to start the transfer at.
        void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The number of bytes transferred.
        int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Initialise data index to start the transfer at.
        copy_pointer((void*) &i, (void*) &p1);

        if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

            // CAUTION! If the loop count handed over as parametre is NULL,
            // then the break flag will NEVER be set to true, because the loop
            // variable comparison does (correctly) not consider null values.
            // Therefore, in this case, the break flag is set to true already here.
            // Initialising the break flag with true will NOT work either, since it:
            // a) will be left untouched if a comparison operand is null;
            // b) would have to be reset to true in each loop cycle.
            copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

        // CAUTION! The send operation does not necessarily
        // handle all the bytes handed over to it.
        // It therefore has to be CALLED AGAIN AND AGAIN,
        // in a loop, until the complete message has been transmitted!
        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_smaller_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                break;
            }

            send_serial_port_stream_elements(p0, i, p2, (void*) &n);

            // Increment byte array index.
            calculate_pointer_add((void*) &i, (void*) &n);
            // Decrement byte array count.
            calculate_integer_subtract(p2, (void*) &n);
        }

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the procedure that might cause an error.
        copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        // Make sure all data associated with the open file
        // is written to the device associated with the descriptor.
        // The function call does not return unless all actions have finished.
        //
        // CAUTION! The glibc "write" function is called within
        // the "send_serial_port_stream_elements" function.
        // Once "write" returns, the data is enqueued to be written
        // and can be read back right away, but it is not necessarily
        // written out to permanent storage immediately. Therefore,
        // the "fsync" function is called here in order to make sure
        // the data has been permanently stored before continuing.
        //
        // It is more efficient for the system to batch up
        // consecutive writes and do them all at once when
        // convenient. Normally, they will always be written
        // to disk within a minute or less.
        //
        // One can use the "O_FSYNC" open mode to make write
        // always store the data to disk before returning.
        int e = fsync(*d);

        // Test error value.
        // The return value of the "fsync" function is zero
        // if no error occurred; otherwise, it is minus one.
        if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            if (errno == EBADF) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream. The file descriptor is not valid.");

            } else if (errno == EINVAL) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream. No synchronization is possible since the system does not implement this.");

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream. An unknown error occured.");
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream. The serial port output file descriptor is null.");
    }
}

/* STREAM_SERIAL_PORT_SENDER_SOURCE */
#endif
