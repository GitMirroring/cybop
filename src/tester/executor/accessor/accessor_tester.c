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

#ifndef ACCESSOR_TESTER
#define ACCESSOR_TESTER
#include "getter/datetime_getter_tester.c"
#include "getter/duration_getter_tester.c"
#include "getter/complex_getter_tester.c"
#include "getter/fraction_getter_tester.c"
#include "getter/getter_tester.c"

void test_accessor(){
    fwprintf(stdout, L"Test executer/accessor/getter/datetime.\n");
    test_datetime_getter();
    fwprintf(stdout, L"Test executer/accessor/getter/complex.\n");
    test_complex_getter();
    fwprintf(stdout, L"Test executer/accessor/getter/duration.\n");
    test_duration_getter();
    fwprintf(stdout, L"Test executer/accessor/getter/duration.\n");
    test_fraction_getter();
    fwprintf(stdout, L"Test executer/accessor/getter/get.\n");
    test_getter();
}

/* ACCESSOR_TESTER */
#endif
