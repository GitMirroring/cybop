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

#ifndef BASE_NUMBER_SELECTOR_SOURCE
#define BASE_NUMBER_SELECTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Selects the number base by prefix.
 *
 * @param p0 the destination format
 * @param p1 the destination type
 * @param p2 the destination integer value one
 * @param p3 the destination integer value two
 * @param p4 the destination double value one
 * @param p5 the destination double value two
 * @param p6 the source data position (pointer reference)
 * @param p7 the source count remaining
 * @param p8 the loop break flag
 */
void select_number_base(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select number base.");
    fwprintf(stdout, L"Debug: Select number base. count remaining p7: %i\n", p7);
    fwprintf(stdout, L"Debug: Select number base. count remaining *p7: %i\n", *((int*) p7));
    fwprintf(stdout, L"Debug: Select number base. data position *p6: %i\n", *((void**) p6));
    fwprintf(stdout, L"Debug: Select number base. data position *p6 ls: %ls\n", (wchar_t*) *((void**) p6));
    fwprintf(stdout, L"Debug: Select number base. data position *p6 lc: %lc\n", *((wchar_t*) *((void**) p6)));
    fwprintf(stdout, L"Debug: Select number base. data position *p6 lc as int: %i\n", *((wchar_t*) *((void**) p6)));

    //
    // CAUTION! Do NOT easily change the ORDER of below comparisons since
    // otherwise, some sequences may not get detected or lead to errors.
    // A hexadecimal integer with prefix "0x", for instance,
    // would falsely get detected as octal integer with prefix "0".
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The number base with decimal number base as default.
    int b = *DECIMAL_BASE_NUMBER_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p6, p7, (void*) SMALL_HEXADECIMAL_PREFIX_NUMBER_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALL_HEXADECIMAL_PREFIX_NUMBER_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set hexadecimal number base.
            copy_integer((void*) &b, (void*) HEXADECIMAL_BASE_NUMBER_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p6, p7, (void*) CAPITAL_HEXADECIMAL_PREFIX_NUMBER_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CAPITAL_HEXADECIMAL_PREFIX_NUMBER_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set hexadecimal number base.
            copy_integer((void*) &b, (void*) HEXADECIMAL_BASE_NUMBER_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p6, p7, (void*) OCTAL_PREFIX_NUMBER_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) OCTAL_PREFIX_NUMBER_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set octal number base.
            copy_integer((void*) &b, (void*) OCTAL_BASE_NUMBER_MODEL);
        }
    }

    //
    // Deserialise number value.
    //
    // CAUTION! Hand over the number base as parametre.
    //
    deserialise_number_value(p0, p1, p2, p6, p7, (void*) &b);
}

/* BASE_NUMBER_SELECTOR_SOURCE */
#endif
