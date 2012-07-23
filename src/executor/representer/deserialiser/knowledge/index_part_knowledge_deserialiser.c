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

#ifndef INDEX_PART_KNOWLEDGE_DESERIALISER_SOURCE
#define INDEX_PART_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/accessor/getter/part_getter.c"
#include "../../../../executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/modifier/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/cybol/integer/value_integer_cybol_deserialiser.c"
#include "../../../../executor/searcher/selector/knowledge/end_index_knowledge_selector.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3);

/**
 * Gets a knowledge part by index.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the source whole part element index (one of:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties)
 */
void deserialise_knowledge_part_index(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge part index.");

        // The break flag.
        int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The index string data, count.
        // CAUTION! This variable IS necessary, since the knowledge path data
        // position parametre is a pointer reference that cannot be handed over
        // to some of the functions below, which expect a simple pointer.
        // Also, the count has to be incremented below.
        void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
        int sc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The index item.
        void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The index item data.
        void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Initialise index string data.
        copy_pointer((void*) &sd, p2);

        if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

            compare_integer_smaller_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                break;
            }

            // If a "]" delimiter is found, then the break flag is set to "true".
            // Otherwise, the position is just moved by one character forward.
            select_knowledge_index_end((void*) &b, p2, p3);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Allocate temporary index item.
                // CAUTION! Initialise integer items with a size of ONE,
                // in order to avoid later reallocation when overwriting
                // the element and to thus increase efficiency.
                allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

                // Deserialise index.
                deserialise_cybol_integer_value(i, sd, (void*) &sc, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

                // Get temporary index item data.
                // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                // Inside the structure, arrays may have been reallocated,
                // with elements pointing to different memory areas now.
                copy_array_forward((void*) &id, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

                // Get part with index from source whole part model OR properties,
                // depending on the source whole part element index p4.
                //
                // CAUTION! Do NOT use the following commented function,
                // since it is low-level and does not check array boundaries.
                // copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, id);
                get_part_element(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, id, p4);

                // Deallocate temporary index item.
                deallocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

                // Process knowledge hierarchy recursively further down.
                //
                // CAUTION! The current p0 is the SOURCE AND DESTINATION!
                // A part node of the source p1 was assigned to p0 above,
                // so that p0 is now the source.
                // If it has a child part, then that will be assigned to the
                // destination. Otherwise, the destination remains UNTOUCHED.
                //
                // CAUTION! Hand over the source as DEREFERENCED parametre!
                deserialise_knowledge(p0, *d, p2, p3);

                break;

            } else {

                // The closing bracket "]" indicating the end of
                // the index string data was not found.

                // Increment index string count.
                sc++;
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise knowledge part index. The destination part is null.");
    }
}

/* INDEX_PART_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
