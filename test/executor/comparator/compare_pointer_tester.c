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

#ifndef COMPARE_POINTER_TESTER
#define COMPARE_POINTER_TESTER

#include <assert.h>

#include "../../../src/executor/comparator/all/part_all_comparator.c"
#include "../../../src/executor/comparator/pointer_comparator.c"
#include "../../../src/executor/copier/array_copier.c"
#include "../../../src/executor/memoriser/allocator/array_allocator.c"
#include "../../../src/executor/memoriser/deallocator/array_deallocator.c"
#include "../../../src/executor/modifier/array_modifier.c"
#include "../../../src/executor/modifier/part_modifier.c"

//
// Forward declarations.
//

void compare_integer_unequal(void* p0, void* p1, void* p2);

void compare_pointer_for_equal_should_fail() {

    int p1 = 1;
    int p2 = 2;
    int result = 0;

    compare_pointer(&result, &p1, &p2, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(result == 0);
}

void compare_pointer_for_smaller_should_fail() {

    int p1 = 1;
    int p2 = 2;
    int result = 0;

    compare_pointer(&result, &p1, &p2, (void*) LESS_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(result == 0);
}

void compare_pointer_for_greater_should_succeed() {

    int p1 = 1;
    int p2 = 2;
    int result = 0;

    compare_pointer(&result, &p1, &p2, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(result == 1);
}

void compare_pointer_for_smaller_or_equal_should_fail() {

    int p1 = 1;
    int p2 = 2;
    int result = 0;

    compare_pointer(&result, &p1, &p2, (void*) LESS_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(result == 0);
}

void compare_pointer_for_greater_or_equal_should_succeed() {

    int p1 = 1;
    int p2 = 2;
    int result = 0;

    compare_pointer(&result, &p1, &p2, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(result == 1);
}

void compare_pointer_for_unequal_should_succeed() {

    int p1 = 1;
    int p2 = 2;
    int result = 0;

    compare_pointer(&result, &p1, &p2, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(result == 1);
}

int main() {

    compare_pointer_for_equal_should_fail();
    compare_pointer_for_smaller_should_fail();
    compare_pointer_for_greater_should_succeed();
    compare_pointer_for_smaller_or_equal_should_fail();
    compare_pointer_for_greater_or_equal_should_succeed();
    compare_pointer_for_unequal_should_succeed();

    return 0;
}

/* COMPARE_POINTER_TESTER */
#endif
