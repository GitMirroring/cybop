/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the xdt field hierarchy.
 *
 * @param p0 the field hierarchy
 * @param p1 the field identification
 */
void deserialise_xdt_field_hierarchy(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field hierarchy.");

    //
    // CAUTION! The following comparisons rely on the bdt standard main version < 3.
    //
    // Since bdt 3.0 and higher provide a "hierarchy dependency" field element,
    // there is NO NEED to find out the hierarchy level via comparisons like HERE.
    // This is not only a more flexible, but also more efficient solution.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) KBV_TEST_NUMBER_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) RESPONSIBLE_ENTITY_FIELD_XDT_NAME);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    //?? TEST ONLY. DELETE LATER!
    copy_integer(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //?? Copy hierarchy level for ALL possible xdt fields here ...
}
