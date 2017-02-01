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

#ifndef INDEX_KNOWLEDGE_DESERIALISER_SOURCE
#define INDEX_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/part_getter.c"
#include "../../../../executor/representer/deserialiser/cybol/integer/primitive_value_integer_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Gets a knowledge part by index.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the part name data
 * @param p3 the part name count
 * @param p4 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for stack variables
 */
void deserialise_knowledge_index(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** s = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge index.");

        // The index.
        int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        // Deserialise string into integer.
        deserialise_cybol_integer_value_primitive((void*) &i, p2, p3, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        // Get part with index from source whole part model OR properties,
        // depending on the source whole part element index p5.
        //
        // CAUTION! Do NOT use the "copy_array_forward" function,
        // since it is low-level and does not check array boundaries!
        get_part_metadata(p0, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i, p4);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise knowledge index. The source whole part is null.");
    }
}

/* INDEX_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
