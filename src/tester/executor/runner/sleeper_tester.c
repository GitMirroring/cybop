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

#ifndef SLEEPER_TESTER
#define SLEEPER_TESTER

#include "time.h"
#include "math.h"
#include "../../../executor/runner/sleeper.c"
#include "../../../constant/format/cyboi/logic_cyboi_format.c"

void test_sleep_duration() {

    fwprintf(stdout, L"TEST - sleep for one second\n");

    void* dur = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    void* type = SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT;

    time_t start = time(0);
    sleep_duration(dur, type);
    time_t end = time(0);

    int t = (int)difftime(end,start);

    if (t < *NUMBER_1_INTEGER_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"ERROR - expected to be greater than 1 second but was: %d\n", t);
    }
    else {
        fwprintf(stdout, L"OK - slept for %d seconds\n", t);
    }
}

/**
 * Tests the sleeper.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_sleeper() {
	fwprintf(stdout, L"TEST sleep test.\n");
    test_sleep_duration();
}

/* SLEEPER_TESTER */
#endif
