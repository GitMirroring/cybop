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
 * Selects the object member or primitive string depending on the given flag.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the decimal separator data
 * @param p5 the decimal separator count
 * @param p6 the thousands separator data
 * @param p7 the thousands separator count
 * @param p8 the member name data
 * @param p9 the member name count
 * @param p10 the break flag
 * @param p11 the object flag (true if this is an object; false for array or otherwise the default)
 */
void select_json_string_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select json string type.");
    //?? fwprintf(stdout, L"Debug: Select json string type. count remaining p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Select json string type. count remaining *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p11, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a SIMPLE string representing either of:
        // - simple array element
        // - object member value
        //

        deserialise_json_string(p0, p1, p2, p3, p8, p9);

        // Set break flag.
        copy_integer(p10, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        //
        // This is an object member PAIR containing:
        // - object member name
        // - object member value
        //

        deserialise_json_member(p0, p1, p2, p3, p4, p5, p6, p7);
    }
}
