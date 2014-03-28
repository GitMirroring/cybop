/*
 * Copyright (C) 1999-2014. Christian Heller.

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

#ifndef MANIPULATOR_CHARACTER_TESTER
#define MANIPULATOR_CHARACTER_TESTER

#include "../../../../executor/manipulator/character/shift_left_character_manipulator.c"
#include "../../../../executor/manipulator/character/shift_right_character_manipulator.c"
#include "../../../../executor/manipulator/character/rotate_left_character_manipulator.c"
#include "../../../../executor/manipulator/character/rotate_right_character_manipulator.c"

void test_shift_left_character() {

    fwprintf(stdout, L"TEST - shift 2 left by 1 (expect 4)\n");

    unsigned char v = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    manipulate_character_shift_left((void*) &v, s);

    char expected = 4;

    if (expected == (char)v) {

        fwprintf(stdout, L"OK - shift result: %d\n", v);
    }
    else {
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, v);
    }
}


void test_shift_right_character() {

        fwprintf(stdout, L"TEST - shift 1 right by 1 (expect 2)\n");

        unsigned char v = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
        void* s = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        manipulate_character_shift_left((void*) &v, s);

        char expected = 2;

        if (expected == (char)v) {

            fwprintf(stdout, L"OK - shift result: %d\n", v);
        }
        else {
            fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, v);
        }
}

void test_rotate_right_character() {

    fwprintf(stdout, L"TEST - rotate 25 right by 2 (expect 6)\n");

    char v = *NUMBER_25_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_2_INTEGER_STATE_CYBOI_MODEL;

    manipulate_character_rotate_right((void*) &v, s);

    char expected = 6;

    if (expected == (char)v) {

        fwprintf(stdout, L"OK - rotate result: %d\n", v);
    }
    else {
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, v);
    }
}

void test_rotate_left_character() {

    fwprintf(stdout, L"TEST - rotate 25 left by 2 (expect 100)\n");

    unsigned char v = *NUMBER_25_INTEGER_STATE_CYBOI_MODEL;
    void* s = NUMBER_2_INTEGER_STATE_CYBOI_MODEL;

    manipulate_character_rotate_left((void*) &v, s);

    char expected = 100;

    if (expected == (char)v) {

        fwprintf(stdout, L"OK - rotate result: %d\n", v);
    }
    else {
        fwprintf(stdout, L"ERROR - expected: %d but was: %d\n", expected, v);
    }
}

/**
 * Tests the character manipulators.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_manipulator_character() {

    fwprintf(stdout, L"TEST modul executor/manipulator/character:\n");
    test_shift_left_character();
    test_shift_right_character();
    test_rotate_left_character();
    test_rotate_right_character();
}

/* MANIPULATOR_CHARACTER_TESTER */
#endif
