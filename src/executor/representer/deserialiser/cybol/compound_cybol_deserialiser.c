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
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source xml tree OR json tree OR xml or json filestream model data
 * @param p3 the source xml tree OR json tree OR xml or json filestream model count
 * @param p4 the source xml tree OR json tree properties data (currently NOT in use but left here anyway)
 * @param p5 the source xml tree OR json tree properties count
 * @param p6 the language properties (constraints) data
 * @param p7 the language properties (constraints) count
 * @param p8 the knowledge memory part (pointer reference)
 * @param p9 the stack memory item
 * @param p10 the internal memory data
 * @param p11 the language
 * @param p12 the decimal separator data
 * @param p13 the decimal separator count
 * @param p14 the thousands separator data
 * @param p15 the thousands separator count
 * @param p16 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p17 the root node flag
 * @param p18 the initial fileread flag
 * @param p19 the format
 */
void deserialise_cybol_compound(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol compound.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol compound. format p19: %i\n", p19);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol compound. format *p19: %i\n", *((int*) p19));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p18, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a subsequent processing.
        //
        // The data HAVE BEEN parsed from xml or json BEFORE and
        // are now already available as knowledge tree structure,
        // so that they can be used AS THEY ARE.
        //

        //?? fwprintf(stdout, L"Debug: Deserialise cybol compound. subsequent processing (no reading from xml or json) r: %i\n", r);

        //
        // step 1: xml or json
        //
        // This step is NOT NECESSARY, since data have been parsed from xml or json before.
        //
        // deserialise_cybol_decision(m, p, p2, p3, p6, p7, p8, p9, p10, p11);
        //

        //
        // step 2: cybol
        //

        deserialise_cybol_destination(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19);

    } else {

        //
        // This is the initial fileread.
        //
        // The data YET HAVE TO be parsed from xml or json.
        //

        //?? fwprintf(stdout, L"Debug: Deserialise cybol compound. initial fileread (parsing from xml or json) r: %i\n", r);

        //
        // Reset initial fileread flag.
        //
        // If a knowledge tree is stored in just ONE file (e.g. in json format) instead of
        // in many (e.g. in xml format), then it needs to be read from file just ONCE,
        // but NOT again for each of its child nodes.
        //
        // This is achieved by using this flag, which is initially set to TRUE
        // in file "constraints_cybol_deserialiser.c" and gets reset to FALSE
        // in file "compound_cybol_deserialiser.c", after having read the data from file.
        //
        copy_integer(p18, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Declaration
        //

        // The temporary source xml tree OR json tree model, properties item.
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The temporary source xml tree OR json tree model, properties data, count.
        void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Allocation
        //

        //
        // Allocate temporary source xml tree OR json tree model, properties item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &m, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
        allocate_item((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        //
        // Deserialisation
        //

        //
        // step 1: xml or json
        //

        // Deserialise source message from xml or json into temporary source xml tree OR json tree model, properties item.
        deserialise_cybol_decision(m, p, p2, p3, p6, p7, p8, p9, p10, p11);

        //?? TESTING ONLY BEGIN
        //?? #include "inspector.h"
        //?? fwprintf(stdout, L"Debug: Deserialise cybol compound. inspect temporary source xml tree OR json tree model item m: %i\n", m);
        //?? inspect_knowledge_item((void*) L"inspect_1_initial_fileread_xml", (void*) NUMBER_30_INTEGER_STATE_CYBOI_MODEL, m, p8, p9, p10);
        //?? TESTING ONLY END

        //
        // Get temporary source xml tree OR json tree model, properties data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        //
        // step 2: cybol
        //

        deserialise_cybol_destination(p0, p1, md, mc, pd, pc, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19);

        //?? TESTING ONLY BEGIN
        //?? #include "inspector.h"
        //?? fwprintf(stdout, L"Debug: Deserialise cybol compound. inspect destination model item p0: %i\n", p0);
        //?? inspect_knowledge_item((void*) L"inspect_2_subsequent_processing_cybol", (void*) NUMBER_37_INTEGER_STATE_CYBOI_MODEL, m, p8, p9, p10);
        //?? TESTING ONLY END

        //
        // Deallocation
        //

        // Deallocate temporary source xml tree OR json tree model, properties item.
        deallocate_item((void*) &m, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
        deallocate_item((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    }
}
