/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
#include "../../../../../executor/calculator/basic/integer_calculator.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"

#ifndef INTEGER_CALCULATOR_TESTER_SOURCE
#define INTEGER_CALCULATOR_TESTER_SOURCE

void test_calculate_integer_absolute(){

    int* result;
    int operand;
    int* expected;

    result = NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    operand = -5;
    expected = NUMBER_5_INTEGER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"pre operand: %d\n", operand);
    fwprintf(stdout, L"pre result: %d\n", *result);

    calculate_integer_absolute((void*)result, (void*) &operand);

    if (*result != *expected){
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", *expected, *result);
    }
        else {
                fwprintf(stdout, L"OK - post result: %d, post operand: %d\n", *result, operand);
        }

}

void test_calculate_integer_add(){

    int* result;
    int* operand;
    int* expected;

    result = NUMBER_500_INTEGER_STATE_CYBOI_MODEL;
    operand = NUMBER_500_INTEGER_STATE_CYBOI_MODEL;
    expected = NUMBER_1000_INTEGER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"pre operand: %d\n", *operand);
    fwprintf(stdout, L"pre result: %d\n", *result);

    calculate_integer_add((void*) result, (void*) operand);

    if (*result != *expected){
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", *expected, *result);
    }
        else {
                fwprintf(stdout, L"OK - post result: %d, post operand: %d\n", *result, *operand);
        }

}

void test_calculate_integer_divide(){

    int* result;
    int* operand;
    int* expected;

    result = NUMBER_5000_INTEGER_STATE_CYBOI_MODEL;
    operand = NUMBER_1000_INTEGER_STATE_CYBOI_MODEL;
    expected = NUMBER_5_INTEGER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"pre operand: %d\n", *operand);
    fwprintf(stdout, L"pre result: %d\n", *result);

    calculate_integer_divide((void*) result, (void*) operand);

    if (*result != *expected){
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", *expected, *result);
    }
        else {
                fwprintf(stdout, L"OK - post result: %d, post operand: %d\n", *result, *operand);
        }
}

void test_calculate_integer_modulo(){

    int* result;
    int* operand;
    int* expected;

    result = NUMBER_13_INTEGER_STATE_CYBOI_MODEL;
    operand = NUMBER_4_INTEGER_STATE_CYBOI_MODEL;
    expected = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"pre operand: %d\n", *operand);
    fwprintf(stdout, L"pre result: %d\n", *result);

    calculate_integer_modulo((void*) result, (void*) operand);

    if (*result != *expected){
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", *expected, *result);
    }
        else {
                fwprintf(stdout, L"OK - post result: %d, post operand: %d\n", *result, *operand);
        }
}

void test_calculate_integer_multiply(){

    int* result;
    int* operand;
    //    int* expected;
    int expected;

    result = NUMBER_1000_INTEGER_STATE_CYBOI_MODEL;
    operand = NUMBER_5_INTEGER_STATE_CYBOI_MODEL;
    // Doesn't work with constant
    //expected = NUMBER_5000_INTEGER_STATE_CYBOI_MODEL;
    expected = 5000;

    fwprintf(stdout, L"pre operand: %d\n", *operand);
    fwprintf(stdout, L"pre result: %d\n", *result);

    calculate_integer_multiply((void *) result, (void*) operand);

    if (*result != expected){
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, *result);
    }
        else {
                fwprintf(stdout, L"OK - post result: %d, post operand: %d\n", *result, *operand);
        }
}

void test_calculate_integer_negate(){

    int* result;
    int* operand;
    int expected;

    result = NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    operand = NUMBER_10_INTEGER_STATE_CYBOI_MODEL;
    expected = -10;

    fwprintf(stdout, L"pre operand: %d\n", *operand);
    fwprintf(stdout, L"pre result: %d\n", *result);

    calculate_integer_negate((void*) result, (void*) operand);

    if (*result != expected){
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, *result);
    }
        else {
                fwprintf(stdout, L"OK - post result: %d, post operand: %d\n", *result, *operand);
        }
}

void test_calculate_integer_subtract(){

    int result;
    int operand;
    int expected;

//    result = NUMBER_1000_INTEGER_STATE_CYBOI_MODEL;
//    operand = NUMBER_500_INTEGER_STATE_CYBOI_MODEL;
//    expected = NUMBER_500_INTEGER_STATE_CYBOI_MODEL;

    result = 1000;
    operand= 500;
    expected = 500;
    calculate_integer_subtract((void*) &result, (void*) &operand);

    if (result != expected){
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, result);
    }
        else {
                fwprintf(stdout, L"OK - post result: %d, post operand: %d\n", result, operand);
        }
}

void test_integer_calculator(){
    fwprintf(stdout, L"TEST integer/calculator\n");
    fwprintf(stdout, L"TEST integer/calculator/absolute\n");
    test_calculate_integer_absolute();
    fwprintf(stdout, L"TEST integer/calculator/add\n");
    test_calculate_integer_add();
    fwprintf(stdout, L"TEST integer/calculator/divide\n");
    test_calculate_integer_divide();
    fwprintf(stdout, L"TEST integer/calculator/modulo\n");
    test_calculate_integer_modulo();
    fwprintf(stdout, L"TEST integer/calculator/multiply\n");
    test_calculate_integer_multiply();
    fwprintf(stdout, L"TEST integer/calculator/negate\n");
    test_calculate_integer_negate();
    fwprintf(stdout, L"TEST integer/calculator/substract\n");
    test_calculate_integer_subtract();
}
#endif
