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

#ifndef BASE_NUMERAL_SELECTOR_SOURCE
#define BASE_NUMERAL_SELECTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/numeral/base_numeral_model.c"
#include "../../../constant/name/numeral/base_numeral_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "../../../logger/logger.c"

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
