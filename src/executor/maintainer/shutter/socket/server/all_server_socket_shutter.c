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

#ifndef ALL_SERVER_SOCKET_SHUTTER_SOURCE
#define ALL_SERVER_SOCKET_SHUTTER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../../../executor/copier/integer_copier.c"
#include "../../../../../executor/maintainer/shutter/socket/server/element_server_socket_shutter.c"
#include "../../../../../logger/logger.c"

/**
 * Shuts down all clients in the list.
 *
 * @param p0 the client list data (pointer reference)
 * @param p1 the client list count
 * @param p2 the client list size
 * @param p3 the accepttime list data (pointer reference)
 * @param p4 the accepttime list count
 * @param p5 the accepttime list size
 */
void shutdown_socket_server_all(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown socket server all.");

    //
    // CAUTION! The loop is running in REVERSE ORDER,
    // from the last to the first element, since that way,
    // the function "remove" works much faster inside.
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise loop variable.
    copy_integer((void*) &j, p1);
    // Subtract one, since this is an index.
    calculate_integer_subtract((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (p1 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    //?? fwprintf(stdout, L"Test: Shutdown socket server all. The loop is running in reverse order! Loop count p1: %i\n", p1);
    //?? fwprintf(stdout, L"Test: Shutdown socket server all. The loop is running in reverse order! Loop count p1: %i\n", *((int*) p1));

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &b, (void*) &j, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        shutdown_socket_server_element(p0, p1, p2, p3, p4, p5, (void*) &j);

        // Decrement loop variable.
        j--;
    }
}

/* ALL_SERVER_SOCKET_SHUTTER_SOURCE */
#endif
