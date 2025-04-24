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

#include "applicator.h"
#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Compares the type of destination- and source node.
 *
 * If a wrong knowledge path is given, e.g. with non-existing node-names,
 * then a cybol operation might write data into a wrong destination,
 * e.g. source data of format "text/plain" (type wide character)
 * into a destination of format "element/part" (type pointer).
 *
 * Therefore, the types have to be IDENTICAL.
 *
 * @param p0 the destination part
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the move flag (NOT deep copying flag)
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 * @param p7 the adjust count flag
 * @param p8 the repetition number for "modify/repeat"
 * @param p9 the searchterm data for "modify/replace"
 * @param p10 the searchterm count for "modify/replace"
 * @param p11 the index pointing to the current element
 * @param p12 the function part
 * @param p13 the internal memory data
 * @param p14 the knowledge memory part (pointer reference)
 * @param p15 the stack memory item
 * @param p16 the signal memory item
 * @param p17 the internal memory data (pointer reference)
 * @param p18 the shutdown flag
 * @param p19 the operation type
 * @param p20 the destination part item index
 * @param p21 the source part item index
 * @param p22 the source part
 * @param p23 the source type
 */
void apply_modify_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply modify type.");
    //?? fwprintf(stdout, L"Debug: Apply modify type. Destination type: %i. Source type: %i.\n", *((int*) p2), *((int*) p23));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p2, p23);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The destination- and source type are identical.
        //

        apply_modify_deep(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22);

    } else {

        //
        // CAUTION! Comment out this error message since it may be normal behaviour
        // that one part does not exist. When applying an identical algorithm to
        // different data structures, then some child nodes may not exist.
        // However, in this case it is WANTED behaviour in order to reuse the
        // algorithm for different tree structures. Therefore, IGNORE this error.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply modify type. The destination type and source type are different.");
        // fwprintf(stdout, L"Error: Could not apply modify type. The destination type and source type are different.\n");
        // fwprintf(stdout, L"Error: Destination type: %i. Source type: %i.\n", *((int*) p2), *((int*) p23));
        //
    }
}
