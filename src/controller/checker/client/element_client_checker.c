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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ELEMENT_CLIENT_CHECKER_SOURCE
#define ELEMENT_CLIENT_CHECKER_SOURCE

#include <time.h> // time_t, time()

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../controller/checker/client/available_element_client_checker.c"
#include "../../../controller/checker/client/empty_element_client_checker.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/sensor/sensor.c"
#include "../../../logger/logger.c"

/**
 * Checks open client for available data.
 *
 * @param p0 the destination client
 * @param p1 the client list data (pointer reference)
 * @param p2 the client list count
 * @param p3 the client list size
 * @param p4 the accepttime list data (pointer reference)
 * @param p5 the accepttime list count
 * @param p6 the accepttime list size
 * @param p7 the list index
 * @param p8 the input/output entry
 * @param p9 the channel
 * @param p10 the client removed flag
 */
void check_client_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** cl = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check client element.");

        // The client.
        int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        //
        // The data available flag.
        //
        // CAUTION! It is actually the data count being returned.
        // Any value greater than zero means that data are available.
        //
        int f = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Get client from client list at the given index.
        copy_array_forward((void*) &c, *cl, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p7);

        // Sense data available on already open client.
        sense((void*) &f, (void*) &c, p8, p9);

        //
        // The current calendar time.
        //
        // The type "time_t" is used to represent a simple calendar time.
        // In iso c, it can be either an integer or a floating-point type.
        //
        // On posix-conformant systems, "time_t" is an integer type
        // and its values represent the number of seconds elapsed
        // since the epoch, which is 1970-01-01T00:00:00 UTC.
        //
        time_t t = time(*NULL_POINTER_STATE_CYBOI_MODEL);

        if (f > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // There ARE data available on the client.
            //

            check_client_element_available(p0, p4, p7, (void*) &c, (void*) &t);

        } else {

            //
            // There are NO data available on the client.
            //

            check_client_element_empty(p1, p2, p3, p4, p5, p6, p7, (void*) &c, p8, p10, (void*) &t);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check client element empty. The accepttime list data is null.");
    }
}

/* ELEMENT_CLIENT_CHECKER_SOURCE */
#endif
