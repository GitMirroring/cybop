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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Gets a knowledge name.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the stack memory item
 * @param p5 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts on heap
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties on heap
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for variables on stack
 *           - *NULL_POINTER_STATE_CYBOI_MODEL if none of the above applies
 * @param p6 the knowledge path end flag
 */
void deserialise_knowledge_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge name.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The name data, count.
    //
    // CAUTION! This variable IS necessary, since the knowledge path data
    // position parametre is a pointer reference that cannot be handed over
    // to some of the functions below, which expect a simple pointer.
    // Also, the count has to be incremented below.
    //
    void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise name data.
    copy_pointer((void*) &nd, p2);

    if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    //?? fwprintf(stdout, L"Debug: Deserialise knowledge name. nd: %ls\n", (wchar_t*) nd);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"Debug: Deserialise knowledge name. nc: %i\n", nc);

        compare_integer_less_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The knowledge path END has been reached
            // OR a special DELIMITER was found.
            //

            if (nc > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                //
                // CAUTION! Only call function below if a name EXISTS.
                //
                // Calling the function with an empty name anyway, would NOT
                // cause errors and just be ignored inside, returning null values.
                // However, this comparison here is done to improve PERFORMANCE.
                //

                //
                // Get part with the given name
                // from the memory identified by p5.
                //
                select_knowledge_identification(p0, p1, nd, (void*) &nc, p4, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            }

            break;

        } else {

            // Search for a delimiter.
            select_knowledge_move(p2, p3, p5, p6, (void*) &nc, (void*) &b);
        }
    }
}
