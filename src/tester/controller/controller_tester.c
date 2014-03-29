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

#ifndef TESTER_CONTROLLER_SOURCE
#define TESTER_CONTROLLER_SOURCE
#include "checker/checker_tester.c"
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
void test_controller(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test.");

    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_UNIT_TEST_CYBOI_MODEL);

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
        {
            compare_integer_equal((void*)&r, p0, (void*)ALL_UNIT_TEST_CYBOI_MODEL );
        }

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // all tests
            test_checker();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_CHECKER_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            // checker tests
            test_checker();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_DEOPTIONALISER_UNIT_OPTION_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            // deoptionaliser tests
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_GLOBALISER_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            // globaliser tests
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_CHECKER_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            // checker tests
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_HANDLER_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            // handler tests
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_MANAGER_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            // manager tests
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_OPTIONALISER_UNIT_OPTION_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            // optionaliser tests
        }
    }
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) CONTROLLER_UNGLOBALISER_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
            // unglobaliser tests
        }
    }
}
/* TESTER_CONTROLLER_SOURCE */
#endif
