/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_SERIAL_PORT_WRITER_SOURCE
#define STREAM_SERIAL_PORT_WRITER_SOURCE

/*??
#include <errno.h>
#include <stdio.h>

#ifdef WIN32
    #include <windows.h>

    int fsync(int fd) {

        return (FlushFileBuffers ((HANDLE) _get_osfhandle (fd))) ? 0 : -1;
    }
#endif
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/calculator/basic/integer/subtract_integer_calculator.c"
#include "../../../../executor/calculator/basic/pointer/add_pointer_calculator.c"
#include "../../../../executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/streamer/writer/serial_port/write_serial_port_writer.c"
#include "../../../../logger/logger.c"

/**
 * Writes source to the serial port.
 *
 * @param p0 the destination file descriptor
 * @param p1 the source data
 * @param p2 the source count
 */
void write_serial_port_stream(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write serial port stream.");

        // The source data position.
        void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source count remaining.
        int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The number of bytes transferred.
        int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The break flag.
        int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Copy source data position.
        // This is the index to start the transfer at.
        copy_pointer((void*) &d, (void*) &p1);
        // Copy source count remaining.
        copy_integer((void*) &c, p2);

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

        // CAUTION! The write operation does not necessarily
        // handle all the bytes handed over to it.
        // It therefore has to be CALLED AGAIN AND AGAIN,
        // in a loop, until the complete message has been transmitted!
        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_smaller_or_equal((void*) &b, (void*) &c, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                break;
            }

            write_serial_port_write(p0, d, (void*) &c, (void*) &n);

            // Increment source data position.
            calculate_pointer_add((void*) &d, (void*) &n);
            // Decrement source count remaining.
            calculate_integer_subtract((void*) &c, (void*) &n);
        }

/*?? TODO:
        // Initialise error number.
        // It is a global variable/function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the procedure that might cause an error.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Make sure all data associated with the open file
        // is written to the device associated with the descriptor.
        // The function call does not return unless all actions have finished.
        //
        // CAUTION! The glibc "write" function is called within
        // the "write_serial_port_write" function.
        // Once "write" returns, the data is enqueued to be written
        // and can be read back right away, but it is not necessarily
        // written out to permanent storage immediately. Therefore,
        // the "fsync" function is called here in order to make sure
        // the data has been permanently stored before continuing.
        //
        // It is more efficient for the system to batch up consecutive
        // writes and do them all at once when convenient. Normally,
        // they will always be written to disk within a minute or less.
        //
        // One can use the "O_FSYNC" open mode to make write
        // always store the data to disk before returning.
        int e = fsync(*f);

        // Test error value.
        // The return value of the "fsync" function is zero
        // if no error occurred; otherwise, it is minus one.
        if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            if (errno == EBADF) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port stream. The file descriptor is not valid.");

            } else if (errno == EINVAL) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port stream. No synchronization is possible since the system does not implement this.");

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port stream. An unknown error occured.");
            }
        }
*/

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port stream. The destination file descriptor is null.");
    }
}

/* STREAM_SERIAL_PORT_WRITER_SOURCE */
#endif
