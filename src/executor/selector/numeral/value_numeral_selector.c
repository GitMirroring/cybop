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
#include "type.h"

/**
 * Selects the numeral value end.
 *
 * @param p0 the source data position (pointer reference)
 * @param p1 the source count remaining
 * @param p2 the decimal separator data
 * @param p3 the decimal separator count
 * @param p4 the thousands separator data
 * @param p5 the thousands separator count
 * @param p6 the number base
 * @param p7 the post point value flag
 * @param p8 the decimal power flag
 * @param p9 the detected format
 * @param p10 the detected type
 * @param p11 the count
 * @param p12 the loop break flag
 */
void select_numeral_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select numeral value.");
    //?? fwprintf(stdout, L"Debug: Select numeral value. source count remaining p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Select numeral value. source count remaining *p1: %i\n", *((int*) p1));
    //?? fwprintf(stdout, L"Debug: Select numeral value. source data position *p0 ls: %ls\n", (wchar_t*) *((void**) p0));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The hexadecimal number base comparison result.
    int h = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The decimal separator data, count.
    void* dd = SEPARATOR_DECIMAL_NUMERAL_NAME;
    int dc = *SEPARATOR_DECIMAL_NUMERAL_NAME_COUNT;
    // The thousands separator data, count.
    void* td = SEPARATOR_THOUSANDS_NUMERAL_NAME;
    int tc = *SEPARATOR_THOUSANDS_NUMERAL_NAME_COUNT;

/*??
    fwprintf(stdout, L"Debug: Select numeral value. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Select numeral value. p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Select numeral value. p2 as string: %ls\n", (wchar_t*) p2);

    fwprintf(stdout, L"Debug: Select numeral value. pre dc: %i\n", dc);
    fwprintf(stdout, L"Debug: Select numeral value. pre dd: %i\n", dd);
    fwprintf(stdout, L"Debug: Select numeral value. pre dd as string: %ls\n", (wchar_t*) dd);
*/

    //
    // CAUTION! The following checks for null ARE necessary BEFORE copying the pointer,
    // in order to ensure that the initial destination value remains untouched
    // in case the parametres are null.
    //
    // The count integer value gets copied ONLY if the source value is NOT NULL,
    // which is checked inside the function "copy_integer".
    // However, for copying the data pointer, this would NOT work, since its value
    // has to be handed over as pointer REFERENCE, but can then never be null,
    // which makes the check for null inside function "copy_pointer" useless.
    // Therefore, the data pointer gets checked here as well.
    //

    if ((p2 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p3 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Assign decimal separator data, count.
        copy_pointer((void*) &dd, (void*) &p2);
        copy_integer((void*) &dc, p3);
    }

    if ((p4 != *NULL_POINTER_STATE_CYBOI_MODEL) && (p5 != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Assign thousands separator data, count.
        copy_pointer((void*) &td, (void*) &p4);
        copy_integer((void*) &tc, p5);
    }

/*??
    fwprintf(stdout, L"Debug: Select numeral value. post dc: %i\n", dc);
    fwprintf(stdout, L"Debug: Select numeral value. post dd: %i\n", dd);
    fwprintf(stdout, L"Debug: Select numeral value. post dd as string: %ls\n", (wchar_t*) dd);
*/

    //
    // digit
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        select_digit_decimal((void*) &r, p0, p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p11);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! This check is IMPORTANT since otherwise, the
        // letter "e" or "E" might get interpreted as hexadecimal
        // DIGIT while it could actually mean SCIENTIFIC NOTATION.
        //
        // Per definition, scientific notation ALWAYS uses a DECIMAL number base,
        // so that a conflict with the hexadecimal digit "e" is impossible.
        //
        compare_integer_equal((void*) &h, p6, (void*) HEXADECIMAL_BASE_NUMERAL_MODEL);

        if (h != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This number has a hexadecimal base.
            //

            select_digit_hexadecimal((void*) &r, p0, p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p11);
        }
    }

    //
    // decimals
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // .
        detect((void*) &r, p0, p1, dd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &dc, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p9, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p10, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE);

            // Set post point value flag.
            copy_integer(p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
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
            copy_integer(p9, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p10, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE);

            // Set number base power flag.
            copy_integer(p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // E
        detect((void*) &r, p0, p1, (void*) CAPITAL_POWER_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CAPITAL_POWER_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p9, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p10, (void*) FLOAT_NUMBER_STATE_CYBOI_TYPE);

            // Set number base power flag.
            copy_integer(p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set loop break flag.
            copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
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
            copy_integer(p9, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p10, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
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
            copy_integer(p9, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p10, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
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
            copy_integer(p9, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p10, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // exponent (indicating the argument of a complex number in polar notation)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // *exp(
        detect((void*) &r, p0, p1, (void*) BEGIN_EXPONENT_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_EXPONENT_NUMERAL_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Assign format and type.
            copy_integer(p9, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);
            copy_integer(p10, (void*) COMPLEX_NUMBER_STATE_CYBOI_TYPE);

            // Set loop break flag.
            copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
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
            copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
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
        copy_integer(p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}
