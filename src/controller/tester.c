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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TESTER_SOURCE
#define TESTER_SOURCE

#include "../tester/accessor_tester.c"
#include "../tester/arithmetiser_tester.c"
#include "../tester/assembler_tester.c"
#include "../tester/caster_tester.c"
#include "../tester/communicator_tester.c"
#include "../tester/comparator_tester.c"
#include "../tester/constant_tester.c"
#include "../tester/converter_tester.c"
#include "../tester/copier_tester.c"
#include "../tester/empty_tester.c"
#include "../tester/finder_tester.c"
#include "../tester/logger_tester.c"
#include "../tester/memoriser_tester.c"
#include "../tester/modifier_tester.c"
#include "../tester/pointer_tester.c"
#include "../tester/preprocessor_tester.c"
#include "../tester/referencer_tester.c"
#include "../tester/representer_tester.c"
#include "../tester/serial_port_tester.c"
#include "../tester/variable_tester.c"
#include "../tester/x_window_system_tester.c"

//
// Examples for source code testing via log messages.
//
// fwprintf(stdout, L"TEST integer: %i\n", x);
// fwprintf(stdout, L"TEST pointer: %i\n", x);
// fwprintf(stdout, L"TEST w_char array string: %ls\n", (wchar_t*) x);
// fwprintf(stdout, L"TEST string literal: %ls\n", "string");
//

//
// Write some character data into a test file.
//

/*
    // --- START TEST ---
    // The log file name.
    char* n = "http_response";
    // The log file status flags.
    int status = O_TRUNC | O_CREAT | O_WRONLY;
    // The log file.
    int f = open(n, status);

    if (f >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // The file owner.
        int o = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // The file group.
        int g = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // Set file owner.
        chown(n, o, g);

        // The file access rights.
        //?? TODO: When trying to cross-compile cyboi for windows,
        //?? the two S_IRGRP and S_IWGRP were not recognised by mingw.
        int r = S_IRUSR | S_IWUSR; //?? | S_IRGRP | S_IWGRP;

        // Set file access rights.
        chmod(n, r);

        // Log html to output.
        write(f, p13, *((int*) p14));

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before these global variables are set.
        log_write(stdout, L"Error: Could not open socket sending http_response file. A file error occured.\n");
    }
    // --- END TEST ---
*/

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
    test_preprocessor();

    // Logger.
    test_logger();

    // Executor.
    test_accessor();
    test_arithmetiser();
    test_caster();
    test_communicator();
    test_comparator();
    test_converter();
    test_copier();
    test_finder();
    test_memoriser();
    test_modifier();
    test_referencer();
    test_representer();

    // Communication.
    test_serial_port();
    test_x_window_system();

    // Empty.
    test_empty();
}

/* TESTER_SOURCE */
#endif
