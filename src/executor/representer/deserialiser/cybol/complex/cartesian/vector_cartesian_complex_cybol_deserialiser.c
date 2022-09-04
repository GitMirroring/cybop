/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef VECTOR_CARTESIAN_COMPLEX_CYBOL_DESERIALISER_SOURCE
#define VECTOR_CARTESIAN_COMPLEX_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/representer/deserialiser/cybol/complex/cartesian/element_cartesian_complex_cybol_deserialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the double data into a complex item.
 *
 * @param p0 the destination complex item
 * @param p1 the source double data
 * @param p2 the source double count
 */
void deserialise_cybol_complex_cartesian_vector(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol complex cartesian vector.");

    // The loop variables.
    // CAUTION! They serve as index for
    // accessing the complex number data:
    // i - real part
    // j - imaginary part (with initial value of ONE)
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int j = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! The comparison of j suffices here,
        // since if j is greater or equal the source count,
        // then also i is.
        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        deserialise_cybol_complex_cartesian_element(p0, p1, (void*) &i, (void*) &j);

        // Increment loop variable.
        calculate_integer_add((void*) &i, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
        calculate_integer_add((void*) &j, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* VECTOR_CARTESIAN_COMPLEX_CYBOL_DESERIALISER_SOURCE */
#endif
