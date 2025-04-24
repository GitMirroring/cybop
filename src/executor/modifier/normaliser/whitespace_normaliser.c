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
#include "text.h"

/**
 * Parses through the whitespace characters of the given source array.
 *
 * If a non-whitespace character is found, then the parsing stops
 * and only ONE space character is written into the destination,
 * no matter how many whitespaces had been found in the source before.
 *
 * @param p0 the destination wide character item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void normalise_whitespace(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise whitespace.");
    //?? fwprintf(stdout, L"Debug: Normalise whitespace. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Normalise whitespace. count remaining *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Normalise whitespace. data position *p1: %i\n", *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Normalise whitespace. data position *p1 ls: %ls\n", (wchar_t*) *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Normalise whitespace. data position *p1 lc: %lc\n", *((wchar_t*) *((void**) p1)));
    //?? fwprintf(stdout, L"Debug: Normalise whitespace. data position *p1 lc as int: %i\n", *((wchar_t*) *((void**) p1)));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

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

        compare_integer_less_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Either a NON-whitespace character delimiting this
            // sequence of whitespace characters has been found
            // OR the source count remaining is ZERO.
            // In BOTH cases, a space character is to be added.
            //
            // This function "normalise_whitespace" was entered only
            // because a space character was detected BEFORE, so that
            // at least one space character is present in the source
            // and in BOTH cases mentioned above, also if the
            // source count remaining is zero, a space is to be added.
            //

            // Append ONE space character to destination.
            modify_item(p0, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            break;
        }

        // Search for non-whitespace character.
        select_whitespace_non((void*) &b, p1, p2);
    }
}
