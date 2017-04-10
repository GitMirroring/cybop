/*
 * Copyright (C) 1999-2017. Christian Heller.

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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SLEEPER_TESTER
#define SLEEPER_TESTER

#include <assert.h>
#include "math.h"
#include "time.h"

#include "../../../src/constant/format/cyboi/logic_cyboi_format.c"
#include "../../../src/constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../src/executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../src/executor/memoriser/allocator/array_allocator.c"
#include "../../../src/executor/memoriser/deallocator/array_deallocator.c"
#include "../../../src/executor/copier/array_copier.c"
#include "../../../src/executor/modifier/array_modifier.c"
#include "../../../src/executor/modifier/part_modifier.c"
#include "../../../src/executor/comparator/all/part_all_comparator.c"
#include "../../../src/executor/runner/sleeper.c"

void test_sleep_duration() {

    void* dur = NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    void* type = SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT;

    time_t start = time(0);

    sleep_duration(dur, type);

    time_t end = time(0);

    int t = (int) difftime(end, start);

    assert(t >= *NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
}

int main() {

    test_sleep_duration();

    return 0;
}

/* SLEEPER_TESTER */
#endif
