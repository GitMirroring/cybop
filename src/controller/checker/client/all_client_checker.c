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

#ifndef ALL_CLIENT_CHECKER_SOURCE
#define ALL_CLIENT_CHECKER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../controller/checker/client/element_client_checker.c"
#include "../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks already open clients for new available data.
 *
 * @param p0 the destination client
 * @param p1 the client list data (pointer reference)
 * @param p2 the client list count
 * @param p3 the client list size
 * @param p4 the accepttime list data (pointer reference)
 * @param p5 the accepttime list count
 * @param p6 the accepttime list size
 * @param p7 the input/output entry
 * @param p8 the channel
 */
void check_client_all(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check client all.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The client.
    int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The client removed flag.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

    //?? fwprintf(stdout, L"Debug: Check client all. count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Check client all. count *p2: %i\n", *((int*) p2));

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        //
        // Test for data available on client.
        //
        // CAUTION! This function only PEEKS into data,
        // but does NOT remove them, so that they can be read again later.
        //
        check_client_element((void*) &c, p1, p2, p3, p4, p5, p6, (void*) &j, p7, p8, (void*) &r);

        //
        // CAUTION! This second comparison IS NECESSARY for two reasons:
        //
        // 1 Correct client number
        //
        // If data are available on one of the clients,
        // then that client number has to be preserved
        // in order to be returned correctly.
        //
        // 2 Efficiency
        //
        // Once data are available on one of the clients, the other
        // clients in the list do NOT have to be checked anymore.
        //
        compare_integer_greater((void*) &b, (void*) &c, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Copy client.
            copy_integer(p0, (void*) &c);

            break;
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // There was NO client socket removed.
            // This is standard behaviour.
            //

            // Increment loop variable.
            j++;

        } else {

            //
            // An inactive client socket was REMOVED inside,
            // due to a crossed timeout.
            //
            // CAUTION! All following elements got MOVED one
            // position towards the beginning of the list.
            // The loop variable MUST NOT be incremented here!
            // It is now already pointing to the NEXT element.
            //
            // CAUTION! Also, the LIST COUNT value should be LEFT AS IT IS.
            // The corresponding parametre is a pointer to the correct value,
            // which has got changed already in the remove function inside.
            //

            // Reset client removed flag.
            r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        }
    }
}

/* ALL_CLIENT_CHECKER_SOURCE */
#endif
