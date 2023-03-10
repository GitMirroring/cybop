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

#ifndef BEGIN_JOINED_STRING_SELECTOR_SOURCE
#define BEGIN_JOINED_STRING_SELECTOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/detector/detector.c"
#include "../../../executor/representer/deserialiser/joined_string/value_joined_string_deserialiser.c"
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
 * @param p11 the quotation begin data, e.g. a quotation mark
 * @param p12 the quotation begin count
 * @param p13 the quotation flag
 * @param p14 the part name data
 * @param p15 the part name count
 */
void select_joined_string_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select joined string begin.");
    //?? fwprintf(stdout, L"Debug: Select joined string begin. source count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select joined string begin. source count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! Do NOT skip whitespace characters here.
    // They can get considered by defining a suitable
    // delimiter sequence containing a whitespace character.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Detect quotation begin character sequence.
        detect((void*) &r, p1, p2, p11, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set quotation flag.
            copy_integer(p13, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Deserialise value.
            deserialise_joined_string_value(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p13, p14, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The quotation begin character sequence could NOT be detected.
        // Therefore, process any other data as simple values.
        //

        // Deserialise value.
        deserialise_joined_string_value(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p13, p14, p15);
    }
}

/* BEGIN_JOINED_STRING_SELECTOR_SOURCE */
#endif
