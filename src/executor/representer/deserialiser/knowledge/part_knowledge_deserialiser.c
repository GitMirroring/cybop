/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "cybol.h"
#include "logger.h"

/**
 * Deserialises a knowledge part.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 * @param p7 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts on heap
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties on heap
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for variables on stack
 *           - *NULL_POINTER_STATE_CYBOI_MODEL if none of the above applies
 */
void deserialise_knowledge_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge part.");
    //?? fwprintf(stdout, L"Debug: Deserialise knowledge part. knowledge path data position: %ls\n", (wchar_t*) *((void**) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise knowledge part. knowledge path count remaining: %i\n", *((int*) p3));

    // The new whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Get new whole part.
    //
    // CAUTION! Forward the source whole part element INDEX p7 as argument here,
    // since it identifies the memory to retrieve the part from.
    //
    deserialise_knowledge((void*) &w, p1, p2, p3, p4, p5, p6, p7, *NULL_POINTER_STATE_CYBOI_MODEL);

    if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A new whole (parent) EXISTS.
        //
        // Hand it over as new parent node.
        // Further processing of the knowledge path makes sense.
        //
        // CAUTION! If the whole (parent) node has a NULL value,
        // then NOTHING is done here. However, it may be REGULAR behaviour
        // in a cybol application since sometimes, knowledge paths
        // may point to NON-EXISTING nodes.
        //

        deserialise_knowledge_element(p0, (void*) &w, p2, p3, p4, p5, p6);
    }
}
