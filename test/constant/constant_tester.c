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

#ifndef CONSTANT_TESTER
#define CONSTANT_TESTER

#include <assert.h>
#include <stdio.h>

#include "../../src/constant/model/cyboi/state/mathematics_state_cyboi_model.c"
#include "../../src/constant/model/cyboi/state/pointer_state_cyboi_model.c"

/**
 * Tests the mathematical state model constants.
 */
void test_mathematics_state_model() {

    assert(M_E == *E_DOUBLE_STATE_CYBOI_MODEL && "Test base of natural logarithms");
    assert(M_LOG2E == *LOG_2_E_DOUBLE_STATE_CYBOI_MODEL && "Test logarithm to base 2 of M_E");
    assert(M_LOG10E == *LOG_10_E_DOUBLE_STATE_CYBOI_MODEL_ARRAY && "Test natural logarithm of 10");
    assert(M_LN2 == *LN_2_DOUBLE_STATE_CYBOI_MODEL && "Test natural logarithm of 2");
    assert(M_LN10 == *LN_10_DOUBLE_STATE_CYBOI_MODEL && "Test natural logarithm of 10");
    assert(M_PI == *PI_DOUBLE_STATE_CYBOI_MODEL && "Test ratio of a circle's circumference to its diameter, called pi");
    assert(M_PI_2 == *PI_DIVIDED_BY_2_DOUBLE_STATE_CYBOI_MODEL && "Test pi divided by 2");
    assert(M_PI_4 == *PI_DIVIDED_BY_4_DOUBLE_STATE_CYBOI_MODEL && "Test pi divided by 4");
    assert(M_1_PI == *RECIPROCAL_OF_PI_DOUBLE_STATE_CYBOI_MODEL && "Test reciprocal of pi (1/pi)");
    assert(M_2_PI == *TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE_STATE_CYBOI_MODEL && "Test two times the reciprocal of pi");
    assert(M_2_SQRTPI == *TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE_STATE_CYBOI_MODEL && "Test two times the reciprocal of the square root of pi");
    assert(M_SQRT2 == *SQUARE_ROOT_OF_2_DOUBLE_STATE_CYBOI_MODEL && "Test square root of 2");
    assert(M_SQRT1_2 == *RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE_STATE_CYBOI_MODEL && "Test reciprocal of the square root of 2");
}

/**
 * Tests the pointer state model constants.
 */
void test_pointer_state_model() {
    assert((void*) 0 == *NULL_POINTER_STATE_CYBOI_MODEL && "null pointer memory model");
}

/**
 * Tests the constant values and usage.
 */
int main() {

    test_mathematics_state_model();
    test_pointer_state_model();

    return 0;
}

/* CONSTANT_TESTER */
#endif
