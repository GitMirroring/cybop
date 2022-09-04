/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CHARACTER_STRIPPER_SOURCE
#define CHARACTER_STRIPPER_SOURCE

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "../../../logger/logger.c"

/**
 * Searches for a non-whitespace character within the given array.
 *
 * @param p0 the loop break flag
 * @param p1 the data position (pointer reference)
 * @param p2 the count remaining
 */
void strip_character(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip character.");
/*??
    fwprintf(stdout, L"Debug: Strip character. count remaining p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Strip character. count remaining *p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"Debug: Strip character. data position *p1: %i\n", *((void**) p1));
    fwprintf(stdout, L"Debug: Strip character. data position *p1 ls: %ls\n", (wchar_t*) *((void**) p1));
    fwprintf(stdout, L"Debug: Strip character. data position *p1 lc: %lc\n", *((wchar_t*) *((void**) p1)));
    fwprintf(stdout, L"Debug: Strip character. data position *p1 lc as int: %i\n", *((wchar_t*) *((void**) p1)));
*/

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // whitespace
    //

    //
    // The following kinds of white space are considered:
    // - space: 0020
    // - line feed: 000A
    // - carriage return: 000D
    // - character tabulation: 0009
    //
    // All kinds of whitespace characters are skipped.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // CAUTION! If the searched character sequence was found,
        // then the function "detect" already MOVED the data position
        // pointer and decremented the count remaining accordingly,
        // at least if the last argument move flag is TRUE.
        //
        // Therefore, do NOT call function "move" here additionally
        // since otherwise, some characters would be skipped and
        // could not be processed later, which is not wanted.
        //
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) LINE_FEED_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // CAUTION! If the searched character sequence was found,
        // then the function "detect" already MOVED the data position
        // pointer and decremented the count remaining accordingly,
        // at least if the last argument move flag is TRUE.
        //
        // Therefore, do NOT call function "move" here additionally
        // since otherwise, some characters would be skipped and
        // could not be processed later, which is not wanted.
        //
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) CARRIAGE_RETURN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // CAUTION! If the searched character sequence was found,
        // then the function "detect" already MOVED the data position
        // pointer and decremented the count remaining accordingly,
        // at least if the last argument move flag is TRUE.
        //
        // Therefore, do NOT call function "move" here additionally
        // since otherwise, some characters would be skipped and
        // could not be processed later, which is not wanted.
        //
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) CHARACTER_TABULATION_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // CAUTION! If the searched character sequence was found,
        // then the function "detect" already MOVED the data position
        // pointer and decremented the count remaining accordingly,
        // at least if the last argument move flag is TRUE.
        //
        // Therefore, do NOT call function "move" here additionally
        // since otherwise, some characters would be skipped and
        // could not be processed later, which is not wanted.
        //
    }

    //
    // non-whitespace character
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip character. Found non-whitespace character.");
/*??
        fwprintf(stdout, L"Debug: Strip character. Found non-whitespace character. count remaining p2: %i\n", p2);
        fwprintf(stdout, L"Debug: Strip character. Found non-whitespace character. count remaining *p2: %i\n", *((int*) p2));
        fwprintf(stdout, L"Debug: Strip character. Found non-whitespace character. data position *p1: %i\n", *((void**) p1));
        fwprintf(stdout, L"Debug: Strip character. Found non-whitespace character. data position *p1 ls: %ls\n", (wchar_t*) *((void**) p1));
        fwprintf(stdout, L"Debug: Strip character. Found non-whitespace character. data position *p1 lc: %lc\n", *((wchar_t*) *((void**) p1)));
*/

        // Set value end flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* CHARACTER_STRIPPER_SOURCE */
#endif
