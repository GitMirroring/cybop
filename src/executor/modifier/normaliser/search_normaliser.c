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

#include "algorithm.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "text.h"

/**
 * Searches for a whitespace character.
 *
 * @param p0 the destination wide character item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void normalise_search(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise search.");
    //?? fwprintf(stdout, L"Debug: Normalise search. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Normalise search. count remaining *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Normalise search. data position *p1: %i\n", *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Normalise search. data position *p1 ls: %ls\n", (wchar_t*) *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Normalise search. data position *p1 lc: %lc\n", *((wchar_t*) *((void**) p1)));
    //?? fwprintf(stdout, L"Debug: Normalise search. data position *p1 lc as int: %i\n", *((wchar_t*) *((void**) p1)));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Detect whitespace character.
    select_whitespace((void*) &r, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A WHITESPACE character HAS been found
        //

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise search. Found whitespace character.");
        //?? fwprintf(stdout, L"Debug: Normalise search. Found whitespace character. count remaining p2: %i\n", p2);
        //?? fwprintf(stdout, L"Debug: Normalise search. Found whitespace character. count remaining *p2: %i\n", *((int*) p2));

        // Parse whitespace characters.
        normalise_whitespace(p0, p1, p2);

    } else {

        //
        // This is a NON-whitespace character
        //

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise search. Found non-whitespace character.");
        //?? fwprintf(stdout, L"Debug: Normalise search. Found non-whitespace character. count remaining p2: %i\n", p2);
        //?? fwprintf(stdout, L"Debug: Normalise search. Found non-whitespace character. count remaining *p2: %i\n", *((int*) p2));
        //?? fwprintf(stdout, L"Debug: Normalise search. Found non-whitespace character. data position *p1: %i\n", *((void**) p1));
        //?? fwprintf(stdout, L"Debug: Normalise search. Found non-whitespace character. data position *p1 ls: %ls\n", (wchar_t*) *((void**) p1));
        //?? fwprintf(stdout, L"Debug: Normalise search. Found non-whitespace character. data position *p1 lc: %lc\n", *((wchar_t*) *((void**) p1)));

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The source data.
            void** d = (void**) p1;

            // Append character AS IS to destination item.
            modify_item(p0, *d, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            // Increment the current position by one.
            move(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not normalise search. The source data position is null.");
            fwprintf(stdout, L"Error: Could not normalise search. The source data position is null. p1: %i\n", p1);
        }
    }
}
