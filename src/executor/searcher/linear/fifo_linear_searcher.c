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
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Finds the index of the given searched element (sequence) within the list
 * using the first-in-first-out (fifo) principle (queue), with FORWARD search.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the list data
 * @param p2 the list count
 * @param p3 the list type
 * @param p4 the list model flag (false = name, true = model)
 * @param p5 the searchword data
 * @param p6 the searchword count
 * @param p7 the searchword type
 * @param p8 the perfect match flag (requesting equal count)
 */
void search_linear_fifo(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear fifo.");
    //?? fwprintf(stdout, L"Debug: Search linear fifo. list count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Search linear fifo. list count *p2: %i\n", *((int*) p2));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The loop variable.
    //
    // CAUTION! Do NOT delete this variable since it is needed as result index.
    //
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The list data position.
    void* pos = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The list count remaining.
    int rem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise list data position.
    copy_pointer((void*) &pos, (void*) &p1);
    // Initialise list count remaining.
    copy_integer((void*) &rem, p2);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Check loop criterion.
        //
        // CAUTION! Do NOT try to optimise by reducing loop cycles or break the
        // loop earlier here, since this would work only with primitive data.
        // For parts, however, EACH part's name or model has to be searched inside.
        //
        // Therefore, compare with ZERO and NOT with the list count or
        // searchword count here.
        //
        compare_integer_less_or_equal((void*) &b, (void*) &rem, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            //
            // Compare list entry with given searched element.
            //
            // CAUTION! Set step to INCREMENT (+1).
            //
            // CAUTION! Set BACKWARD flag to FALSE.
            //
            search_linear_type(p0, (void*) &pos, (void*) &rem, p3, p4, p5, p6, p7, p8, (void*) &b, (void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }
}
