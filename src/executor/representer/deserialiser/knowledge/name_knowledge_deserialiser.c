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

#ifndef NAME_KNOWLEDGE_DESERIALISER_SOURCE
#define NAME_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/accessor/name_getter/part_name_getter.c"
#include "../../../../executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/modifier/copier/pointer_copier.c"
#include "../../../../executor/searcher/selector/knowledge/end_part_knowledge_selector.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3);

/**
 * Gets a knowledge part by name.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the source whole part element index (one of:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties)
 */
void deserialise_knowledge_name(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge name.");

        // The break flag.
        int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The name string data, count.
        // CAUTION! This variable IS necessary, since the knowledge path data
        // position parametre is a pointer reference that cannot be handed over
        // to some of the functions below, which expect a simple pointer.
        // Also, the count has to be incremented below.
        void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
        int sc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Initialise name string data.
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

                // CAUTION! The function "select_knowledge_part_end" below
                // may have decremented the remaining count,
                // if neither a "." nor a "#" delimiter were found.
                //
                // This is regularly the case if a part was the
                // LAST IN THE HIERARCHY, having no further
                // child nodes to follow in the name.
                //
                // In order to also consider such parts, the
                // following function call IS NECESSARY here.
                //
                // CAUTION! In case the remaining count is too small
                // or zero (name does not exist) right at the beginning,
                // then the destination remains UNTOUCHED.

                // Get part with name from source whole part model OR properties,
                // depending on the source whole part element index p4.
                get_name_part_element(p0, p1, sd, (void*) &sc, p4);

                // CAUTION! There is NO USE in processing the knowledge hierarchy
                // recursively further down here, since the part was the
                // LAST IN THE HIERARCHY, having no further
                // child nodes to follow in the knowledge path.

                break;
            }

            // If a "." or "#" delimiter is found, then the break flag is set to "true".
            // Otherwise, the position is just moved by one character forward.
            select_knowledge_part_end((void*) &b, p2, p3);

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Get part with name from source whole part model OR properties,
                // depending on the source whole part element index p4.
                get_name_part_element(p0, p1, sd, (void*) &sc, p4);

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

                // The "." or "#" delimiter indicating the end of
                // the part name string data was not found.

                // Increment name string count.
                sc++;
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise knowledge name. The destination part is null.");
    }
}

/* NAME_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
