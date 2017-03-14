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

#ifndef INTEGER_CASTER_TESTER
#define INTEGER_CASTER_TESTER

#include <assert.h>

#include "../../../src/constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../src/constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../src/constant/type/cyboi/state_cyboi_type.c"
#include "../../../src/executor/caster/basic/double/integer_double_caster.c"
#include "../../../src/executor/caster/basic/double_caster.c"
#include "../../../src/executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/greater_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../src/executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../src/executor/memoriser/allocator/array_allocator.c"
#include "../../../src/executor/memoriser/deallocator/array_deallocator.c"
#include "../../../src/executor/modifier/copier/array_copier.c"
#include "../../../src/executor/modifier/emptier/array_emptier.c"
#include "../../../src/executor/modifier/overwriter/part_overwriter.c"

void cast_double_from_integer() {

    int i = 2;
    double d = 0.0;
    double expected = 2.0;

    cast_double_integer((void*) &d, (void*) &i);

    assert(expected == d);
}

void cast_double_integer_to_double_with_type() {

    int i = 2;
    double d = 0.0;
    int expected = 2;

    cast_double((void*) &d, (void*) &i, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    assert(expected == d);
}

int main() {

    cast_double_from_integer();
    cast_double_integer_to_double_with_type();

    return 0;
}

/* INTEGERS_CASTER_TESTER */
#endif
