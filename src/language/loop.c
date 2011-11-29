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

#ifndef LOOP_SOURCE
#define LOOP_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/representer/serialiser/model_diagram_serialiser.c"
#include "../../../executor/searcher/mover/position_mover.c"
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
