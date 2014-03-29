/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOCAL_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE
#define LOCAL_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE

#ifdef __APPLE__
    //?? Check support for apple
#elif WIN32
    //?? Add WIN32 support
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif
#else
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif
#endif

#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/address_cybol_model.c"
#include "../../../../constant/model/cybol/communication_style_cybol_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cybol/namespace_cybol_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/memoriser/allocator.c"
#include "../../../../variable/type_size/socket_type_size.c"

/**
 * Startup socket socket address local.
 *
 * @param p0 the local socket address (pointer reference)
 * @param p1 the file name data
 * @param p2 the file name count
 */
void startup_socket_socket_address_local(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* fc = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            wchar_t* f = (wchar_t*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // CAUTION! The compiler brings an error if the "struct sockaddr_un"
                // type is used, because pointer calculation is done below!
                // Therefore, a cast to void** is done here instead.
                void** a = (void**) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket socket address local.");

                // Determine position of namespace
                // ("sun_family" field within the "sockaddr_un" structure).
                //
                // Do NOT access the "sun_family" field directly with:
                // (*a)->sun_family = AF_LOCAL;
                // It won't work because the "sockaddr_un" structure, due to
                // the unknown size of its "sun_path" field (a character array),
                // is considered an incomplete type, so that the compiler
                // brings an error.
                short int* family = (short int*) (*a + *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                // Set namespace (address format/ family).
                //
                // CAUTION! Use the prefix "AF_" here and NOT "PF_"!
                // The latter is to be used for socket creation.
                *family = AF_LOCAL;

                // CAUTION! For some strange reason, the socket file name length
                // is limited to 108 ascii characters in the gnu c library!
                // The documentation called it a "magic number" and does not
                // know why this limit exists.
                if (*fc < *NUMBER_108_INTEGER_STATE_CYBOI_MODEL) {

                    // CAUTION! Do NOT reallocate the file name array with:
                    // int nc = *fc + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                    // reallocate_array((void*) &((*a)->sun_path), p2, (void*) &nc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
                    //
                    // The reason is that the size of the "sun_path" field of
                    // the "sockaddr_un" structure had to be fixed (to 108,
                    // for reasons explained above), in order to be able to
                    // calculate the overall size of the "sockaddr_un" structure.
                    //
                    // It is no problem if the "sun_path" array size is greater
                    // than the actual file name size, since the file name is
                    // terminated with a null character.

                    // Determine position of file name
                    // ("sun_path" field within the "sockaddr_un" structure).
                    //
                    // Do NOT access the "sun_path" field directly with:
                    // (*a)->sun_path
                    // It won't work because the "sockaddr_un" structure, due to
                    // the unknown size of its "sun_path" field (a character array),
                    // is considered an incomplete type, so that the compiler
                    // brings an error.
                    void* path = (void*) (*a + *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);

                    // Set terminated file name by first copying the actual name
                    // and then adding the null termination character.
                    copy_array_forward((void*) &path, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                    copy_array_forward((void*) &path, (void*) NULL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address local. The socket file name is longer than the limit 108, as set by the gnu c library.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address local. The socket address is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address local. The file name is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket socket address local. The file name count is null.");
    }
}

/* LOCAL_SOCKET_ADDRESS_SOCKET_STARTER_SOURCE */
#endif
