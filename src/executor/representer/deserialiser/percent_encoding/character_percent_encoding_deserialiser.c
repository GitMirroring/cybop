/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHARACTER_PERCENT_ENCODING_DESERIALISER_SOURCE
#define CHARACTER_PERCENT_ENCODING_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/basic/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/cybol/integer/char_primitive_value_integer_cybol_deserialiser.c"
#include "../../../../executor/searcher/mover/position_mover.c"
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

    // The percent encoding character data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise percent encoding character data.
    copy_pointer((void*) &cd, p1);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Test if characters are left.
        compare_integer_smaller_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        // Test percent encoding character count.
        // CAUTION! Following the specification, it consists of TWO DIGITS at most.
        // CAUTION! The variable b may be used as return value once more,
        // since it is left untouched if the test above is false.
        compare_integer_greater_or_equal((void*) &b, (void*) &cc, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // CAUTION! The data are available as multibyte (NOT wide) character sequence.
            move_position(p1, p2, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            // Increment percent encoding character count.
            cc++;
        }
    }

    // Test for correct character count.
    // CAUTION! It may be unequal two if for instance just one character was found
    // and no more characters were left in the source character data.
    if (cc == *NUMBER_2_INTEGER_STATE_CYBOI_MODEL) {

        // The deserialised integer.
        int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Deserialise percent encoding character data into integer number.
        //
        // CAUTION! Hand over NUMBER BASE 16 as parametre!
        // Following the specification, a percent-encoded character
        // consists of two digits representing a HEXADECIMAL number.
        deserialise_cybol_integer_value_primitive_char((void*) &i, cd, (void*) &cc, (void*) NUMBER_16_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        // Cast integer to character.
        //
        // CAUTION! The type "int" has a size of 4 Byte,
        // whilst the type "char" has only a size of 1 Byte.
        // This means, that information loss is possible.
        // However, the integer number deserialised above
        // should lie in the ASCII range, as defined by
        // the percent encoding specification.
        //
        unsigned char c = (unsigned char) i;

        // Append character to destination.
        modify_item(p0, (void*) &c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise percent encoding character. The character count (number of digits) is unequal two.");
    }
}

/* CHARACTER_PERCENT_ENCODING_DESERIALISER_SOURCE */
#endif
