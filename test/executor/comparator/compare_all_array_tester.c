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

#ifndef COMPARE_ALL_ARRAY_TESTER
#define COMPARE_ALL_ARRAY_TESTER

#include <assert.h>
#include "../../../src/constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../src/constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../src/constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../src/executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../src/executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../src/executor/memoriser/allocator/array_allocator.c"
#include "../../../src/executor/memoriser/deallocator/array_deallocator.c"
#include "../../../src/executor/comparator/all/array_all_comparator.c"
#include "../../../src/executor/comparator/basic/array_comparator.c"
#include "../../../src/executor/comparator/basic/part_comparator.c"
#include "../../../src/executor/comparator/all/part_all_comparator.c"
#include "../../../src/executor/copier/array_copier.c"
#include "../../../src/executor/modifier/array_modifier.c"
#include "../../../src/executor/modifier/part_modifier.c"
#include "../../../src/executor/comparator/prefix/part_prefix_comparator.c"
#include "../../../src/executor/comparator/suffix/part_suffix_comparator.c"

void compare_all_array_should_succeed() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_all_array((void*) &result, (void*) L"Hello, World!", (void*) L"Hello, World!", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 1);
}

void compare_all_array_same_string_different_parts_should_fail() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_all_array((void*) &result, (void*) L"Hello, World!", (void*) L"Hello World!", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_12_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

void compare_all_array_same_prefix_should_succeed() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_prefix_array((void*) &result, (void*) L"Hello, World!", (void*) L"Hell", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 1);
}

void compare_all_array_different_prefix_should_fail() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_prefix_array((void*) &result, (void*) L"Hello, World!", (void*) L"ello", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

void compare_all_array_same_suffix_should_succeed() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_suffix_array((void*) &result, (void*) L"Hello, World!", (void*) L"World!", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

void compare_all_array_different_suffix_should_fail() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    compare_suffix_array((void*) &result, (void*) L"Hello, World!", (void*) L"World", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

void compare_all_array_equal_of_different_integer_should_fail() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int i1 = *NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;
    int* i2 = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

    compare_all_array((void*) &result, (void*) &i1, (void*) i2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

void compare_all_array_smaller_or_equal_of_different_integer_should_succeed() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int i1 = *NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;
    int* i2 = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

    compare_all_array((void*) &result, (void*) &i1, (void*) i2, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 1);
}

void compare_all_array_greater_of_different_integer_should_fail() {

    int result = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int i1 = *NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;
    int* i2 = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

    compare_all_array((void*) &result, (void*) &i1, (void*) i2, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

int main() {

    compare_all_array_should_succeed();
    compare_all_array_same_string_different_parts_should_fail();
    compare_all_array_same_prefix_should_succeed();
    compare_all_array_different_prefix_should_fail();
    compare_all_array_same_suffix_should_succeed();
    compare_all_array_different_suffix_should_fail();
    compare_all_array_equal_of_different_integer_should_fail();
    compare_all_array_smaller_or_equal_of_different_integer_should_succeed();
    compare_all_array_greater_of_different_integer_should_fail();

    return 0;
}

/* COMPARE_ALL_ARRAY_TESTER */
#endif
