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
#include "constant.h"
#include "controller.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Handles the part signal.
 *
 * @param p0 the signal model data (operation)
 * @param p1 the signal model count
 * @param p2 the internal memory data
 * @param p3 the knowledge memory part (pointer reference)
 * @param p4 the stack memory item
 * @param p5 the signal memory item
 * @param p6 the internal memory data (pointer reference)
 * @param p7 the direct execution flag
 * @param p8 the shutdown flag
 * @param p9 the cybol loop break property
 */
void handle_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle part.");
    //?? fwprintf(stdout, L"Debug: Handle part. signal model count p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Handle part. signal model count *p1: %i\n", *((int*) p1));

    //
    // Declaration
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Execution
    //

    if (p1 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

    //
    // CAUTION! If the signal is to be executed INDIRECTLY,
    // i.e. by adding it to the signal memory,
    // where it later gets checked and handled,
    // then do NOT store any properties in stack memory!
    //
    // There is no guarantee as to when the signal gets
    // actually processed from the signal memory (queue).
    // External interrupts such as from a socket communication
    // or mouse events might occur and be processed first.
    // In this case, the order of stack memory entries
    // would get MIXED UP.
    // Therefore, the stack memory may ONLY be used with
    // DIRECT handling of signals as done in the "if" branch above.
    //

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Check if model count has been reached.
        compare_integer_greater_or_equal((void*) &b, (void*) &j, p1);

        //
        // Check if cybol loop break property was set.
        //
        // CAUTION! Normally, the WHOLE loop model with ALL its operations would be executed
        // before realising in file "applicator/flow/loop.c" that the break flag is set.
        // This corresponds to a test-last-loop. It is therefore necessary to check
        // the break condition once BEFORE calling the loop in cybol source code.
        //
        // <node name="compare_index" channel="inline" format="compare/greater-or-equal" model="">
        //     <node name="result" channel="inline" format="text/cybol-path" model="#break"/>
        //     <node name="left" channel="inline" format="text/cybol-path" model="#index"/>
        //     <node name="right" channel="inline" format="text/cybol-path" model="#count"/>
        // </node>
        //
        // There are two reasons to check the break flag after EACH operation:
        //
        // 1 Avoid additional check of break condition before calling "flow/loop" in cybol
        // 2 Being able to leave the loop at each step in cybol
        //
        // Therefore, the break flag gets handed over to the handler and
        // forwarded to this file "part_handler.c" where it gets checked.
        //
        // CAUTION! If this model is NOT executed within a loop, then the
        // cybol loop break property is NULL and just gets IGNORED inside
        // the comparison function, so that the break flag does NOT get set.
        //
        compare_integer_unequal((void*) &b, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Handle model part.
        handle_element(p0, (void*) &j, p2, p3, p4, p5, p6, p7, p8);

        // Increment loop variable.
        j++;
    }
}
