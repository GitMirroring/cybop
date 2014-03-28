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
#ifndef BETWEEN_INTEGER_COMPARATOR_TESTER
#define BETWEEN_INTEGER_COMPARATOR_TESTER
//#include "../../../../../executor/comparator/basic/integer/between_integer_comparator.c"
void test_between_integer_comparator()
{
    fwprintf(stdout, L"TEST between integer comparator\n");
    int* lv = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    int* cv = NUMBER_10_INTEGER_STATE_CYBOI_MODEL;
    int* rv = NUMBER_100_INTEGER_STATE_CYBOI_MODEL;
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
        compare_integer_between((void*)&r, lv, rv, cv);
    }
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
        fwprintf(stdout, L"TEST between faild.\n");
    }
    else
        fwprintf(stdout, L"TEST between successfull.\n");
}
/* BETWEEN_INTEGER_COMPARATOR_TESTER */
#endif
