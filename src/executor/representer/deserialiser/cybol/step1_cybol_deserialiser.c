/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

//
// Representer interface
//

#include "cybol.h"

/**
 * Deserialises the cybol compound element (part or property).
 *
 * @param p0 the temporary model data (pointer reference)
 * @param p1 the temporary model count (pointer reference)
 * @param p2 the temporary properties data (pointer reference)
 * @param p3 the temporary properties count (pointer reference)
 * @param p4 the temporary model item
 * @param p5 the temporary properties item
 * @param p6 the source model data (pointer reference)
 * @param p7 the source model count (pointer reference)
 * @param p8 the source properties data (pointer reference)
 * @param p9 the source properties count (pointer reference)
 * @param p10 the source model data
 * @param p11 the source model count
 * @param p12 the language properties (constraints) data
 * @param p13 the language properties (constraints) count
 * @param p14 the knowledge memory part (pointer reference)
 * @param p15 the stack memory item
 * @param p16 the internal memory data
 * @param p17 the language
 * @param p18 the initial fileread flag
 */
void deserialise_cybol_step1(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol step1.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol step1. initial fileread flag p18: %i\n", p18);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol step1. initial fileread flag *p18: %i\n", *((int*) p18));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p18, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a subsequent processing.
        //
        // The data have been parsed from xml or json BEFORE and
        // are now already available as knowledge tree structure,
        // so that they can be used as they are.
        //

        // Take given model and properties AS THEY ARE.
        copy_pointer(p0, p6);
        copy_pointer(p1, p7);
        copy_pointer(p2, p8);
        copy_pointer(p3, p9);

    } else {

        //
        // This is the initial fileread.
        //
        // The data yet have to be parsed from xml or json NOW.
        //

        //
        // Reset initial fileread flag.
        //
        // If a knowledge tree is stored in just ONE file (e.g. in json format) instead of
        // in many (e.g. in xml format), then it needs to be read from file just ONCE,
        // but NOT again for each of its child nodes.
        //
        // This is achieved by using this flag, which is initially set to TRUE
        // in file "constraints_cybol_deserialiser.c" and gets reset to FALSE
        // in file "step1_cybol_deserialiser.c", after having read the data from file.
        //
        copy_integer(p18, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Deserialise source message from xml or json into temporary model, properties item.
        deserialise_cybol_decision(p4, p5, p10, p11, p12, p13, p14, p15, p16, p17);

        //
        // Get temporary model, properties data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward(p0, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward(p1, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        copy_array_forward(p2, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward(p3, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    }
}
