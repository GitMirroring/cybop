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

#ifndef MEMBER_JSON_DESERIALISER_SOURCE
#define MEMBER_JSON_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
//
// CAUTION! The file below is NOT included, in order to avoid circular
// references leading to the warning "conflicting types" due to a previous
// implicit declaration. Therefore, a forward declaration is used instead.
//
// #include "../../../executor/representer/deserialiser/json/value_json_deserialiser.c"
//
#include "../../../../executor/selector/json/end_string_json_selector.c"
#include "../../../../logger/logger.c"

//
// Forward declarations
//

void deserialise_json_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

/**
 * Deserialises the json object member.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void deserialise_json_member(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise json member.");
    fwprintf(stdout, L"Debug: Deserialise json member. count remaining p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise json member. count remaining *p3: %i\n", *((int*) p3));

    // The element data, count.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise element.
    copy_pointer((void*) &ed, p2);

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

        select_json_string_end(p2, p3, (void*) &b);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;

        } else {

            // Increment member count.
            ec++;
        }
    }

    //
    // CAUTION! Set object flag to FALSE.
    //
    // It is relevant only if the value to be detected is a STRING.
    // The flag indicates that the string is to be allocated as
    // standalone value and NOT to be taken as name of an
    // object member name-value pair.
    //
    // CAUTION! Do NOT call function "select_json_value_begin" directly,
    // but function "deserialise_json_value" instead, since that contains
    // a loop which is necessary for detecting and skipping unnecessary characters.
    //
    deserialise_json_value(p0, p1, p2, p3, ed, (void*) &ec, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"Debug: Deserialise json member. FINISHED member ec: %i\n", ec);
}

/* MEMBER_JSON_DESERIALISER_SOURCE */
#endif
