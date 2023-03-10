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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LEADING_STRIPPER_SOURCE
#define LEADING_STRIPPER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/modifier/stripper/item_leading_stripper.c"
#include "../../../logger/logger.c"

/**
 * Removes leading whitespaces from the string.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data
 * @param p4 the source count
 * @param p5 the type
 */
void strip_leading(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip leading.");
    //?? fwprintf(stdout, L"Information: Strip leading. type p5: %i\n", p5);
    //?? fwprintf(stdout, L"Information: Strip leading. type *p5: %i\n", *((int*) p5));
    //?? fwprintf(stdout, L"Information: Strip leading. source count p4: %i\n", p4);
    //?? fwprintf(stdout, L"Information: Strip leading. source count *p4: %i\n", *((int*) p4));
    //?? fwprintf(stdout, L"Information: Strip leading. source data p3: %ls\n", (wchar_t*) p3);

    //
    // CAUTION! The destination is NOT an item, but an array,
    // since this function is called from file "array_modifier.c".
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        strip_leading_item(p0, p1, p2, p3, p4);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not strip leading. The source type is not wide character.");
        fwprintf(stdout, L"Warning: Could not strip leading. The source type is not wide character. type p5: %i\n", p5);
        fwprintf(stdout, L"Warning: Could not strip leading. The source type is not wide character. type *p5: %i\n", *((int*) p5));
    }
}

/* LEADING_STRIPPER_SOURCE */
#endif
