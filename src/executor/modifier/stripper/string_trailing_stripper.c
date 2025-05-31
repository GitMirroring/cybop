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

#include "algorithm.h"
#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Searches for a non-whitespace character from the END of the given array.
 *
 * @param p0 the destination wide character item
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 */
void strip_trailing_string(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip trailing string.");
    //?? fwprintf(stdout, L"Debug: Strip trailing string. source count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Strip trailing string. source count *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Strip trailing string. source data p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Strip trailing string. source data p1 ls: %ls\n", (wchar_t*) p1);
    //?? fwprintf(stdout, L"Debug: Strip trailing string. source data *p1 lc: %lc\n", *((wchar_t*) p1));
    //?? fwprintf(stdout, L"Debug: Strip trailing string. source data *p1 lc as int: %i\n", *((wchar_t*) p1));

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The move positions number for initialisation.
    int m = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The number of characters to be copied.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p1);
    // Copy source count remaining.
    copy_integer((void*) &c, p2);

    // Initialise move positions number with source count remaining.
    copy_integer((void*) &m, p2);
    //
    // Subtract ONE since otherwise, the source data position
    // would point to the element AFTER the last.
    //
    calculate_integer_subtract((void*) &m, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Move source data position to LAST element.
    move((void*) &d, (void*) &c, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &m, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

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

        //
        // CAUTION! Do NOT compare for greater_or_equal,
        // since the "equal" case still has to be processed.
        //
        compare_integer_greater((void*) &b, (void*) &c, p2);

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
            // A non-whitespace character HAS been found.
            //

            //
            // Calculate number of characters to be copied.
            //

            // Add original source count.
            calculate_integer_add((void*) &n, p2);
            // Subtract source count remaining (number of whitespaces).
            calculate_integer_subtract((void*) &n, (void*) &c);
            //
            // Add one, since the number of whitespaces subtracted above is
            // one too large and contains the found non-whitespace character.
            //
            calculate_integer_add((void*) &n, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

            //?? fwprintf(stdout, L"Debug: Strip trailing string. number of characters to be copied n: %i\n", n);

            // Append string to destination item.
            modify_item(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &n, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            break;

        } else {

            //
            // A non-whitespace character has NOT been found.
            //
            // (In other words: A whitespace character has been found.)
            //

            //
            // Decrement the current position by TWO and increment
            // the remaining count at the same time.
            //
            // CAUTION! It is moved by two for the following reasons:
            // - one position move was caused by file "character_stripper.c",
            //   so that this step has to be undone
            // - a second step back is necessary, so that a new character
            //   (and not the same from before) can be compared with
            //
            // CAUTION! Let loop run backwards using function "move"
            // with BACKWARD flag (last argument) set to TRUE.
            //
            // CAUTION! Stepping backward here relies on a character size of ONE.
            // If some day character SEQUENCES are to be detected,
            // possibly even with varying length, then moving back by TWO
            // as done here might be WRONG. In this case, the backward moving
            // should better be done in file "character_stripper.c", since
            // each if-comparison there knows how long the sequence is,
            // so that the current position may be move back correctly.
            //
            move((void*) &d, (void*) &c, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }
}
