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

#ifndef LIFO_LINEAR_SEARCHER_SOURCE
#define LIFO_LINEAR_SEARCHER_SOURCE

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
 * using the last-in-first-out (lifo) principle (stack) with BACKWARD search.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the list data
 * @param p2 the list count
 * @param p3 the list type
 * @param p4 the list model flag (false = name, true = model)
 * @param p5 the searchword data
 * @param p6 the searchword count
 * @param p7 the searchword type
 */
void search_linear_lifo(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear lifo.");
    fwprintf(stdout, L"Debug: Search linear lifo. p0: %i\n", p0);

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The loop variable.
    //
    // CAUTION! Do NOT delete this variable since it is needed as result index.
    //
    // CAUTION! The value of -1 is IMPORTANT since it causes the loop
    // to break by default, if the given element count is null or zero.
    //
    int j = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The list data position.
    void* pos = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The list count remaining.
    int rem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The initial offset.
    int o = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise list data position.
    copy_pointer((void*) &pos, (void*) &p1);
    // Initialise list count remaining.
    copy_integer((void*) &rem, p2);
    //
    // Initialise offset.
    //
    // CAUTION! Do NOT try to optimise by reducing loop cycles or break the
    // loop earlier here, since this would work only with primitive data.
    // For parts, however, EACH part's name or model has to be searched inside.
    //
    // Therefore, just move by the LIST COUNT and do NOT subtract
    // the searchword count from the offset here.
    //
    // CAUTION! Subtract ONE since this is used for an index.
    //
    copy_integer((void*) &o, p2);
    calculate_integer_subtract((void*) &o, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    // Move current position forward to the END of the list.
    move((void*) &pos, (void*) &rem, p3, (void*) &o, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Check loop criterion.
        //
        // CAUTION! Use the "greater" and NOT the "greater_or_equal" function here,
        // since the case of equal counts still has to be considered below.
        //
        compare_integer_greater((void*) &b, (void*) &rem, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            //
            // Compare list entry with given searched element.
            //
            // CAUTION! Set step to DECREMENT (-1).
            //
            // CAUTION! Set BACKWARD flag to TRUE.
            //
            search_linear_type(p0, (void*) &pos, (void*) &rem, p3, p4, p5, p6, p7, (void*) &j, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &b);
        }
    }
}

/* LIFO_LINEAR_SEARCHER_SOURCE */
#endif
