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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARITHMETISER_TESTER
#define ARITHMETISER_TESTER

#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../logger/logger.c"

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

    fwprintf(stdout, L"TEST - Add 3 to 4 (expect 7):\n");
    
    // Add integer to integer.
    calculate_integer_add((void*) &i, (void*) &s);

    if (i == 7) {
        
        fwprintf(stdout, L"OK - integer addition result: %i\n", i);
    }    
    else {

        fwprintf(stdout, L"ERROR - expected 7 but was %i\n", i);
    }

    fwprintf(stdout, L"TEST - Add 3 to pointer");
    fwprintf(stdout, L"Pointer original: %i\n", p);
    
    // Add integer to pointer.
    calculate_integer_add((void*) &p, (void*) &s);
    
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

    fwprintf(stdout, L"TEST arithmetiser.\n");

    test_arithmetiser_integer_adder();
    test_arithmetiser_multiplicator();
}

/* ARITHMETISER_TESTER */
#endif
