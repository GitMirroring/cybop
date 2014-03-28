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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TESTER_SOURCE
#define TESTER_SOURCE
#include "../executor/comparator/basic/integer/between_integer_comparator.c"
#include "../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "controller/controller_tester.c"
#include "applicator/applicator_tester.c"
#include "executor/executor_tester.c"
#include "unknown/unknown_tester.c"
//
// Examples for source code testing via log messages.
//
// fwprintf(stdout, L"TEST integer: %i\n", x);
// fwprintf(stdout, L"TEST pointer: %i\n", x);
// fwprintf(stdout, L"TEST w_char array string: %ls\n", (wchar_t*) x);
// fwprintf(stdout, L"TEST string literal: %ls\n", "string");
//

//
// Using printf to check parametre values:
//
// The printf function uses stdout for output, but nothing appears on console.
// Therefore, fprintf is used and stdout is given for output.
// Example:
// int x = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
// fwprintf(stdout, L"The value of x is: %d\n", x);
//
/**
 * The main test procedure.
 *
 * @param p0 the test unit
 */
#include "logger_tester.c"
void test(void* p0) {
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test.");
    fwprintf(stdout, L"TEST logger.\n");
    // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            compare_integer_equal((void*) &r, p0, (void*) ALL_UNIT_TEST_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // CAUTION! There is NO specific test function for this case.
                // Instead, ALL OTHER test functions are to be called here.
                //test_calculator();
                test_controller(p0);
                test_applicator(p0);
                test_executor(p0);
                test_unknown();
            }
        }
        // Next level of the folder applicator
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            compare_integer_equal((void*)&r, p0,APPLICATOR_UNIT_TEST_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                test_applicator(p0);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            compare_integer_between((void*)&r, APPLICATOR_UNIT_TEST_CYBOI_MODEL, NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY, p0);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                test_applicator(p0);
            }
        }

        // Next level of the folder controller
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            compare_integer_equal((void*)&r, p0, CONTROLLER_UNIT_TEST_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                test_controller(p0);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            compare_integer_between((void*)&r, CONTROLLER_UNIT_TEST_CYBOI_MODEL, NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY, p0);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                test_controller(p0);
            }
        }

        // Next level of the folder executor
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            compare_integer_equal((void*)&r, p0, EXECUTOR_UNIT_TEST_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                test_executor(p0);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            compare_integer_between((void*)&r, EXECUTOR_UNIT_TEST_CYBOI_MODEL, NUMBER_300_INTEGER_STATE_CYBOI_MODEL_ARRAY, p0);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                test_executor(p0);
            }
        }
}

/* TESTER_SOURCE */
#endif
