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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WHITESPACE_SELECTOR_SOURCE
#define WHITESPACE_SELECTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Detects and skips any whitespace characters.
 *
 * CAUTION! This function filters out the same kind of
 * whitespace characters as mentioned in the JSON specification.
 *
 * The json standard defines five kinds of white space:
 * - empty: ""
 * - space: 0020
 * - line feed: 000A
 * - carriage return: 000D
 * - character tabulation: 0009
 *
 * Reference:
 * https://www.json.org/
 *
 * The first (empty) can obviously NOT be considered.
 * Therefore, just FOUR comparisons are done below.
 * All of these kinds of whitespace characters are skipped.
 *
 * @param p0 the destination loop break flag
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void select_whitespace(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select whitespace.");
    fwprintf(stdout, L"Debug: Select whitespace. count remaining p8: %i\n", p8);
    fwprintf(stdout, L"Debug: Select whitespace. count remaining *p8: %i\n", *((int*) p8));
    fwprintf(stdout, L"Debug: Select whitespace. data position *p7: %i\n", *((void**) p7));
    fwprintf(stdout, L"Debug: Select whitespace. data position *p7 ls: %ls\n", (wchar_t*) *((void**) p7));
    fwprintf(stdout, L"Debug: Select whitespace. data position *p7 lc: %lc\n", *((wchar_t*) *((void**) p7)));
    fwprintf(stdout, L"Debug: Select whitespace. data position *p7 lc as int: %i\n", *((wchar_t*) *((void**) p7)));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

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

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A whitespace character was NOT detected.
        //

        // Set loop break flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* WHITESPACE_SELECTOR_SOURCE */
#endif
