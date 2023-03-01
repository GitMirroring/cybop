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
 * Christian Heller <christian.heller@cybop.org>
 *
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CRITERION_BUBBLE_SORTER_SOURCE
#define CRITERION_BUBBLE_SORTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../executor/representer/deserialiser/knowledge/knowledge_deserialiser.c"
#include "../../../logger/logger.c"

/*
 * Determines the left- and right part using the given comparison criterion.
 *
 * The comparison criterion is a path to some value belonging to a part.
 * For example, the title of a song (in a list of songs to be sorted).
 *
 * @param p0 the destination left part (pointer reference)
 * @param p1 the destination right part (pointer reference)
 * @param p2 the source left part (pointer reference)
 * @param p3 the source right part (pointer reference)
 * @param p4 the criterion data (pointer reference)
 * @param p5 the criterion count
 * @param p6 the criterion type
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 */
void sort_bubble_criterion(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sort bubble criterion.");

    // The left source data position and source count remaining.
    void* lpos = *NULL_POINTER_STATE_CYBOI_MODEL;
    int lrem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The right source data position and source count remaining.
    void* rpos = *NULL_POINTER_STATE_CYBOI_MODEL;
    int rrem = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! The left and right source data position gets copied and
        // used independently, since it is handed over as pointer reference
        // and gets manipulated inside the "deserialise_knowledge" function.
        //

        // Initialise left source data position and source count remaining.
        copy_pointer((void*) &lpos, p4);
        copy_integer((void*) &lrem, p5);
        // Initialise right source data position and source count remaining.
        copy_pointer((void*) &rpos, p4);
        copy_integer((void*) &rrem, p5);

        // Get left part.
        deserialise_knowledge(p0, p2, (void*) &lpos, (void*) &lrem, p7, p8, p9, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
        // Get right part.
        deserialise_knowledge(p1, p3, (void*) &rpos, (void*) &rrem, p7, p8, p9, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    } else {

        fwprintf(stdout, L"Error: Could not sort bubble part. The comparison criterion type is not WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE.");
        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sort bubble part. The comparison criterion type is not WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE.\n");
    }
}

/* CRITERION_BUBBLE_SORTER_SOURCE */
#endif
