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
#ifndef CALCULATOR_SOURCE
#define CALCULATOR_SOURCE
#include "basic/integer/arithmetiser_tester.c"
#include "basic/pointer/pointer_calculator_tester.c"
#include "basic/integer/integer_calculator_tester.c"
void test_calculator()
{
    fwprintf(stdout, L"TEST Modul executor/calculator/integer.\n");
    test_arithmetiser();
    test_integer_calculator();
    fwprintf(stdout, L"TEST Modul executor/calculator/pointer.\n");
    test_pointer();

}
/* CALCULATOR_SOURCE */
#endif
