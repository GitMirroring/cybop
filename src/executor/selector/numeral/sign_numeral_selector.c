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
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the algebraic sign of the numeral.
 *
 * @param p0 the algebraic sign factor
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void select_numeral_sign(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select numeral sign.");
    //?? fwprintf(stdout, L"Debug: Select numeral sign. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select numeral sign. count remaining *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Select numeral sign. data position *p1: %i\n", *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Select numeral sign. data position *p1 ls: %ls\n", (wchar_t*) *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Select numeral sign. data position *p1 lc: %lc\n", *((wchar_t*) *((void**) p1)));
    //?? fwprintf(stdout, L"Debug: Select numeral sign. data position *p1 lc as int: %i\n", *((wchar_t*) *((void**) p1)));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) MINUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MINUS_SIGN_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign NEGATIVE algebraic sign factor.
            copy_integer(p0, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) PLUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PLUS_SIGN_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! This detection IS important even if plus is the default,
            // because a possibly existing plus sign has to get processed
            // so that the parser may continue with the FOLLOWING digit.
            //

            // Assign POSITIVE algebraic sign factor.
            copy_integer(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }
}
