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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CASTER_TESTER
#define CASTER_TESTER

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/caster/double/integer_double_caster.c"
#include "../logger/logger.c"

/**
 * Tests type caster double integer.
 */
void test_caster_double_integer() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test caster double integer.");

    int i = 5;
    double d = 0.0;

    fwprintf(stdout, L"TEST pre i: %i\n", i);
    fwprintf(stdout, L"TEST pre d: %f\n", d);

    cast_double_integer((void*) &d, (void*) &i);

    fwprintf(stdout, L"TEST post i: %i\n", i);
    fwprintf(stdout, L"TEST post d: %f\n", d);
}

/**
 * Tests type caster.
 */
void test_caster() {

//    fwprintf(stdout, L"TEST caster.\n");

    // Uncomment below functions as needed,
    // in order for them to be executed.

//    test_caster_double_integer();
}

/* CASTER_TESTER */
#endif
