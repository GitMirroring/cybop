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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FLAG_JSON_DESERIALISER_SOURCE
#define FLAG_JSON_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/representer/deserialiser/json/member_json_deserialiser.c"
#include "../../../../executor/representer/deserialiser/json/string_json_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Evaluates the object flag.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the member name data
 * @param p5 the member name count
 * @param p6 the object flag (true if this is an object; false for array or otherwise the default)
 */
void deserialise_json_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise json flag.");
    fwprintf(stdout, L"Debug: Deserialise json flag. count remaining p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise json flag. count remaining *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Compare object flag.
    compare_integer_unequal((void*) &r, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a SIMPLE string representing either of:
        // - simple array element
        // - object member name
        // - object member value
        //

        deserialise_json_string(p0, p1, p2, p3, p4, p5);

    } else {

        //
        // This is an object member PAIR containing name and value.
        //

        deserialise_json_member(p0, p1, p2, p3);
    }
}

/* FLAG_JSON_DESERIALISER_SOURCE */
#endif
