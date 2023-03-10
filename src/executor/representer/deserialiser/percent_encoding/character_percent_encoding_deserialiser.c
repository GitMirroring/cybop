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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CHARACTER_PERCENT_ENCODING_DESERIALISER_SOURCE
#define CHARACTER_PERCENT_ENCODING_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/mover/mover.c"
#include "../../../../executor/representer/deserialiser/numeral/integer_numeral_deserialiser.c"
#include "../../../../executor/representer/serialiser/ascii/ascii_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the percent-encoded character.
 *
 * @param p0 the destination character item
 * @param p1 the source character data position (pointer reference)
 * @param p2 the source character count remaining
 */
void deserialise_percent_encoding_character(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise percent encoding character.");
    //?? fwprintf(stdout, L"Debug: Deserialise percent encoding character. source character count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise percent encoding character. source character count remaining *p2: %i\n", *((int*) p2));

    // The percent encoding character data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise percent encoding character data.
    copy_pointer((void*) &cd, p1);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Test if characters are left.
        compare_integer_less_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        //
        // Test percent encoding character count.
        //
        // CAUTION! Following the specification, it consists of TWO DIGITS at most.
        //
        // CAUTION! The variable b may be used as return value once more,
        // since it is left untouched if the test above is false.
        //
        compare_integer_greater_or_equal((void*) &b, (void*) &cc, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // The step.
            int step = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

            //
            // Move the current position.
            //
            // CAUTION! The data are available as multibyte (NOT wide) character sequence.
            //
            move(p1, p2, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &step, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Adjust percent encoding character count.
            calculate_integer_add((void*) &cc, (void*) &step);
        }
    }

    //
    // Test for correct character count.
    //
    // CAUTION! It may be unequal two if for instance just one character was found
    // and no more characters were left in the source character data.
    //
    if (cc == *NUMBER_2_INTEGER_STATE_CYBOI_MODEL) {

        // The wide character item.
        void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The wide character item data, count.
        void* wd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* wc = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The deserialised integer.
        int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The character.
        unsigned char c = *NULL_ASCII_CHARACTER_CODE_MODEL;

        //
        // Allocate wide character item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &w, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Serialise percent encoding ascii character data into wide character data.
        serialise_ascii(w, cd, (void*) &cc);

        //
        // Get wide character item data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &wd, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &wc, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        //
        // Deserialise wide character data into integer value.
        //
        // CAUTION! Hand over NUMBER BASE 16 as parametre!
        // Following the specification, a percent-encoded character
        // consists of two digits representing a HEXADECIMAL number.
        //
        deserialise_numeral_integer((void*) &i, wd, wc, (void*) HEXADECIMAL_BASE_NUMERAL_MODEL);

        //
        // Cast integer to character.
        //
        // CAUTION! The type "int" has a size of 4 Byte,
        // whilst the type "char" has only a size of 1 Byte.
        // This means, that information loss is possible.
        //
        // However, the integer number deserialised above
        // should lie in the ASCII range, as defined by
        // the percent encoding specification.
        //
        cast_character_integer((void*) &c, (void*) &i);

        // Append character to destination.
        modify_item(p0, (void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Deallocate wide character item.
        deallocate_item((void*) &w, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise percent encoding character. The character count (number of digits) is unequal two.");
        fwprintf(stdout, L"Error: Could not deserialise percent encoding character. The character count (number of digits) is unequal two. source character count remaining p2: %i\n", p2);
        fwprintf(stdout, L"Error: Could not deserialise percent encoding character. The character count (number of digits) is unequal two. source character count remaining *p2: %i\n", *((int*) p2));
    }
}

/* CHARACTER_PERCENT_ENCODING_DESERIALISER_SOURCE */
#endif
