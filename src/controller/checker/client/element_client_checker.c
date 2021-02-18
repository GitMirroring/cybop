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
 * @param p1 the source client list data
 * @param p2 the source accepttime list data
 * @param p3 the source list index
 * @param p4 the input/output entry
 * @param p5 the channel
 */
void check_client_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

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
    copy_array_forward((void*) &c, p1, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);

    //?? fwprintf(stdout, L"TEST: Check client element. pre sense. client c: %i \n", c);
    // Sense data available on already open client.
    sense((void*) &f, (void*) &c, p4, p5);
    //?? fwprintf(stdout, L"TEST: Check client element. post sense. data count f: %i \n", f);

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

        check_client_element_available(p0, p2, p3, (void*) &c, (void*) &t);

    } else {

        //
        // There are NO data available on the client.
        //

        check_client_element_empty(p2, p3, p4, (void*) &c, (void*) &t);
    }
}

/* ELEMENT_CLIENT_CHECKER_SOURCE */
#endif
