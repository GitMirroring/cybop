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
 * along with CYBO/*
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
 * @author Christian Heller <christian.heller@tuxtax.de>l
 */

#ifndef CALCULATOR_TESTER
#define CALCULATOR_TESTER

#include <complex.h>

#include "../constant/format/cyboi/logic_cyboi_format.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../executor/calculator/basic/pointer_calculator.c"

/**
 * Tests the pointer calculation.
 */
void test_calculator_pointer() {

    int i = 10;
    void* p = (void*) &i;
//??    int p1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int p1 = *NUMBER_10_INTEGER_STATE_CYBOI_MODEL;

    fwprintf(stdout, L"Base adress: %i\n", p);

    calculate_pointer(&p, (void*) &p1, (void*) ADD_CALCULATE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"TEST calculator pointer add: %i\n", p);

    calculate_pointer(&p, (void*) &p1, (void*) SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"TEST calculator pointer subtract: %i\n", p);

//??    calculate_pointer(p, (void*) &p1, (void*) DIFFERENCE_CALCULATE_LOGIC_CYBOI_FORMAT);
    fwprintf(stdout, L"TEST calculator pointer difference: %i\n", p);
}

/**
 * Tests the calculator.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_calculator() {

    test_calculator_pointer();
}

/* CALCULATOR_TESTER */
#endif
