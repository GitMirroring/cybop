/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EQUAL_WIDE_CHARACTER_CHECKER_SOURCE
#define EQUAL_WIDE_CHARACTER_CHECKER_SOURCE

#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"

/**
 * Checks the left- with the right wide character for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left array
 * @param p2 the right array
 * @param p3 the index
 */
void check_wide_character_equal(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check wide character equal.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p3);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // All elements have been compared successfully.
            // The comparison of all element pairs delivered "true".
            //
            // CAUTION! The arrays are expected to be EQUAL, even if
            // the count is zero. This is important, because the PROPERTIES
            // (meta properties) of many otherwise equal models are empty.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            break;
        }

        compare_value_offset((void*) &r, p1, p2, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &j);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        j++;
    }
}

/* EQUAL_WIDE_CHARACTER_CHECKER_SOURCE */
#endif
