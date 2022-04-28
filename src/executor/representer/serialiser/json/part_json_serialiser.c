/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PART_JSON_SERIALISER_SOURCE
#define PART_JSON_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/name/json/json_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/serialiser/json/break_json_serialiser.c"
#include "../../../../executor/representer/serialiser/json/element_json_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the part into json.
 *
 * @param p0 the destination item
 * @param p1 the source model or properties data
 * @param p2 the source model or properties count
 * @param p3 the indentation flag
 * @param p4 the tree level
 */
void serialise_json_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise json part.");
    fwprintf(stdout, L"Debug: Serialise json part. tree level p4: %i\n", p4);
    fwprintf(stdout, L"Debug: Serialise json part. tree level *p4: %i\n", *((int*) p4));

    // Append array begin character.
    modify_item(p0, (void*) ARRAY_BEGIN_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ARRAY_BEGIN_JSON_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Append line feed character if non-empty.
    serialise_json_break(p0, p2, p3);

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
    copy_integer((void*) &l, p4);

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

            //
            // The last child part element has been reached.
            //

            // Append array end character.
            modify_item(p0, (void*) ARRAY_END_JSON_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) ARRAY_END_JSON_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
            // Append comma character.
            modify_item(p0, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            break;
        }

        fwprintf(stdout, L"Debug: Serialise json part. j: %i\n", j);
        fwprintf(stdout, L"Debug: Serialise json part. level l: %i\n", l);

        serialise_json_element(p0, p1, (void*) &j, p3, (void*) &l);

        // Increment loop variable.
        j++;
    }
}

/* PART_JSON_SERIALISER_SOURCE */
#endif
