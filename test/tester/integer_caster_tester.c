/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_CASTER_TESTER
#define DOUBLE_CASTER_TESTER

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/caster/basic/integer/double_integer_caster.c"
#include "../../../../../logger/logger.c"
/**
 * Tests type caster double to integer.
 */
void test_caster_double_integer(){
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test caster double to integer.");

    int i = 0;
    double d = 5.0;

    fwprintf(stdout, L"TEST pre i: %i\n", i);
    fwprintf(stdout, L"TEST pre d: %f\n", d);

    cast_integer_double((void*) &i, (void*) &d);

    fwprintf(stdout, L"TEST post i: %i\n", i);
    fwprintf(stdout, L"TEST post d: %f\n", d);
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) &i);

    if (r !=  *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
        fwprintf(stdout, L"TEST successfull.\n");
    else
        fwprintf(stdout, L"TEST failed.\n");

}

/**
 * Tests type caster char to integer with type.
 */
void test_caster_char_integer_type() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test caster char to integer.");

    int i = 0;
    unsigned char c = '5';

    fwprintf(stdout, L"TEST pre i: %i\n", i);
    fwprintf(stdout, L"TEST pre c: %c\n", c);

    cast_integer((void*) &i, (void*)&c, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"TEST post i: %i\n", i);
    fwprintf(stdout, L"TEST post c: %c\n", c);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, (void*) NUMBER_53_INTEGER_STATE_CYBOI_MODEL, (void*) &i);

    if (r !=  *FALSE_BOOLEAN_STATE_CYBOI_MODEL)
        fwprintf(stdout, L"TEST successfull.\n");
    else
        fwprintf(stdout, L"TEST failed.\n");
}
/**
 * Tests type caster.
 */
void test_caster_integer() {
    // Uncomment below functions as needed,
    // in order for them to be executed.

    test_caster_double_integer();
    test_caster_char_integer_type();
}

/* DOUBLE_CASTER_TESTER */
#endif

