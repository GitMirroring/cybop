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

#ifndef MANIPULATOR_CHARACTER_TESTER
#define MANIPULATOR_CHARACTER_TESTER

#include <assert.h>

#include "../../../src/constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../src/executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../src/executor/manipulator/character/check_character_manipulator.c"
#include "../../../src/executor/manipulator/character/rotate_left_character_manipulator.c"
#include "../../../src/executor/manipulator/character/rotate_right_character_manipulator.c"
#include "../../../src/executor/manipulator/character/shift_left_character_manipulator.c"
#include "../../../src/executor/manipulator/character/shift_right_character_manipulator.c"
#include "../../../src/executor/memoriser/allocator/array_allocator.c"
#include "../../../src/executor/memoriser/deallocator/array_deallocator.c"
#include "../../../src/executor/modifier/copier/array_copier.c"
#include "../../../src/executor/modifier/emptier/array_emptier.c"
#include "../../../src/executor/modifier/overwriter/part_overwriter.c"

void manipulate_character_shift_left_by_one() {

    unsigned char v = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    char expected = 4;

    manipulate_character_shift_left((void*) &v, s);

    assert(expected == (char) v);
}

void manipulate_character_shift_right_by_1() {

    unsigned char v = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    char expected = 0;

    manipulate_character_shift_right((void*) &v, s);

    assert(expected == (char) v);
}

void manipulate_character_rotate_right_by_2() {

    char v = *NUMBER_25_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
    char expected = 6;

    manipulate_character_rotate_right((void*) &v, s);

    assert(expected == (char) v);
}

void manipulate_character_rotate_left_by_2() {

    unsigned char v = *NUMBER_25_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
    char expected = 100;

    manipulate_character_rotate_left((void*) &v, s);

    assert(expected == (char) v);
}

void manipulate_character_check_of_ones() {

    unsigned char v = *NUMBER_15_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_3_INTEGER_STATE_CYBOI_MODEL;
    char expected = 1;

    manipulate_character_check((void*) &v, s);

    assert(expected == (char) v);
}

int main() {

    manipulate_character_shift_left_by_one();
    manipulate_character_shift_right_by_1();
    manipulate_character_rotate_right_by_2();
    manipulate_character_rotate_left_by_2();
    manipulate_character_check_of_ones();

    return 0;
}

/* MANIPULATOR_CHARACTER_TESTER */
#endif
