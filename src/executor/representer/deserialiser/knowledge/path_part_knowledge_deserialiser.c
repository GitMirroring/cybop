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

#ifndef PATH_PART_KNOWLEDGE_DESERIALISER_SOURCE
#define PATH_PART_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/accessor/getter/part_getter.c"
#include "../../../../executor/accessor/name_getter/part_name_getter.c"
#include "../../../../executor/comparator/basic/integer/smaller_or_equal_integer_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/modifier/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/cybol/integer/value_integer_cybol_deserialiser.c"
#include "../../../../executor/searcher/selector/knowledge/end_path_knowledge_selector.c"
#include "../../../../executor/searcher/selector/knowledge/end_part_knowledge_selector.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Deserialises a knowledge part by path.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the knowledge memory part
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 * @param p7 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for stack variables
 */
void deserialise_knowledge_part_path(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge part path.");

    // The name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The name part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // If a ")" delimiter is found, then the break flag is set to "true".
    // Otherwise, the position is just moved by one character forward.
    select_knowledge_path_end((void*) &b, p2, p3);

    // The closing parenthesis ")" indicating the end of
    // the path string data WAS found.

    // Get name part.
    //
    // CAUTION! Use the KNOWLEDGE MEMORY p4 as source whole part here,
    // since this is a new path whose elements are to be processed
    // starting from the knowledge memory tree root node.
    //
    // CAUTION! Do NOT forward the source whole part element index p7 as argument here,
    // but NULL instead, since the next separator is unknown yet.
    deserialise_knowledge((void*) &n, p4, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Get name part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get name part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Process knowledge path hierarchy recursively further down,
    // using new whole part.
    //
    // CAUTION! Forward the source whole part element index p7 as argument here,
    // since it identifies the memory to retrieve the part from.
    // The memory delimiter was determined before and
    // is still valid for the part name used here.
    select_knowledge_memory(p0, p1, nmd, nmc, p5, p7);
}

/* PATH_PART_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
