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
#ifndef CASTER_TESTER
#define CASTER_TESTER
#include "basic/integer/integer_double_caster_tester.c"
#include "basic/double/double_integer_caster_tester.c"
 void test_caster()
 {
	 fwprintf(stdout, L"TEST modul executor/caster/double.\n");
	 test_double_caster();
	 fwprintf(stdout, L"TEST modul executor/caster/integer.\n");
	 test_integer_caster();

 }
 /* DOUBLE_CASTER_TESTER */
 #endif
