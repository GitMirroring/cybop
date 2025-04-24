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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the part into json.
 *
 * @param p0 the destination item
 * @param p1 the source model or properties data
 * @param p2 the source model or properties count
 * @param p3 the sign flag
 * @param p4 the number base
 * @param p5 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p6 the decimal separator data
 * @param p7 the decimal separator count
 * @param p8 the decimal places
 * @param p9 the scientific notation flag
 * @param p10 the indentation flag
 * @param p11 the tree level
 */
void serialise_json_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise json part.");
    //?? fwprintf(stdout, L"Debug: Serialise json part. tree level p11: %i\n", p11);
    //?? fwprintf(stdout, L"Debug: Serialise json part. tree level *p11: %i\n", *((int*) p11));

    // Append array begin character.
    modify_item(p0, (void*) BEGIN_ARRAY_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) BEGIN_ARRAY_JSON_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Append part prefix.
    serialise_json_prefix(p0, p2, p10);

    //
    // The new tree level.
    //
    // It gets initialised with the current tree level incremented by one.
    //
    // CAUTION! Do NOT manipulate the original tree level that was
    // handed over as parametre since otherwise, it would never get
    // decremented anymore leading to wrong indentation.
    //
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise new tree level with current tree level.
    copy_integer((void*) &l, p11);

    // Increment new tree level.
    calculate_integer_add((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        //
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        //?? fwprintf(stdout, L"Debug: Serialise json part. j: %i\n", j);
        //?? fwprintf(stdout, L"Debug: Serialise json part. level l: %i\n", l);

        // Append element.
        serialise_json_element(p0, p1, (void*) &j, p3, p4, p5, p6, p7, p8, p9, p10, (void*) &l);

        // Increment loop variable.
        j++;

        //
        // Append comma if this is NOT the last element.
        //
        // CAUTION! Call this function only AFTER having incremented
        // the loop variable, in order to be able to compare
        // that index with the source model count.
        // Remember that indices start with zero and are
        // smaller by ONE as compared to the count.
        //
        serialise_json_comma(p0, (void*) &j, p2);

        // Append two line breaks.
        serialise_json_break(p0, p10);
        serialise_json_break(p0, p10);
    }

    // Append part suffix.
    serialise_json_suffix(p0, p2, p10, p11);
    // Append array end character.
    modify_item(p0, (void*) END_ARRAY_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) END_ARRAY_JSON_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}
