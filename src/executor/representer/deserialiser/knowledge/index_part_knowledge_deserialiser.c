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

#ifndef INDEX_PART_KNOWLEDGE_DESERIALISER_SOURCE
#define INDEX_PART_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/part_getter.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Deserialises a knowledge part by index.
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
void deserialise_knowledge_part_index(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge part index.");

    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get index part.
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
    deserialise_knowledge((void*) &i, p4, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get index part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get destination part with the given index
    // from source whole part model OR properties OR stack memory,
    // depending on the source whole part element index p7.
    //
    // CAUTION! Forward the source whole part element index p7 as argument here,
    // since it identifies the memory to retrieve the part from.
    // The memory delimiter was determined before and
    // is still valid for the part index used here.
    //
    // CAUTION! The stack memory argument p5 is NOT needed here,
    // since it is forbidden to access arbitrary stack variables via index.
    // Otherwise, the whole stack order might get ignored,
    // which is not wanted.
    //
    // CAUTION! Do NOT use the "copy_array_forward" function,
    // since it is low-level and does not check array boundaries!
    get_part_metadata(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, imd, p7);
}

/* INDEX_PART_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
