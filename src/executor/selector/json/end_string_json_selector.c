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

#ifndef END_STRING_JSON_SELECTOR_SOURCE
#define END_STRING_JSON_SELECTOR_SOURCE

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
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the json string end.
 *
 * @param p0 the source data position (pointer reference)
 * @param p1 the source count remaining
 * @param p2 the string count
 * @param p3 the break flag
 */
void select_json_string_end(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select json string end.");
    //?? fwprintf(stdout, L"Debug: Select json string end. count remaining p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Select json string end. count remaining *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) QUOTATION_MARK_BACKSLASH_ESCAPE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) QUOTATION_MARK_BACKSLASH_ESCAPE_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Ignore this backslash escape sequence '\"'.
            //
            // CAUTION! It is important to check for this escape sequence BEFORE
            // detecting a standard quotation mark as end-of-string marker below
            // since otherwise, the backslash quotation mark character might
            // misleadingly be interpreted as end-of-string.
            //
            // CAUTION! But since the json specification permits usage of
            // backslash escape characters, these have to be handled,
            // which is done in another function of the json deserialiser.
            //
            // CAUTION! The data position and count remaining
            // got adapted by the function "detect" already.
            //

            //
            // Adjust string count.
            //
            // CAUTION! Do NOT add NUMBER_1_INTEGER_STATE_CYBOI_MODEL
            // but QUOTATION_MARK_BACKSLASH_ESCAPE_MODEL_COUNT instead,
            // since the sequence consists of more than just one character.
            //
            calculate_integer_add(p2, (void*) QUOTATION_MARK_BACKSLASH_ESCAPE_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) BEGIN_END_STRING_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_END_STRING_JSON_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The step.
        int step = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        // Move the current position.
        move(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &step, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Adjust string count.
        calculate_integer_add(p2, (void*) &step);
    }
}

/* END_STRING_JSON_SELECTOR_SOURCE */
#endif
