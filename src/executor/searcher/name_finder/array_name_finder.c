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

#ifndef ARRAY_NAME_FINDER_SOURCE
#define ARRAY_NAME_FINDER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/calculator/integer_adder.c"
#include "../../../executor/calculator/integer_multiplier.c"
#include "../../../executor/memoriser/offset_adder.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../executor/modifier/copier/value_copier.c"
#include "../../../logger/logger.c"

/**
 * Finds a part with the given name in the investigated array.
 *
 * @param p0 the index (if found; unchanged otherwise)
 * @param p1 the investigated array (each element pointing to a part)
 * @param p2 the searched name array
 * @param p3 the searched name array count
 * @param p4 the investigated array count
 */
void find_name_array(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* c = (int*) p4;

        log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Find name array.");

        // The loop variable.
        int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The part.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The comparison result.
        int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (j >= *c) {

                // The maximum loop count has been reached.
                // All elements have been compared.
                // A part with the searched name could not be found.
                // Leave index untouched.

                break;
            }

            // Get part j from investigated pointer array p1.
            copy_array_forward((void*) &p, p1, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) &j);
            // Compare part p name item with given name p2.
            compare_all_part_element((void*) &r, p, p2, (void*) EQUAL_PRIMITIVE_OPERATION_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE, p3, (void*) NAME_PART_MEMORY_NAME);

            if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // The part with the searched name has been found.

                // Remember the index.
                copy_integer(p0, (void*) &j);

                // The loop may be left now.
                break;
            }

            j++;
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not find name array. The array is null.");
    }
}

/* ARRAY_NAME_FINDER_SOURCE */
#endif
