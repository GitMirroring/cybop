/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

#if defined(__linux__) || defined(__unix__)
    #include <sys/socket.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/socket.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <winsock.h>
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "variable.h"

/**
 * Sets the local socket address.
 *
 * @param p0 the local socket address data
 * @param p1 the filename data
 * @param p2 the filename count
 */
void set_socket_address_local(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* fc = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                //
                // CAUTION! The compiler brings an error if the type "struct sockaddr_un"
                // is used, because pointer calculation is done below!
                // Therefore, a cast to void* is done here instead.
                //
                void* a = (void*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Set socket address local.");

                //
                // CAUTION! For some strange reason, the socket file name length
                // is limited to 108 ascii characters in the gnu c library!
                // The documentation called it a "magic number" and does not
                // know why this limit exists.
                //
                // CAUTION! Use the operator < (less than) and NOT
                // the operator <= (less than or equal) for comparison,
                // because there has to be space for the null termination character.
                //
                if (*fc < *NUMBER_108_INTEGER_STATE_CYBOI_MODEL) {

                    //
                    // Determine position of namespace
                    // ("sun_family" field within the "sockaddr_un" structure).
                    //
                    // Do NOT access the "sun_family" field DIRECTLY with:
                    // (*a).sun_family = AF_LOCAL;
                    // It won't work because the "sockaddr_un" structure, due to
                    // the unknown size of its "sun_path" field (a character array),
                    // is considered an incomplete type, so that the compiler
                    // brings an error.
                    //
                    short int* family = (short int*) (a + *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
                    //
                    // Determine position of file name
                    // ("sun_path" field within the "sockaddr_un" structure).
                    //
                    // Do NOT access the "sun_path" field directly with:
                    // (*a).sun_path
                    // It won't work because the "sockaddr_un" structure, due to
                    // the unknown size of its "sun_path" field (a character array),
                    // is considered an incomplete type, so that the compiler
                    // brings an error.
                    //
                    void* path = (void*) (a + *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
                    // The terminated file name item.
                    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
                    // The terminated file name item data, count.
                    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* tc = *NULL_POINTER_STATE_CYBOI_MODEL;

                    //
                    // Allocate terminated file name item.
                    //
                    // CAUTION! Due to memory allocation handling, the size MUST NOT
                    // be negative or zero, but have at least a value of ONE.
                    //
                    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
                    // Encode wide character file name into multibyte character data.
                    encode_utf_8(t, p1, p2);
                    //
                    // Get terminated file name item data, count.
                    //
                    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                    // Inside the structure, arrays may have been reallocated,
                    // with elements pointing to different memory areas now.
                    //
                    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                    copy_array_forward((void*) &tc, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

                    fwprintf(stdout, L"Debug: Set socket address local. td: %s\n", td);
                    fwprintf(stdout, L"Debug: Set socket address local. tc: %i\n", *((int*) tc));

                    //
                    // Set namespace (address format/family).
                    //
                    // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                    // The latter is to be used for socket creation.
                    //
                    *family = *LOCAL_ADDRESS_FAMILY_SOCKET_SYMBOLIC_NAME;

                    //
                    // Set terminated file name by first copying the actual name
                    // and then adding the null termination character.
                    //
                    // CAUTION! Do NOT reallocate the file name array with:
                    // int nc = *fc + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                    // reallocate_array((void*) &(a.sun_path), p2, (void*) &nc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
                    //
                    // The reason is that the size of the "sun_path" field of
                    // the "sockaddr_un" structure had to be fixed (to 108,
                    // for reasons explained above), in order to be able to
                    // calculate the overall size of the "sockaddr_un" structure.
                    //
                    // It is no problem if the "sun_path" array size is greater
                    // than the actual file name size, since the file name is
                    // terminated with a null character.
                    //
                    copy_array_forward(path, td, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, tc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
                    copy_array_forward(path, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, tc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                    fwprintf(stdout, L"Debug: Set socket address local. path: %s\n", path);

                    // Deallocate terminated file name item.
                    deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set socket address local. The socket file name is longer than the limit 108, as set by the gnu c library.");
                    fwprintf(stdout, L"Error: Could not set socket address local. The socket file name is longer than the limit 108, as set by the gnu c library. *fc: %i\n", *fc);
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set socket address local. The socket address is null.");
                fwprintf(stdout, L"Error: Could not set socket address local. The socket address is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set socket address local. The file name is null.");
            fwprintf(stdout, L"Error: Could not set socket address local. The file name is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not set socket address local. The file name count is null.");
        fwprintf(stdout, L"Error: Could not set socket address local. The file name count is null. p2: %i\n", p2);
    }
}
