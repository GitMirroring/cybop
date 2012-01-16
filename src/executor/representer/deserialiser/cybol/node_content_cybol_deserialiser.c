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

#ifndef NODE_CONTENT_CYBOL_DESERIALISER_SOURCE
#define NODE_CONTENT_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../../executor/representer/deserialiser/cybol/root_node_cybol_deserialiser.c"
#include "../../../../executor/representer/deserialiser/cybol/standard_node_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the cybol node content.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the root part flag
 */
void deserialise_cybol_node_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol node content.");

fwprintf(stdout, L"TEST content: %i\n", p0);

    deserialise_cybol_node_standard(p0, p1, p2, p3, p4, p5);

/*??
    // The root node flag.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

//??    compare_integer_greater((void*) &r, p5, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    compare_integer_unequal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // This is a standard node and NOT the root node.

        deserialise_cybol_node_standard(p0, p1, p2, p3, p4, p5);

    } else {

        // This IS the root node.

        // Add the meta node model and properties directly
        // to root destination item.
        deserialise_cybol_node_root(p0, p1, p2, p5);
    }
*/
}

/* NODE_CONTENT_CYBOL_DESERIALISER_SOURCE */
#endif
