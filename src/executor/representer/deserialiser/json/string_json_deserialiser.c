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

#ifndef STRING_JSON_DESERIALISER_SOURCE
#define STRING_JSON_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/modifier/part_modifier.c"
#include "../../../../executor/selector/json/end_string_json_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the json string.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the name data
 * @param p5 the name count
 */
void deserialise_json_string(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise json string.");
    //?? fwprintf(stdout, L"Debug: Deserialise json string. count remaining p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise json string. count remaining *p3: %i\n", *((int*) p3));
    //?? fwprintf(stdout, L"Debug: Deserialise json string. data position *p2 ls: %ls\n", (wchar_t*) *((void**) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise json string. data position *p2 lc: %lc\n", *((wchar_t*) *((void**) p2)));
    //?? fwprintf(stdout, L"Debug: Deserialise json string. data position *p2 lc as int: %i\n", *((wchar_t*) *((void**) p2)));

    // The string part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The string part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The string data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int sc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Allocate string part.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Fill string part.
    //
    // CAUTION! Do NOT forget to assign the format and type.
    //
    modify_part(p, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p5, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
    modify_part(p, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    modify_part(p, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

    // Get string part model.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Initialise string data.
    copy_pointer((void*) &sd, p2);

    if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_json_string_end(p2, p3, (void*) &sc, (void*) &b);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Deserialise json string. sc: %i\n", sc);
            //?? fwprintf(stdout, L"Debug: Deserialise json string. sd: %ls\n", (wchar_t*) sd);

            // Overwrite string part model.
            modify_item(pm, sd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &sc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            break;
        }
    }

    //
    // Append string part to destination.
    //
    // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
    // This is necessary in order to activate rubbish (garbage) collection.
    //
    modify_item(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}

/* STRING_JSON_DESERIALISER_SOURCE */
#endif
