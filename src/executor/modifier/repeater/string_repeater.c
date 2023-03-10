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

#ifndef STRING_REPEATER_SOURCE
#define STRING_REPEATER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Repeats the source data string count times.
 *
 * @param p0 the destination wide character item
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 * @param p3 the repeat count
 */
void repeat_string(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Repeat.");
    fwprintf(stdout, L"Debug: Repeat string. source count p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Repeat string. source count *p2: %i\n", *((int*) p2));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The source index.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

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

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p3);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Append source wide character at index to destination item.
        modify_item(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Increment source index.
        j++;
    }
}

/* STRING_REPEATER_SOURCE */
#endif
