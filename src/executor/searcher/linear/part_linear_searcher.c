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

#ifndef PART_LINEAR_SEARCHER_SOURCE
#define PART_LINEAR_SEARCHER_SOURCE

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Searches within the part's name OR model, depending on the given model flag.
 *
 * @param p0 the found flag (set to TRUE if found; unchanged otherwise)
 * @param p1 the part array (list data position)
 * @param p2 the model flag (false = name, true = model)
 * @param p3 the searchword data
 * @param p4 the searchword count
 * @param p5 the searchword type
 */
void search_linear_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Search linear part.");
    //?? fwprintf(stdout, L"Debug: Search linear part. model flag p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Search linear part. model flag *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Search linear part. data position *pos: %i\n", *pos);

    //
    // The part.
    //
    // CAUTION! The parametre handed over is an ARRAY of pointers to the single parts.
    // Therefore, this parametre has to be DEREFERENCED in order to get the actual part.
    // In order to achieve this, the FIRST pointer at index ZERO is copied below.
    //
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The index.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Get part at index ZERO.
    copy_array_forward((void*) &p, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    // Compare if part name (false) or model (true) is to be retrieved.
    compare_integer_unequal((void*) &r, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Search part name
        //

        search_linear_name((void*) &i, p, p3, p4, p5);

    } else {

        //
        // Search within part model
        //

        search_linear_model((void*) &i, p, p3, p4, p5);
    }

    if (i >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        //
        // The given searchword has been found.
        //

        // Set found flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* PART_LINEAR_SEARCHER_SOURCE */
#endif
