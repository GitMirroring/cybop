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

#ifndef PUSHER_SOURCE
#define PUSHER_SOURCE

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
#include "knowledge.h"
#include "logger.h"

/**
 * Pushes (adds) parts onto stack memory.
 *
 * @param p0 the stack memory item
 * @param p1 the parts data
 * @param p2 the parts count
 * @param p3 the knowledge memory part (pointer reference)
 * @param p4 the internal memory data
 */
void push(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Push.");
    //?? fwprintf(stdout, L"Debug: Push. p2: %i\n", p2);
    //
    // CAUTION! The parts count may be null, since runtime arguments exist only
    // for compound logic operations called via "text/cybol-path" but NOT for
    // those being defined and called directly using the format "element/part".
    //
    // Therefore, comment out this test log message.
    //
    //?? fwprintf(stdout, L"Debug: Push. *p2: %i\n", *((int*) p2));
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! The parts count may be null, since runtime arguments exist only
    // for compound logic operations called via "text/cybol-path" but NOT for
    // those being defined and called directly using the format "element/part".
    //
    // However, this is NOT a problem, since a null value is just IGNORED here.
    //
    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Push (add) part onto stack memory.
        push_part(p0, p1, (void*) &j, p3, p4);

        // Increment loop variable.
        j++;
    }
}

/* PUSHER_SOURCE */
#endif
