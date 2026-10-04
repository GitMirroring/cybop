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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises a knowledge path retrieving the specified part.
 *
 * @param p0 the destination name or part (pointer reference)
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
 * @param p8 the knowledge path end flag
 */
void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge.");
    //?? fwprintf(stdout, L"Debug: deserialise knowledge *p3: %i\n", *((int*) p3));
    //?? fwprintf(stdout, L"Debug: deserialise knowledge *p2: %ls\n", (wchar_t*) *((void**) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Compare if knowledge path count remaining contains at least one character.
    //
    // CAUTION! This comparison IS IMPORTANT and has to be done right HERE.
    // The knowledge path count remaining p3 is NOT checked by
    // the "detect_array" functions inside "select_knowledge_begin".
    //
    // CAUTION! Use a GREATER comparison and NOT smaller or equal etc.
    // In case p3 is null, the comparison result r remains false that way.
    //
    compare_integer_greater((void*) &r, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The knowledge path contains FURTHER characters.
        //

        select_knowledge_root(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    } else {

        //
        // The knowledge path END has been reached.
        //

        //
        // Set knowledge path end flag.
        //
        // CAUTION! Setting this flag IS IMPORTANT
        // for deciding whether to assign the whole (parent) or
        // element (child) node in file "part_knowledge_deserialiser.c".
        //
        // There are two files, where the end flag is set:
        // 1) knowledge_deserialiser.c
        // 2) end_knowledge_selector.c
        //
        // Case 1 applies, when the absolute end of the knowledge path
        // has been reached, i.e. count remaining is zero.
        //
        // Case 2 applies, when a SUB PATH was used:
        // - either as name, like e.g. "(.some.path)"
        // - or as index, like e.g. "[#some_index_on_stack]"
        // and the end of that sub path has been reached:
        // - either a ")"
        // - or a "]"
        //
        copy_integer(p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}
