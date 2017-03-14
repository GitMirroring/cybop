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

#ifndef COMPARE_SUBSEQUENCE_ARRAY_TESTER
#define COMPARE_SUBSEQUENCE_ARRAY_TESTER

#include <assert.h>
#include "../../../src/constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../src/constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../../../src/constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../src/executor/comparator/all/array_all_comparator.c"
#include "../../../src/executor/comparator/all/part_all_comparator.c"
#include "../../../src/executor/comparator/basic/array_comparator.c"
#include "../../../src/executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/part_comparator.c"
#include "../../../src/executor/comparator/subsequence/array_subsequence_comparator.c"
#include "../../../src/executor/memoriser/allocator/array_allocator.c"
#include "../../../src/executor/memoriser/deallocator/array_deallocator.c"
#include "../../../src/executor/modifier/emptier/array_emptier.c"
#include "../../../src/executor/modifier/overwriter/part_overwriter.c"

void compare_subsequence_array_same_subsequence_should_succeed() {

    int result = 0;

    compare_subsequence_array((void*) &result, (void*) L"Hello, World!", (void*) L"Hello, World!", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 1);
}

void compare_subsequence_array_contains_subsequence_should_succeed() {

    // TODO: this one is failing, but shouldn't
    int result = 0;

    compare_subsequence_array((void*) &result, (void*) L"Hello, World!", (void*) L"o, Wor", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 1);
}

void compare_subsequence_array_contains_one_letter_should_succeed() {

    // TODO: this one is failing, but shouldn't
    int result = 0;

    compare_subsequence_array((void*) &result, (void*) L"Hello, World!", (void*) L"o", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 1);
}

void compare_subsequence_array_does_not_contains_one_letter_should_fail() {

    int result = 0;

    compare_subsequence_array((void*) &result, (void*) L"Hello, World!", (void*) L"y", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

void compare_subsequence_array_does_fail_because_of_out_bounds() {

    int result = 0;

    compare_subsequence_array((void*) &result, (void*) L"Hello, World!", (void*) L"o", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_100_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

void compare_subsequence_array_different_should_fail() {

    int result = 0;

    compare_subsequence_array((void*) &result, (void*) L"Hello, World!", (void*) L"blubla", (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_13_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL);

    assert(result == 0);
}

int main() {

    compare_subsequence_array_same_subsequence_should_succeed();
    compare_subsequence_array_contains_subsequence_should_succeed();
    compare_subsequence_array_contains_one_letter_should_succeed();
    compare_subsequence_array_does_not_contains_one_letter_should_fail();
    compare_subsequence_array_does_fail_because_of_out_bounds();
    compare_subsequence_array_different_should_fail();

    return 0;
}

/* COMPARE_SUBSEQUENCE_ARRAY_TESTER */
#endif
