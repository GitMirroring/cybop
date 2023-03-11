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

#ifndef JSON_SERIALISER_SOURCE
#define JSON_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/representer/serialiser/json/part_json_serialiser.c"
#include "../../../../executor/representer/serialiser/json/string_json_serialiser.c"
#include "logger.h"

/**
 * Serialises the source cyboi knowledge tree into the destination json format.
 *
 * @param p0 the destination wide character item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the sign flag
 * @param p6 the number base
 * @param p7 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p8 the decimal separator data
 * @param p9 the decimal separator count
 * @param p10 the decimal places
 * @param p11 the scientific notation flag
 * @param p12 the indentation flag
 * @param p13 the tree level
 * @param p14 the format
 */
void serialise_json(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise json.");
    //?? fwprintf(stdout, L"Debug: Serialise json. format p14: %i\n", p14);
    //?? fwprintf(stdout, L"Debug: Serialise json. format *p14: %i\n", *((int*) p14));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_json_part(p0, p1, p2, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) PROPERTY_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Using the model data and count p1 and p2 is CORRECT here,
            // and setting the properties flag to FALSE is correct as well.
            //
            // The distinction between model and properties by setting the properties flag
            // is made in file "content_json_serialiser.c".
            //
            serialise_json_part(p0, p1, p2, p5, p6, p7, p8, p9, p10, p11, p12, p13);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) BYTE_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Use Base64 encoding for binary data.
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) ASCII_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Use Base64 encoding for binary data.
        }
    }

    //
    // Other formats
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Treat other formats as string.
        //
        // CAUTION! The boolean values and all kinds of numbers are serialised
        // as STRING and put in quotation marks on purpose, even though the
        // json standard recommends them to be serialised without quotation marks.
        //
        // The reason is that cyboi manages all data as ARRAY inside,
        // no matter if a SINGLE or MANY values are stored.
        // But json makes a difference between a single value
        // and many values, whereby the latter are treated as array
        // and have to be put in brackets.
        //
        // Examples:
        //
        // 1 List of values WITHOUT quotation marks:
        // ["array", "inline", "number/integer", 1,2,3, []],
        // Problem: Wrong cybop schema due to the many commas.
        //
        // 2 Array BRACKETS as in json:
        // ["array", "inline", "number/integer", [1,2,3], []],
        // Problem: Injured cybop schema, since the contained
        // numbers are NOT parts.
        //
        // 3 Values in QUOTATION MARKS:
        // ["array", "inline", "number/integer", "1,2,3", []],
        //
        // The currently implemented solution is number 3.
        //

        serialise_json_string(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p14);
    }
}

/* JSON_SERIALISER_SOURCE */
#endif
