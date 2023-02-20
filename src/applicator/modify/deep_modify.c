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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DEEP_MODIFY_SOURCE
#define DEEP_MODIFY_SOURCE

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/modifier/part_modifier.c"
#include "../../logger/logger.c"

/**
 * Determines the correct deep copying flag, depending on the given "move" flag.
 *
 * @param p0 the destination part
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the move flag (NOT deep copying flag)
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 * @param p7 the adjust count flag
 * @param p8 the repetition number for "modify/repeat"
 * @param p9 the searchterm data for "modify/replace"
 * @param p10 the searchterm count for "modify/replace"
 * @param p11 the operation type
 * @param p12 the destination part item index
 * @param p13 the source part item index
 * @param p14 the source part
 */
void apply_modify_deep(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply modify deep.");
    //?? fwprintf(stdout, L"Debug: Apply modify deep. move flag (NOT deep copying flag) p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Apply modify deep. move flag (NOT deep copying flag) *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! Do NOT easily change the compare logic here.
    // The "move" flag might be null, since it is optional.
    // Comparison ignores null values inside,
    // so that the comparison result remains unchanged.
    //
    compare_integer_unequal((void*) &r, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The "move" flag is NOT set.
        //
        // Therefore, DEEP copying is used (if applicable to the operation).
        //

        //
        // Modify part by applying operation.
        //
        // CAUTION! Set deep copying flag to TRUE.
        //
        modify_part(p0, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p4, p5, p6, p7, p8, p9, p10, p11, p12);

    } else {

        //
        // The "move" flag IS set.
        //
        // Therefore, SHALLOW copying is used (if applicable to the operation).
        // That is, only pointers/references to child nodes get copied,
        // but not their sub trees (children of children).
        // Afterwards, the source elements get REMOVED,
        // i.e. only pointers/references, but not allocated memory.
        // This is no problem, since the destination now holds
        // pointers/references to the original child nodes.
        //

        //
        // Modify part by applying operation.
        //
        // CAUTION! Set deep copying flag to FALSE.
        //
        modify_part(p0, p1, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p4, p5, p6, p7, p8, p9, p10, p11, p12);

        //
        // Remove elements from source part.
        //
        // CAUTION! Set the adjust count flag to TRUE since otherwise,
        // the destination item will hold a wrong "count" number
        // leading to unpredictable errors in further processing.
        //
        modify_part(p14, *NULL_POINTER_STATE_CYBOI_MODEL, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p4, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT, p13);
    }
}

/* DEEP_MODIFY_SOURCE */
#endif
