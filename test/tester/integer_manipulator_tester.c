/*
 * Copyright (C) 1999-2016. Christian Heller.

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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MANIPULATOR_INTEGER_TESTER
#define MANIPULATOR_INTEGER_TESTER

#include "../../../../executor/manipulator/integer/rotate_left_integer_manipulator.c"
#include "../../../../executor/manipulator/integer/rotate_right_integer_manipulator.c"
#include "../../../../executor/manipulator/integer/shift_left_integer_manipulator.c"
#include "../../../../executor/manipulator/integer/shift_right_integer_manipulator.c"

void test_shift_left_integer() {

    fwprintf(stdout, L"TEST - shift 1 left by 2 (expect 4)\n");

    int v = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_2_INTEGER_STATE_CYBOI_MODEL;

    manipulate_integer_shift_left((void*) &v, s);

    int expected = 4;

    if (expected == (int) v) {

        fwprintf(stdout, L"OK - shift result: %d\n", v);
    } else {
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, v);
    }
}

void test_shift_right_integer() {

    fwprintf(stdout, L"TEST - shift 40 right by 2 (expect 10)\n");

    int v = *NUMBER_40_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_2_INTEGER_STATE_CYBOI_MODEL;

    manipulate_integer_shift_right((void*) &v, s);

    int expected = 10;

    if (expected == (int) v) {

        fwprintf(stdout, L"OK - shift result: %d\n", v);
    } else {
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, v);
    }
}

void test_rotate_right_integer() {

    fwprintf(stdout, L"TEST - rotate 25 right by 2 (expect 6)\n");

    int v = *NUMBER_25_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_2_INTEGER_STATE_CYBOI_MODEL;

    manipulate_integer_rotate_right((void*) &v, s);

    int expected = 6;

    if (expected == (int) v) {

        fwprintf(stdout, L"OK - rotate result: %d\n", v);
    } else {
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, v);
    }
}

void test_rotate_left_integer() {

    fwprintf(stdout, L"TEST - rotate 25 left by 2 (expect 100)\n");

    unsigned char v = *NUMBER_25_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_2_INTEGER_STATE_CYBOI_MODEL;

    manipulate_integer_rotate_left((void*) &v, s);

    int expected = 100;

    if (expected == (int) v) {

        fwprintf(stdout, L"OK - rotate result: %d\n", v);
    } else {
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, v);
    }
}

/**
 * Tests the integer manipulators.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_manipulator_integer() {

    fwprintf(stdout, L"TEST modul executor/manipulator/integer:\n");
    test_shift_left_integer();
    test_shift_right_integer();
    test_rotate_left_integer();
    test_rotate_right_integer();
}

/* MANIPULATOR_INTEGER_TESTER */
#endif
