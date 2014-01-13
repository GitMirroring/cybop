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
#include "../tester/accessor_tester.c"
#include "../tester/arithmetiser_tester.c"
#include "../tester/assembler_tester.c"
#include "../tester/calculator_tester.c"
//#include "../tester/caster_tester.c"
#include "../tester/communicator_tester.c"
#include "../tester/comparator_tester.c"
#include "../tester/compound_tester.c"
#include "../tester/constant_tester.c"
//#include "../tester/converter_tester.c"
//#include "../tester/copier_tester.c"
//#include "../tester/display_tester.c"
#include "../tester/empty_tester.c"
//#include "../tester/finder_tester.c"
#include "../tester/logger_tester.c"
#include "../tester/memoriser_tester.c"
//#include "../tester/modifier_tester.c"
#include "../tester/pointer_tester.c"
#include "../tester/preprocessor_tester.c"
#include "../tester/referencer_tester.c"
//#include "../tester/representer_tester.c"
//#include "../tester/serial_port_tester.c"
#include "../tester/variable_tester.c"

//
// Examples for source code testing via log messages.
//
// fwprintf(stdout, L"TEST integer: %i\n", x);
// fwprintf(stdout, L"TEST pointer: %i\n", x);
// fwprintf(stdout, L"TEST w_char array string: %ls\n", (wchar_t*) x);
// fwprintf(stdout, L"TEST string literal: %ls\n", "string");
//

/**
 * The main test procedure.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test cyboi.");

    // How to use printf to check parametre values.
    // The printf function uses stdout for output, but nothing appears on console.
    // Therefore, fprintf is used and stdout is given for output.
    // Example:
    // int x = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
    // fwprintf(stdout, L"The value of x is: %d\n", x);

    // Globals.
    test_constant();
    test_variable();
    test_assembler();
    test_pointer();
//    test_preprocessor();

    // Logger.
//    test_logger();

    // Executor.
    test_accessor();
    test_arithmetiser();
    test_calculator();
//    test_caster();
    test_communicator();
    test_comparator();
    test_compound();
//    test_converter();
//    test_copier();
//    test_finder();
//    test_memoriser();
//    test_modifier();
//    test_referencer();
//    test_representer();

    // Communication.
//    test_display();
//    test_serial_port();

    // Empty.
    test_empty();
}

/* TESTER_SOURCE */
#endif
