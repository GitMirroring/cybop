/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef REFERENCE_KNOWLEDGE_DESERIALISER_SOURCE
#define REFERENCE_KNOWLEDGE_DESERIALISER_SOURCE

//
// Executable interface
//

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/knowledge/element_knowledge_deserialiser.c"
#include "logger.h"

//
// Forbidden includes
//
// CAUTION! Do NOT include the following files since otherwise,
// circular references would occur due to module dependencies.
// Instead, forward declarations are used further below.
// Therefore, the following includes are to be commented OUT
// and listed here just for information.
//

// #include "../../../../executor/representer/deserialiser/knowledge/knowledge_deserialiser.c"

//
// Forward declarations
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

/**
 * Deserialises a knowledge reference.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 */
void deserialise_knowledge_reference(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge reference.");

    // The knowledge path part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The knowledge path part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The knowledge path part model item data, count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary knowledge path data, count.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    int tc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Get knowledge path part.
    //
    // CAUTION! Do NOT forward the source whole part element index p7 as argument here,
    // but NULL instead, since it has no influence anyway.
    //
    deserialise_knowledge((void*) &p, p1, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Get knowledge path part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get knowledge path part model item data, count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Copy knowledge path part model item data, count
    // to temporary knowledge path data, count.
    //
    // CAUTION! It IS NECESSARY to forward a COPY of pmd and pmc below.
    // Otherwise, the original knowledge part would get modified,
    // with its count being decremented to zero, leading to false results.
    // For example, multiple references would not be processed in this case.
    //
    copy_pointer((void*) &td, (void*) &pmd);
    copy_integer((void*) &tc, pmc);

    // The new whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Get destination part using knowledge path part determined above.
    //
    // CAUTION! Hand over td as REFERENCE.
    //
    // CAUTION! Do NOT forward the source whole part element index p7 as argument,
    // but NULL instead, since it has no influence anyway.
    //
    deserialise_knowledge((void*) &w, p1, (void*) &td, (void*) &tc, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

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

/* REFERENCE_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
