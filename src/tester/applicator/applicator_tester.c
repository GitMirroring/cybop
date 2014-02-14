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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TESTER_APPLICATOR_SOURCE
#define TESTER_APPLICATOR_SOURCE

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

void test_applicator(void* p0) {
	log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test.");

		int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_UNIT_TEST_CYBOI_MODEL);

			if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
			{
				compare_integer_equal((void*)&r, p0, (void*)ALL_UNIT_TEST_CYBOI_MODEL );
			}

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// all tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_ACCESS_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// access tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_CALCULATE_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// calculate tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_CAST_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// cast tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_COMMAND_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// command tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_COMPARE_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// compare tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_FLOW_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// flow tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_LIVE_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// live tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_LOGIFIER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// logifier tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_MAINTAIN_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// maintain tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_MANIPULATE_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// manipulate tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_MEMORISE_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// memorise tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_MODIFY_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// modify tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_REPRESENT_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// represent tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) APPLICATOR_RUN_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// run tests
			}
		}
}
/* TESTER_APPLICATOR_SOURCE */
#endif
