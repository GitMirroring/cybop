/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef VARIABLE_TESTER
#define VARIABLE_TESTER

#include <assert.h>

#include "../../src/variable/type_size/integral_type_size.c"
#include "../../src/variable/type_size/pointer_type_size.c"
#include "../../src/variable/type_size/real_type_size.c"

/**
 * Tests the integral type sizes.
 */
void test_integral_type_sizes() {

    // assert(sizeof (signed char) == *SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE && "signed char");
    assert(0 == *UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE && "unsigned char");
    assert(0 == *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE && "signed short int");
    // assert(sizeof (unsigned short int) == *UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE && "unsigned short int");
    assert(0 == *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE && "signed int");
    // assert(sizeof (unsigned int) == *UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE && "unsigned int");
    // assert(sizeof (signed long int) == *SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE && "signed long int");
    // assert(sizeof (unsigned long int) == *UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE && "unsigned long int");
    assert(0 == *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE && "signed long long int");
    // assert(sizeof (unsigned long long int) == *UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE && "unsigned long long int");
    assert(0 == *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE && "wchar_t");
    // assert(sizeof (unsigned long DWORD) == *DOUBLE_WORD_INTEGRAL_TYPE_SIZE && "unsigned long DWORD");
}

/**
 * Tests the integral type sizes.
 */
void test_pointer_type_sizes() {

    assert(0 == *POINTER_TYPE_SIZE && "pointer");
}

/**
 * Tests the integral type sizes.
 */
void test_real_type_sizes() {

    assert(0 == *DOUBLE_REAL_TYPE_SIZE && "double");
    // assert(sizeof (long double) == *LONG_DOUBLE_REAL_TYPE_SIZE && "long double");
}

/**
 * Tests the variable usage.
 */
int main() {

    test_integral_type_sizes();
    test_pointer_type_sizes();
    test_real_type_sizes();

    return 0;
}

/* VARIABLE_TESTER */
#endif
