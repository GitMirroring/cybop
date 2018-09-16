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
#include <wchar.h>

#include "../../../src/constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../src/constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../src/executor/calculator/integer/add_integer_calculator.c"
#include "../../../src/executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../src/executor/copier/array_copier.c"
#include "../../../src/executor/copier/pointer_copier.c"
#include "../../../src/executor/sensor/sensor.c"
#include "../../../src/executor/modifier/part_modifier.c"

#ifndef TERMINAL_SENSOR_TESTER_SOURCE
#define TERMINAL_SENSOR_TESTER_SOURCE

void test_sense_terminal() {

    // The return value (data available flag).
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // Get file descriptor from stream.
    int f = fileno(stdin);

    sense((void*) &r, (void*) &f, (void*) TERMINAL_CYBOI_CHANNEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        fwprintf(stdout, L"TEST: Input was sensed on terminal.\n");

    } else {

        fwprintf(stdout, L"TEST: No input was sensed on terminal.\n");
    }
}

int main() {

    test_sense_terminal();

    return 0;
}

/* TERMINAL_SENSOR_TESTER_SOURCE */
#endif
