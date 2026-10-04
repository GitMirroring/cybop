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
 * Writes a destination string whose value is the concatenation
 * of the source string repeated count times.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data
 * @param p4 the source count
 * @param p5 the repetition number
 * @param p6 the type
 */
void repeat(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Repeat.");
    fwprintf(stdout, L"Information: Repeat. source count p2: %i\n", p2);
    fwprintf(stdout, L"Information: Repeat. source count *p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"Information: Repeat. source data p1: %ls\n", (wchar_t*) p1);

    //
    // CAUTION! The destination is NOT an item, but an array,
    // since this function is called from file "array_modifier.c".
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        repeat_item(p0, p1, p2, p3, p4, p5);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not repeat. The source type is not wide character.");
        fwprintf(stdout, L"Warning: Could not repeat. The source type is not wide character. type p5: %i\n", p5);
        fwprintf(stdout, L"Warning: Could not repeat. The source type is not wide character. type *p5: %i\n", *((int*) p5));
    }
}
