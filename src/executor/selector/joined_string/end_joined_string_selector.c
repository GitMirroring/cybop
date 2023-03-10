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

#ifndef END_JOINED_STRING_SELECTOR_SOURCE
#define END_JOINED_STRING_SELECTOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/selector/joined_string/quotation_end_joined_string_selector.c"
#include "../../../executor/selector/joined_string/value_end_joined_string_selector.c"
#include "../../../logger/logger.c"

/**
 * Forks deserialisation between a branch WITH and WITHOUT given quotation character.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the delimiter data, e.g. a comma OR semicolon OR some character sequence
 * @param p4 the delimiter count
 * @param p5 the escape data, e.g. a DOUBLE quotation mark
 * @param p6 the escape count
 * @param p7 the quotation end PLUS delimiter data, e.g. a quotation mark + comma OR apostrophe + semicolon
 * @param p8 the quotation end PLUS delimiter count
 * @param p9 the quotation end data, e.g. a quotation mark
 * @param p10 the quotation end count
 * @param p11 the quotation flag
 * @param p12 the break flag
 */
void select_joined_string_end(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select joined string end.");
    //?? fwprintf(stdout, L"Debug: Select joined string end. source count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select joined string end. source count remaining *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Select joined string end. quotation flag p11: %i\n", p11);
    //?? fwprintf(stdout, L"Debug: Select joined string end. quotation flag *p11: %i\n", *((int*) p11));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p11, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A quotation end character sequence is NOT given.
        //

        select_joined_string_end_value(p0, p1, p2, p3, p4, p12);

    } else {

        //
        // A quotation end character sequence IS given.
        //

        select_joined_string_end_quotation(p0, p1, p2, p5, p6, p7, p8, p9, p10, p12);
    }
}

/* END_JOINED_STRING_SELECTOR_SOURCE */
#endif
