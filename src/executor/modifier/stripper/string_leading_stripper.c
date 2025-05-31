/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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
 * Searches for a non-whitespace character from the BEGINNING of the given array.
 *
 * @param p0 the destination wide character item
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 */
void strip_leading_string(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip leading string.");
    //?? fwprintf(stdout, L"Debug: Strip leading string. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Strip leading string. count remaining *p2: %i\n", *((int*) p2));

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p1);
    // Copy source count remaining.
    copy_integer((void*) &c, p2);

    //
    // CAUTION! Checking the source count remaining for null is NOT necessary here.
    // The local variable c gets initialised with the source count remaining above.
    // But if that is null, then NOTHING gets copied since the copy function
    // does (correctly) not consider null values, so that c just remains ZERO.
    //
    // Therefore, the loop can be left in its first cycle when realising
    // that c is zero.
    //

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, (void*) &c, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Do NOT copy anything to the destination if the
            // source is EMPTY or NO non-whitespace character could be found.
            //

            break;
        }

        // Search for a non-whitespace character within the given array.
        select_whitespace_non((void*) &b, (void*) &d, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A non-whitespace character has been found.
            //

            //
            // Append string to destination item.
            //
            // CAUTION! The source count remaining got already adapted
            // within the function "select_whitespace" above and can be
            // used as COUNT parametre AS IS.
            //
            modify_item(p0, d, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &c, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            break;
        }
    }
}
