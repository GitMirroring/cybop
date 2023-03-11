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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ELEMENT_TEXTLINE_LIST_DESERIALISER_SOURCE
#define ELEMENT_TEXTLINE_LIST_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/logifier/boolean/or_boolean_logifier.c"
#include "../../../../executor/representer/deserialiser/textline_list/index_textline_list_deserialiser.c"
#include "../../../../executor/selector/newline/newline_selector.c"
#include "logger.h"

/**
 * Deserialises a single textline.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the textline data (pointer reference)
 * @param p4 the textline count
 * @param p5 the loop index
 */
void deserialise_textline_list_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** td = (void**) p3;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise textline list element.");
        //?? fwprintf(stdout, L"Debug: Deserialise textline list element. source count remaining p2: %i\n", p2);
        //?? fwprintf(stdout, L"Debug: Deserialise textline list element. source count remaining *p2: %i\n", *((int*) p2));

        // The newline flag.
        int n = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The end flag.
        int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Check for newline sequence.
        select_newline((void*) &n, p1, p2, p4);
        //
        // Check for source data end.
        //
        // CAUTION! The LAST line is NOT always followed by a
        // newline sequence. But in order to process it correctly,
        // a source data end check has to be performed here.
        //
        // CAUTION! Do this check only AFTER having called function
        // "select_newline" above, so that the source count remaining
        // is already decremented to ZERO and the END can be detected here.
        //
        compare_integer_less_or_equal((void*) &e, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        // Initialise comparison result.
        copy_integer((void*) &r, (void*) &n);
        // Apply logic OR to both results.
        logify_boolean_or((void*) &r, (void*) &e);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Serialise loop index to be used as part name.
            deserialise_textline_list_index(p0, *td, p4, p5);

            //
            // Adjust textline data, count.
            //
            // CAUTION! Assign current source DATA position as new textline start.
            // It got moved inside the called select function
            // and already points to the CURRENT position.
            //
            // CAUTION! The textline COUNT has to be reset to ZERO,
            // so that each new line gets counted separately.
            //
            copy_pointer(p3, p1);
            copy_integer(p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            //
            // Increment line index.
            //
            // CAUTION! Do NOT increment it in the loop since that counts
            // the CHARACTERS while here, the single LINES are numerated.
            //
            calculate_integer_add(p5, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise textline list element. The textline data is null.");
        fwprintf(stdout, L"Error: Could not deserialise textline list element. The textline data is null. textline data p3: %i\n", p3);
    }
}

/* ELEMENT_TEXTLINE_LIST_DESERIALISER_SOURCE */
#endif
