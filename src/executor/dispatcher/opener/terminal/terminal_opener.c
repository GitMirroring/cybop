/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <unistd.h> // STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Opens the terminal with the given filename.
 *
 * @param p0 the file descriptor
 * @param p1 the filename data
 * @param p2 the filename count
 */
void open_terminal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open terminal.");
    //?? fwprintf(stdout, L"Debug: Open terminal. p0: %i\n", p0);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) STANDARD_ERROR_OUTPUT_TERMINAL_DEVICE_CYBOL_MODEL, p2, (void*) STANDARD_ERROR_OUTPUT_TERMINAL_DEVICE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The standard file descriptor.
            //
            // CAUTION! Use the symbolic constant of the file DESCRIPTOR
            // STDERR_FILENO and NOT the standard stream stderr.
            //
            // CAUTION! The standard streams "stdin" and "stdout"
            // exist on posix as well as on win32.
            //
            int f = STDERR_FILENO;

            // Copy standard file descriptor to destination file descriptor.
            copy_integer(p0, (void*) &f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) STANDARD_INPUT_TERMINAL_DEVICE_CYBOL_MODEL, p2, (void*) STANDARD_INPUT_TERMINAL_DEVICE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The standard file descriptor.
            //
            // CAUTION! Use the symbolic constant of the file DESCRIPTOR
            // STDIN_FILENO and NOT the standard stream stdin.
            //
            // CAUTION! The standard streams "stdin" and "stdout"
            // exist on posix as well as on win32.
            //
            int f = STDIN_FILENO;

            // Copy standard file descriptor to destination file descriptor.
            copy_integer(p0, (void*) &f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) STANDARD_OUTPUT_TERMINAL_DEVICE_CYBOL_MODEL, p2, (void*) STANDARD_OUTPUT_TERMINAL_DEVICE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The standard file descriptor.
            //
            // CAUTION! Use the symbolic constant of the file DESCRIPTOR
            // STDOUT_FILENO and NOT the standard stream stdout.
            //
            // CAUTION! The standard streams "stdin" and "stdout"
            // exist on posix as well as on win32.
            //
            int f = STDOUT_FILENO;

            // Copy standard file descriptor to destination file descriptor.
            copy_integer(p0, (void*) &f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open terminal. The filename is unknown.");
        fwprintf(stdout, L"Warning: Could not open terminal. The filename is unknown. p0: %i\n", p0);
    }
}
