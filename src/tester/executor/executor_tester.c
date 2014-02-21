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

#ifndef TESTER_EXECUTOR_SOURCE
#define TESTER_EXECUTOR_SOURCE
#include "memoriser/memoriser_tester.c"
#include "manipulator/manipulator_tester.c"
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

void test_executor(void* p0) {
	log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test.");

		int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_UNIT_TEST_CYBOI_MODEL);

			if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
			{
				compare_integer_equal((void*)&r, p0, (void*)ALL_UNIT_TEST_CYBOI_MODEL );
			}

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// all tests
				test_memoriser();
				test_manipulator();
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_ACCESSOR_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// accessor tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_CALCULATOR_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// calculator tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_CASTER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// caster tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_COMMANDER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// commandander tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_COMMUNICATOR_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// communicator tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_COMPARATOR_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// comparator tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_CONVERTER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// converter tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_LIFEGUARD_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// lifeguard tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_LOGIFIER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// logifier tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_MAINTAINER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// maintainer tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_MANIPULATOR_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// manipulator tests
				test_manipulator();
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_MEMORISER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// memoriser tests
				test_memoriser();
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_MODIFIER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// modifier tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_REFERENCER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// referencer tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_REPRESENTER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// representer tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_RUNNER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// runner tests
			}
		}

		if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

			compare_integer_equal((void*) &r, p0, (void*) EXECUTER_SEARCHER_UNIT_TEST_CYBOI_MODEL);

			if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

				// searcher tests
			}
		}
}
/* TESTER_EXECUTOR_SOURCE */
#endif

