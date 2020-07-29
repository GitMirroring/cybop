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

#ifndef WRITE_SERIAL_PORT_WRITER_SOURCE
#define WRITE_SERIAL_PORT_WRITER_SOURCE

#include <errno.h>
#include <stdio.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Writes the source elements to the serial port output.
 *
 * @param p0 the destination file descriptor data
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the number of bytes transferred
 */
void write_serial_port_write(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* n = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* sc = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                //
                // This test IS NECESSARY, because the parametre
                // is handed over to a glibc function below.
                //

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* d = (int*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write serial port write.");

                    //
                    // CAUTION! Locking does NOT seem to be necessary here.
                    // The serial RS-232 interface has two independent data wires,
                    // one for input and another one for output.
                    // In case a sensing thread is running for serial input detection,
                    // there is NO problem in sending data here,
                    // since input and output may be accessed in parallel
                    // without having to fear conflicts.
                    //

                    //
                    // The temporary size_t variable.
                    //
                    // CAUTION! It IS NECESSARY because on 64 Bit machines,
                    // the "size_t" type has a size of 8 Byte,
                    // whereas the "int" type has the usual size of 4 Byte.
                    // When trying to cast between the two, memory errors
                    // will occur and the valgrind memcheck tool report:
                    // "Invalid read of size 8".
                    //
                    // CAUTION! Initialise temporary size_t variable with final int value
                    // JUST BEFORE handing that over to the glibc function requiring it.
                    //
                    // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
                    // because values are casted to int* internally again.
                    //
                    size_t tsc = *sc;

                    //
                    // Initialise error number.
                    // It is a global variable/function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling
                    // the function that might cause an error.
                    //
                    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    //
                    // Write to serial port.
                    //
                    // CAUTION! The data is NOT necessarily a character string
                    // and a null character is output like any other character.
                    //
                    // CAUTION! The return value is the number of bytes
                    // actually written. This may be equal to the size
                    // handed over, but can always be smaller.
                    // Therefore, this function "write_serial_port_stream_elements"
                    // is called in a loop, iterating until all the data is written.
                    //
                    *n = write(*d, p1, tsc);

                    // Test error value.
                    if (*n < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (errno == EAGAIN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The O_NONBLOCK flag has been set for the file, so that it returns immediately without writing any data.");

                        } else if (errno == EBADF) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The file descriptor is not valid, or is not open for writing.");

                        } else if (errno == EFBIG) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The size of the file would become larger than the implementation can support.");

                        } else if (errno == EINTR) {

                            //
                            // Remark from the gnu glibc manual:
                            // Unless you have arranged to prevent EINTR failures,
                            // you should check errno after each failing call to write,
                            // and if the error was EINTR, you should simply repeat the call.
                            //

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The write operation was interrupted by a signal while it was blocked waiting for completion.");

                        } else if (errno == EIO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. A hardware error occured.");

                        } else if (errno == ENOSPC) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The device containing the file is full.");

                        } else if (errno == EPIPE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The pipe or FIFO to be written to isn't open for reading by any process.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. An unknown error occured.");
                        }
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The serial port output file descriptor is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The source data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The source count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write serial port write. The number of transferred bytes is null.");
    }
}

/* WRITE_SERIAL_PORT_WRITER_SOURCE */
#endif
