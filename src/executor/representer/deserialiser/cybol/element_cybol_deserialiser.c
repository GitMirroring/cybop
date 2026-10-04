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

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

//
// Representer interface
//

#include "cybol.h"

/**
 * Deserialises the cybol part element.
 *
 * @param p0 the destination model OR properties item
 * @param p1 the source xml tree OR json tree model data
 * @param p2 the source xml tree OR json tree model index (NOT count)
 * @param p3 the source xml tree OR json tree properties data (currently NOT in use but left here anyway)
 * @param p4 the source xml tree OR json tree properties count
 * @param p5 the language properties (constraints) data
 * @param p6 the language properties (constraints) count
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 * @param p10 the language
 * @param p11 the decimal separator data
 * @param p12 the decimal separator count
 * @param p13 the thousands separator data
 * @param p14 the thousands separator count
 * @param p15 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p16 the root node flag
 * @param p17 the initial fileread flag
 */
void deserialise_cybol_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol element.");
    //?? fwprintf(stdout, L"\nDebug: Deserialise cybol element. index p2: %i\n", p2);
    //?? fwprintf(stdout, L"\nDebug: Deserialise cybol element. index *p2: %i\n", *((int*) p2));

    //
    // Declaration
    //

    // The source xml tree OR json tree child part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source xml tree OR json tree child part model, properties.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source xml tree OR json tree child part model, properties data, count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ppd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ppc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get source xml tree OR json tree child part with given INDEX.
    copy_array_forward((void*) &p, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    // Get source xml tree OR json tree child part model, properties.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get source xml tree OR json tree child part model, properties data, count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ppd, pp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ppc, pp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Branching
    //

    // Compare with root flag.
    compare_integer_equal((void*) &r, p16, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a standard node.
        //

        //?? fwprintf(stdout, L"\nDebug: Deserialise cybol element. TEST: standard node r: %i\n", r);

        // Deserialise source xml tree OR json tree child part model, properties data, count.
        deserialise_cybol_content(p0, pmd, pmc, ppd, ppc, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);

    } else {

        //
        // This is the root node.
        //

        //?? fwprintf(stdout, L"\nDebug: Deserialise cybol element. TEST: root node r: %i\n", r);

        //
        // Reset root node flag.
        //
        // A root node usually just serves as CONTAINER for child nodes,
        // but does not contain any other semantic data itself.
        // Therefore, it gets treated DIFFERENTLY than standard nodes on parsing.
        //
        // This is achieved by using this flag, which is initially set to TRUE
        // in file "constraints_cybol_deserialiser.c" and gets reset to FALSE
        // in file "element_cybol_deserialiser.c", after having detected the root node.
        //
        copy_integer(p16, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Jump over root node and process its children directly.
        deserialise_cybol_part(p0, pmd, pmc, ppd, ppc, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17);
    }
}
