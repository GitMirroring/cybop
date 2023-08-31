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
 * @version CYBOP 0.27.0 2023-08-31
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

#include "algorithm.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the joined string value end by searching for the given delimiter sequence,
 * consisting of a quotation and the actual delimiter.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the escape data, e.g. a DOUBLE quotation mark
 * @param p4 the escape count
 * @param p5 the quotation end PLUS delimiter data, e.g. a quotation mark + comma OR apostrophe + semicolon
 * @param p6 the quotation end PLUS delimiter count
 * @param p7 the quotation end data, e.g. a quotation mark
 * @param p8 the quotation end count
 * @param p9 the break flag
 */
void select_joined_string_end_quotation(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select joined string end quotation.");
    //?? fwprintf(stdout, L"Debug: Select joined string end quotation. source count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select joined string end quotation. source count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The ORDER of the following comparisons is IMPORTANT!
    //
    // The escape characters have to get replaced BEFORE
    // the end delimiter sequence gets detected.
    //
    // Example: """value 1"", with comma and additional content", "value 2", "value 3"
    //
    // The double quotation marks are escaped and represent just ONE quotation mark.
    // The comma following after the double quotation mark does NOT represent
    // a delimiter, since it is standing in between the quoted sequence.
    //

    //
    // CAUTION! Do NOT skip whitespace characters here,
    // since they might belong to the actual VALUE.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Replace escape characters.
        detect((void*) &r, p1, p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Append SIMPLE quotation character to destination item.
            //
            // CAUTION! Do NOT use the doubled escape sequence.
            //
            modify_item(p0, p7, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p8, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Detect COMBINATION of quotation and delimiter sequence.
        detect((void*) &r, p1, p2, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set loop break flag.
            copy_integer(p9, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Detect quotation end ONLY sequence.
        //
        // CAUTION! This is more proper than letting the loop detect a
        // remaining count <= zero, since it is a well-defined end sequence.
        // It applies for the LAST value only.
        //
        detect((void*) &r, p1, p2, p7, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set loop break flag.
            copy_integer(p9, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a STANDARD character.
        //
        // CAUTION! A standalone delimiter character (e.g. comma)
        // gets IGNORED and is treated like any other character,
        // since standing WITHIN the quotation.
        //

        // The character.
        void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Copy character.
        copy_pointer((void*) &c, p1);

        // Append character to destination item.
        modify_item(p0, c, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Increment the current position by one.
        move(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}
