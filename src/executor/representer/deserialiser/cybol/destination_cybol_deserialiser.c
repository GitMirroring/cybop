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
 * @param p2 the source xml tree OR json tree model data
 * @param p3 the source xml tree OR json tree model count
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
void deserialise_cybol_destination(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol destination.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol destination. format p19: %i\n", p19);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol destination. format *p19: %i\n", *((int*) p19));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p19, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Deserialise cybol destination. part r: %i\n", r);

            //
            // Deserialise temporary model and properties into cyboi MODEL using temporary type, format.
            //
            // CAUTION! The tags (structural data) and attributes (meta data) are swapped in meaning.
            //
            deserialise_cybol_part(p0, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p19, (void*) PROPERTY_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Deserialise cybol destination. property r: %i\n", r);

            //
            // Deserialise temporary model and properties into cyboi PROPERTIES using temporary type, format.
            //
            // CAUTION! The tags (structural data) and attributes (meta data) are swapped in meaning.
            //
            deserialise_cybol_part(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18);
        }
    }
}
