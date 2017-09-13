/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef READ_SERIAL_PORT_READER_SOURCE
#define READ_SERIAL_PORT_READER_SOURCE

#include <errno.h>
#include <limits.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

#ifdef _MSC_VER
    #include <io.h>
    #include "../../../../windows/cyboi_win_mapper.h"
#endif

/**
 * Reads a serial port character.
 *
 * @param p0 the destination item
 * @param p1 the source file descriptor data
 * @param p2 the source mutex
 * @param p3 the minimum number of bytes to be received in one call of the read function
 * @param p4 the maximum number of bytes to be received in one call of the read function
 * @param p5 the character count
 * @param p6 the loop break flag
 */
void read_serial_port_read(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    // The minimum number of bytes to be received in one call of the read function.
    // CAUTION! Set default value. At least one byte has to be received.
    // Otherwise, this function would not make sense.
    int min = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    // The maximum number of bytes to be received in one call of the read function.
    // CAUTION! Set default value. The SSIZE_MAX value is defined in <limits.h>.
    // Another possible common value would be 4096
    // (seen in other source code examples).
    // int max = SSIZE_MAX; // CAUTION! If using this constant, then care about overflow, since SSIZE_MAX has a greater value range than int on 64 Bit machines.
    int max = INT_MAX; // This is the maximum value that can be represented by a signed int. On most machines that the GNU C Library runs on, an int is a 32-bit quantity.
    // The minimum maximum comparison result.
    int rminmax = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        max = *((int*) p4);
    }

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        min = *((int*) p3);
    }

    // CAUTION! The following source code should NOT depend
    // upon the existence of parametres "minimum" and "maximum"
    // in an if statement, since they are optional.
    // Therefore, they got initialised independently above.

    // CAUTION! The minimum has to be SMALLER than the maximum.
    // Equality IS ALSO possible, e.g. when just reading one character.
    compare_integer_less_or_equal((void*) &rminmax, (void*) &min, (void*) &max);

    if (rminmax != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* f = (int*) p1;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read serial port read.");

                if (*f >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // The input character.
                    // unsigned char c[max];
                    unsigned char c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // The maximum number of bytes to be read.
                    //
                    // The number of bytes actually read might be less,
                    // for example, if there aren't that many bytes left
                    // in the file or if there aren't that many bytes
                    // immediately available.
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
                    // size_t ts = max;
                    size_t ts = *PRIMITIVE_STATE_CYBOI_MODEL_COUNT;

                    // Initialise error number.
                    // It is a global variable/function and other operations
                    // may have set some value that is not wanted here.
                    //
                    // CAUTION! Initialise the error number BEFORE calling
                    // the function that might cause an error.
                    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                    // Lock serial port mutex.
                    //
                    // CAUTION! This IS NECESSARY to avoid conflicts with the serial port sensing thread,
                    // which in parallel is trying to detect that some character is available,
                    // what is also called "peeking ahead" at the input.
                    pthread_mutex_lock(p2);

                    // Get character from source input stream of serial port.
                    // ssize_t e = read(*f, (void*) c, ts);
#if defined(__linux__) || defined(__unix__)
                    ssize_t e = read(*f, (void*) &c, ts);
#elif defined(__APPLE__) && defined(__MACH__)
                    ssize_t e = read(*f, (void*) &c, ts);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
                    int e = read(*f, (void*) &c, ts);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

                    // Unlock serial port mutex.
                    pthread_mutex_unlock(p2);

                    // The byte number as temporary "int" variable.
                    //
                    // The "ssize_t" type is signed and a glibc extension.
                    // The similar "size_t" type, on the other hand, is unsigned.
                    //
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

                    // Test error value.
                    // The return value of the "read" function is
                    // the number of bytes actually read, if no
                    // error occurred; otherwise, it is minus one.
                    if (e > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

    // fwprintf(stdout, L"TEST read serial port read character c[0]: %i\n", c[0]);
    fwprintf(stdout, L"TEST read serial port read character c: %i %c\n", c, c);

                        // The maximum comparison result.
                        int rmax = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                        compare_integer_less((void*) &rmax, p5, (void*) &max);

                        if (rmax != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            // The maximum possible number of characters to read
                            // has NOT been reached yet.
                            // Therefore, further characters may be appended below.

                            // The minimum comparison result.
                            int rmin = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                            compare_integer_less((void*) &rmin, p5, (void*) &min);

                            if (rmin != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                                // The minimum required number of characters to read
                                // has NOT been reached. Therefore, read on.
                                // EVEN ZERO VALUE characters are appended below.
                                // This is on purpose, because on some devices
                                // they may have a special meaning.

                                // Append source character to destination item.
                                // modify_item(p0, (void*) c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
                                modify_item(p0, (void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                                // Increment character count.
                                calculate_integer_add(p5, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

                            } else {

                                // The minimum required number of characters to read
                                // HAS been reached.

                                if (c > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                                    // However, as long as FURTHER VALID characters
                                    // are returned by the "read" function, these
                                    // are appended to the destination as well.

                                    // Append source character to destination item.
                                    // modify_item(p0, (void*) c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
                                    modify_item(p0, (void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                                    // Increment character count.
                                    calculate_integer_add(p5, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

                                } else {

                                    // Zero value characters are now NOT appended anymore,
                                    // since a zero value character indicates end-of-file (EOF).
                                    // This is contrarily to above, where the minimum
                                    // had not been reached yet.

                                    // Set loop break flag.
                                    // CAUTION! If this was not done here,
                                    // the loop would run endlessly.
                                    copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                                }
                            }

                        } else {

                            // The maximum possible number of characters to read
                            // HAS been reached.

                            // Set loop break flag.
                            // CAUTION! If this was not done here,
                            // the loop would run endlessly.
                            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                        }

                    } else if (e == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. The number of bytes returned is zero.");

                        // Set loop break flag.
                        // CAUTION! If this was not done here,
                        // the loop would run endlessly.
                        copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                    } else if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        if (errno == EAGAIN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. The O_NONBLOCK flag is set for the file, so that read returned immediately without reading any data.");

                        } else if (errno == EBADF) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. The file descriptor is not valid, or is not open for reading.");

                        } else if (errno == EINTR) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. The read function was interrupted by a signal while it was waiting for input.");

                        } else if (errno == EIO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. A hardware error occured.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. An unknown error occured.");
                        }

                        // Set loop break flag.
                        // CAUTION! If this was not done here,
                        // the loop would run endlessly.
                        copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. The source serial port file descriptor is zero or negative.");

                    // Set loop break flag.
                    // CAUTION! If this was not done here,
                    // the loop would run endlessly.
                    copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. The source serial port file descriptor is null.");

                // Set loop break flag.
                // CAUTION! If this was not done here,
                // the loop would run endlessly.
                copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. The source serial port mutex is null.");

            // Set loop break flag.
            // CAUTION! If this was not done here,
            // the loop would run endlessly.
            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read serial port read. The minimum is greater than the maximum.");

        // Set loop break flag.
        // CAUTION! If this was not done here,
        // the loop would run endlessly.
        copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* READ_SERIAL_PORT_READER_SOURCE */
#endif
