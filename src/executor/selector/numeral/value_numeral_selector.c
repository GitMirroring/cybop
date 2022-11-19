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

#ifndef VALUE_NUMERAL_SELECTOR_SOURCE
#define VALUE_NUMERAL_SELECTOR_SOURCE

#include "../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/name/numeral/decimal_numeral_name.c"
#include "../../../constant/name/numeral/exponent_numeral_name.c"
#include "../../../constant/name/numeral/fraction_numeral_name.c"
#include "../../../constant/name/numeral/power_numeral_name.c"
#include "../../../constant/name/numeral/sign_numeral_name.c"
#include "../../../constant/name/numeral/thousands_numeral_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "../../../executor/mover/mover.c"
#include "../../../executor/selector/digit/digit_selector.c"
#include "../../../logger/logger.c"

/**
 * Selects the numeral value end.
 *
 * @param p0 the source data position (pointer reference)
 * @param p1 the source count remaining
 * @param p2 the decimal separator data
 * @param p3 the decimal separator count
 * @param p4 the thousands separator data
 * @param p5 the thousands separator count
 * @param p6 the post point value flag
 * @param p7 the number base power flag
 * @param p8 the detected format
 * @param p9 the detected type
 * @param p10 the count
 * @param p11 the loop break flag
 */
void select_numeral_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select numeral value.");
    //?? fwprintf(stdout, L"Debug: Select numeral value. source count remaining p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Select numeral value. source count remaining *p1: %i\n", *((int*) p1));
    //?? fwprintf(stdout, L"Debug: Select numeral value. source data position *p0: %i\n", *((void**) p0));
    //?? fwprintf(stdout, L"Debug: Select numeral value. source data position *p0 ls: %ls\n", (wchar_t*) *((void**) p0));
    //?? fwprintf(stdout, L"Debug: Select numeral value. source data position *p0 lc: %lc\n", *((wchar_t*) *((void**) p0)));
    //?? fwprintf(stdout, L"Debug: Select numeral value. source data position *p0 lc as int: %i\n", *((wchar_t*) *((void**) p0)));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The decimal separator data, count.
    void* dd = SEPARATOR_DECIMAL_NUMERAL_NAME;
    int dc = *SEPARATOR_DECIMAL_NUMERAL_NAME_COUNT;
    // The thousands separator data, count.
    void* td = SEPARATOR_THOUSANDS_NUMERAL_NAME;
    int tc = *SEPARATOR_THOUSANDS_NUMERAL_NAME_COUNT;

/*??
    fwprintf(stdout, L"Debug: Select numeral value. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Select numeral value. *p3: %i\n", *((int*) p3));
    fwprintf(stdout, L"Debug: Select numeral value. p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Select numeral value. p2 as string: %ls\n", (wchar_t*) p2);

    fwprintf(stdout, L"Debug: Select numeral value. dc: %i\n", dc);
    fwprintf(stdout, L"Debug: Select numeral value. dd: %i\n", dd);
    fwprintf(stdout, L"Debug: Select numeral value. dd as string: %ls\n", (wchar_t*) dd);
*/

    // Assign decimal separator data, count.
    copy_pointer((void*) &dd, (void*) &p2);
    copy_integer((void*) &dc, p3);
    // Assign thousands separator data, count.
    copy_pointer((void*) &td, (void*) &p4);
    copy_integer((void*) &tc, p5);

    //
    // CAUTION! The ORDER of the following comparisons is IMPORTANT!
    //
    // Example:
    //
    // The MULTIPLICATION abbreviation begin exponent "*exp(" has to get
    // detected BEFORE the same sequence without multiplication sign "exp(".
    //

    //
    // digit
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        select_digit((void*) &r, p0, p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p10);
    }

    //
    // decimals
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // .
        detect((void*) &r, p0, p1, dd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &dc, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE);

            // Set post point value flag.
            copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // power
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // e
        detect((void*) &r, p0, p1, (void*) SMALL_POWER_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SMALL_POWER_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE);

            // Set number base power flag.
            copy_integer(p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // E
        detect((void*) &r, p0, p1, (void*) CAPITAL_POWER_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CAPITAL_POWER_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE);

            // Set number base power flag.
            copy_integer(p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // fraction
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // /
        detect((void*) &r, p0, p1, (void*) SLASH_FRACTION_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SLASH_FRACTION_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // sign (indicating the imaginary part of a complex number)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // -
        //
        // CAUTION! Do NOT move the position here since the algebraic sign
        // needs to be detected once AGAIN, for the number to be complete.
        // Therefore, hand over FALSE as last parametre.
        //
        detect((void*) &r, p0, p1, (void*) MINUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MINUS_SIGN_NUMERAL_NAME_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // +
        //
        // CAUTION! Do NOT move the position here since the algebraic sign
        // needs to be detected once AGAIN, for the number to be complete.
        // Therefore, hand over FALSE as last parametre.
        //
        detect((void*) &r, p0, p1, (void*) PLUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PLUS_SIGN_NUMERAL_NAME_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // exponent (indicating the argument of a complex number in polar notation)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // *exp(
        detect((void*) &r, p0, p1, (void*) MULTIPLICATION_ABBREVIATION_BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MULTIPLICATION_ABBREVIATION_BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // *E(
        detect((void*) &r, p0, p1, (void*) MULTIPLICATION_LETTER_BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MULTIPLICATION_LETTER_BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // exp(
        detect((void*) &r, p0, p1, (void*) ABBREVIATION_BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ABBREVIATION_BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // E(
        detect((void*) &r, p0, p1, (void*) LETTER_BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LETTER_BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p8, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p9, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // end of exponent (indicating the argument of a complex number in polar notation)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // )
        detect((void*) &r, p0, p1, (void*) END_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set loop break flag.
            copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // other
    //

    //
    // CAUTION! This check for other characters (for example whitespace)
    // IS necessary since some data formats like json have NO delimiter for numbers,
    // so that sometimes, especially for the LAST number in an object or array,
    // a following line break or space indicates the END of that number.
    //
    // Example:
    //
    //     "person": {
    //         "children": 4,
    //         "age": 50
    //     }
    //
    // If this check was not done here, the number would be too long.
    // In the example above, instead of just 50 it would be 5000000
    // (one line break under linux and four spaces indentation).
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Set loop break flag.
        copy_integer(p11, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* VALUE_NUMERAL_SELECTOR_SOURCE */
#endif
