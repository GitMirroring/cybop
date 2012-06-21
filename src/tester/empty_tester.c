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

#ifndef EMPTY_TESTER
#define EMPTY_TESTER

#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../executor/memoriser/size_determiner.c"
#include "../logger/logger.c"

//
// This is an empty test file.
// It is provided to test miscellaneous things
// which are not to be archived in subversion (svn).
//

/**
 * Tests something 1.
 */
void test_empty_1() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test empty 1.");

    // Add YOUR SOURCE CODE here!

    // Example:
    int a = 3;
    fwprintf(stdout, L"TEST a: %i\n", a);
}

/**
 * Tests something.
 */
void test_empty() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test empty.");

    // Uncomment below functions as needed,
    // in order for them to be executed.

    test_empty_1();
//    test_empty_2();
//    test_empty_3();
}

/* EMPTY_TESTER */
#endif
