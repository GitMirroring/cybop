/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONSTANT_TESTER
#define CONSTANT_TESTER

#include <stdio.h>

#include "../../constant/model/memory/double_memory_model.c"
#include "../../logger/logger.c"

/**
 * Tests the float constants.
 */
void test_constant_float() {

    log_write_terminated_message((void*) stdout, L"Test float constants:\n");

    fwprintf(stdout, L"Test base of natural logarithms: %f\n", *E_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test logarithm to base 2 of M_E: %f\n", *LOG_2_E_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test logarithm to base 10 of M_E: %f\n", *LOG_10_E_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test natural logarithm of 2: %f\n", *LN_2_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test natural logarithm of 10: %f\n", *LN_10_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test ratio of a circle's circumference to its diameter, called pi: %f\n", *PI_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test pi divided by 2: %f\n", *PI_DIVIDED_BY_2_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test pi divided by 4: %f\n", *PI_DIVIDED_BY_4_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test reciprocal of pi (1/pi): %f\n", *RECIPROCAL_OF_PI_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test two times the reciprocal of pi: %f\n", *TWO_TIMES_THE_RECIPROCAL_OF_PI_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test two times the reciprocal of the square root of pi: %f\n", *TWO_TIMES_THE_RECIPROCAL_OF_THE_SQUARE_ROOT_OF_PI_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test square root of 2: %f\n", *SQUARE_ROOT_OF_2_DOUBLE_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Test reciprocal of the square root of 2: %f\n", *RECIPROCAL_OF_THE_SQUARE_ROOT_OF_2_DOUBLE_STATE_CYBOI_MODEL);
}

/**
 * Tests the constant values and usage.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_constant() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test constant usage.");

//    test_constant_float();
}

/* CONSTANT_TESTER */
#endif
