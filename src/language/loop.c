/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LOOP_SOURCE
#define LOOP_SOURCE

#include "../../../executor/representer/serialiser/model_diagram_serialiser.c"
#include "../../../executor/mover/mover.c"
#include "../../../logger/logger.c"
#include "../../../variable/type_size/integral_type_size.c"

/**
 * Loops the given source code.
 *
 * @param p0 the break flag
 * @param p1 the loop count
 * @param p2 the loop variable
 * @param p3 the body function
 * @param p4 the body function parametre
 */
void loop(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    // Loop as long as break flag is NOT set.
    while (!(*((int*) p0))) {

        // Test break condition.
        compare_integer_greater_or_equal(p0, p2, p1);

        // Dereference and call function.
        (*((void (*)(void*)) p3))(p4);

        // Increment loop variable.
        calculate_integer_add(p2, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* LOOP_SOURCE */
#endif
