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

#ifndef BASE_SERVER_IDENTIFICATION_CALCULATOR_SOURCE
#define BASE_SERVER_IDENTIFICATION_CALCULATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Calculates the server identification as sum of base and port.
 *
 * @param p0 the resulting server identification
 * @param p1 the server base
 * @param p2 the service port
 */
void calculate_server_identification_base(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate server identification base.");
    fwprintf(stdout, L"Debug: Calculate server identification base. p0: %i\n", p0);

    // The server identification.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Calculate server identification.
    //
    // Summands:
    // - server base
    // - service port
    //
    // CAUTION! If the service port is NULL, then it is NOT copied here.
    // This is tested inside the "calculate_integer_add" function.
    // In this case, the server base added before remains AS IS,
    // which is the same as a service port of ZERO.
    //
    // In other words, the service port is ZERO BY DEFAULT.
    // Only for the socket channel, it gets replaced by the PORT number.
    //
    calculate_integer_add((void*) &i, p1);
    calculate_integer_add((void*) &i, p2);

    //
    // CAUTION! Use greater-or-EQUAL operator >=,
    // since the first service has the port zero.
    //
    compare_integer_greater_or_equal((void*) &r, (void*) &i, p1);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Copy server identification to result.
        copy_integer(p0, (void*) &i);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate server identification base. The server identification is invalid.");
        fwprintf(stdout, L"Error: Could not calculate server identification base. The server identification is invalid. i: %i\n", i);
    }
}

/* BASE_SERVER_IDENTIFICATION_CALCULATOR_SOURCE */
#endif
