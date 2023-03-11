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

#ifndef ROTATE_RIGHT_CHARACTER_MANIPULATOR_SOURCE
#define ROTATE_RIGHT_CHARACTER_MANIPULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/calculator/integer/multiply_integer_calculator.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/manipulator/character/check_character_manipulator.c"
#include "../../../executor/manipulator/character/clear_character_manipulator.c"
#include "../../../executor/manipulator/character/set_character_manipulator.c"
#include "../../../executor/manipulator/character/shift_right_character_manipulator.c"
#include "logger.h"
#include "../../../mapper/type_to_size_mapper.c"

/**
 * Rotates all bits of value to the right by position.
 *
 * Those digits which are moved out on the right
 * are "wrapped around" and moved in again on the left.
 *
 * http://en.wikipedia.org/wiki/Bitwise_operation
 *
 * @param p0 the value
 * @param p1 the position
 */
void manipulate_character_rotate_right(void* p0, void* p1) {

    //
    // CAUTION! Use "unsigned char" with range 0..+255
    // and NOT just "char" with range -128..+127 here.
    //

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate character rotate right.");

    // The index of the left-most bit.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The right-most bit as stored value.
    unsigned char b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get type size.
    map_type_to_size((void*) &i, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Calculate type size in bit units.
    // CAUTION! A byte is assumed to have 8 bit.
    calculate_integer_multiply((void*) &i, (void*) NUMBER_8_INTEGER_STATE_CYBOI_MODEL);
    // Calculate index of the left-most bit.
    // CAUTION! Indices are counted from zero.
    calculate_integer_subtract((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Get right-most bit.
    // CAUTION! The type "unsigned char"
    // has a size of 1 Byte == 8 Bit.
    // The positions are counted from 0..7.
    manipulate_character_check((void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    // Shift right.
    manipulate_character_shift_right(p0, p1);

    // Set left-most bit to stored value.
    if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        manipulate_character_clear(p0, (void*) &i);

    } else {

        manipulate_character_set(p0, (void*) &i);
    }
}

/* ROTATE_RIGHT_CHARACTER_MANIPULATOR_SOURCE */
#endif
