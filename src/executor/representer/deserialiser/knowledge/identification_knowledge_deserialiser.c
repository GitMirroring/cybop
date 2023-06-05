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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises a knowledge part identification (name or index).
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
 * @param p8 the index flag (true if index; false otherwise, i.e. name)
 */
void deserialise_knowledge_identification(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge identification.");

    // The name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Get name part.
    //
    // CAUTION! Use the KNOWLEDGE MEMORY p4 as source whole part here,
    // since this is a new path whose elements are to be processed
    // starting from the knowledge memory tree root node.
    //
    // CAUTION! Hand over the knowledge memory as REFERENCE,
    // since it might get copied inside.
    //
    // CAUTION! Do NOT forward the source whole part element index p7 as argument here,
    // but NULL instead, since the next separator is unknown yet.
    //
    deserialise_knowledge((void*) &n, p4, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Get name part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get name part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Get destination part with the given identification
    // from source whole part model OR properties OR stack memory,
    // depending on the source whole part element index p7.
    //
    // CAUTION! Forward the source whole part element index p7 as argument here,
    // since it identifies the memory to retrieve the part from.
    // The memory delimiter was determined before and
    // is still valid for the part name used here.
    //
    select_knowledge_identification(p0, p1, nmd, nmc, p5, p7, p8);
}
