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
 * @version CYBOP 0.27.0 2023-08-31
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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "type.h"

/**
 * Serialises the integer value into a wide character sequence.
 *
 * @param p0 the destination wide character item
 * @param p1 the source integer value
 * @param p2 the sign flag
 * @param p3 the number base
 * @param p4 the prefix flag (some conversions like html numeric references do not want a "0x" prefix and prepend "&#x" themselves instead)
 * @param p5 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 */
void serialise_numeral_integer(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral integer.");
    //?? fwprintf(stdout, L"Debug: Serialise numeral integer. source number p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Serialise numeral integer. source number *p1: %i\n", *((int*) p1));

    //
    // Declaration
    //

    //
    // The temporary number wide character item.
    //
    // CAUTION! It is necessary since the single digits get inserted at the
    // beginning. If they were added to the destination wide character item
    // directly, they would stand in front and mix up the order of text output.
    //
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary number wide character item data, count.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ic = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The temporary number.
    //
    // CAUTION! It is necessary in order to avoid manipulation of
    // the original number, for example when calculating the
    // absolute value below.
    //
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The negative number comparison result.
    int neg = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The sign flag comparison result.
    int s = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The number base.
    int nb = *DECIMAL_BASE_NUMERAL_MODEL;
    // The prefix flag comparison result.
    int p = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The zero flag comparison result.
    int z = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The digit as wide character.
    wchar_t wc = *NULL_UNICODE_CHARACTER_CODE_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The remainder.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Initialisation
    //

    // Initialise temporary number.
    copy_integer((void*) &n, p1);

    compare_integer_less((void*) &neg, (void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (neg != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append minus sign to destination item.
        modify_item(p0, (void*) MINUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) MINUS_SIGN_NUMERAL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        compare_integer_unequal((void*) &s, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (s != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The sign flag IS set.
            //

            // Append plus sign to destination item.
            modify_item(p0, (void*) PLUS_SIGN_NUMERAL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PLUS_SIGN_NUMERAL_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    // Eliminate sign from negative temporary number, since the sign was already added above.
    calculate_integer_absolute((void*) &n, (void*) &n);

    // Initialise number base.
    copy_integer((void*) &nb, p3);

    compare_integer_unequal((void*) &p, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (p != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append suitable prefix depending on the given number base.
        serialise_numeral_prefix(p0, (void*) &nb, p5);
    }

    //
    // Assembling
    //

    //
    // Allocate temporary number wide character item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Compare temporary number for ZERO value.
    //
    // CAUTION! This special block for zero IS necessary since due to
    // the break condition, the loop below would NEVER enter a cycle
    // if the number were zero.
    //
    compare_integer_equal((void*) &z, (void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (z != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The value is ZERO
        //

        // Map integer value to a unicode digit wide character.
        map_integer_to_digit_wide_character((void*) &wc, (void*) &n);
        // Insert remainder as digit wide character at the BEGINNING.
        modify_item(i, (void*) &wc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        //
        // Append pre-point value.
        //
        // Beispielzahl: 124
        // Basis: 10
        //
        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_less_or_equal((void*) &b, (void*) &n, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                break;

            } else {

                // Initialise remainder.
                copy_integer((void*) &r, (void*) &n);
                // Calculate remainder.
                calculate_integer_modulo((void*) &r, (void*) &nb);

                // Map integer value to a unicode digit wide character.
                map_integer_to_digit_wide_character((void*) &wc, (void*) &r);
                // Insert remainder as digit wide character at the BEGINNING.
                modify_item(i, (void*) &wc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

                // Divide number by base.
                calculate_integer_divide((void*) &n, (void*) &nb);
            }
        }
    }

    //
    // Assignment
    //

    // Get temporary number wide character item data, count.
    copy_array_forward((void*) &id, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ic, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Append temporary number wide character item data to destination wide character item.
    modify_item(p0, id, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, ic, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Deallocate temporary number wide character item.
    deallocate_item((void*) &i, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
