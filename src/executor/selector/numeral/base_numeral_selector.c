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

#ifndef BASE_NUMERAL_SELECTOR_SOURCE
#define BASE_NUMERAL_SELECTOR_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the numeral base by prefix.
 *
 * @param p0 the number base
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void select_numeral_base(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select numeral base.");
    //?? fwprintf(stdout, L"Debug: Select numeral base. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select numeral base. count remaining *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Select numeral base. data position *p1: %i\n", *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Select numeral base. data position *p1 ls: %ls\n", (wchar_t*) *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Select numeral base. data position *p1 lc: %lc\n", *((wchar_t*) *((void**) p1)));
    //?? fwprintf(stdout, L"Debug: Select numeral base. data position *p1 lc as int: %i\n", *((wchar_t*) *((void**) p1)));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The ORDER of the following comparisons is IMPORTANT!
    //
    // The HEXADECIMAL integer with prefix "0x" has to get
    // detected BEFORE the octal integer with prefix just "0".
    //
    // Recognised number prefixes are:
    //
    // binary: 0B and 0b (capital "B" and small "b")
    // hexadecimal: 0X and 0x (capital "X" and small "x")
    // octal: 0O and 0o (capital "O" and small "o") as well as the CLASSIC prefix just 0 (zero)
    //
    // The prefix "zero and lower- or uppercase letter o" for
    // octal numbers is NOT used in the c programming language,
    // but suggested as new format in python since version 3.x.
    //

    //
    // binary
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) SMALL_BINARY_BASE_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALL_BINARY_BASE_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign binary number base.
            copy_integer(p0, (void*) BINARY_BASE_NUMERAL_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) CAPITAL_BINARY_BASE_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CAPITAL_BINARY_BASE_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign binary number base.
            copy_integer(p0, (void*) BINARY_BASE_NUMERAL_MODEL);
        }
    }

    //
    // hexadecimal
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) SMALL_HEXADECIMAL_BASE_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALL_HEXADECIMAL_BASE_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign hexadecimal number base.
            copy_integer(p0, (void*) HEXADECIMAL_BASE_NUMERAL_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) CAPITAL_HEXADECIMAL_BASE_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CAPITAL_HEXADECIMAL_BASE_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign hexadecimal number base.
            copy_integer(p0, (void*) HEXADECIMAL_BASE_NUMERAL_MODEL);
        }
    }

    //
    // octal
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) SMALL_OCTAL_BASE_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALL_OCTAL_BASE_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign octal number base.
            copy_integer(p0, (void*) OCTAL_BASE_NUMERAL_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) CAPITAL_OCTAL_BASE_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CAPITAL_OCTAL_BASE_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign octal number base.
            copy_integer(p0, (void*) OCTAL_BASE_NUMERAL_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p1, p2, (void*) OCTAL_BASE_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) OCTAL_BASE_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign octal number base.
            copy_integer(p0, (void*) OCTAL_BASE_NUMERAL_MODEL);
        }
    }
}

/* BASE_NUMERAL_SELECTOR_SOURCE */
#endif
