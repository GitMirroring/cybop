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
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Detects the given array.
 *
 * This code was moved into its own function, because:
 * - the current position pointer needs to be dereferenced
 * - the element count and remaining count need to be compared
 *   in order to avoid crossing array boundaries
 * - the current position and remaining count are moved automatically
 *
 * Example calls of this function for ascii characters:
 * detect(p0, p1, p2, p3, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, p7);
 *
 * Example calls of this function for wide characters:
 * detect((void*) &r, p7, p8, (void*) QUERY_PARAMETRE_BEGIN_SEPARATOR_URI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) QUERY_PARAMETRE_BEGIN_SEPARATOR_URI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
 *
 * @param p0 the comparison result
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the data
 * @param p4 the type
 * @param p5 the count
 * @param p6 the move flag
 */
void detect(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detect.");
    //?? fwprintf(stdout, L"Debug: Detect. count p5: %i\n", p5);
    //?? fwprintf(stdout, L"Debug: Detect. count *p5: %i\n", *((int*) p5));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! This comparison ensures that array boundaries are not crossed.
    // The count p5 is used for both, the array AND source data.
    //
    compare_integer_greater_or_equal((void*) &r, p2, p5);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_comparison(p0, p1, p2, p3, p4, p5, p6);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not detect. The remaining count is smaller than the array count.");
    }
}
