/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EMPTY_TESTER
#define EMPTY_TESTER

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../executor/memoriser/allocator/array_allocator.c"
#include "../executor/memoriser/deallocator/array_deallocator.c"
#include "../executor/modifier/copier/integer_copier.c"
#include "../logger/logger.c"

//
// This is an empty test file.
// It is provided to test miscellaneous things
// which are not to be archived in subversion (svn).
//

/**
 * Tests something 1.
 */
void test_empty_1() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test empty 1.");

    // Add YOUR SOURCE CODE here!

    // Example:
    int a = 3;
    fwprintf(stdout, L"TEST a: %i\n", a);
}

/**
 * Tests something 2.
 */
void test_empty_2() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test empty 2.");

    char c = 'X';
    char* s = "ABC";
    wchar_t* w = L"WIDE";

    fwprintf(stdout, L"TEST blubla: %c\n", c);
    fwprintf(stdout, L"TEST blubla: %i\n", s);
    fwprintf(stdout, L"TEST blubla: %s\n", s);
    fwprintf(stdout, L"TEST blubla: %ls\n", w);
}

/**
 * Tests something 3.
 */
void test_empty_3() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test empty 3.");

    int sum = 0;
//    int summand = 3;
    void* summand = *NULL_POINTER_STATE_CYBOI_MODEL;

    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &summand, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

//    *((int*) summand) = 4;
    copy_integer(summand, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

//    calculate_integer_add((void*) &sum, (void*) &summand);
    calculate_integer_add((void*) &sum, summand);

    fwprintf(stdout, L"TEST sum: %i\n", sum);

    deallocate_array((void*) &summand, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/**
 * Tests something.
 */
void test_empty() {

//    fwprintf(stdout, L"TEST empty.\n");

    // Uncomment below functions as needed,
    // in order for them to be executed.

//    test_empty_1();
//    test_empty_2();
//    test_empty_3();
}

/* EMPTY_TESTER */
#endif
