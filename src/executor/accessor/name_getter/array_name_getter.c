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

#include "algorithm.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Gets the knowledge part by name, from the given whole array.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole data (pointer reference)
 * @param p2 the part name data
 * @param p3 the part name count
 * @param p4 the source whole count
 * @param p5 the lifo flag (use last-in-first-out instead of first-in-first-out)
 */
void get_name_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get name array.");

    // The index of the searched part.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Determine index of searched part.
    //
    // CAUTION! Set perfect match flag (second-last argument) to TRUE so that
    // equal counts of searchword and searched child nodes are requested.
    //
    search_linear((void*) &i, p1, p4, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p5);

    if (i > *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

        //
        // A part with the given name was found.
        //

        // Get part at index from source whole part.
        copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
    }
}
