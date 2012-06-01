/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VARIABLE_TESTER
#define VARIABLE_TESTER

#include <stdio.h>

#include "../logger/logger.c"
#include "../variable/type_size/integral_type_size.c"

/**
 * Tests the type sizes.
 */
void test_type_sizes() {

    log_write((void*) stdout, L"Test type sizes:\n");

    fwprintf(stdout, L"null pointer memory model: %i\n", *NULL_POINTER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"pointer: %i\n", *POINTER_TYPE_SIZE);

    fwprintf(stdout, L"signed char: %i\n", *SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"unsigned char: %i\n", *UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"signed short int: %i\n", *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"unsigned short int: %i\n", *UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"signed int: %i\n", *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"unsigned int: %i\n", *UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"signed long int: %i\n", *SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"unsigned long int: %i\n", *UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"signed long long int: %i\n", *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"unsigned long long int: %i\n", *UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"wchar_t: %i\n", *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);
    fwprintf(stdout, L"float: %i\n", *FLOAT_REAL_TYPE_SIZE);
    fwprintf(stdout, L"double: %i\n", *DOUBLE_REAL_TYPE_SIZE);
    fwprintf(stdout, L"long double: %i\n", *LONG_DOUBLE_REAL_TYPE_SIZE);
}

/**
 * Tests the variable usage.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_variable() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test variable.");

    test_type_sizes();
}

/* VARIABLE_TESTER */
#endif
