/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_NAME_GETTER_SOURCE
#define ARRAY_NAME_GETTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/searcher/name_finder/array_name_finder.c"
#include "../../../logger/logger.c"

/**
 * Gets the knowledge part by name, from the given whole array.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole data
 * @param p2 the part name data
 * @param p3 the part name count
 * @param p4 the source whole count
 */
void get_name_array(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get name array.");

    // The index of the searched part.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Determine index of searched part.
    find_name_array((void*) &i, p1, p2, p3, p4);

    if (i > *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

        // A part with the given name was found.

        // Get part at index from source whole part.
        copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
    }
}

/* ARRAY_NAME_GETTER_SOURCE */
#endif
