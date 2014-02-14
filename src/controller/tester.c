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

#ifndef TESTER_SOURCE
#define TESTER_SOURCE

#include "../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../constant/model/cyboi/test/unit_test_cyboi_model.c"
#include "../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../executor/modifier/copier/integer_copier.c"
//#include "../tester/accessor_tester.c"
//#include "../tester/arithmetiser_tester.c"
#include "../tester/assembler_tester.c"
#include "../tester/calculator_tester.c"
#include "../tester/sleeper_tester.c"
//#include "../tester/caster_tester.c"
#include "../tester/communicator_tester.c"
#include "../tester/comparator_tester.c"
#include "../tester/compound_tester.c"
#include "../tester/constant_tester.c"
//#include "../tester/converter_tester.c"
//#include "../tester/copier_tester.c"
//#include "../tester/display_tester.c"
#include "../tester/example_tester.c"
//#include "../tester/finder_tester.c"
#include "../tester/logger_tester.c"
#include "../tester/memoriser_tester.c"
//#include "../tester/modifier_tester.c"
#include "../tester/pointer_tester.c"
#include "../tester/preprocessor_tester.c"
#include "../tester/referencer_tester.c"
//#include "../tester/representer_tester.c"
//#include "../tester/serial_port_tester.c"
//#include "../tester/variable_tester.c"

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
void test(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) ACCESSOR_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

<<<<<<< .mine
            test_memoriser();
        }
    }
=======
            //test_accessor();
        //}
    //}
>>>>>>> .r2633

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p0, (void*) ALL_UNIT_TEST_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! There is NO specific test function for this case.
            // Instead, ALL OTHER test functions are to be called here.

<<<<<<< .mine
            test_memoriser();
            //test_arithmetiser();
=======
            test_sleeper();
            test_accessor();
            test_arithmetiser();
>>>>>>> .r2630
            test_assembler();
            test_calculator();
//              test_caster();
            test_communicator();
            test_comparator();
            test_compound();
            test_constant();
//              test_converter();
//              test_copier();
//              test_display();
            test_example();
//              test_finder();
//              test_logger();
//              test_memoriser();
//              test_modifier();
            test_pointer();
//              test_preprocessor();
//              test_referencer();
//              test_representer();
//              test_serial_port();
//            test_variable();
        }
    }

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) ARITHMETISER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

<<<<<<< .mine
            //test_arithmetiser();
        }
    }
=======
            //test_arithmetiser();
        //}
    //}
>>>>>>> .r2633

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) ASSEMBLER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //test_assembler();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) CALCULATOR_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //test_calculator();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) CASTER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_caster();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) COMMUNICATOR_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //test_communicator();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) COMPARATOR_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //test_comparator();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) COMPOUND_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //test_compound();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) CONSTANT_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //test_constant();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) CONVERTER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_converter();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) COPIER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_copier();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) DISPLAY_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_display();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) EXAMPLE_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //test_example();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) FINDER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_finder();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) LOGGER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_logger();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) MEMORISER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_memoriser();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) MODIFIER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_modifier();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) POINTER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //test_pointer();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) PREPROCESSOR_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_preprocessor();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) REFERENCER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_referencer();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) REPRESENTER_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_representer();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) SERIAL_PORT_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

////              test_serial_port();
        //}
    //}

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //compare_integer_equal((void*) &r, p0, (void*) VARIABLE_UNIT_TEST_CYBOI_MODEL);

        //if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

<<<<<<< .mine
            //test_variable();
        }
    }
=======
            //test_variable();
        //}
    //}
>>>>>>> .r2633

    //if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not test. The test unit is unknown.");
    //}
}

/* TESTER_SOURCE */
#endif
