/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REPRESENTER_TESTER
#define REPRESENTER_TESTER

#include "serialiser/serialiser_tester.c"
#include "deserialiser/deserialiser_tester.c"

/**
 * Tests the representer.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_representer() {

    fwprintf(stdout, L"TEST executor/representer/deserialiser\n");
    //test_deserialiser();
    fwprintf(stdout, L"TEST executor/representer/serialiser\n");
    test_serialiser();
}

/* REPRESENTER_TESTER */
#endif
