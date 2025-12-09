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
 * Branches programme flow depending upon xml or json, in order to deserialise cybol node with the correct arguments.
 *
 * @param p0 the destination item
 * @param p1 the source name part model item data
 * @param p2 the source name part model item count
 * @param p3 the source channel part model item data
 * @param p4 the source channel part model item count
 * @param p5 the source format part model item data
 * @param p6 the source format part model item count
 * @param p7 the source model part model item data
 * @param p8 the source model part model item count
 * @param p9 the source properties part model item data
 * @param p10 the source properties part model item count
 * @param p11 the source model data
 * @param p12 the source model count
 * @param p13 the language properties (constraints) data
 * @param p14 the language properties (constraints) count
 * @param p15 the knowledge memory part (pointer reference)
 * @param p16 the stack memory item
 * @param p17 the internal memory data
 * @param p18 the language
 * @param p19 the decimal separator data
 * @param p20 the decimal separator count
 * @param p21 the thousands separator data
 * @param p22 the thousands separator count
 * @param p23 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p24 the root node flag
 * @param p25 the initial fileread flag
 */
void deserialise_cybol_branching2(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23, void* p24, void* p25) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol branching2.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p18, (void*) CYBOL_JSON_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a text/cybol+json file.
            //

            //
            // Deserialise cybol node.
            //
            // CAUTION! Hand over p9 and p10 as properties (and NOT p11 and p12).
            //
            deserialise_cybol_standard(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p18, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a text/cybol file, which is identical to a text/cybol+xml file.
            //

            //
            // Deserialise cybol node.
            //
            // CAUTION! Hand over p11 and p12 as properties (and NOT p9 and p10).
            //
            deserialise_cybol_standard(p0, p1, p2, p3, p4, p5, p6, p7, p8, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p18, (void*) CYBOL_XML_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a text/cybol+xml file.
            //

            //
            // Deserialise cybol node.
            //
            // CAUTION! Hand over p11 and p12 as properties (and NOT p9 and p10).
            //
            deserialise_cybol_standard(p0, p1, p2, p3, p4, p5, p6, p7, p8, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol branching2. The language is unknown.");
        fwprintf(stdout, L"Warning: Could not deserialise cybol branching2. The language is unknown. language p18: %i\n", p18);
        fwprintf(stdout, L"Warning: Could not deserialise cybol branching2. The language is unknown. language *p18: %i\n", *((int*) p18));
    }
}
