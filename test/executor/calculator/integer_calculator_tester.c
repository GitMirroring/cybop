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
#include <assert.h>

#include "../../../src/constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../src/constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../src/constant/format/cyboi/logic_cyboi_format.c"
#include "../../../src/executor/calculator/basic/integer/absolute_integer_calculator.c"
#include "../../../src/executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../src/executor/calculator/basic/integer/divide_integer_calculator.c"
#include "../../../src/executor/calculator/basic/integer/modulo_integer_calculator.c"
#include "../../../src/executor/calculator/basic/integer/multiply_integer_calculator.c"
#include "../../../src/executor/calculator/basic/integer/negate_integer_calculator.c"
#include "../../../src/executor/calculator/basic/integer/subtract_integer_calculator.c"
#include "../../../src/executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../src/executor/memoriser/allocator/array_allocator.c"
#include "../../../src/executor/memoriser/deallocator/array_deallocator.c"
#include "../../../src/executor/modifier/copier/array_copier.c"
#include "../../../src/executor/modifier/emptier/array_emptier.c"
#include "../../../src/executor/modifier/overwriter/part_overwriter.c"

#ifndef INTEGER_CALCULATOR_TESTER_SOURCE
#define INTEGER_CALCULATOR_TESTER_SOURCE

void calculate_integer_absolute_should_abs_value(){

    int result = 0;
    int operand = -5;
    int expected = 5;

    calculate_integer_absolute((void*)&result, (void*)&operand);

    assert(result == expected);
}

void calculate_integer_absolute_should_keep_positiv(){

    int result = 0;
    int operand = 5;
    int expected = 5;

    calculate_integer_absolute((void*)&result, (void*)&operand);

    assert(result == expected);
}

void calculate_integer_absolute_should_do_nothing_if_source_is_null(){

    int result = 0;
    int expected = 0;

    calculate_integer_absolute((void*)&result, NULL);

    assert(result == expected);
}

void calculate_integer_absolute_should_do_nothing_if_destination_is_null(){

    int operand = -5;

    calculate_integer_absolute(NULL, (void*)&operand);

    assert(-5 == operand);
}

void test_calculate_integer_add(){

    int* result = NUMBER_500_INTEGER_STATE_CYBOI_MODEL;
    int* operand = NUMBER_500_INTEGER_STATE_CYBOI_MODEL;
    int* expected = NUMBER_500_INTEGER_STATE_CYBOI_MODEL;

    calculate_integer_add((void*) result, (void*) operand);

    assert(*result == *expected);
}

void test_calculate_integer_divide(){

    int* result = NUMBER_5000_INTEGER_STATE_CYBOI_MODEL;
    int* operand = NUMBER_1000_INTEGER_STATE_CYBOI_MODEL;
    int* expected = NUMBER_5_INTEGER_STATE_CYBOI_MODEL;

    calculate_integer_divide((void*) result, (void*) operand);

    assert(*result == *expected);
}

void test_calculate_integer_modulo(){

    int* result = NUMBER_13_INTEGER_STATE_CYBOI_MODEL;
    int* operand = NUMBER_4_INTEGER_STATE_CYBOI_MODEL;
    int* expected = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    calculate_integer_modulo((void*) result, (void*) operand);

    assert(*result == *expected);
}

void test_calculate_integer_multiply(){

    int* result = NUMBER_1000_INTEGER_STATE_CYBOI_MODEL;
    int* operand = NUMBER_5_INTEGER_STATE_CYBOI_MODEL;
    int expected = 5000;

    calculate_integer_multiply((void *) result, (void*) operand);

    assert(*result == expected);
}

void test_calculate_integer_negate(){

    int* result = NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int* operand = NUMBER_10_INTEGER_STATE_CYBOI_MODEL;
    int expected = -10;

    calculate_integer_negate((void*) result, (void*) operand);

    assert(*result == expected);
}

void test_calculate_integer_subtract(){

    int result = 1000;
    int operand = 500;
    int expected = 500;

    calculate_integer_subtract((void*) &result, (void*) &operand);

    assert(result == expected);
}

int main(){

    calculate_integer_absolute_should_abs_value();
    calculate_integer_absolute_should_keep_positiv();
    calculate_integer_absolute_should_do_nothing_if_source_is_null();
    calculate_integer_absolute_should_do_nothing_if_destination_is_null();
    test_calculate_integer_add();
    test_calculate_integer_divide();
    test_calculate_integer_modulo();
    test_calculate_integer_multiply();
    test_calculate_integer_negate();
    test_calculate_integer_subtract();

    return 0;
}
#endif