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

#ifndef ELEMENTS_STREAM_SERIAL_PORT_SENDER_SOURCE
#define ELEMENTS_STREAM_SERIAL_PORT_SENDER_SOURCE

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
#include "../../../../logger/logger.c"

/**
 * Sends the source elements to the serial port output.
 *
 * @param p0 the destination file descriptor data
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the number of bytes transferred
 */
void send_serial_port_stream_elements(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* n = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* sc = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // This test is necessary, because the parametre
                // is handed over to a glibc function below.

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* d = (int*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send serial port stream elements.");

                    //
                    // CAUTION! Locking does NOT seem to be necessary here.
                    // The serial RS-232 interface has two independent data wires,
                    // one for input and another one for output.
                    // In case a sensing thread is running for serial input detection,
                    // there is NO problem in sending data here,
                    // since input and output may be accessed in parallel
                    // without having to fear conflicts.
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
                    size_t tsc = *sc;

                    // Initialise error number.
                    // It is a global variable/ function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling
                    // the function that might cause an error.
                    copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                    // Send to serial port.
                    //
                    // CAUTION! The data is NOT necessarily a character string
                    // and a null character is output like any other character.
                    //
                    // CAUTION! The return value is the number of bytes
                    // actually written. This may be equal to the size
                    // handed over, but can always be smaller.
                    // Therefore, this function "send_serial_port_stream_elements"
                    // is called in a loop, iterating until all the data is written.
                    *n = write(*d, p1, tsc);

                    // Test error value.
                    if (*n < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (errno == EAGAIN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The O_NONBLOCK flag has been set for the file, so that it returns immediately without writing any data.");

                        } else if (errno == EBADF) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The file descriptor is not valid, or is not open for writing.");

                        } else if (errno == EFBIG) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The size of the file would become larger than the implementation can support.");

                        } else if (errno == EINTR) {

                            // Remark from the gnu glibc manual:
                            // Unless you have arranged to prevent EINTR failures,
                            // you should check errno after each failing call to write,
                            // and if the error was EINTR, you should simply repeat the call.

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The write operation was interrupted by a signal while it was blocked waiting for completion.");

                        } else if (errno == EIO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. A hardware error occured.");

                        } else if (errno == ENOSPC) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The device containing the file is full.");

                        } else if (errno == EPIPE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The pipe or FIFO to be written to isn't open for reading by any process.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. An unknown error occured.");
                        }
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The serial port output file descriptor is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The source data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The source count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send serial port stream elements. The number of transferred bytes is null.");
    }
}

/* ELEMENTS_STREAM_SERIAL_PORT_SENDER_SOURCE */
#endif
