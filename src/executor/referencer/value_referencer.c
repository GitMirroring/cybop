/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VALUE_REFERENCER_SOURCE
#define VALUE_REFERENCER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/memoriser/offset_adder.c"
#include "../../../executor/modifier/copier/character_copier.c"
#include "../../../executor/modifier/copier/double_copier.c"
#include "../../../executor/modifier/copier/fraction_copier.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/modifier/copier/part_copier.c"
#include "../../../executor/modifier/copier/pointer_copier.c"
#include "../../../executor/modifier/copier/unsigned_long_copier.c"
#include "../../../executor/modifier/copier/wide_character_copier.c"
#include "../../../logger/logger.c"

/**
 * Decrements the value.
 *
 * @param p0 the value
 * @param p1 the type
 */
void decrement_value(void* p0, void* p1) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Reference value.");

    // The comparison result.
    // CAUTION! It is used instead of if-else statements.
    // May be one day, this is useful when using assembler or implementing cyboi as hardware chip.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

/*
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) CHARACTER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decrement_character(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DOUBLE_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decrement_double(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) FRACTION_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decrement_fraction(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) INTEGER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decrement_integer(p0, p1);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) PART_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decrement_part(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) POINTER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decrement_pointer(p0, p1);
        }
    }

/*
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) UNSIGNED_LONG_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decrement_unsigned_long(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decrement_wide_character(p0, p1);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy value. The operand type is unknown.");
    }
}

/**
 * Decrements the source- to the destination value
 * using the given index to calculate an offset.
 *
 * @param p0 the value
 * @param p1 the operation type
 * @param p2 the operand type
 * @param p3 the index
 */
void reference_value_offset(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Reference value offset.");

    // The value.
    // CAUTION! It HAS TO BE initialised with p0,
    // since an offset is added below.
    void* v = p0;

    add_offset((void*) &v, p2, p3);

    reference_value(v, p1, p2);
}

/* VALUE_REFERENCER_SOURCE */
#endif
