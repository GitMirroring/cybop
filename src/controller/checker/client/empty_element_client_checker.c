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

#ifndef EMPTY_ELEMENT_CLIENT_CHECKER_SOURCE
#define EMPTY_ELEMENT_CLIENT_CHECKER_SOURCE

//
// System interface
//

#include <time.h> // time_t, difftime()
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "client.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Checks timeout of open but inactive client
 * and closes it if the timeout has been crossed.
 *
 * @param p0 the client list data (pointer reference)
 * @param p1 the client list count
 * @param p2 the client list size
 * @param p3 the accepttime list data (pointer reference)
 * @param p4 the accepttime list count
 * @param p5 the accepttime list size
 * @param p6 the list index
 * @param p7 the client
 * @param p8 the input/output entry
 * @param p9 the client removed flag
 * @param p10 the current calendar time
 */
void check_client_element_empty(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p10 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        time_t* t = (time_t*) p10;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** ad = (void**) p3;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check client element empty.");

            // The accepttime.
            int a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The timeout.
            void* to = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get accepttime from accepttime list at the given index.
            copy_array_forward((void*) &a, *ad, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);
            // Get timeout from input/output entry.
            copy_array_forward((void*) &to, p8, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TIMEOUT_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME);

            // The accepttime with correct type.
            time_t at = (time_t) a;
            //
            // Calculate elapsed time (difference) between two calendar times.
            //
            // CAUTION! Since the type "time_t" might differ between platforms
            // (integer or floating-point), a simple subtraction might fail.
            // Therefore, the function "difftime" is used to compute the difference.
            //
            double d = difftime(*t, at);
            // The elapsed time (difference) as integer value.
            int di = (int) d;
            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_greater((void*) &r, (void*) &di, to);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The timeout has been crossed.
                //

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close client connexion due to crossed timeout.");
                fwprintf(stdout, L"Debug: Close client connexion due to crossed timeout. r: %i\n", r);

                // Remove element from client list.
                remove_data(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p6, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                // Remove element from accepttime list.
                remove_data(p3, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p6, p4, p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                // Set client removed flag.
                copy_integer(p9, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                // Close client.
                shutdown_socket_close(p7);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check client element empty. The accepttime list data is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check client element empty. The current calendar time is null.");
    }
}

/* EMPTY_ELEMENT_CLIENT_CHECKER_SOURCE */
#endif
