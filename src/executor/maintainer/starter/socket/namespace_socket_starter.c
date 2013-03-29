/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NAMESPACE_SOCKET_STARTER_SOURCE
#define NAMESPACE_SOCKET_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

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
 * Starts up socket- and address namespace.
 *
 * @param p0 the socket namespace (pointer reference)
 * @param p1 the address namespace (pointer reference)
 * @param p2 the namespace model
 * @param p3 the namespace model count
 */
void startup_socket_namespace(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* an = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* sn = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup socket namespace.");

            // The comparison result.
            int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p2, (void*) LOCAL_NAMESPACE_CYBOL_MODEL);

                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    *sn = PF_LOCAL;
                    *an = AF_LOCAL;
                }
            }

            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p2, (void*) INET_NAMESPACE_CYBOL_MODEL);

                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    *sn = PF_INET;
                    *an = AF_INET;
                }
            }

            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                compare_integer_equal((void*) &r, p2, (void*) INET6_NAMESPACE_CYBOL_MODEL);

                if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    *sn = PF_INET6;
                    *an = AF_INET6;
                }
            }

            if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket namespace. The namespace model is not known.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket namespace. The socket namespace is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup socket namespace. The address namespace is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* NAMESPACE_SOCKET_STARTER_SOURCE */
#endif
