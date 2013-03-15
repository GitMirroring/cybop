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

#ifndef CHARACTER_SERIAL_PORT_RECEIVER_SOURCE
#define CHARACTER_SERIAL_PORT_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <errno.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Receives a serial port character.
 *
 * @param p0 the destination item
 * @param p1 the source serial port file descriptor
 * @param p2 the source serial port mutex
 * @param p3 the loop break flag
 */
void receive_serial_port_character(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* sp = (int*) p1;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive serial port character.");

            if (*sp >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // The input character.
                unsigned char c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

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
                size_t ts = *PRIMITIVE_STATE_CYBOI_MODEL_COUNT;

                // Initialise error number.
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                // Lock serial port mutex.
                //
                // CAUTION! This IS NECESSARY to avoid conflicts with the serial port sensing thread,
                // which in parallel is trying to detect that some character is available,
                // what is also called "peeking ahead" at the input.
                pthread_mutex_lock(p2);

                // Get character from source input stream of serial port.
                ssize_t e = read(*sp, (void*) &c, ts);

                // The byte number as temporary "int" variable.
                //
                // The "ssize_t" type is similar to "size_t".
                // On 64 Bit machines they might have a size of 8 Byte,
                // whereas the "int" type has the usual size of 4 Byte.
                // When trying to cast between the two, memory errors
                // will occur and the valgrind memcheck tool report:
                // "Invalid read of size 8".
                //
                // CAUTION! Initialise variable JUST BEFORE handing
                // it over to the function requiring it.
                //
                // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
                // because values are casted to int* internally again.
                int n = e;

fwprintf(stdout, L"TEST receive serial port character c: %i\n", c);

                // Unlock serial port mutex.
                pthread_mutex_unlock(p2);

                // Test error value.
                // The return value of the "read" function is
                // the number of bytes actually read, if no
                // error occurred; otherwise, it is minus one.
                if (e > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    if (c > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // Append source character to destination item.
                        append_item_element(p0, (void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &n, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                    } else {

                        // Set loop break flag.
                        // An input character value of zero indicates end-of-file.
                        // Since all values have been received, the loop can be left now.
                        copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }

                } else if (e == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. The number of bytes returned is zero.");

                    // Set loop break flag.
                    // An input character value of zero indicates end-of-file.
                    // Since all values have been received, the loop can be left now.
                    copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                } else if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    if (errno == EAGAIN) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. The O_NONBLOCK flag is set for the file, so that read returned immediately without reading any data.");

                    } else if (errno == EBADF) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. The file descriptor is not valid, or is not open for reading.");

                    } else if (errno == EINTR) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. The read function was interrupted by a signal while it was waiting for input.");

                    } else if (errno == EIO) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. A hardware error occured.");

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. An unknown error occured.");
                    }

                    // Set loop break flag.
                    // CAUTION! If this was not done here,
                    // the loop would run endlessly.
                    copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. The source serial port file descriptor is zero or negative.");

                // Set loop break flag.
                // An input character value of zero indicates end-of-file.
                // Since all values have been received, the loop can be left now.
                copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. The source serial port file descriptor is null.");

            // Set loop break flag.
            // CAUTION! If this was not done here,
            // the loop would run endlessly.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive serial port character. The source serial port mutex is null.");

        // Set loop break flag.
        // CAUTION! If this was not done here,
        // the loop would run endlessly.
        copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* CHARACTER_SERIAL_PORT_RECEIVER_SOURCE */
#endif
