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

#ifndef COMPARE_DOUBLE_TESTER
#define COMPARE_DOUBLE_TESTER

#include <assert.h>
#include "../../../src/executor/calculator/integer/add_integer_calculator.c"
#include "../../../src/executor/comparator/basic/double/equal_double_comparator.c"
#include "../../../src/executor/comparator/basic/double/greater_double_comparator.c"
#include "../../../src/executor/comparator/basic/double/greater_or_equal_double_comparator.c"
#include "../../../src/executor/comparator/basic/double/smaller_double_comparator.c"
#include "../../../src/executor/comparator/basic/double/smaller_or_equal_double_comparator.c"
#include "../../../src/executor/comparator/basic/double/unequal_double_comparator.c"
#include "../../../src/executor/comparator/basic/double_comparator.c"
#include "../../../src/executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../src/executor/memoriser/allocator/array_allocator.c"
#include "../../../src/executor/memoriser/deallocator/array_deallocator.c"
#include "../../../src/executor/copier/array_copier.c"
#include "../../../src/executor/modifier/array_modifier.c"
#include "../../../src/executor/modifier/part_modifier.c"
#include "../../../src/executor/comparator/all/part_all_comparator.c"

void compare_double_for_equal_should_fail() {

    double l = 1.2;
    double r = 1.3;
    int res = 0;

    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(res == 0);
}

void compare_double_for_smaller_should_succeed() {

    double l = 1.2;
    double r = 1.3;
    int res = 0;

    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) SMALLER_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(res == 1);
}

void compare_double_for_greater_should_fail() {

    double l = 1.2;
    double r = 1.3;
    int res = 0;

    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) GREATER_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(res == 0);
}

void compare_double_for_smaller_or_equal_should_succeed() {

    double l = 1.2;
    double r = 1.3;
    int res = 0;

    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(res == 1);
}

void compare_double_for_greater_or_equal_should_fail() {

    double l = 1.2;
    double r = 1.3;
    int res = 0;

    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(res == 0);
}

void compare_double_for_unequal_should_succeed() {

    double l = 1.2;
    double r = 1.3;
    int res = 0;

    compare_double((void*) &res, (void*) &l, (void*) &r, (void*) UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT);

    assert(res == 1);
}

int main() {

    compare_double_for_equal_should_fail();
    compare_double_for_smaller_should_succeed();
    compare_double_for_greater_should_fail();
    compare_double_for_smaller_or_equal_should_succeed();
    compare_double_for_greater_or_equal_should_fail();
    compare_double_for_unequal_should_succeed();

    return 0;
}

/* COMPARE_DOUBLE_TESTER */
#endif
