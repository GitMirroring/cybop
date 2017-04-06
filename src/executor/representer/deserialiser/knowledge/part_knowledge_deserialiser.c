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

#ifndef PART_KNOWLEDGE_DESERIALISER_SOURCE
#define PART_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

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
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for stack variables
 */
void deserialise_knowledge_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge part.");

    // The new whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get new whole part.
    //
    // CAUTION! Forward the source whole part element INDEX p7 as argument here,
    // since it identifies the memory to retrieve the part from.
    deserialise_knowledge((void*) &w, p1, p2, p3, p4, p5, p6, p7);

    // Get element part.
    //
    // Process knowledge path hierarchy recursively further down,
    // using new whole part.
    //
    // CAUTION! Do NOT forward the source whole part element index p7 as argument here,
    // but NULL instead, since the next separator is unknown yet.
    deserialise_knowledge((void*) &e, (void*) &w, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL);

    //
    // CAUTION! The order of below comparisons IS IMPORTANT.
    // If an element (child) was found, then it has
    // higher priority than the whole (parent) found before.
    //

    if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The knowledge path contains another element to follow.

        // Take the element (child) as result.
        copy_pointer(p0, (void*) &e);

    } else if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The knowledge path does NOT contain further elements.
        // Its end has been reached.

        // Take the whole (parent) as result,
        // since it is the last existing part in the hierarchy.
        copy_pointer(p0, (void*) &w);
    }

    // If both, the whole and the element are null,
    // then nothing will be done and p0 remains untouched.
}

/* PART_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
