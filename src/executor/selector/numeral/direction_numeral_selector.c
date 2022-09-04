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

#ifndef DIRECTION_NUMERAL_SELECTOR_SOURCE
#define DIRECTION_NUMERAL_SELECTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Selects the growth direction of the decimal power (power of 10),
 * depending on the given sign (plus or minus).
 *
 * @param p0 the minus sign flag
 * @param p1 the destination format
 * @param p2 the destination type
 * @param p3 the destination integer value one
 * @param p4 the destination integer value two
 * @param p5 the destination double value one
 * @param p6 the destination double value two
 * @param p7 the source data position (pointer reference)
 * @param p8 the source count remaining
 */
void select_numeral_direction(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select numeral direction.");
    fwprintf(stdout, L"Debug: Select numeral direction. count remaining p8: %i\n", p8);
    fwprintf(stdout, L"Debug: Select numeral direction. count remaining *p8: %i\n", *((int*) p8));
    fwprintf(stdout, L"Debug: Select numeral direction. data position *p7: %i\n", *((void**) p7));
    fwprintf(stdout, L"Debug: Select numeral direction. data position *p7 ls: %ls\n", (wchar_t*) *((void**) p7));
    fwprintf(stdout, L"Debug: Select numeral direction. data position *p7 lc: %lc\n", *((wchar_t*) *((void**) p7)));
    fwprintf(stdout, L"Debug: Select numeral direction. data position *p7 lc as int: %i\n", *((wchar_t*) *((void**) p7)));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p7, p8, (void*) MINUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MINUS_SIGN_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Deserialise decimal power (power of 10).
            //
            // CAUTION! Hand over minus sign flag as parametre.
            // Set value to TRUE, which means MINUS.
            //
            deserialise_numeral_power(p1, p2, p3, p4, p5, p6, p7, p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p7, p8, (void*) PLUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PLUS_SIGN_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Deserialise decimal power (power of 10).
            //
            // CAUTION! Hand over minus sign flag as parametre.
            // Set value to FALSE, which means PLUS.
            //
            deserialise_numeral_power(p1, p2, p3, p4, p5, p6, p7, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A sign was NOT detected.
        //

        //
        // Deserialise decimal power (power of 10).
        //
        // CAUTION! Hand over minus sign flag as parametre.
        // Set value to FALSE, which means PLUS.
        // This is the DEFAULT value.
        //
        deserialise_numeral_power(p1, p2, p3, p4, p5, p6, p7, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* DIRECTION_NUMERAL_SELECTOR_SOURCE */
#endif
