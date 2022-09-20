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

#ifndef DECIMALS_NUMERAL_SELECTOR_SOURCE
#define DECIMALS_NUMERAL_SELECTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Selects the numeral decimal places (decimals).
 *
 * @param p0 the source data position (pointer reference)
 * @param p1 the source count remaining
 * @param p2 the decimal power flag
 * @param p3 the second part flag
 * @param p4 the decimals count
 * @param p5 the loop break flag
 */
void select_numeral_decimals(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select numeral decimals.");
    fwprintf(stdout, L"Debug: Select numeral decimals. count remaining p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Select numeral decimals. count remaining *p1: %i\n", *((int*) p1));
    fwprintf(stdout, L"Debug: Select numeral decimals. data position *p0: %i\n", *((void**) p0));
    fwprintf(stdout, L"Debug: Select numeral decimals. data position *p0 ls: %ls\n", (wchar_t*) *((void**) p0));
    fwprintf(stdout, L"Debug: Select numeral decimals. data position *p0 lc: %lc\n", *((wchar_t*) *((void**) p0)));
    fwprintf(stdout, L"Debug: Select numeral decimals. data position *p0 lc as int: %i\n", *((wchar_t*) *((void**) p0)));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The ORDER of the following comparisons is IMPORTANT!
    //
    // Example:
    //
    // The MULTIPLICATION abbreviation begin exponent "*exp(" has to get
    // detected BEFORE the same sequence without multiplication sign "exp(".
    //

    //
    // power
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) SMALL_POWER_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALL_POWER_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set decimal power flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) CAPITAL_POWER_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CAPITAL_POWER_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set decimal power flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // sign (indicating the imaginary part of a complex number)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) MINUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MINUS_SIGN_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set second part flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) PLUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PLUS_SIGN_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set second part flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // exponent (indicating the argument of a complex number in polar notation)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) MULTIPLICATION_ABBREVIATION_BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MULTIPLICATION_ABBREVIATION_BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set second part flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) MULTIPLICATION_LETTER_BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MULTIPLICATION_LETTER_BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set second part flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) ABBREVIATION_BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ABBREVIATION_BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set second part flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) LETTER_BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LETTER_BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set second part flag.
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // other
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Increment the current position by one.
        move(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Adjust decimals count.
        calculate_integer_add(p4, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* DECIMALS_NUMERAL_SELECTOR_SOURCE */
#endif
