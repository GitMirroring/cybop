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

#ifndef ROTATE_LEFT_INTEGER_MANIPULATOR_SOURCE
#define ROTATE_LEFT_INTEGER_MANIPULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/manipulator/integer/check_integer_manipulator.c"
#include "../../../executor/manipulator/integer/clear_integer_manipulator.c"
#include "../../../executor/manipulator/integer/set_integer_manipulator.c"
#include "../../../executor/manipulator/integer/shift_left_integer_manipulator.c"
#include "logger.h"
#include "../../../mapper/type_to_size_mapper.c"

/**
 * Rotates all bits of value to the left by position.
 *
 * Those digits which are moved out on the left
 * are "wrapped around" and moved in again on the right.
 *
 * http://en.wikipedia.org/wiki/Bitwise_operation
 *
 * @param p0 the value
 * @param p1 the position
 */
void manipulate_integer_rotate_left(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate integer rotate left.");

    // The index of the left-most bit.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The left-most bit as stored value.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get type size.
    map_type_to_size((void*) &i, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    // Calculate type size in bit units.
    // CAUTION! A byte is assumed to have 8 bit.
    calculate_integer_multiply((void*) &i, (void*) NUMBER_8_INTEGER_STATE_CYBOI_MODEL);
    // Calculate index of the left-most bit.
    // CAUTION! Indices are counted from zero.
    calculate_integer_subtract((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Get left-most bit.
    manipulate_integer_check((void*) &b, (void*) &i);
    // Shift left.
    manipulate_integer_shift_left(p0, p1);

    // Set right-most bit to stored value.
    if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        manipulate_integer_clear(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    } else {

        manipulate_integer_set(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* ROTATE_LEFT_INTEGER_MANIPULATOR_SOURCE */
#endif
