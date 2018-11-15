/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#include <stdio.h>
#include <termios.h>
#include <wchar.h>

//
// CAUTION! Do NOT delete any of these includes!
// ALL of them are important, some due to indirect dependencies.
//

/*??
#include "../../../src/constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../src/constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../src/controller/globaliser.c"
#include "../../../src/controller/orienter.c"
#include "../../../src/controller/unglobaliser.c"
#include "../../../src/executor/calculator/integer/add_integer_calculator.c"
#include "../../../src/executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../src/executor/copier/array_copier.c"
#include "../../../src/executor/copier/pointer_copier.c"
#include "../../../src/executor/modifier/part_modifier.c"
#include "../../../src/executor/runner/second_sleeper.c"
#include "../../../src/executor/sensor/sensor.c"
*/

#ifndef TERMINAL_SENSOR_TESTER_SOURCE
#define TERMINAL_SENSOR_TESTER_SOURCE

void test_sense_terminal() {

/*??
    // Startup global variables.
    globalise();

    // Set orientation of standard streams to wide character.
    orient((void*) stdin, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    orient((void*) stdout, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    orient((void*) stderr, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"TEST\n");

    // Get file descriptor from stream.
    int f = fileno(stdin);

    // The terminal structure storing the entire collection of attributes of a terminal.
    struct termios t;
    // The original terminal attributes.
    struct termios o;

    // Get terminal attributes.
    int e = tcgetattr(f, &t);

    if (e >= 0) {

        // Store original terminal attributes.
        o = t;

        // Modify attributes.

        // Turn off stripping of valid input bytes to seven bits,
        // so that all eight bits are available for programmes to read.
        t.c_iflag &= ~ISTRIP;

        // Turn off canonical input processing mode.
        t.c_lflag &= ~ICANON;

        // Turn off echo.
        t.c_lflag &= ~ECHO;

        // Set number of input characters to be available, before read() will return.
        //
        // CAUTION! This value HAS TO BE set to zero,
        // so that one key press such as ESCAPE gets processed
        // right away (e.g. to exit an application),
        // without waiting for yet another character input.
        t.c_cc[VMIN] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Set time to wait before read() will return.
        t.c_cc[VTIME] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Set terminal attributes.
        e = tcsetattr(f, TCSANOW, &t);

        if (e >= 0) {

            // The return value (data available flag).
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            // The sleep time in seconds.
            int s = 1;

            // Add endless loop optionally.
            // It should get interrupted, as soon as a key is typed on keyboard.
            while (1) {

                //?? TODO: Add input/output entry as third argument.
//??                sense((void*) &r, (void*) &f, (void*) TERMINAL_CYBOI_CHANNEL);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    fwprintf(stdout, L"Information: Input was sensed on terminal.\n");

                    break;

                } else {

                    fwprintf(stdout, L"Information: No input was sensed on terminal.\n");
                    fwprintf(stdout, L"Information: Sleep for some time.\n");

                    // Sleep for some time.
                    sleep_second((void*) &s);
                }
            }

            // Reset terminal attributes.
            e = tcsetattr(f, TCSANOW, &o);

            if (e >= 0) {

                fwprintf(stdout, L"Information: The terminal attributes have been reset successfully.\n");

            } else {

                fwprintf(stdout, L"Error: Could not reset attributes. The return value e is negative.\n");
            }

        } else {

            fwprintf(stdout, L"Error: Could not set attributes. The return value e is negative.\n");
        }

    } else {

        fwprintf(stdout, L"Error: Could not get attributes. The return value e is negative.\n");
    }

    // Shutdown global variables.
    unglobalise();
*/
}

int main() {

    test_sense_terminal();

    return 0;
}

/* TERMINAL_SENSOR_TESTER_SOURCE */
#endif
