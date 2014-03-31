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

#ifndef TESTER_SOURCE
#define TESTER_SOURCE

#include "../executor/container/basic/integer/left_integer_container.c"
#include "../tester/applicator/applicator_tester.c"
#include "../tester/controller/controller_tester.c"
#include "../tester/executor/executor_tester.c"
#include "../tester/unknown/unknown_tester.c"
#include "../tester/logger_tester.c"

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
//
// Example:
// int x = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
// fwprintf(stdout, L"The value of x is: %d\n", x);
//

/**
 * Call given test unit.
 *
 * @param p0 the test unit
 */
void test(void* p0) {

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) ALL_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! There is NO specific test function for this case.
            // Instead, ALL OTHER test functions are to be called here.

            test_controller(p0);
            test_applicator(p0);
            test_executor(p0);
            test_unknown();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        contain_integer_left((void*) &r, p0, (void*) APPLICATOR_UNIT_TEST_CYBOI_MODEL, (void*) CONTROLLER_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            test_applicator(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        contain_integer_left((void*) &r, p0, (void*) CONTROLLER_UNIT_TEST_CYBOI_MODEL, (void*) EXECUTOR_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            test_controller(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        contain_integer_left((void*) &r, p0, (void*) EXECUTOR_UNIT_TEST_CYBOI_MODEL, (void*) NUMBER_1000_INTEGER_STATE_CYBOI_MODEL_ARRAY);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            test_executor(p0);
        }
    }
}

/* TESTER_SOURCE */
#endif
