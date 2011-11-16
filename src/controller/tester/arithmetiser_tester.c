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

#ifndef ARITHMETISER_TESTER
#define ARITHMETISER_TESTER

#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Tests the arithmetiser integer adder.
 */
void test_arithmetiser_integer_adder() {

    // The integer number.
    int i = *NUMBER_4_INTEGER_STATE_CYBOI_MODEL;
    // Some test variable with no meaning, to create a pointer.
    int test = *NUMBER_298_INTEGER_STATE_CYBOI_MODEL;
    // The pointer.
    void* p = (void*) &test;
    // The summand integer number.
    int s = *NUMBER_3_INTEGER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"Pointer original: %i\n", p);

    // Add integer to integer.
    calculate_integer_add((void*) &i, (void*) &s);
    // Add integer to pointer.
    calculate_integer_add((void*) &p, (void*) &s);

    fwprintf(stdout, L"Integer addition result: %i\n", i);
    fwprintf(stdout, L"Pointer addition result: %i\n", p);
}

/**
 * Tests the arithmetiser multiplicator.
 */
void test_arithmetiser_multiplicator() {

    // The integer number.
    int i = *NUMBER_3_INTEGER_STATE_CYBOI_MODEL;
    // The factor integer number.
    int f = *NUMBER_4_INTEGER_STATE_CYBOI_MODEL;

    // Multiply integer with integer.
    calculate_integer_multiply((void*) &i, (void*) &f);

    fwprintf(stdout, L"Multiplication result: %i\n", i);
}

/**
 * Tests the arithmetiser.
 */
void test_arithmetiser() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test arithmetiser.");

//    test_arithmetiser_integer_adder();
//    test_arithmetiser_multiplicator();
}

/* ARITHMETISER_TESTER */
#endif
